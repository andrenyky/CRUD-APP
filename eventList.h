//
// Created by andre on 5/11/2021.
//

#ifndef A45_ANDRENYKY_EVENTLIST_H
#define A45_ANDRENYKY_EVENTLIST_H
#include "Event.h"
#include "vector"
using namespace std;

class EventList{


public:
    vector<Event>eventList;
    virtual void write();

    vector<Event> &getEventList();
};

class CsvEventList: public EventList{
public:
    void write() override;

};

class HtmlEventList: public EventList{
    void write() override;
};

#endif //A45_ANDRENYKY_EVENTLIST_H
