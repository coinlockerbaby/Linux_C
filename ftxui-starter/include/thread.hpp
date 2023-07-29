#ifndef __THREAD_H__
#define __THREAD_H__

#include <iostream>
#include <stdio.h>
#include <vector>
#include <unistd.h>
#include "process.hpp"
#include <time.h>
#include <sys/time.h>
#include <string.h>

extern std::vector<std::string> uart_port;
extern itas109::CSerialPort my_serialport;
extern std::string uart_receive_string;
void* thread_scan_port(void *args);
void* thread_readportdata(void *args);
#endif