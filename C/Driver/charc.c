#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
int main(int argc, char *argv[])
{
  int fd;
  ssize_t nread, nwrite;
  char rdstr[10];
  
  fd = open("/dev/MYDRIV", O_RDWR);
  
  if (fd==-1)
  {
    perror("File description !!!! \n");
    return -1;
  }
   
  nread = read(fd, &rdstr, 10);
  if (nread==-1) 
  {
    perror("Cannot READ \n");
    return -1;
  }
      
  nwrite = write(fd, argv[1], sizeof(argv[1]));
  
  if (nwrite==-1) 
  {
    perror("Cannot WRITE \n");
    return -1;
  }
    
  close(fd);

    return 0;
}
