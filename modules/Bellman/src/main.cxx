/*#include "ResourceAllocTask.h"
#include <cstdlib>

int main()
{
    int sizeN, sizeM;
    setlocale(LC_ALL, "rus");

    cout << "Доброго времени суток!" << endl;
    cout << "Введите количество предприятий" << endl;
    cin >> sizeM;
    cout << "Введите количество инвестиций" << endl;
    cin >> sizeN;
    ResourceAllocTask task(sizeN,sizeM);

    cout << "Введите варианты инестиций" << endl;
    for (int i = 0; i < sizeN; i++)
    {
        cin >> task.Invest[i];
    }

    cout << "Введите доходы по каждому предприятию" << endl;
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