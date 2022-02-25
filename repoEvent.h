//
// Created by andre on 5/10/2021.
//
#ifndef A45_ANDRENYKY_REPOEVENT_H
#define A45_ANDRENYKY_REPOEVENT_H



#include <vector>
#include "Event.h"
#include <iostream>
#include "Undo.h"
class RepoEvent
{
//private:

public:
    vector<Action*>undo;
    vector<Action*>redo;
    std::vector<Event>elements;
    void write_to_file();
    void read_file();
    const vector<Event> &getElements() const;
    RepoEvent();
    void add_event(const Event& event, bool save=true);
    void add_event1(const Event& event, bool save=true);
    void insert_event_at_position(int pos, Event& event,bool save=true);
    void remove_event(int pos);
    void update_event(int pos,string title, string description, string datetime, string link,int nr_people);

    void remove_ev( Event &e);
    void update_ev( Event &e,string title, string description, string datetime, string link,int nr_people);
};







template<typename T>
ostream &operator<<(ostream &os, const vector<T>v) {
    for (auto& el:v)
        os <<el<<endl;
    return os;
}


#endif //A45_ANDRENYKY_REPOEVENT_H
