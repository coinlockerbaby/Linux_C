/****************************************************/
// ESP8266 TOOL TUI
// 程序功能:ESP8266 TUI Tool
// 描述: 处理串口功能相关函数
// by:flose
// E-mail:seeyounextsun@Outlook.com
// 创建日期:2023/7/26
// 备注：
/**********************[INCLUDE]*********************/
#include "process.hpp"
using namespace itas109;
// 初始化串口信息
void
uart_getinfo(std::vector<std::string> *uart_port)
{
    std::vector<SerialPortInfo> uart_portinfo = CSerialPortInfo::availablePortInfos();
    std::vector<SerialPortInfo>::iterator v = uart_portinfo.begin();
    // 清空port
    *uart_port = {};
    // 迭代器遍历串口name
    while( v != uart_portinfo.end()) {
        (*uart_port).push_back(std::string(v->portName));
        v++;
    }
}
   