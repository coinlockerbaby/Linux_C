/****************************************************/
// ESP8266 TOOL TUI
// 程序功能:ESP8266 TUI Tool
// 描述:具有TUI界面的串口收发上位机
// by:flose
// E-mail:seeyounextsun@Outlook.com
// 创建日期:2023/7/21
// 备注：
/**********************[INCLUDE]*********************/
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/dom/elements.hpp"
#include <iostream>
#include "CSerialPort/SerialPort.h"

using namespace ftxui;

// 串口选择下拉框
std::vector<std::string> uart_port = {
    "port1",
    "port2",
    "port3"
};
int uart_port_selected = 0;
auto uart_port_Dropdown = Dropdown(&uart_port,&uart_port_selected);
// 配置单选框内容
// 波特率
std::vector<std::string> uart_baudrate = {
    "9600",
    "19200",
    "115200"
};
int uart_baudrate_selected = 0;
auto uart_baudrate_radiobox = Radiobox(&uart_baudrate,&uart_baudrate_selected);
// 校验位
std::vector<std::string> uart_check = {
    "无校验",
    "奇校验",
    "偶校验",
    "1校验",
    "0校验"
};
int uart_check_selected = 0;
auto uart_check_radiobox = Radiobox(&uart_check,&uart_check_selected);

// 数据位
std::vector<std::string> uart_databit = {
    "5",
    "6",
    "7",
    "8"
};
int uart_databit_selected = 0;
auto uart_databit_radiobox = Radiobox(&uart_databit,&uart_databit_selected);

// 输入框
std::string uart_transdata;
auto uart_transdata_input = Input(&uart_transdata, "Please input trans data");

// 接受数据框
std::string uart_receive_string = "power by ftxui \n make by flose";
// 按钮
auto uart_button = Container::Horizontal({
    Button("connect",nullptr)|color(Color::Pink1),
    Button("disconnect",nullptr)|color(Color::Red1),
    Button("trans",nullptr)
});

int
main(void)
{
    // 组件 装饰器模式
    auto component = Container::Vertical(
    {
        // dropdown
        uart_port_Dropdown,
        // raiobox
        uart_baudrate_radiobox, 
        uart_check_radiobox,
        uart_databit_radiobox,
        // input
        uart_transdata_input,
        // button
        uart_button
    }
    );
    // 布局
    auto layout = Renderer(
        component,
        [&]{
            return vbox(
                paragraphAlignCenter("ESP8266 ASSISTANT")|color(Color::Gold1),
                separator(),
                hbox(
                    vbox(
                        window(text("端口"),uart_port_Dropdown->Render()),
                        window(text("波特率"),uart_baudrate_radiobox->Render()),
                        window(text("校验位"),uart_check_radiobox->Render()),
                        window(text("数据位"),uart_databit_radiobox->Render())
                    ),
                    vbox(
                        window(text("[receive data]")|color(Color::Cyan1),paragraph(uart_receive_string))|flex,
                        window(text("[trans data]")|color(Color::Cyan1),uart_transdata_input->Render())|flex,
                        hbox(
                            uart_button->Render()
                        )
                    )|flex
                )
            )|border;
        }
    );
    // screen
    auto screen = ScreenInteractive::Fullscreen();
    screen.Loop(layout);
    exit(0);
}