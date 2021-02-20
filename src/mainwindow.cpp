#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_card = new SelectCard(ui->wgtCardContainer);
    connect(m_card, &SelectCard::onSelected, this, &MainWindow::onCardSelected);
    QHBoxLayout* lay = new QHBoxLayout();
    lay->setContentsMargins(0, 0, 0, 0);
    ui->wgtCardContainer->setLayout(lay);
    lay->addWidget(m_card);
    loadTheme();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadTheme(int index)
{
    QFile file(QApplication::applicationDirPath() + QString("/qss/%1.qss").arg(index));
    file.open(QFile::ReadOnly);
    QString qssText = file.readAll();
    ui->wgtToolBar->setStyleSheet(qssText);

    file.close();
}




void MainWindow::on_btnAdd_clicked()
{
    QMenu* menu = new QMenu(this);
    QPoint pt = QPoint(0, ui->btnAdd->height());
    pt = ui->btnAdd->mapToGlobal(pt);
    QStringList menuNames;
    menuNames << "单窗口" << "水平二宫格" << "垂直二宫格" << "四宫格" << "九宫格" << "十六宫格";
    for (int i = 0; i < menuNames.count(); i++)
    {
        QAction* act = new QAction(this);
        act->setText(menuNames[i]);
        connect(act, &QAction::triggered, this, &MainWindow::onAddMenuPop);
        menu->addAction(act);
    }
    menu->exec(pt);

    delete  menu;
}

void MainWindow::onAddMenuPop()
{
    QAction* act = static_cast<QAction*>(sender());
    LayWindow* w = new LayWindow(this);
    int id = rand();
    w->setId(id);
    ui->wgtPages->addWidget(w);
    ui->wgtPages->setCurrentWidget(w);



    m_card->addItem(act->text(), id);
    if (act->text() == "单窗口")
    {
        w->setLayStyle(Single_Style);
    }
    if (act->text() == "水平二宫格")
    {
        w->setLayStyle(Hor2_Style);

    }
    else if (act->text() == "垂直二宫格")
    {
        w->setLayStyle(Ver2_Style);

    }
    else if (act->text() == "四宫格")
    {
        w->setLayStyle(Gong4_Style);
    }
    else if (act->text() == "九宫格")
    {
        w->setLayStyle(Gong9_Style);
    }
    else if (act->text() == "十六宫格")
    {
        w->setLayStyle(Gong16_Style);
    }


}

void MainWindow::onCardSelected(SelectCardItem* item)
{
    for (int i = 0; i < ui->wgtPages->count(); i++)
    {
        LayWindow* w = static_cast<LayWindow*>(ui->wgtPages->widget(i));
        if (w->id() == item->id)
        {
            ui->wgtPages->setCurrentWidget(w);
            break;
        }
    }

}
