//Copyright 2016 GoncharovaKochetova

#include "include\TTable.h"

TTable::TTable()
{
    size = 0;
}

TTable::TTable(int _N)
{
    size = _N;
    OpTab = new Trio[size];      // создание таблицы-массива структур
    for (int i = 0; i < size; i++)   //  обнуление элементов структуры 
    {
        OpTab[i].surplus = 0;
        OpTab[i].OptControl = 0;
        OpTab[i].MaxFunValue = 0;
    }
}
