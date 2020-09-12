#ifndef MATH_H
#define MATH_H

const float EXP = 2.71828;

float sigmoid(float x)
{
  return 1.0f/(1.0f + pow(EXP, -x));

}

float activation(float x)
{
  float a = sigmoid(x);
  return a * (1 - a);

}



namespace Math
{
 template<typename T>
 std::vector<std::vector<T>> Transpose(std::vector<std::vector<T>> &a)
  {
    std::vector<std::vector<T>> result ;
    size_t as = a.size();
    size_t bs = a[0].size();
    result.resize(bs);
   
    for(auto &i : result)
    {
      i.resize(as);    
    } 
        
    for(int i = 0;i < a.size(); ++i)
    {
      for(int j = 0;j < a[i].size(); ++j)
      {                     //Транспонирование матрицы 
        result[j][i] = a[i][j];
      
      }
    }
    return result;
  }
  //Скалярное произведение векторов
  template<typename T>
  T Multy(std::vector<T> &a, std::vector<T> &b)
  {
    T result{};
    if (a.size() != b.size())
    {
      return 0;
    }
        
    for(int i=0;i<a.size();++i)
    {
      result += a[i] * b[i]; 
    }
   
    return result;
  }

 // произведение вектор на число
 template<typename T>
 std::vector<T> Multy(std::vector<T> &a, T b)
  {
    std::vector<T> result = a;
        
    for(int i=0;i<a.size();++i)
    {
      result[i] *= b; 
    }
   
    return result;
  }


 //произведение матрицы на вектор
 template<typename T>
 std::vector<T> Multy(std::vector<std::vector<T>> &a, std::vector<T> &b)
  {
    std::vector<T> result (b.size());
        
    for(int i= 0;i < b.size(); i++)
    {
      result[i] = Multy(a[i],b); 
    }
   
    return result;
  }
  
  // сложение векторов 
 template<typename T>
 std::vector<T> Plus(std::vector<T> &a, std::vector<T> &b)
  {
    std::vector<T> result(a.size());
        
    for(int i=0;i<a.size();++i)
    {
      result[i] = a[i] + b[i]; 
    }
   
    return result;
  }
  
  
  

}



#endif

