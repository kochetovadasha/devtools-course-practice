//Copyright 2016 GoncharovaKochetova

#pragma once

#include "TTable.h"
#include <algorithm>
#include <iostream>
#include <locale>
#include <fstream>
#include <string>

using namespace std;

class ResourceAllocTask
{
public:
    int * Invest;      // массив вложений
    int ** Profit;     // массив доходов
    TTable * S;         //  массив таблиц для демонстрации процесса решения
    TTable Decision;    // таблица для записи ответа
    bool flag;    // контролирует вывод на консоль

    ResourceAllocTask();
    ResourceAllocTask(int n, int m);
    ~ResourceAllocTask();

    int operator[] (int i) const { return Invest[i]; }
    int* operator[](int elem)  { return Profit[elem]; }

    int GetSizeN() { return SizeN; }
    int GetSizeM() { return SizeM; }

    void BellStep();   // процесс решения-реализация принципа Беллмана

    void Print(int i);    // печатает i-ую таблицу решения
    void PrintInvest();   // печатаем массив вложений
    void PrintProfit();   // печатает массив доходов
    void PrintDecision(); // печатает ответ

    void main();  
    void SaveInFile(string name);   // запись ответа в файл
    int GetAnswer() { return Answer; }

private:
    int X_k;   // текущее состояние
    int U;     // текущее управление
    int SizeN, SizeM;
    int Answer;   

    void CreateS1();   // создание первой таблицы

    int sur(int i, int j) { return S[i].OpTab[j].surplus; }
    int optcont(int i, int j) { return S[i].OpTab[j].OptControl; }
    int maxfun(int i, int j) { return S[i].OpTab[j].MaxFunValue; }

    int MaxValueFun(int i, int j);   // вычисление максимального значения
    int ElemPos(int value, int *arr, int size);  // определение позиции элемента в массиве
    void Solution();   // запись ответа в таблицу
};
