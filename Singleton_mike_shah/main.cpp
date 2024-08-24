#include <bits/stdc++.h>
using namespace std;
#include <thread>
#include <mutex>
class Logger{
    public:
        static Logger* getInstance(){
            lock_guard<mutex> guard(mtx);
            if(s_instance == nullptr){
                return s_instance = new Logger;
            }
            mtx.unlock();
            return s_instance;
        }
        static int noofinstance;
        void printmessage(){
            cout << "Accessing the log: " << endl;
            for(const auto &it: msg){
                cout << it << endl;
            }
        }
        void addmessage(string s){
            msg.push_back(s);
        }
    private:
        Logger(){
            noofinstance++;
            cout << "Logger no of instance: " <<  noofinstance << endl;
        }
        ~Logger(){
            cout << "Logger was distructed" << endl;
        }
        static Logger* s_instance;
        static mutex mtx;
        vector <string> msg;
};

Logger* Logger::s_instance = nullptr;
mutex Logger::mtx;

int Logger::noofinstance = 0;

void giveobj(){
    Logger::getInstance();
}
int main()
{
    thread t1(giveobj);
    thread t2(giveobj);
    t1.join();
    t2.join();
    Logger::getInstance()->addmessage("Hello 1");
    Logger::getInstance()->addmessage("Hello 2");
    Logger::getInstance()->addmessage("Hello 3");
    Logger::getInstance()->addmessage("Hello 4");
    Logger::getInstance()->printmessage();
    cout << "Total no of loggers: " << Logger::noofinstance << endl;
    return 0;
}