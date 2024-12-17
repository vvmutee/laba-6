#include <iostream>
#include <limits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long matrix[100][100];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int max_row_index = 0;
    long long max_product = numeric_limits<long long>::lowest(); //Инициализация минимальным значением long long

    for (int i = 0; i < n; ++i) {
        long long current_product = 1;
        for (int j = 0; j < m; ++j) {
            current_product *= matrix[i][j];
        }
        if (current_product > max_product) {
            max_product = current_product;
            max_row_index = i;
        }
    }

    for (int j = 0; j < m; ++j) {
        matrix[max_row_index][j] = max_product;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << (j == m - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}

