#include <bits/stdc++.h>
using namespace std;

class temp{
    temp(){}
    static int var;
    public:
    static temp* getinstance(){
        return new temp;
    }
};

int temp::var = 0;
int main()
{
    temp* obj= temp::getinstance();
    cout << obj << endl;
    temp* obj2= temp::getinstance();
    cout << obj2 << endl;
    temp* obj3= temp::getinstance();
    cout << obj3 << endl;
    return 0;
}