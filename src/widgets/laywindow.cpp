#include "laywindow.h"
#include "ui_laywindow.h"

LayWindow::LayWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::LayWindow)
{
    ui->setupUi(this);
}

LayWindow::~LayWindow()
{
    delete ui;
}

LayWindowStyle LayWindow::layStyle() const
{
    return m_layStyle;
}

void LayWindow::setLayStyle(const LayWindowStyle& layStyle)
{
    m_layStyle = layStyle;
    if (m_layStyle == Single_Style)
    {


        QHBoxLayout* lay = new QHBoxLayout(this);
        setLayout(lay);
        lay->setContentsMargins(0, 0, 0, 0);
        ControlWidget* w = new ControlWidget(this);
        lay->addWidget(w);


        w->show();
    }
    else if ((m_layStyle == Hor2_Style) || (m_layStyle == Ver2_Style))
    {
        QSplitter* m_spl = new QSplitter(m_layStyle == Hor2_Style ? Qt::Horizontal : Qt::Vertical, this);
        QHBoxLayout* lay = new QHBoxLayout(this);
        setLayout(lay);
        lay->setContentsMargins(0, 0, 0, 0);
        lay->addWidget(m_spl);

        ControlWidget* w1 = new ControlWidget(this);
        ControlWidget* w2 = new ControlWidget(this);

        m_spl->addWidget(w1);
        m_spl->addWidget(w2);
        m_spl->show();
    }
    else if (m_layStyle == Gong4_Style)
    {
        addGongWidgets(2, 2);

    }
    else if (m_layStyle == Gong9_Style)
    {
        addGongWidgets(3, 3);

    }
    else if (m_layStyle == Gong16_Style)
    {
        addGongWidgets(4, 4);

    }

}

void LayWindow::addGongWidgets(int m, int n)
{
    QSplitter* m_spl = new QSplitter(Qt::Horizontal, this);
    QHBoxLayout* lay = new QHBoxLayout(this);
    setLayout(lay);
    lay->setContentsMargins(0, 0, 0, 0);
    lay->addWidget(m_spl);
    for (int i = 0; i < m; i++)
    {
        QSplitter* m_tmpSpl = new QSplitter(Qt::Vertical, this);

        for (int j = 0; j < n; j++)
        {
            ControlWidget* w = new ControlWidget(this);
            m_tmpSpl->addWidget(w);
        }


        m_spl->addWidget(m_tmpSpl);

    }
    m_spl->show();
}

int LayWindow::id() const
{
    return m_id;
}

void LayWindow::setId(int id)
{
    m_id = id;
}
