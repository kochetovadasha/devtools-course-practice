//Copyright 2016 GoncharovaKochetova

#pragma once

struct Trio {
    int surplus; //������� ��������� 
    int OptControl; // ����������� ����������
    int MaxFunValue;  //������������ �������� ������� ��� ������� ���������
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
