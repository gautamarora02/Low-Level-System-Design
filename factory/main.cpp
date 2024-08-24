#include <bits/stdc++.h>
using namespace std;

class IGameObject{
    public:
    virtual ~IGameObject(){}
    virtual void Update() = 0;
    virtual void Render() = 0;
};

class Plane : public IGameObject{
    public: 
    Plane(){
        cout << "Plane Game Started!" << endl;
    }
    void Update(){}
    void Render(){}
};

class Boat : public IGameObject{
    public: 
    Boat(){
        cout << "Boat Game Started!" << endl;
    }
    void Update(){}
    void Render(){}
};

class FactoryGameObjects{
    public: 
    static IGameObject* CreateObject(string type){
        if(type == "plane"){
            return new Plane;
        }
        else if(type == "boat"){
            return new Boat;
        }
        return new Boat;
    }
    private:
    static int s_plane;
    static int s_boat;
    FactoryGameObjects(){}
    ~FactoryGameObjects(){}
    FactoryGameObjects(const FactoryGameObjects &o){}
};

int FactoryGameObjects::s_boat = 0;
int FactoryGameObjects::s_plane = 0;
int main()
{
    // Through factory design pattern we want to remove the below statments
    // Boat b;
    // Plane p;
    // we want one factory to decide what type of object it will be and create that for us
    // so make one func makegamefactory
    string objname;
    cout << "Enter the game you wanna start: ";
    cin >> objname;
    
    IGameObject* objplane = FactoryGameObjects::CreateObject(objname);

    // now we want to add an ability to count the number of each object 
    // like we can create only 10  planes in a game or 15 boats in a game

    // IGameObject* objboat = makeGameFactory("boat");
    return 0;
}