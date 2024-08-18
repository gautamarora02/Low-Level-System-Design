#include <bits/stdc++.h>
using namespace std;

// we want to make notify function mandatory to all the users, 
// so that whenever the sender sends msg, all the observers get notified
// for that we can make a abstract class by making pure virtual function

class Isubsciber{
    public:
        virtual void notify(string msg) = 0;
};

class User : public Isubsciber{
    int userID;
    public:
        User(int userID){
            this->userID = userID; 
        }
        void notify(string msg){
            cout << "User " << userID  << " got the msg: " <<  msg << endl;
        }
};

class Group{
    list <User*> users;
    public:
        void subscribe(User * user){
            users.push_back(user);
        }
        void unsubscribe(User* user){
            users.remove(user);
        }
        void notify(string msg){
            for(auto user: users){
                user->notify(msg);
            }
        }
};


int main(){
    Group* group = new Group;

    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);

    group-> subscribe(user1);
    group-> subscribe(user2);
    group-> subscribe(user3);

    group-> notify("new msg");

    group-> unsubscribe(user1);
    group-> notify("again new msg");
    return 0;

}

