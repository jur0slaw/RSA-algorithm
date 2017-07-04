#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int zakres;
    cout << "Wprowadz zakres: ";
    cin >> zakres;
    int podloga = floor(sqrt(zakres));

    //generacja tablicy liczb naturalnych

    int tab[zakres];

    for(int i = 1 ;i < zakres; i++){
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

    cout << "Liczby pierwsze od 2 do "<< zakres << "to: " << endl;

    for(int i = 2;i<zakres;i++){
        if(tab[i]!=0){
            cout << i<<",";
        }
    }

    int n,k,l;

    cout << "Podaj i,j aby uzyskac i,j-ta liczbe pierwsza z kolei(zakladajac ze i<j): ";
    cin >> n >> k;

    l=0;

    for(int i = 2;i<zakres;i++){
        if(tab[i]!=0){
            l++;
            if(l==n or l==k){
                cout << i <<",";
            }
        }
    }


    return 0;
}
