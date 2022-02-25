//
// Created by andre on 6/2/2021.
//

#ifndef PROJECT_UNDO_H
#define PROJECT_UNDO_H

#include <vector>

class Action;
class RepoEvent;

class Undo {
private:
    std::vector<Action*> history;
    int index;
    RepoEvent* repoEvent;

public:
    explicit Undo(RepoEvent*);

    Undo(){};

    ~Undo();

    void record(Action*);

    void undo();

    void redo();
};

#endif //PROJECT_UNDO_H
