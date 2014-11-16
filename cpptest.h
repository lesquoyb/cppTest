#ifndef TEST_H
#define TEST_H
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include "cpptesttools.h"







class CppTest{


protected:

    std::vector<std::function<bool()>> _functions;
    std::vector<std::string> _names;
    std::vector<std::string> _run;
    std::string _name;


public:

    void run(){
        for(int i = 0 ; i < _functions.size() ; i++){
            std::string detail;
            if(_functions[i]()) detail = "réussie";
            else detail ="ECHEC !";
            _run.push_back(_names[i] + " " + detail);
        }
    }
    std::vector<std::string> getRunResult()const{return _run;}
     std::string getName()const{return _name;}



};

#endif // TEST_H
