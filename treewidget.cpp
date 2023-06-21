#include "treewidget.h"


TreeWidget::TreeWidget(QWidget* parent)
	: QTreeWidget(parent)
{
    QObject::connect(this, &QTreeWidget::itemDoubleClicked, this, &TreeWidget::onItemDoubleClicked);
}

void TreeWidget::onItemDoubleClicked(QTreeWidgetItem* item, int column)
{
	if (!item->parent() && this->selectedItems().size() != 0)
		this->selectedItems().pop_back();

	if (this->selectedItems().size() != 0)
		if (item->parent())
		{
			qDebug() << "Tree";
		}

			/*Geometry::IGeometry* geom =  mainWindow.geomMap[item->text(column).toStdString()];
			geom->thickness = (this->selectedItems().contains(item)) ? Geometry::BOLD : Geometry::REGULAR;
			mainWindow.glWidget->paintGL();

			mainWindow.lineList.clear();
			for (auto item : this->selectedItems())
			{
				Geometry::IGeometry* geom = mainWindow.geomMap[item->text(column).toStdString()];
				if (geom->geomID._Starts_with("Line ")) {
					mainWindow.lineList.push_back(dynamic_cast<Geometry::Line*>(geom));
				}
			}
			std::vector<Geometry::Point*> intersectionPoints = mainWindow.intersection->getLineIntersectionPoints(mainWindow.lineList);
			for (auto& item : intersectionPoints)
			{
				Geometry::IGeometry* point = item;
				point->thickness = Geometry::REGULAR;
				point->setColor(mainWindow.colorMode);
				mainWindow.glWidget->addGeom(point);
				mainWindow.glWidget->paintGL();
				mainWindow.glWidget->update();
			}
		}*/
}