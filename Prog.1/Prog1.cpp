#include <iostream>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <utility>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

void SINCHRO(auto &m,auto &v,auto &dop,auto &mit,auto &vit,auto &e)
{
  for (mit = m.begin(); mit != m.end(); ++mit)
  {
    dop.push_back(mit->second);
  }

  sort(v.begin(), v.end());
  sort(dop.begin(), dop.end());

  for (const auto &r : v)
  {
    cout << r << ",";
  }

  cout << endl;

  for (const auto &w : dop)
  {
    cout << w <<",";
  }

  cout << endl << endl;

  vit = set_intersection(v.begin(), v.end(), dop.begin(), dop.end(), e.begin());

}

void SHOW(auto &v, auto &m)
{
  cout << "-Map-: " << endl;

  for (const auto &a : m)
  {
    cout << a.second <<",";
  }

  cout << endl << endl;
  cout << "-Vector-: " << endl;

  for (const auto &b : v)
  {
    cout << b << ",";
  }

  cout << endl;
}

void DEL(auto &v,auto &m)
{
  v.erase(v.begin() + (1+rand()%15), v.end());

  for (auto it = m.begin(); it != m.end();)
  {
    if (it->second == (1+rand()%9))
    {
      it = m.erase(it);
    }
    else
    {
      ++it;
    }
  }
}

int main()
{
  const size_t N = 15;
  srand(time(0));

  vector<int>  v(N);
  vector<int>  e(N);
  vector<int>  dop;
  vector<int>::iterator vit;

  map<int,int> m;
  map<int,int>::iterator mit;

  for (size_t i = 0; i < N; ++i)
  {
    v[i] = (1+rand()%9);
    m.insert(make_pair(i,(1+rand()%9)));
  }

  DEL(v, m);
  SHOW(v, m);

  cout << endl << setw(30) << "---Sinchron---" << endl;

  SINCHRO(m, v, dop, mit, vit, e);

  v.clear();
  m.clear();

  for (size_t i = 0; i < N; ++i)
  {
    v=e;
    m.insert(make_pair(i, e[i]));
  }

  SHOW(v, m);

  return 0;
}
 
