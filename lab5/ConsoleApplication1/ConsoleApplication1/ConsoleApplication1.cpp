#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#define size 10

using namespace std;

void input(); // Функция для ввода данных о студентах
void output(); // Функция для вывода данных о студентах
void inFile(); // Функция для записи данных в файл
void outFile(); // Функция для чтения данных из файла
void find(); // Функция для поиска студентов по среднему баллу

union buf // Объединение для хранения различных типов данных атрибутов студента
{
	char fullname[50];
	char day[50];
	char spec[50];
	int gr;
	char fac[50];
	float av;
};

struct student // Структура для представления студента
{
	buf full_name;
	buf entrday;
	buf speciality;
	buf group;
	buf facultyd;
	buf average;
};

student students[size]; // Массив студентов

int choice; // Выбор пользователя
int current_size; // Текущий размер массива студентов

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	do
	{
		cout << "1 - Ввод элементов с клавиатуры" << endl;
		cout << "2 - Вывод элементов в консольное окно" << endl;
		cout << "3 - Запись информации в файл" << endl;
		cout << "4 - Чтение информации из файла" << endl;
		cout << "5 - Поиск информации" << endl;
		cout << "6 - Выход из программы" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			inFile();
			break;
		case 4:
			outFile();
			break;
		case 5:
			find();
			break;
		}
	} while (choice != 6);
	return 0;
}

void input() // Функция для ввода данных о студентах
{
	int numb; // Количество студентов для ввода
	int choice; // Выбор пользователя
	cout << "Введите количество студентов: "; cin >> numb;
	for (int i = 0; i < numb; i++)
	{
		if (current_size < size) // Проверка на заполненность массива
		{
			cout << "Информация о " << i + 1 << " студенте: " << endl;
			cin.ignore();
			cout << endl << "ФИО: " << endl;
			gets_s(students[current_size].full_name.fullname, 50);
			cout << "Дата поступления: " << endl;
			gets_s(students[current_size].entrday.day, 50);
			cout << "Специальность: " << endl;
			gets_s(students[current_size].speciality.spec, 50);
			cout << "Группа: " << endl;
			cin >> students[current_size].group.gr;
			cin.ignore();
			cout << "Факультет: " << endl;
			gets_s(students[current_size].facultyd.fac, 50);
			cout << "Средний балл: " << endl;
			cin >> students[current_size].average.av;
			current_size++;
		}
	}
}

void output() // Функция для вывода данных о студентах
{
	for (int i = 0; i < current_size; i++)
	{
		cout << "Информация о " << i + 1 << " студенте: " << endl;
		cout << endl << "ФИО: " << students[i].full_name.fullname << endl;
		cout << "Дата поступления: " << students[i].entrday.day << endl;
		cout << "Специальность: " << students[i].speciality.spec << endl;
		cout << "Группа: " << students[i].group.gr << endl;
		cout << "Факультет: " << students[i].facultyd.fac << endl;
		cout << "Средний балл: " << students[i].average.av << endl;
	}
}

void inFile() // Функция для записи данных о студентах в файл
{
	ofstream file1("file.txt");
	if (file1)
	{
		for (int i = 0; i < current_size; i++)
		{
			file1 << "Информация о " << i + 1 << " студенте: " << endl;
			file1 << endl << "ФИО: " << students[i].full_name.fullname << endl;
			file1 << "Дата поступления: " << students[i].entrday.day << endl;
			file1 << "Специальность: " << students[i].speciality.spec << endl;
			file1 << "Группа: " << students[i].group.gr << endl;
			file1 << "Факультет: " << students[i].facultyd.fac << endl;
			file1 << "Средний балл: " << students[i].average.av << endl;
		}
		cout << "Информация записана в файл!" << endl;
		file1.close();
	}
	else
		cout << "Не удалось открыть файл!" << endl;
}

void outFile() // Функция для чтения данных о студентах из файла
{
	ifstream file1("file.txt");
	string line;
	while (getline(file1, line))
	{
		cout << line << endl;
	}
	file1.close();
}

void find() // Функция для поиска студентов по среднему баллу
{
	float aver; // Средний балл для поиска
	bool f = true;
	cout << "Введите средний балл: ";
	cin >> aver;
	for (int i = 0; i < current_size; i++)
	{
		if (aver == students[i].average.av)
		{
			cout << "Информация о " << i + 1 << " студенте: " << endl;
			cout << endl << "ФИО: " << students[i].full_name.fullname << endl;
			cout << "Дата поступления: " << students[i].entrday.day << endl;
			cout << "Специальность: " << students[i].speciality.spec << endl;
			cout << "Группа: " << students[i].group.gr << endl;
			cout << "Факультет: " << students[i].facultyd.fac << endl;
			cout << "Средний балл: " << students[i].average.av << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "Информация не найдена!" << endl;
	}
}
