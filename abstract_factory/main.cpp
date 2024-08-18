#include <bits/stdc++.h>
using namespace std;

// the sequence of the class defination matters
// we cannot define Ifactory before ibutton and itextbox

class IButton{
    public:
        virtual void press() = 0;
};

class ITextbox{
    public:
        virtual void showText() = 0;
};


class MacButton : public IButton{
    public:
        void press(){
            cout << "Mac Button is pressed" << endl;
        }
};

class MacTextBox : public ITextbox{
    public:
        void showText(){
            cout << "Mac Textbox is showed" << endl;
        }
};

class WinButton : public IButton{
    public:
        void press(){
            cout << "Win Button is pressed" << endl;
        }
};

class WinTextBox : public ITextbox{
    public:
        void showText(){
            cout << "Win Textbox is showed" << endl;
        }
};


class Ifactory{
    public:
        virtual IButton* CreateButton() = 0;
        virtual ITextbox* CreateTextBox() = 0;
};

class WinFactory : public Ifactory{
    public:
        IButton* CreateButton(){
            return new WinButton;
        }
        ITextbox* CreateTextBox(){
            return new WinTextBox;
        }
};

class MacFactory : public Ifactory{
    public:
        IButton* CreateButton(){
            return new MacButton;
        }
        ITextbox* CreateTextBox(){
            return new MacTextBox;
        }
};


class GUIAbstractFactory{
    public:
        static  Ifactory* CreateFactory(string ostype){
            if(ostype == "windows"){
                return new WinFactory;
            }
            else if(ostype == "mac"){
                return new MacFactory;
            }
            return new MacFactory;
        }
};

int main(){
    string ostype;
    cout << "Enter the os type" << endl;
    cin >> ostype;
    // I stands for interface: meaning that we are creating abstract classes for factory
    Ifactory* fact = GUIAbstractFactory::CreateFactory(ostype);
    IButton* button = fact->CreateButton();
    button-> press();

    ITextbox* textbox = fact-> CreateTextBox();
    textbox->showText();

    return 0;
}