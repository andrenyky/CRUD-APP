#include "TableModel.h"
#include "repoEvent.h"
#include <iostream>
#include <QFont>

TableModel::TableModel(EventList eventList, QObject *parent) : QAbstractTableModel(parent) {
    this->eventList = eventList;
}

int TableModel::rowCount(const QModelIndex &parent) const {
    return this->eventList.eventList.size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    int row = index.row(), column = index.column();
    std::vector<Event> data = this->eventList.eventList;
    if (role == Qt::DisplayRole){
        if (column == 0) {
            return QString::fromStdString(data[row].title);
        }
        if (column == 1){
            return QString::fromStdString(data[row].description);
        }
        if (column == 2){
            return QString::fromStdString(data[row].datetime);
        }
        if (column == 3){
            return QString::number(data[row].nr_people);
        }
        if (column == 4){
            return QString::fromStdString(data[row].link);
        }

    }
    return {};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {

    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return QString{"Title"};

                case 1:
                    return QString("Description");

                case 2:
                    return QString("Datetime");
                case 3:
                    return QString("Nr. People");
                case 4:
                    return QString("Link");

                default:
                    break;
            }
        }
    }

    return {};
}


