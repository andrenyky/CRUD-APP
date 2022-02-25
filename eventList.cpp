#include "eventList.h"
#include <fstream>

void CsvEventList::write() {

    ofstream myfile("C:\\Users\\andre\\Documents\\GitHub\\a45-andrenyky\\Project\\user1.csv");
    for (auto const &e:this->eventList) {
        myfile << e.title << "," << e.description  << "," << e.datetime << "," << e.nr_people << "," << e.link << "\n";
    }
    myfile.close();
}

vector<Event> &EventList::getEventList() {
    return eventList;
}

void EventList::write() {

}

void HtmlEventList::write() {
    ofstream myfile("C:\\Users\\andre\\Documents\\GitHub\\a45-andrenyky\\Project\\user2.html");
    myfile << "<!DOCTYPE html>" << endl << "<html>" << endl << "<head>" << endl << "<title>Event List</title>"
           << endl << "</head>" << endl << "<body>" << "<table border=\"1\">" << endl << "<tr>" << "<td>Title</td>"
           << endl << "<td>Description</td>" << endl << "<td>Date</td>" << endl << "<td>Nr. People</td>" << endl << "<td>Link</td>" << endl << "</tr>"
           << "<tr>" << endl;
    for (auto const &e:this->getEventList()) {
        myfile << "<tr>" << "<td>" << e.title << "</td>" << "<td>" << e.description << "</td>" << "<td>"
               << e.datetime << "</td>" << "<td>" << e.nr_people <<"</td>" << "<td>" << "<a href= \""<<e.link << "\">Link</a></td></tr>";
    }
    myfile << "</table>\n"
              "</body>\n"
              "</html>";
    myfile.close();
}
