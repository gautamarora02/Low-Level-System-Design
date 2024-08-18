#include <bits/stdc++.h>
using namespace std;



int main(){
    string ostype;
    cin >> ostype;
    // I stands for interface: meaning that we are creating abstract classes for factory
    Ifactory* fact = GUIAbstractFactory::CreateFactory(ostype);
    IButton* button = fact->CreateButton();
    button-> press();

    ITextBox* textbox = fact-> CreateTextBox();
    textbox->showText();

    return 0;
}