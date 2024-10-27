#include<iostream>
#include<cmath>
int main(void)
{
    using namespace std;
    double x, n, term, ans = 0.0;
    cout << "TAP IN NUMBER:\n";
    cout << "x = ";
    cin >> x;
    cout << "n = "; 
    cin >> n;
    int sign = 1; 
    for (int i = 0; i < n; i++)
    {
    int exp = 2 * i + 1; 
    double mi = 1.0;
        for (int j = 1; j <= exp; j++) 
        {
            mi *= j;
        }
    term = pow(x, exp)/mi;
    ans += sign * term;
    sign*= -1;
    }
    cout<<"ans="<<ans<<endl;   
    system("pause");
}

