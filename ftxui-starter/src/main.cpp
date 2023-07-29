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
#include "process.hpp"
#include "thread.hpp"
#include <pthread.h>
#include "CSerialPort/SerialPort.h"
using namespace ftxui;

// 定义串口信息结构体
uart_settings uart_Settings;
itas109::CSerialPort my_serialport;

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
auto uart_baudrate_Dropdown = Dropdown(&uart_baudrate,&uart_baudrate_selected);
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
int uart_databit_selected = 3;
auto uart_databit_radiobox = Radiobox(&uart_databit,&uart_databit_selected);

// 停止位
std::vector<std::string> uart_stopbit = {
    "1",
    "1.5",
    "2"
};
int uart_stopbit_selected = 0;
auto uart_stopbit_radiobox = Radiobox(&uart_stopbit,&uart_stopbit_selected);

// 输入框
std::string uart_transdata;
auto uart_transdata_input = Input(&uart_transdata, "Please input trans data");

// 接收数据框
std::string uart_receive_string = my_serialport.getVersion();
// 按钮
// 按钮回调函数
std::string on_off_lable = "connect";
void
on_off_button_clicked(void)
{
    if (on_off_lable == "connect")
    {
        uart_Settings.portName = uart_port[uart_port_selected];
        uart_Settings.baudRate = stoi(uart_baudrate[uart_baudrate_selected]);
        uart_Settings.parity = itas109::Parity (uart_check_selected);
        uart_Settings.dataBits = itas109::DataBits(stoi(uart_databit[uart_databit_selected]));
        uart_Settings.stopBits = itas109::StopBits (uart_stopbit_selected);
        my_serialport.init( uart_Settings.portName.c_str(),                                 // 串口名称 Windows:COM1 Linux:/dev/ttyS0
                                uart_Settings.baudRate,                 // 波特率
                                uart_Settings.parity,         // 校验位
                                uart_Settings.dataBits,      // 数据位
                                uart_Settings.stopBits        // 停止位
        );
        my_serialport.open();
        if(my_serialport.isOpen())
        {
            uart_receive_string.append("UART CONNECT SUCCESS! ");
        }
        else
        {
            uart_receive_string.append("UART CONNECT ERROR! ");
        }
        on_off_lable = "disconnect";
    }
    else 
    {
        my_serialport.close();
        uart_receive_string.append("UART DISCONNCT!\n");
        on_off_lable = "connect";
    }
}

void
trans_button_clicked(void)
{
   my_serialport.writeData(&uart_transdata ,uart_transdata.length());
}
void
clear_button_clicked(void)
{
    uart_receive_string = {};
}

auto uart_button = Container::Horizontal({
    Button(&on_off_lable,on_off_button_clicked)|color(Color::Pink1),
    Button("trans",trans_button_clicked)|color(Color::SkyBlue1),
    Button("clear",clear_button_clicked)|color(Color::Aquamarine1)
});

int
main(void)
{
    // 创建线程->串口扫描
    pthread_t tid[2];
    int ret1 = pthread_create(&tid[0], NULL, &thread_scan_port, NULL);
    if(ret1 != 0)
    {
        fprintf(stderr, "PortScan thread creation failed\n");
        exit(1);
    }
    int ret2 = pthread_create(&tid[1], NULL, &thread_readportdata, NULL);
    if(ret2 != 0)
    {
        fprintf(stderr, "ReadData thread creation failed\n");
        exit(1);
    }
    // 组件 装饰器模式
    auto component = Container::Vertical(
    {
        // dropdown
        uart_port_Dropdown,
        uart_baudrate_Dropdown, 
        // raiobox
        uart_check_radiobox,
        uart_databit_radiobox,
        uart_stopbit_radiobox,
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
                paragraphAlignCenter("UART ASSISTANT")|color(Color::Gold1),
                separator(),
                hbox(
                    vbox(
                        window(text("端口"),uart_port_Dropdown->Render()),
                        window(text("波特率"),uart_baudrate_Dropdown->Render()),
                        window(text("校验位"),uart_check_radiobox->Render()),
                        window(text("数据位"),uart_databit_radiobox->Render()),
                        window(text("停止位"),uart_stopbit_radiobox->Render())
                    ),
                    vbox(
                        window(text("[receive data]")|color(Color::Cyan1),paragraphAlignLeft(uart_receive_string))|flex,
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