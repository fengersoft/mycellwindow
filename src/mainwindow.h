#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "./api/controls/card/selectcard.h"
#include <QMenu>
#include "./widgets/laywindow.h"
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void loadTheme(int index = 0);


private slots:
    void on_btnAdd_clicked();
    void onAddMenuPop();
    void onCardSelected(SelectCardItem* item);

private:
    Ui::MainWindow* ui;
    SelectCard* m_card;
};
#endif // MAINWINDOW_H
