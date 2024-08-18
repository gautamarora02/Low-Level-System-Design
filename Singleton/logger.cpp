#include <iostream>
#include "logger.hpp"
using namespace std;
int Logger::ctr = 0;
mutex Logger::mtx;

Logger* Logger::loggerInstance = nullptr;

Logger::Logger(){
    ctr++;
    cout << "the instance created with number: " << ctr << endl;
}

void Logger::log(string msg){
    cout << msg << endl;
}

Logger* Logger::getlogger(){
    mtx.lock();
    if(!loggerInstance){
        loggerInstance = new Logger();
    }
    mtx.unlock();
    return loggerInstance;
}