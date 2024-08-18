#include <iostream>
using namespace std;

class Base {
public:
    virtual void myFunction() = 0; // Pure virtual function
};

class chekc : public Base{
    public:
    
};

int main(){
    chekc *temp = new chekc();
    return 0;
}