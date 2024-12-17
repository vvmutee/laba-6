#include <iostream>
#include <algorithm>

using namespace std;

int sum_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int product_digits(int n) {
    int product = 1;
    if (n == 0) return 0;
    while (n > 0) {
        product *= (n % 10);
        n /= 10;
    }
    return product;
}

int main() {
    int n;
    cin >> n;

    int numbers[1000];
    int sums[1000];
    int products[1000];

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        sums[i] = sum_digits(numbers[i]);
        products[i] = product_digits(numbers[i]);
    }

    // Здесь я воспользовался сортировкой пузырьком по трём критериям
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (sums[j] > sums[j + 1] ||
                (sums[j] == sums[j + 1] && products[j] > products[j + 1]) ||
                (sums[j] == sums[j + 1] && products[j] == products[j + 1] && numbers[j] > numbers[j + 1])) {
                swap(numbers[j], numbers[j + 1]);
                swap(sums[j], sums[j + 1]);
                swap(products[j], products[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << numbers[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}

