#include <iostream>
using namespace std;

class Hero
{
public:
  int viability;
  int attack;
  virtual void
  skill1 ()
  {
    cout << "英雄释放一技能" << endl;
  }
  virtual void
  skill2 ()
  {
    cout << "英雄释放二技能" << endl;
  }
  virtual void
  uskill ()
  {
    cout << "英雄释放了大招" << endl;
  }
};

class XS : public Hero
{
public:
  void
  skill1 ()
  {
    cout << "西施释放一技能" << endl;
  }
  void
  skill2 ()
  {
    cout << "西施释放二技能" << endl;
  }
  void
  uskill ()
  {
    cout << "西施释放大招" << endl;
  }
};

class LB : public Hero
{
public:
  void
  skill1 ()
  {
    cout << "李白释放一技能" << endl;
  }
  void
  skill2 ()
  {
    cout << "李白释放二技能" << endl;
  }
  void
  uskill ()
  {
    cout << "李白释放大招" << endl;
  }
};

int
main ()
{
  int id = 0;
  cout << "请输入英雄 (1-西施 2-李白)" << endl;
  cin >> id;
  Hero *ptr = nullptr;
  if (id == 1)
    {
      ptr = new XS;
    }
  else if (id == 2)
    {
      ptr = new LB;
    }
  if (ptr != nullptr)
    {
      ptr->skill1 ();
      ptr->skill2 ();
      ptr->uskill ();
    }
  delete ptr;
  
}
