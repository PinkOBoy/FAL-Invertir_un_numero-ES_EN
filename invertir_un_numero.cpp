/*
* Solucion aportada por el profesor de la FdI (UCM):
* Solution given by FdI's (UCM) professor:
*   ANTONIO ALEJANDRO SANCHEZ RUIZ-GRANADOS
*/
#include <iostream>
#include <vector>

using namespace std;

// Tail recursive version
// ac = last numbers in reverse order (input parameter)
int invert(int n, int ac) {
    int r = 0;
    if (n == 0)
        r = ac;
    else
        r = invert(n / 10, ac * 10 + n % 10);
    return r;
}

// T(n) = c0 if n == 0
// T(n) = T(n/10) + c if n > 2
// a = 1, b = 10, k = 0 -> O(log n)

// Non tail recursive version
// p = 10^{number of digits of n} (output parameter)
int invert2(int n, int& p) {
    int r;
    if (n == 0) {
        r = 0;
        p = 1;
    }
    else {
        r = invert2(n / 10, p) + (n % 10) * p;
        p *= 10;
    }
    return r;
}

bool solve() {
    int n;
    cin >> n;
    if (n == -1)
        return false;
    cout << invert(n, 0) << endl;
    //int p;
    //cout << invert2(n, p) << endl;
    return true;
}

int main() {
    while (solve());
}