#include <iostream>
#include <fstream>
#include "myFunc.h"

using namespace std;

void push(char x, Stack*& myStk) //Добавление элемента х в стек
{
	Stack* e = new Stack; //выделение памяти для нового элемента
	e->data = x; //запись элемента x в поле data
	e->next = myStk; //перенос вершины на следующий элемент 
	e->before = nullptr; //перенос вершины на предыдущий элемент 
	myStk = e; //сдвиг вершины на позицию вперед

}

char pop(Stack*& myStk) //Извлечение (удаление) элемента из стека
{
	if (myStk == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1; //если стек пуст - возврат (-1) 
	}
	else
	{
		Stack* e = myStk; //е-переменная для хранения адреса элемента
		char x = myStk->data; //запись элемента из поля data в перем. x 
		if (myStk)
			myStk = myStk->next; //перенос вершины
		delete e;
		return x;
	}
}

void toFile(Stack*& myStk) //Запись в файл
{
	Stack* e = myStk;
	Stack buf;
	ofstream frm("mStack.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (e)
	{
		buf = *e;
		frm.write((char*)&buf, sizeof(Stack));
		e = e->next;
	}
	frm.close();
	cout << "Стек записан в файл mStack.dat\n";
}

void fromFile(Stack*& myStk) //Считывание из файла
{
	Stack buf, * p = nullptr, * e = nullptr;
	ifstream frm("mStack.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.seekg(0);
	frm.read((char*)&buf, sizeof(Stack));
	while (!frm.eof())
	{
		push(buf.data, e);
		frm.read((char*)&buf, sizeof(Stack));
	}
	frm.close();
	while (e != NULL)
	{
		buf.data = pop(e);
		push(buf.data, p);
		myStk = p;
	}
	cout << "\nСтек считан из файла mStack.dat\n\n";
}

void show(Stack*& myStk) //Вывод стека с очисткой
{
	Stack* e = myStk;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		cout << e->data << " ";
		e = e->next;
	}
	cout << endl;
}

void clear(Stack*& myStk)
{
	while (myStk != nullptr)
	{
		Stack* temp = myStk;
		myStk = myStk->next;
		delete temp;
	}
	cout << "\nСтек пуст.\n";
}

void counterEqualLeftAndRight(Stack*& myStk)
{
	int counter = 0; // Счетчик для подсчета соответствующих пар

	// Проверяем, что текущий элемент и его следующие два элемента не являются нулевыми
	while (myStk != nullptr && myStk->next != nullptr && myStk->next->next != nullptr)
	{
		if (myStk->data == myStk->next->next->data)
		{
			counter++; // Увеличиваем счетчик, если значения текущего элемента и элемента через один равны
		}

		myStk = myStk->next; // Переходим к следующему элементу стека
	}

	cout << counter << endl; // Выводим значение счетчика
}
