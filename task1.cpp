#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    int a[10000];
    bool has_prime = false;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (is_prime(a[i])) {
            has_prime = true;
        }
    }

    if (!has_prime) {
        sort(a, a + n); // Здесь сортируем массив
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
