#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

// ��������� ��� �������� ������
struct Address
{
    int age;
    char name[NAME_SIZE];
    char city[CITY_SIZE];
    Address* next;
    Address* prev;
};

// ������� ��� �������� ������ �������� ������
Address* setElement();

// ������� ��� ������� �������� � ����� ������
void insert(Address* e, Address** phead, Address** plast);

// ������� ��� ������ ������ �� �����
void outputList(Address** phead, Address** plast);

// ������� ��� �������� �������� �� �����
void delet(char name[NAME_SIZE], Address** phead, Address** plast);

// ������� ��� ������ �������� �� �����
void find(char name[NAME_SIZE], Address** phead);

// ������� ��� �������� ������� �������������� �������� � �������� ���������
void countX(Address** phead, Address** plast, int x);

int main()
{
    // ��������� ��������� ��� ����������� ����� � ������ �� ��������� � ������� Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "rus");

    Address* head = NULL;
    Address* last = NULL;
    char choice;

    // ����� ���� ������������
    cout << "1 - ���������� ����������" << endl
        << "2 - �������� ����������" << endl
        << "3 - ����� ���� ���������" << endl
        << "4 - �����" << endl
        << "5 - ������� ��������� � �������� ���������" << endl
        << "6 - �����" << endl;

    do
    {
        cout << "?: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case '1':
            // ���������� ������ �������� � ����� ������
            insert(setElement(), &head, &last);
            break;
        case '2':
            // �������� �������� �� �����
            char dname[NAME_SIZE];
            cout << "������� ���: ";
            cin.getline(dname, NAME_SIZE - 1, '\n');
            cin.ignore(cin.rdbuf()->in_avail());
            cin.sync();
            delet(dname, &head, &last);
            break;
        case '3':
            // ����� ���� ��������� ������
            outputList(&head, &last);
            break;
        case '4':
            // ����� �������� �� �����
            char fname[NAME_SIZE];
            cout << "������� ���: ";
            cin.getline(fname, NAME_SIZE - 1, '\n');
            cin.ignore(cin.rdbuf()->in_avail());
            cin.sync();
            find(fname, &head);
            break;
        case '5':
            // �������� ������� �������������� �������� � �������� ���������
            int x;
            cout << "������� �������: ";
            cin >> x;
            countX(&head, &last, x);
            break;
        case '6':
            cout << "�����..." << endl;
            break;
        default:
            cout << "������������ �����" << endl;
            break;
        }
    } while (choice != '6');
}

// ������� ��� ������� �������� � ����� ������
void insert(Address* e, Address** phead, Address** plast)
{
    Address* p = *plast;
    if (*plast == NULL)
    {
        // ���� ������ ����, ����� ������� ���������� ������� � ������ ������
        e->next = NULL;
        e->prev = NULL;
        *plast = e;
        *phead = e;
    }
    else
    {
        // ����� ��������� ����� ������� � ����� ������
        p->next = e;
        e->next = NULL;
        e->prev = p;
        *plast = e;
    }
}

// ������� ��� �������� ������ �������� ������
Address* setElement()
{
    Address* temp = new Address();
    if (!temp)
    {
        cerr << "������ ��������� ������";
        return NULL;
    }
    // ���� ������ ��� ������ ��������
    cout << "������� ���: ";
    cin.getline(temp->name, NAME_SIZE - 1, '\n');
    cin.ignore(cin.rdbuf()->in_avail());
    cin.clear();
    cout << "������� �����: ";
    cin.getline(temp->city, CITY_SIZE - 1, '\n');
    cin.ignore(cin.rdbuf()->in_avail());
    cin.clear();
    cout << "������� �������: ";
    cin >> temp->age;
    cin.ignore(cin.rdbuf()->in_avail());
    cin.clear();
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// ������� ��� ������ ������ �� �����
void outputList(Address** phead, Address** plast)
{
    Address* t = *phead;
    while (t)
    {
        // ����� ���������� �� �������� ������
        cout << "���: " << t->name << endl
            << "�����: " << t->city << endl
            << "�������: " << t->age << endl << endl;
        t = t->next;
    }
    cout << endl;
}

// ������� ��� �������� �������� �� �����
void delet(char name[NAME_SIZE], Address** phead, Address** plast)
{
    Address* t = *phead;
    while (t)
    {
        if (!strcmp(name, t->name))
            break;
        t = t->next;
    }
    if (!t)
    {
        cerr << "��� �� �������" << endl;
    }
    else
    {
        if (*phead == t)
        {
            // ���� ��������� ������� - ������ ������
            *phead = t->next;
            if (*phead)
                (*phead)->prev = NULL;
            else
                *plast = NULL;
        }
        else
        {
            // ����� ������� ������� �� �������� ��� ����� ������
            t->prev->next = t->next;
            if (t != *plast)
                t->next->prev = t->prev;
            else
                *plast = t->prev;
        }
        delete t;
        cout << "������� ������" << endl << endl;
    }
}

// ������� ��� ������ �������� �� �����
void find(char name[NAME_SIZE], Address** phead)
{


    Address* t = *phead;
    while (t)
    {
        if (!strcmp(name, t->name))
            break;
        t = t->next;
    }
    if (!t)
    {
        cerr << "��� �� �������" << endl;
    }
    else
    {
        // ����� ���������� ��������
        cout << "���: " << t->name << endl
            << "�����: " << t->city << endl
            << "�������: " << t->age << endl << endl;
    }
}

// ������� ��� �������� ���� ��������� � �������� ��������� x
void countX(Address** phead, Address** plast, int x)
{
    int count = 0;
    Address* t = *phead;
    while (t)
    {
        if (t->age == x)
            count++;
        t = t->next;
    }
    if (count == 0)
    {
        cout << "����� � ����� ��������� �� �������" << endl << endl;
    }
    else
    {
        cout << "���������� �����: " << count << endl << endl;
    }
}