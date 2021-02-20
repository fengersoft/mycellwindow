#include "controlwidget.h"
#include "ui_controlwidget.h"

ControlWidget::ControlWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ControlWidget)
{
    ui->setupUi(this);
    m_darkModel = false;
}

ControlWidget::~ControlWidget()
{
    delete ui;
}

void ControlWidget::on_btnPaste_clicked()
{
    const QMimeData* data = qApp->clipboard()->mimeData();
    if (data->hasText())
    {
        ui->edtInfo->setText(data->text());

    }
    else if (data->hasHtml())
    {
        ui->edtInfo->setHtml(data->html());

    }

}

void ControlWidget::on_btnClear_clicked()
{
    ui->edtInfo->clear();
}

void ControlWidget::on_btnDark_clicked()
{
    m_darkModel = !m_darkModel;
    if (m_darkModel)
    {
        ui->edtInfo->setStyleSheet(R"(background-color:black;color:white;)");
    }
    else
    {
        ui->edtInfo->setStyleSheet(R"(background-color:white;color:black;)");
    }
}


void ControlWidget::on_btnOpenFile_clicked()
{
    QString path = QFileDialog::getOpenFileName();
    if (path == "")
    {
        return;
    }
    m_fileName = path;
    QFile file(path);
    file.open(QFile::ReadOnly);
    ui->edtInfo->setText(file.readAll());
    file.close();
}

void ControlWidget::on_btnInsertDateTime_clicked()
{
    ui->edtInfo->append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + "\n");
    ui->edtInfo->setFocus();
}
