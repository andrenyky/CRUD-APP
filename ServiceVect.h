//
// Created by andre on 6/2/2021.
//

#ifndef PROJECT_SERVICEVECT_H
#define PROJECT_SERVICEVECT_H
#include "repoEvent.h"
#include "Undo.h"
#include "Action.h"
class ServiceVect {




public:
    RepoEvent* repoEvent;
    vector<Action*>undo;
    vector<Action*>redo;
    explicit ServiceVect(RepoEvent* repoEvent): repoEvent(repoEvent){};
    ~ServiceVect();
    void add_event( Event& event, bool save=true);

};

#endif //PROJECT_SERVICEVECT_H
