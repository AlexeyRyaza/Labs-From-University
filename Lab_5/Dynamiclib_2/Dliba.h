#include <limits>

#pragma once

extern "C" __declspec(dllexport) int Input_check();
extern "C" __declspec(dllexport) int Sum(int, int);

extern "C" __declspec(dllexport) int Input_check_n(int number, int bot = 0, int top = INT_MAX);

extern "C" __declspec(dllexport) void Print_mass(double* X, int n);

extern "C" __declspec(dllexport) double Input_check_num(double number, int i, int bot = INT_MIN, int top = INT_MAX);
extern "C" __declspec(dllexport) double Fullfill_B(double* B, int n);

extern "C" __declspec(dllexport) double Solution(double* B, int a, int b);

extern "C" __declspec(dllexport) void Delete_mem(double* B); 
