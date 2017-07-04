#include <iostream>
#include <cmath>
using namespace std;



int main()
{
    int a,b;

    cout << "Wprowadz liczby a,b do obliczenia NWD(a,b): ";
    cin >> a >> b;

    int b0,a0;

    a0 = a;
    b0 = b;

    int x = 1; int y = 0;
    int r = 0; int s = 1;
    int c,q;

    int r1,s1;


    while (b!=0){
         c = a%b;
         q = floor(a/b);
         a=b;
         b=c;
         r1=r;
         s1=s;
         r=x-q*r;
         s=y-q*s;
         x=r1;
         y=s1;
    }

    cout  << endl << "NWD(" << a0 << "," << b0 << ") = (" << x <<")*" << a0 << "+(" << y << ")*" << b0;

    return 0;
}
