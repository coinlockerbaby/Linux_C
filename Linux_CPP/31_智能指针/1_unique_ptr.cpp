#include <iostream>
#include <memory>
using namespace std;

class AA
{
public:
  string m_name;
  AA()
  {
    cout << m_name << "调用构造函数AA()" << endl;
  }
  AA (const string &name) : m_name(name)
  {
    cout << "调用了构造函数AA(name)" << endl;
  }
  ~AA ()
  {
    cout << "调用了析构函数" << endl;
  }
};

int
main()
{
  AA *p = new AA("西施");
}
