#include <iostream>

int C(int n, int r);

int main()
{
    using namespace std;

    int n = 5, r = 3;

    cout << "C(" << n << ", " << r << ") = " << C(n, r) << endl << endl;

    n = 9;
    r = 4;

    cout << "C(" << n << ", " << r << ") = " << C(n, r) << endl << endl;
    
    return 0;
}

int C(int n, int r)
{
    if (n == r || r == 0) return 1;
    else return C(n - 1, r - 1) + C(n - 1, r);
}
