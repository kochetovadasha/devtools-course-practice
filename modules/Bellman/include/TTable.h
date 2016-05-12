//Copyright 2016 GoncharovaKochetova

#pragma once

struct Trio {
    int surplus; //текущее состояние 
    int OptControl; // оптимальное управление
    int MaxFunValue;  //Максимальное значение функции для данного состояния
};

class TTable
{
private:
    int size;
    int GetSize() { return size; }

public:   
    TTable();
    TTable(int _N);
    Trio* OpTab;
};
