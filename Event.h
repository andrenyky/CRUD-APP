//
// Created by andre on 3/29/2021.
//

#ifndef PROJECT_EVENT_H
#define PROJECT_EVENT_H
using namespace std;
#include <string>
class Event {
public:
    std::string title;
    std::string description;
    std::string datetime;
    int nr_people;
    std::string link;


public:
    Event();
    Event(std::string title, std::string  description, std::string  datetime,int nr_people, std::string  link);
    ~Event();

    std::string getTitle();
    std::string getDescription();
    std::string getDatetime();
    std::string getLink();


    int getNr_people();

    void setTitle(std::string title);
    void setDescription(std::string description);
    void setDateTime(std::string datetime);
    void setLink(std::string link);
    void setNr_people(int nr_people);

    friend ostream& operator<<(ostream& os, const Event& e);
    friend istream &operator>>(istream &is, Event &e);




};


#endif //PROJECT_EVENT_H
