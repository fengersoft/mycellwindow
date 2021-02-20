#ifndef LAYWINDOW_H
#define LAYWINDOW_H

#include <QWidget>
#include <QSplitter>
#include "controlwidget.h"
#include <QHBoxLayout>
#include <QTextEdit>

namespace Ui
{
class LayWindow;
}
enum LayWindowStyle
{
    Single_Style,
    Hor2_Style,
    Ver2_Style,
    Gong4_Style,
    Gong9_Style,
    Gong16_Style,
};

class LayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LayWindow(QWidget* parent = nullptr);
    ~LayWindow();

    LayWindowStyle layStyle() const;
    void setLayStyle(const LayWindowStyle& layStyle);
    void addGongWidgets(int m, int n);
    int id() const;
    void setId(int id);

private:
    Ui::LayWindow* ui;
    LayWindowStyle m_layStyle;
    int m_id;
};

#endif // LAYWINDOW_H
