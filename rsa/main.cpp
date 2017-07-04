#include <iostream>
#include <cmath>

using namespace std;

bool NWD(int a,int b,int &m){

    int a0,b0;
    a0=a;
    b0=b;
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

    m=x;
    if(a0*x+b0*y==1){
        return true;
    }else{
       return false;
    }
}



int main()
{
   int zakres = 20000;
   int foo,bar;
    cout << "Wprowadz kolejno i,j (i<j) aby znalesc i,jte liczby pierwsze : ";
    cin >> foo >> bar;

    int podloga = floor(sqrt(zakres));

    //generacja tablicy liczb naturalnych

    int tab[zakres];

    for(int i = 1; i < zakres; i++){
        tab[i]=1;
    }
    int j;

    for(int i = 2; i<podloga;i++){
        if(tab[i]!=0){
            j=i+i;
            while(j<=zakres){
                tab[j]=0;
                j+=i;
            }
        }
    }

    int pierwsza1,pierwsza2;
    int l=0;

    for(int i = 2;i<zakres;i++){
        if(tab[i]!=0){
            l++;
            if(l==foo){
                pierwsza1=i;
            }
            if(l==bar){
                pierwsza2=i;
            }
        }
    }

    cout << "Liczba pierwsza p to : " << pierwsza1 << "  Liczba pierwsza q to : " << pierwsza2 << endl;

    int n,m;

    n=pierwsza1*pierwsza2;
    m=(pierwsza1-1)*(pierwsza2-1);

    cout << "n = " << n << endl << "m = " << m << endl;


    int e;

    cout << "Wprowadz liczbe e: ";
    cin >> e;
    cout << endl;

    int x;

    while(!NWD(e,m,x)){
        cout << "Podano e nie spelniajace zalozenia, wprowadz e ponownie: " << endl;
        cin >> e;
    }

    while(x<0){
        x+=m;
    }

    cout << "Kluczem publicznym jest para: (" << n <<","<<e <<")." << endl << "Kluczem prywatnym jest para: (" << n <<","<< x <<")." << endl;



    return 0;
}
