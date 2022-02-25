//#include "Undo.h"
//#include "DerivedActions.h"
//#include "exceptions.h"
//
//Undo::Undo(RepoEvent* repoEvent1) {
//    this->repoEvent = repoEvent1;
//    this->index = -1;
//}
//
//void Undo::record(Action *act) {
//    if (this->history.size() - this->index > 1)
//        this->history.erase(this->history.begin() + this->index + 1, this->history.end());
//    this->history.push_back(act);
//    this->index++;
//}
//
//void Undo::undo() {
//    if (this->index == -1)
//        throw EventException("There are no more undos!");
//    this->history[this->index]->undo(this->repoEvent);
//    this->index--;
//}
//
//void Undo::redo() {
//    if (this->index == this->history.size() - 1)
//        throw EventException("There are no more redos!");
//    this->index++;
//    this->history[this->index]->redo(this->repoEvent);
//}
//
//Undo::~Undo() {
//    for (auto action: this->history)
//        delete action;
//}
