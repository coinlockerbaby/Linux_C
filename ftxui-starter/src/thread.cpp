/****************************************************/
// ESP8266 TOOL TUI
// 程序功能:ESP8266 TUI Tool
// 描述: 多线程函数 
// by:flose
// E-mail:seeyounextsun@Outlook.com
// 创建日期:2023/7/26
// 备注：
/**********************[INCLUDE]*********************/
#include "thread.hpp"



// 扫描串口函数
void*
thread_scan_port(void *args)
{
    while(1)
    {
        uart_getinfo(&uart_port);
        sleep(1); // 线程挂起1s
    }
    return 0;
}

// 读取串口接收信息
void*
thread_readportdata(void *args)
{
    char data[512];
    while(1)
    {

        //if(my_serialport.readAllData(data) != -1)
        //{
         //   uart_receive_string.append(std::string(data)+" ");
        //}
        usleep(100000);
    }
}