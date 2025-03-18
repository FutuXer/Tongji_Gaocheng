/* ÐÅ01 2353726 ¸¶ìÏ³¬ */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
using namespace std;
#pragma once

void dig_ini(int row, int col, int sj = 0);
void dropdig(int row, int col, char dig[12][12], char color[12][12], int x, int sj);
void ini_struct(int row, int col, char dig[12][12], char color[12][12], int sj);
int menu();
int strlow(char str[]);
void jieshu();