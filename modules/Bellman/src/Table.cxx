//Copyright 2016 GoncharovaKochetova

#include "include\TTable.h"

TTable::TTable()
{
    size = 0;
}

TTable::TTable(int _N)
{
    size = _N;
    OpTab = new Trio[size];      // �������� �������-������� ��������
    for (int i = 0; i < size; i++)   //  ��������� ��������� ��������� 
    {
        OpTab[i].surplus = 0;
        OpTab[i].OptControl = 0;
        OpTab[i].MaxFunValue = 0;
    }
}
