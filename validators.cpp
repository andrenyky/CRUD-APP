#include "validators.h"
#include <cstring>
#include "exceptions.h"
#include <string>
using namespace std;
void Validator::isDate(string datetime, int &OK) {
    char alphabet[] = { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    if(datetime.length()!=10) {
        OK = 0;
        throw EventException("\nThe datetime is not valid.\n");
    }

    string days,month,year;

    if(OK==1) {
        days = datetime.substr(0, 2);
        month = datetime.substr(3, 2);
        year = datetime.substr(6, 4);
    }
    if(OK == 1)
    {
        for(char day : days)
            if (strchr(alphabet, day) && OK == 1)
            {   OK = 0;
                throw EventException("\nThe datetime is not valid.\n");

            }
        for(char i : month)
            if (strchr(alphabet, i) && OK==1)
            {    OK = 0;
                throw EventException("\nThe datetime is not valid.\n");

            }
        for(char i : year)
            if (strchr(alphabet, i) && OK == 1)
            {    OK = 0;
                throw EventException("\nThe datetime is not valid.\n");

            }


        int days_int = stoi(days);
        int month_int = stoi(month);
        int year_int = stoi(year);
        if ((month_int <= 0 || month_int > 12) && OK == 1)
        {   OK = 0;
            throw EventException("\nThe month is not valid.\n");
        }
        if ((days_int <= 0 || days_int > 31) && OK == 1)
        {    OK = 0;
            throw EventException("\nThe day is not valid.\n");
        }
    }
}

void Validator::isNumber(string nr_people)
{
    for(char digit:nr_people)
    {
        if(digit <'0' || digit >'9')
            throw EventException("The number of people must be an integer");
    }
}