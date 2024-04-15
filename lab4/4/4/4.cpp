#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_SANAT_COUNT = 5;

void input();
void searchBySanatoriumName(string name);

string prof[5] = { "Болезнь нервной системы", "Болезнь органов пищеварения", "Кожные заболевания", "Заболевания органов дыхания нетуберкулезного характера", "Болезнь опорно-двигательного аппарата" };

struct Sanat
{
    char name[20];
    char place[20];
    int prof;
    int count;
};

Sanat sanat_list[MAX_SANAT_COUNT];

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    input();

    // Сортировка пузырьком по профилю и названию
    for (int i = 0; i < MAX_SANAT_COUNT - 1; i++)
    {
        for (int j = 0; j < MAX_SANAT_COUNT - i - 1; j++)
        {
            if (sanat_list[j].prof > sanat_list[j + 1].prof || (sanat_list[j].prof == sanat_list[j + 1].prof && strcmp(sanat_list[j].name, sanat_list[j + 1].name) > 0)) {
                swap(sanat_list[j], sanat_list[j + 1]);
            }
        }
    }

    // Вывод в виде таблицы, сгруппированной по профилю
    cout << left << setw(20) << "Название санатория" << setw(20) << "Место расположения" << setw(40) << "Лечебный профиль" << "Количество путевок\n";
    for (int i = 0; i < MAX_SANAT_COUNT; i++)
    {
        cout << left << setw(20) << sanat_list[i].name << setw(20) << sanat_list[i].place << setw(40) << prof[sanat_list[i].prof - 1] << sanat_list[i].count << "\n";
    }

    // Поиск по названию санатория
    string searchName;
    cout << "Введите название санатория для поиска: ";
    cin >> searchName;
    searchBySanatoriumName(searchName);

    return 0;
}

void input()
{
    Sanat newSanat;
    cout << "Памятка по профилям санаториев: " <<
        endl << "1 - Болезнь нервной системы" <<
        endl << "2 - Болезнь органов пищеварения" <<
        endl << "3 - Кожные заболевания" <<
        endl << "4 - Заболевания органов дыхания нетуберкулезного характера" <<
        endl << "5 - Болезнь опорно-двигательного аппарата" << endl;
    for (int i = 0; i < MAX_SANAT_COUNT; i++)
    {
        cout << "Введите название санатория " << i + 1 << ":";
        cin >> newSanat.name;
        cout << "Введите место расположения санатория " << i + 1 << ":";
        cin >> newSanat.place;
        cout << "Введите номер лечебного профиля санатория " << i + 1 << ":";
        cin >> newSanat.prof;
        cout << "Введите количество путевок санатория " << i + 1 << ":";
        cin >> newSanat.count;
        sanat_list[i] = newSanat;
    }

    cout << "Данные успешно записаны!" << endl << endl;
}

void searchBySanatoriumName(string name)
{
    bool found = false;
    for (int i = 0; i < MAX_SANAT_COUNT; i++)
    {
        if (strcmp(sanat_list[i].name, name.c_str()) == 0)
        {
            cout << "Найден санаторий: " << sanat_list[i].name << "\n";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Санаторий с таким названием не найден.\n";
    }
}
