#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1;
    y = x1 - (b / a) * y1;
    return d;
}

int main() {
    vector<int> arr = {2, 4, 3};
    int res = 1;
    for (int i = 0; i < arr.size(); i++) {
        res = (res * arr[i]) % 7;
    }

    int x, y;
    gcd(res, 7, x, y);

    // make x positive in modulo 7
    x = (x % 7 + 7) % 7;

    cout << "Product mod 7: " << res << endl;
    cout << "Modular inverse of " << res << " mod 7 is: " << x << endl;
    cout << "(res * x) % 7 = " << (res * x) % 7 << endl;

    return 0;
}
