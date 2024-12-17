#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[1000]; 
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Помечаем дубликаты
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) {
                arr[j] = -1; // Помечаем дубликат как -1
            }
        }
    }


    //Выводим уникальные элементы (без -1)
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}


