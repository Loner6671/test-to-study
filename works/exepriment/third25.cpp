#include<stdio.h>
using namespace std;
int main()
{
    int a=0,b=0,c=0,d=0;
    char line1[100],line2[50];
    gets(line1);
    gets(line2);
    while (line1[a] != '\0' && line1[a] != '\n') 
    {
        a++;
    }
    while (line2[b] != '\0' && line2[b] != '\n')
    {
        line1[a] = line2[b];
        a++;
        b++;
    }
    line1[a] = '\0';
    puts(line1);
    return 0;
}