#pragma once

struct Stack
{
	char data; //информационный элемент
	Stack* next; //указатель на следующий элемент
	Stack* before; //указатель на предыдущий элемент
};

void show(Stack*& myStk);
char pop(Stack*& myStk);
void push(char x, Stack*& myStk);
void toFile(Stack*& myStk);
void fromFile(Stack*& myStk);
void clear(Stack*& myStk);
void counterEqualLeftAndRight(Stack*& myStk);
