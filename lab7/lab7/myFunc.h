#pragma once

struct Stack
{
	char data; //�������������� �������
	Stack* next; //��������� �� ��������� �������
	Stack* before; //��������� �� ���������� �������
};

void show(Stack*& myStk);
char pop(Stack*& myStk);
void push(char x, Stack*& myStk);
void toFile(Stack*& myStk);
void fromFile(Stack*& myStk);
void clear(Stack*& myStk);
void counterEqualLeftAndRight(Stack*& myStk);
