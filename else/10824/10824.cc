#include <iostream>
#include <string>


using namespace std;

int main(){
    string a,b,c,d;
    cin>>a>>b>>c>>d;

    a.append(b);
    c.append(d);
    
    
    auto P=stoull(a);
    auto Q=stoull(c);
    cout<<P+Q<<"\n";
}