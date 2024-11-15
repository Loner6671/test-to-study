#include <iostream>
using namespace std;
int factorial(int n) 
{
    if (n == 0) return 1;
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}
int combination(int n, int k) 
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main()  
{
    int n = 5;
    int k = 3;
    int result = combination(n, k);
    cout<<result<<endl;
    system("pause");
    return 0;
}