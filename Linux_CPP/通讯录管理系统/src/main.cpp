#include "head.hpp"
using namespace std;

int
main ()
{
  showMenu ();
  int func_select;
  while (1)
    {
      cin >> func_select;
      switch (func_select)
        {
        case 1:
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          break;
        case 0:
          {
            cout << "欢迎下次使用" << endl;
            return 0;
            break;
          }
        default:
          {
            cout << "输入错误" << endl;
            break;
          }
        }
    }
}