//
// Created by andre on 5/10/2021.
//

#ifndef A45_ANDRENYKY_VALIDATORS_H
#define A45_ANDRENYKY_VALIDATORS_H


#include <string>
using namespace std;
class Validator{

public:
    void isDate(std::__cxx11::basic_string<char> datetime, int &OK);
    void isNumber(string nr_people);
};


#endif //A45_ANDRENYKY_VALIDATORS_H
