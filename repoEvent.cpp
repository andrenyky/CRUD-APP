#include <algorithm>
#include "repoEvent.h"
#include "exceptions.h"
#include <fstream>
#include "DerivedActions.h"




RepoEvent::RepoEvent() : elements(vector<Event>()) {

}


void RepoEvent::add_event(const Event &event, bool save) {
//    if (find_if(this->elements.begin(), this->elements.end(), [&event] (auto const &event1){
//        return event.link == event1.link;
//    }) != this->elements.end() ){
//        throw EventException("The event is already in your list.\n\n");
//    }
    this->elements.push_back(event);
    if (save)
        write_to_file();

}


void RepoEvent::remove_event( int pos) {
    if(pos<0 || pos>=this->elements.size())
    {
        throw EventException("The event does not exist in your list.\n\n");
    }
    this->elements.erase(this->elements.begin()+pos);
    write_to_file();
}

void RepoEvent::update_event(int pos, string title, string description, string datetime, string link, int nr_people) {
    if(pos < 0  || pos >= this->elements.size())
    {
        throw EventException("The event does not exist in your list. \n\n");
    }
    if(title!="#")
        this->elements[pos].setTitle(title);
    if(description!="#")
        this->elements[pos].setDescription(description);
    if(datetime!="#")
        this->elements[pos].setDateTime(datetime);
    if(link!="#")
        this->elements[pos].setLink(link);
    if(nr_people>0)
        this->elements[pos].setNr_people(nr_people);
    write_to_file();
}




void RepoEvent::write_to_file() {
    ofstream myfile ("C:\\Users\\andre\\Documents\\GitHub\\a45-andrenyky\\Project\\input.txt");
    for (auto& event:this->elements){
        myfile<<event.title<<","<<event.description<<","<<event.datetime<<","<<event.nr_people<<","<<event.link<<"\n";
    }
    myfile.close();
}

void RepoEvent::read_file() {
    string line;
    ifstream myfile("C:\\Users\\andre\\Documents\\GitHub\\a45-andrenyky\\Project\\input.txt");
    while (true){
        if (myfile.eof()) {
            break;
        }
        Event e;

        try {
            myfile>>e;
            this->add_event(e, false);
        }
        catch (...){

        }

    }
    myfile.close();
}


const vector<Event> &RepoEvent::getElements() const {
    return elements;
}

void RepoEvent::insert_event_at_position(int pos,  Event &event, bool save) {
    for(int i = elements.size()-1 ; i >= pos ; i --)
        elements[i+1] = elements[i];
    elements[pos] =event;

}
//
//void RepoEvent::remove_ev( Event &e) {
////    if (std::find(this->elements.begin(), this->elements.end(), e) == this->elements.end())
////        throw EventException("No event in the list!\n");
//    this->elements.erase(std::find(this->elements.begin(), this->elements.end(), e));
//}
//void RepoEvent::update_ev( Event &e, string title, string description, string datetime, string link,
//                          int nr_people) {
////        if(std::find(this->elements.begin(), this->elements.end(),e) == this->elements.end())
////            throw EventException("Event is not in the list!\n");
////    if(title!="#")
////        std::find(this->elements.begin(), this->elements.end(), e)[0].setTitle(title);
////    if(description!="#")
////        std::find(this->elements.begin(), this->elements.end(), e)[0].setDescription(description);
////    if(datetime!="#")
////        std::find(this->elements.begin(), this->elements.end(), e)[0].setDateTime(datetime);
////    if(link!="#")
////        std::find(this->elements.begin(), this->elements.end(), e)[0].setLink(link);
////    if(nr_people>0)
////        std::find(this->elements.begin(), this->elements.end(), e)[0].setNr_people(nr_people);
////    write_to_file();

void RepoEvent::add_event1(const Event& event, bool save)
{

//    Action* removeAct = new RemoveAct(this);
//    this->undo.push_back(removeAct);
}