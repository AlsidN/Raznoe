import requests
import numpy as np
import threading


weight = np.array([1,0.5,1])
alpha = 0.1
stlit = np.array([[1,0,0],   
                  [1,1,0],
                  [0,1,1],
                  [0,0,1] ])

runstop = np.array([0,0.4,0.6,1])                  


for i in range(100):
 errorall = 0;
 for it in range(len(runstop)):
   inp = stlit[it]
   goal  = runstop[it]
   pred = inp.dot(weight)
   
   print("in :"+str(inp)+"predskaz :"+str(pred))
   error = (pred - goal)**2
   errorall +=error
   delta = pred - goal
   weight = weight-(alpha * (inp * delta))

 
 
 
 
 
 


