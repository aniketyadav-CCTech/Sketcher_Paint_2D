#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "GLWidget.h"

class TreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget* parent);
public slots:
    void onItemDoubleClicked(QTreeWidgetItem* item, int column);
};

#endif // TREEWIDGET_H
