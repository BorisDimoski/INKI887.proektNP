#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
//Proekt napredno programiranje Boris Dimoski INKI887
//Zadaca 50:Promena na ASCII karakteri na daden string so najgolemata brojka vo indeksot, smestuvanje vo vektor, sortiranje i smestuvanje na sodrzina vo izlezna datoteka
//funkcija za najgolema cifra
int najg(int a)
{
    int x=-999;
    while(a!=0)
    {
        if(a%10>x) x=a%10;
        a/=10;
    }
    return x;
}
int main()
{
//deklaracija na promenlivi
    string str="INKI887Boris Huey Lewis and the News I know that it's crazy I know that it's nowhere But there is no denying that it's hip to be square";
    int br,n,i;
    vector<int> v;
    vector<int>::iterator it;
    fstream dat;
    cout<<"Vnesi trocifren broj (indeks)"<<endl;
    while(br<100 || br>999)
    {
        cin>>br;
    }
    n=najg(br);
    cout<<"Najgolema cifra: "<<n<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<str;
    for(i=0;i<str.size();i++)       //promena na ASCII vrednost i vnesuvanje vo vektorot
    {
        str[i]=(int)str[i]+n;
        v.push_back(str[i]);
    }
    cout<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Stringot so smeneti ASCII karakteri:"<<endl;
    cout<<str;
    sort(v.begin(),v.end());
    cout<<endl;  //algoritam za sortiranje na vektorot
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Sortiran vektor:"<<endl;

    dat.open("INKI887.proekt3.txt", ios::out | std::ofstream::trunc); //otvaranje na datoteka INKI887.proekt3.txt, brisenje na prethodna sodrzina
    for(i=0;i<v.size();i++)                                           //i vnesuvanje na nova
    {
        cout<<(char)v[i];
        dat<<(char)v[i];
    }
    cout<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    dat.close();
    return 0;
}
