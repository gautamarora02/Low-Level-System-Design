#ifndef logger_h
#define logger_h
#include <string>
#include <mutex>

using namespace std;


class Logger{
    static int ctr;
    Logger();  // making all the constructors inaccessible
    Logger(const Logger &);  // making copy constructor inaccessible 
    Logger operator = (const Logger &) = delete;  // makin g operator inaccssible 
    static mutex mtx;
    static Logger* loggerInstance;
    public: 
        static Logger* getlogger();
        void log(string msg);
};

#endif