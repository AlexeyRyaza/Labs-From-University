#pragma once
#include "Struct_1.h"

void SetName(Worker* worker, int num);

void SetNumber(Worker* worker, int num);

void SetHours(Worker* worker, int num);

void SetPayment(Worker* worker, int num);

void SetInfo(Worker* worker, int num);

void PrintInfo(const Worker* worker);

void BubbleSort(Worker* worker);

void AddWorker(Worker* worker);

void AddWorkerEmpty(Worker* worker);

void DeleteWorker(Worker* worker, int num);

void Menu(Worker* worker, int desicion);