#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include <QClipboard>
#include <QMimeData>
#include <QFileDialog>

namespace Ui
{
class ControlWidget;
}

class ControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControlWidget(QWidget* parent = nullptr);
    ~ControlWidget();

private slots:
    void on_btnPaste_clicked();

    void on_btnClear_clicked();

    void on_btnDark_clicked();

    void on_btnOpenFile_clicked();

    void on_btnInsertDateTime_clicked();

private:
    Ui::ControlWidget* ui;
    bool m_darkModel;
    QString m_fileName;
};

#endif // CONTROLWIDGET_H
