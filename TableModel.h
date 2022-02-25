//
// Created by andre on 6/2/2021.
//

#ifndef PROJECT_TABLEMODEL_H
#define PROJECT_TABLEMODEL_H

#include <QAbstractTableModel>
#include "eventList.h"
class TableModel : public QAbstractTableModel {
public:
    explicit TableModel(EventList eventList, QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
    EventList eventList;

};

#endif //PROJECT_TABLEMODEL_H
