#include <iostream>
using namespace std;

const int n = 5; // ���������� �����
int numbers[n] = { 1, 2, 3, 4, 5 }; // ������ �����
int permutation[n]; // ������ ��� �������� ������� ������������
bool used[n]; // ������ ��� ������������ �������������� �����

void generatePermutations(int index) {
    if (index == n) {
        for (int i = 0; i < n; ++i) {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                used[i] = true;
                permutation[index] = numbers[i];
                generatePermutations(index + 1);
                used[i] = false;
            }
        }
    }
}

int main() {
    generatePermutations(0);
}