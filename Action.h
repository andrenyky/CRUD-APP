//
// Created by andre on 6/2/2021.
////
//
#ifndef PROJECT_ACTION_H
#define PROJECT_ACTION_H
#include "Event.h"
#include "repoEvent.h"

class Action
{
private:
    RepoEvent repoEvent;
public:
    explicit Action( RepoEvent repoEvent1) : repoEvent(repoEvent1) {};
    virtual void call() =0;
    virtual ~Action() = default;
};
#endif //PROJECT_ACTION_H
