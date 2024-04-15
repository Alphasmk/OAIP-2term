#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Определение структуры для связанного списка
struct Item {
    char data;
    Item* next;
};

// Инициализация указателей head и tail
Item* head = nullptr;
Item* tail = nullptr;

// Проверка, пустой ли список
bool isNull() {
    return (head == nullptr);
}

// Вставка элемента в очередь
void insertToQueue(char x) {
    Item* p = new Item;
    p->data = x;
    p->next = nullptr;

    if (isNull()) {
        head = tail = p;
    }
    else {
        tail->next = p;
        tail = p;
    }
}

// Обработка строки ввода и вставка цифр в очередь
void processLine(string& line) {
    for (char ch : line) {
        if (isdigit(ch)) {
            insertToQueue(ch);
        }
    }
}

// Печать содержимого очереди в выходной файл
void printQueue(ofstream& out) {
    if (!isNull()) {
        Item* p = head;
        while (p != nullptr) {
            out << p->data;
            p = p->next;
        }
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    // Открытие входного и выходного файлов
    ifstream inFile("f.txt");
    ofstream outFile("g.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        processLine(line);

        outFile << line;
        printQueue(outFile);
        outFile << endl;
    }

    // Закрытие файлов
    inFile.close();
    outFile.close();

    cout << "Данные успешно записаны." << endl;

    return 0;
}
