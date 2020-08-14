#include <linux/module.h>
#include <linux/fs.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/cdev.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/slab.h> 
 
MODULE_LICENSE("GPL"); 
 
#define SIZE 50
 
 
static dev_t dev; // Global variable for the first device number
static struct cdev c_dev; // Global variable for the character device structure
static struct class *cl; // Global variable for the device class
static char buffer[SIZE];	      /* The msg the device will give when asked */
static char *p;
static char *a;
static int r;


static int mopen(struct inode *i, struct file *f)
{
  printk(KERN_INFO "Driver: open\n");
 
  return 0;
}

static int mclose(struct inode *i, struct file *f)
{
  printk(KERN_INFO "Driver: close\n");
  return 0;
}

static ssize_t mread(struct file *f, char __user *buf, size_t
  len, loff_t *off)
{
  
  int rbytes ;
  p=buffer;
   
  if(*off >= sizeof(buffer))
  return 0;
  
  if(raw_copy_to_user(buffer,&buf,sizeof(buffer)))
  return 0;
  
  rbytes = sizeof(buffer); 
  *off += len ;
  return rbytes;
}
  
static ssize_t mwrite(struct file *f, const char __user *buf,
  size_t len, loff_t *off)
{
  printk(KERN_INFO "Driver: write\n");
 
   r = len;
   a = kmalloc(len,GFP_KERNEL);
 
  if(raw_copy_from_user(a,buf,len))
  {
    kfree(a);
    return 0;
  }
  
  
  r = len;
  return r;
  
  
}

static struct file_operations fop =
{
  .owner = THIS_MODULE,
  .open = mopen,
  .release = mclose,
  .read = mread,
  .write = mwrite
};
 
static int __init ini(void) 
{
  printk(KERN_INFO "REGISTERED");
  if (alloc_chrdev_region(&dev, 0, 1, "DRIV") < 0)
  {
    return -1;
  }
    if ((cl = class_create(THIS_MODULE, "CHARDRIV")) == NULL)
  {
    unregister_chrdev_region(dev, 1);
    return -1;
  }
    if (device_create(cl, NULL, dev, NULL, "DRIVER") == NULL)
  {
    class_destroy(cl);
    unregister_chrdev_region(dev, 1);
    return -1;
  }
    cdev_init(&c_dev, &fop);
    if (cdev_add(&c_dev, dev, 1) == -1)
  {
    device_destroy(cl, dev);
    class_destroy(cl);
    unregister_chrdev_region(dev, 1);
    return -1;
  }
  return 0;
}
 
static void __exit exxit(void) /* Destructor */
{
  cdev_del(&c_dev);
  device_destroy(cl, dev);
  class_destroy(cl);
  unregister_chrdev_region(dev, 1);
  printk(KERN_INFO "UNREGISTER");
}
 
module_init(ini);
module_exit(exxit);

