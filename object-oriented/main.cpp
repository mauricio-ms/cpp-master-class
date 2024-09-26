#include "date.h"

#include <iostream>

using namespace std;

template <class T>
T value(T x) {
    return x;
}

int main() {
    Date pgt(1, 1, 1800);
    pgt.print();
    printf("\n");

    for (int i=1; i<=12; i++) {
        pgt.change(1, i, 1996);
        pgt.print();
    }
    printf("\n");

    for (int i=1; i<=12; i++) {
        pgt.change(1, i, 1999);
        pgt.print();
    }
    printf("\n");

    for (int i=1; i<=12; i++) {
        pgt.change(1, i, 2000);
        pgt.print();
    }
    printf("\n");

    for (int i=1; i<=12; i++) {
        pgt.change(1, i, 2024);
        pgt.print();
    }
    printf("\n");

    Date pgt2;
    pgt2.print();

    printf("%d\n", value(11));

    Date d1(1, 1, 2000), d2(1, 1, 1999);
    if (d1 > d2) {
        cout << "d1 > d2\n";
    }
    if (d1 >= d2) {
        cout << "d1 >= d2\n";
    }
    if (d1 != d2) {
        cout << "d1 != d2\n";
    }

    d2.change(1, 1, 2000);
    if (d1 == d2) {
        cout << "d1 == d2\n";
    }

    d2.change(31, 1, 2000);
    if (d1 < d2) {
        cout << "d1 < d2\n";
    }
    if (d1 <= d2) {
        cout << "d1 <= d2\n";
    }
    if (d1 != d2) {
        cout << "d1 != d2\n";
    }

    return 0;
}
