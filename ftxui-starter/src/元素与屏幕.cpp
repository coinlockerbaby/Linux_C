#include <iostream>
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/component.hpp"
using namespace std;
using namespace ftxui;

int main()
{
    // 创建一个文本元素
    Element document = hbox(
            // 元素
            text("原神，启动")|flex|border,
            text("前面的区域以后再来探索")|border
            );
    // 创建一个屏幕
    auto screen = Screen::Create(
            Dimension::Full(),
            Dimension::Full()
            );
    Render(screen, document);
    screen.Print();
    cout << "hello" << endl;
    return 0;
}