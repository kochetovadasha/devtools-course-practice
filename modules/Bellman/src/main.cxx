/*#include "ResourceAllocTask.h"
#include <cstdlib>

int main()
{
    int sizeN, sizeM;
    setlocale(LC_ALL, "rus");

    cout << "������� ������� �����!" << endl;
    cout << "������� ���������� �����������" << endl;
    cin >> sizeM;
    cout << "������� ���������� ����������" << endl;
    cin >> sizeN;
    ResourceAllocTask task(sizeN,sizeM);

    cout << "������� �������� ���������" << endl;
    for (int i = 0; i < sizeN; i++)
    {
        cin >> task.Invest[i];
    }

    cout << "������� ������ �� ������� �����������" << endl;
    for (int j = 0; j < sizeM; j++)
    {
        for (int k = 0; k < sizeN; k++)
        {
            cin >> task.Profit[j][k];
        }
    }

    task.main();
    system("pause");
    return 0;
}*/