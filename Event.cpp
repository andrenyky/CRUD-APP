#include "Event.h"
#include <iostream>
#include <sstream>

using namespace std;
Event::Event() = default;
Event:: Event(std::string title, std::string  description, std::string  datetime,int nr_people, std::string  link) :title{title},description{description},datetime{datetime},nr_people{nr_people}
{
 string baseUrl="https://www.";
 string completeUrl = baseUrl+link;
 this->link=completeUrl;
}
Event::~Event() {

}

std::string Event::getTitle() {
    return this->title;
}
std::string Event::getDatetime() {
    return this->datetime;
}

std::string Event::getDescription() {
    return this->description;
}

std::string Event::getLink() {
    return this->link;
}

int Event::getNr_people() {
    return this->nr_people;
}

void Event::setTitle(std::string title) {
    if(title!="#")
    this->title = title;
}

void Event::setDateTime(std::string datetime) {
    if(datetime!="#")
    this->datetime = datetime;
}

void Event::setDescription(std::string description) {
    if(description!="#")
    this->description = description;
}

void Event::setNr_people(int nr_people) {
    if(nr_people>0)
    this->nr_people = nr_people;
}

void Event::setLink(std::string link) {
    if(link!="#") {
        string baseUrl = "https://www.";
        string completeUrl = baseUrl + link;
        this->link = completeUrl;
    }
}

ostream& operator<<(ostream& os, const Event& e)
{
    os <<"TITLE:"<<" "<<e.title << '|' <<"DESCRIPTION:"<<" "<< e.description << '|' <<"DATE:"<<" "<< e.datetime<< '|' <<"NR PEOPLE:"<<" "<< e.nr_people<< '|' <<"LINK:"<<" "<<endl<< e.link;
    return os;
}

istream &operator>>(istream &is, Event &e) {
    string line;
    int k=0, q=0;
    string newstr[11];
    std::getline(is,line);
    if (line.empty())
        throw std::runtime_error("The line is empty");
    int count = 0;
    for (k = 0; k < (line.size()); k++) {
        if (line[k] == ',' || line[k] == '\0') {

            count++;
        } else {
            newstr[count] += line[k];
            q++;
        }
    }
    e.title = newstr[0];
    e.description = newstr[1];
    e.datetime = newstr[2];
    e.nr_people = stoi(newstr[3]);
    e.link=newstr[4];
    return is;
}