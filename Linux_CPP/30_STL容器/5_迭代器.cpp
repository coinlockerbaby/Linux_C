#include <iostream>
#include <vector>
using namespace std;

int
main()
{
 vector <int> vv = {1,2,3,4,5}; // 初始化vector容器
 vector <int> :: iterator it1 = vv.begin(); // 容器的开始
 *it1 = 8;
 it1++;
 *it1 = 7;
 for (auto it2 = vv.cbegin();it2!=vv.end();it2++)
  {
    cout << *it2 << " ";
  }
  cout << endl;
  vector <int> v2 (vv.cbegin()+2, vv.cend() - 1);
  for (auto i = v2.cbegin();i!=v2.cend();i++)
  {
    cout << *i << " ";
  }


}