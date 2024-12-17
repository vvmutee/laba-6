#include <iostream>
#include <cmath>

using namespace std;

// Проверка на простоту числа
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Проверка на куб целого числа
bool isPerfectCube(int n) {
    if (n < 0) return false; // Кубы неотрицательны
    int root = round(cbrt(n)); // round для округления
    return root * root * root == n;
}


int main() {
    int n;
    cin >> n;

    int arr[10000];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Помечаем простые числа и кубы
    for (int i = 0; i < n; ++i) {
        if (isPrime(arr[i])) {
            arr[i] = -1; // Пометка -1 для удаления
        } else if (isPerfectCube(arr[i])) {
            arr[i] = arr[i] * 2; //Пометка для удвоения
        }
    }

    //Выводим результат, учитывая пометки выше
    for (int i = 0; i < n; ++i){
        if (arr[i] != -1) {
             cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}



