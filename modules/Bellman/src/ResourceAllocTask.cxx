//Copyright 2016 GoncharovaKochetova

#include "include\ResourceAllocTask.h"

ResourceAllocTask::ResourceAllocTask()
{
    SizeM = 0;
    SizeN = 0;
    flag = false;
}

ResourceAllocTask::ResourceAllocTask(int _N, int _M)
{
    SizeN = _N;
    SizeM = _M;
    flag = false;
    Invest = new int[SizeN];
    Profit = new int*[SizeM];
    for (int i = 0; i < SizeM; i++)
        Profit[i] = new int[SizeN];
    S = new TTable [SizeM];
    for (int j = 0; j < SizeM; j++)
    {
        S[j] = TTable(SizeN);
    }
    Decision = TTable(SizeM);
}

ResourceAllocTask::~ResourceAllocTask()
{
    delete[] Invest;
    delete[]S;
    for (int i = 0; i < SizeM; i++)
    {
        delete Profit[i];
    }
    delete[] Profit;
}

void ResourceAllocTask::BellStep()
{
    CreateS1();
    for (int i = 1; i<SizeM; i++)
    {
        for (int j = SizeN - 1; j > -1; j--)
        {
            S[i].OpTab[j].surplus = Invest[j];
            S[i].OpTab[j].MaxFunValue = MaxValueFun(i, j);
            S[i].OpTab[j].OptControl = U;
        }
    }
    Solution();
}

void ResourceAllocTask::Print(int i)
{
    if (flag)
    {
        if (i < SizeM - 1)
        {
            cout << "S" << i;
            for (int j = 0; j < SizeN; j++)
            {
                cout << endl;
                cout << sur(i, j) << "-текущее состояние, ";
                cout << maxfun(i, j) << "-максимум, ";
                cout << "U*" << j << " = " << optcont(i, j);
                cout << endl;
            }
        }
        if (i == SizeM - 1)
        {
            cout << "S" << i;
            cout << endl;
            cout << "Максимальное значение функции = " << maxfun(i, SizeN - 1) << ", ";
            cout << "U*" << SizeM - 1 << " = " << optcont(i, SizeN - 1);
            cout << endl;
        }
    }
}

int ResourceAllocTask::MaxValueFun(int i, int j)
{
    int size = j + 1;
    int x_k = sur(i, j);
    int * fun = new int[size];
    int * u = new int [size];
    for (int k = 0; k < size; k++)
    {
        fun[k] = Profit[SizeM-1-i][k] + maxfun(i - 1, ElemPos(sur(i,j)-Invest[k],Invest,SizeN));
        u[k] = Invest[k];
    }
    int maxvalue = *max_element(fun, fun + size);
    U = u[ElemPos(maxvalue, fun, size)];
    return maxvalue;
}

int ResourceAllocTask::ElemPos(int value, int* arr, int size)
{
    int pos;
    for (int i = 0; i < size; i++)
    {
        if (value == arr[i])
        {
            pos = i;
            break;
        }
    }
    return pos;
}

void ResourceAllocTask::PrintInvest()
{
    if (flag)
    {
        for (int i = 0; i < SizeN; i++)
        {
            cout << Invest[i] << " ";
        }
        cout << endl;
    }
}

void ResourceAllocTask::PrintProfit()
{
    if (flag)
    {
        for (int i = 0; i < SizeM; i++)
        {
            for (int j = 0; j < SizeN; j++)
            {
                cout << Profit[i][j] << "  ";
            }
            cout << endl;
        }
    }
}

void ResourceAllocTask::PrintDecision()
{
    cout << "Начальное состояние ";
    for (int i = 0; i < SizeM; i++)
    {
        cout << "X" << i << " = " << Decision.OpTab[i].surplus<<endl;
        cout << "Выделяем " << i + 1 << "-му предприятию " << Decision.OpTab[i].OptControl;
        cout << " , получая доход " << Decision.OpTab[i].MaxFunValue;
        cout << endl;
    }
    cout << endl;
    cout << "Максимальный доход после инвестирования всех предприятий равен " << Answer << endl;
}

void ResourceAllocTask::CreateS1()
{
    for (int i = 0; i < SizeN; i++){
        S[0].OpTab[i].surplus = Invest[i];
        S[0].OpTab[i].MaxFunValue = Profit[SizeM-1][i];
        S[0].OpTab[i].OptControl = Invest[i];
    }
}

void ResourceAllocTask::main()
{
    setlocale(LC_ALL, "rus");
    flag = true;
    cout << "Варианты инвестиций: ";
    PrintInvest();
    cout << endl;
    cout << "Таблица дохода от предприятий" << endl;
    PrintProfit();
    cout << endl;
    BellStep();
    for (int i = 0; i < SizeM; i++)
    {
        cout << endl;
        Print(i);
    }
    cout << endl;
    Solution();
    PrintDecision();
    SaveInFile("Decision.doc");
}

void ResourceAllocTask::Solution()
{
    Decision.OpTab[0].surplus = Invest[SizeN - 1];
    Decision.OpTab[0].OptControl = optcont(SizeM - 1, SizeN - 1);
    int u = ElemPos(Decision.OpTab[0].OptControl, Invest, SizeN);
    Decision.OpTab[0].MaxFunValue = Profit[0][u];

    for (int i = 1; i < SizeM; i++)
    {
        Decision.OpTab[i].surplus = Decision.OpTab[i - 1].surplus - Decision.OpTab[i - 1].OptControl;
        int k = ElemPos(Decision.OpTab[i].surplus, Invest, SizeN);
        Decision.OpTab[i].OptControl = optcont(SizeM - 1 - i, k);
        int j = ElemPos(Decision.OpTab[i].OptControl, Invest, SizeN);
        Decision.OpTab[i].MaxFunValue = Profit[i][j];
    }
    Answer = maxfun(SizeM - 1, SizeN - 1);
}

void ResourceAllocTask::SaveInFile(string name)
{
    setlocale(LC_ALL, "rus");
    ofstream answerfile;
    answerfile.open(name);
    answerfile << "Варианты инвестиций: ";
    for (int i = 0; i < SizeN; i++)
    {
        answerfile << Invest[i] << " ";
    }
    answerfile << endl;

    answerfile << "Таблица доходов от предприятий: " << endl;
    for (int i = 0; i < SizeM; i++)
    {
        for (int j = 0; j < SizeN; j++)
        {
            answerfile << Profit[i][j] << "  ";
        }
        answerfile << endl;
    }

    for (int i = 0; i < SizeM; i++)
    {
        answerfile << endl;
        answerfile << "S" << i << endl;
        answerfile << "состояние | максимум | U* " << endl;
        for (int j = 0; j < SizeN; j++)
        {
            answerfile << sur(i, j) << "          ";
            answerfile << maxfun(i, j) << "        ";
            answerfile << optcont(i, j) << "  ";
            answerfile << endl;
        }
    }

    answerfile << endl;
    answerfile << "Ответ: " << endl;
    answerfile << "Начальное состояние ";
    for (int i = 0; i < SizeM; i++)
    {
        answerfile << "X" << i << " = " << Decision.OpTab[i].surplus << endl;
        answerfile << "Выделяем " << i + 1 << "-му предприятию " << Decision.OpTab[i].OptControl;
        answerfile << " , получая доход " << Decision.OpTab[i].MaxFunValue;
        answerfile << endl;
    }
    answerfile << endl;
    answerfile << "Максимальный доход после инвестирования всех предприятий равен " << Answer << endl;
    answerfile.close();
}
