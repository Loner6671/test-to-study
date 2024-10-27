#include <iostream>
using namespace std;
void sushu(int num)
{
    for (int i = 2; i <= num; i++) {
        while (num % i == 0) 
        {
            cout << i << "*";
            num /= i;
        }
    }
}
int main() {
    int number;
    cout << "Please tap in a number:";
    cin >> number;
    cout << "Result is:";
    sushu(number);
    system("pause");
    return 0;
}
