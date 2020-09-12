#include <iostream>
#include <vector>
#include <cmath>
#include "math.h"


int main()
{
  
  std::vector<std::vector<float>> inpData = { {1,0,0},{0,0.5,0},{0,0,1} };
 
  std::vector<float> outData = { 0,0.5,1 };
  
  std::vector<float> weight = {1,0,1};

  for(int e = 0; e < 400;++e)
  {
    for(int t = 0 ; t < inpData.size(); ++t)
    {
      float result = sigmoid(Math::Multy(inpData[t],weight));
      float err  = outData[t] - result;
      std::vector<float> nweight = Math::Multy(inpData[t],err * activation(result)); 
      weight = Math::Plus(nweight,weight);
        
    }

  }

 std::cout<<"Resultat:"<<"\n";
 std::cout<<"Out   "<<"Predskazanie"<<"\n";

 for(int t = 0 ; t < inpData.size(); ++t)
    {
      float result = sigmoid(Math::Multy(inpData[t],weight)); 
      std::cout<<outData[t]<<"\t"<<result<<"\n";
   
   
    }

return 0;
}


