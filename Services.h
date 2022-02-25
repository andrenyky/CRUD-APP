//
// Created by andre on 4/7/2021.
//

#ifndef A45_ANDRENYKY_SERVICES_H
#define A45_ANDRENYKY_SERVICES_H
#include "Event.h"
#include "DynamicVector.h"


bool compare(Event e1, Event e2);
void update(DynamicVector<Event> &ve,int pos,string title, string description, string datetime, string link,int nr_people);
#endif //A45_ANDRENYKY_SERVICES_H
