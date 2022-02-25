//
// Created by andre on 4/7/2021.
//

#include "Services.h"
#include "Event.h"
#include "DynamicVector.h"
using namespace std;



void update(DynamicVector<Event> &ve,int pos,string title, string description, string datetime, string link,int nr_people)
{ /* we receive the new data as input and if they aren't '#'(strings) or negative numbers(int)
 * we update the values of the element in ve.elems at the position pos*/
    if(title!="#")
        ve.elems[pos].setTitle(title);
    if(description!="#")
        ve.elems[pos].setDescription(description);
    if(datetime!="#")
        ve.elems[pos].setDateTime(datetime);
    if(link!="#")
        ve.elems[pos].setLink(link);
    if(nr_people>0)
        ve.elems[pos].setNr_people(nr_people);
}

bool compare(Event e1, Event e2) {
    /*we compare the dates of two events in order to sort them in chronological order*/
    string days1 = e1.datetime.substr(0, 2);
    string month1 = e1.datetime.substr(3, 2);
    string year1 = e1.datetime.substr(6, 4);

    string days2 = e2.datetime.substr(0, 2);
    string month2 = e2.datetime.substr(3, 2);
    string year2 = e2.datetime.substr(6, 4);

    int days_int1 = stoi(days1);
    int month_int1 = stoi(month1);
    int year_int1 = stoi(year1);

    int days_int2 = stoi(days2);
    int month_int2 = stoi(month2);
    int year_int2 = stoi(year2);

    if (year_int1 < year_int2)
        return true;
    if (year_int1 == year_int2 && month_int1 < month_int2)
        return true;
    if (year_int1 == year_int2 && month_int1 == month_int2 &&
        days_int1 < days_int2)
        return true;

    // If none of the above cases satisfy, return false
    return false;



}
