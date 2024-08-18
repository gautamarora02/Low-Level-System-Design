#include <iostream>
#include "logger.hpp"
#include <thread>

using namespace std;


void user1(){
    Logger* logger1 = Logger::getlogger();
    logger1->log("hello world from logger 1");
}

void user2(){
    Logger* logger2 = Logger::getlogger();
    logger2->log("hello world from logger 2");
}

int main(){
   thread t1(user1);
   thread t2(user2);
   t1.join();
   t2.join();

    
    return 0;
}
