#include <iostream>

using namespace std;

/** Заполнение */
void input(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "v[" << i << "]=";
        cin >> a[i];
    }
}

