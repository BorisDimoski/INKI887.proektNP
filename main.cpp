#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
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
    cout<<endl;
    for(i=0;i<str.size();i++)
    {
        str[i]+=n;
        v.push_back(str[i]);
    }
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Stringot so smeneti ASCII karakteri:"<<endl;
    cout<<str;
    sort(v.begin(),v.end());
    cout<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Sortiran vektor:"<<endl;
    cout<<endl;
    dat.open("INKI887.proekt3.txt", ios::out | std::ofstream::trunc);
    for(i=0;i<v.size();i++)
    {
        cout<<(char)v[i];
        dat<<(char)v[i];
    }
    dat.close();
    return 0;
}
