/****************************************************/
// ESP8266 TOOL TUI
// 程序功能:ESP8266 TUI Tool
// 描述:具有TUI界面的串口收发上位机
// by:flose
// E-mail:seeyounextsun@Outlook.com
// 创建日期:2023/7/21
/****************************************************/
/**********************[INCLUDE]*********************/
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/dom/elements.hpp"
#include <iostream>

using namespace ftxui;
using namespace std;

int
main(void)
{
    // 组件
    auto component = Container::Vertical(
        {
            
        }
    );
    // 布局
    auto layout = Renderer(
        component,
        [&]{
            return vbox(
                separator(),
                paragraphAlignCenter("HELLO")
            )|border;
        }
    );
    // screen
    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(layout);
    exit(0);
}