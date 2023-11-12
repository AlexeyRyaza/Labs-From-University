#pragma once

int Input_check();
int Input_check_n(int number, int bot = INT_MIN, int top = INT_MAX);
int Input_check_X(int number, int i, int bot = INT_MIN, int top = INT_MAX);

int sum(int, int);

double* alloc_mem(int n);
double fullfil_X(double* X, int n);
double create_Y(double* Y, int n);

double multiplication(double* X, double* Y, double* C, int n);

void print_mass(double* X, int n);

void delete_mass(double* array);