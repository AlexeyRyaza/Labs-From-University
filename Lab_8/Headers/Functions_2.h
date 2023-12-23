#pragma once
#include "Struct_2.h"

void WriteData(const Student* student);

void SetName(Student* student, int num);

void SetAdress(Student* student, int num);

void SetMarkLanguage(Student* student, int num);

void SetMarkMath(Student* student, int num);

void SetMarkPhysics(Student* student, int num);

void SetInfo(Student* student, int num);

void PrintInfo(const Student* student, int i);

void AddStudent(Student* list);

void PrintAllInfo(const Student* list);

void DeleteStudent(Student* student, int num);

void Task(const Student* student);

void Menu(Student* list, int desicion);