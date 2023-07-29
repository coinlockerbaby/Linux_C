#ifndef __PROCESS_H__
#define __PROCESS_H__

#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/dom/elements.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "CSerialPort/SerialPort.h"
#include "CSerialPort/SerialPortInfo.h"

void
uart_getinfo(std::vector<std::string> *uart_port);
typedef struct
{
    std::string portName;
    int baudRate;
    itas109::Parity parity;
    itas109::DataBits dataBits;
    itas109::StopBits stopBits;
    itas109::FlowControl flowControl = itas109::FlowControl(0);
    unsigned int readBufferSize = 512;
}uart_settings;
extern uart_settings uart_Settings;

#endif