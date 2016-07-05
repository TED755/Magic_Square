#include "mods.h"
#include "mainwindow.h"

Mods::Mods(QWidget *pwgt) : QGroupBox("Mod", pwgt)
{
    resize(100, 150);

    Training = new QRadioButton("Training");
    Arcade = new QRadioButton("Arcade");
    Training->setChecked(true);

    connect(Training, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(Arcade, SIGNAL(clicked()), SLOT(slotButtonClicked()));

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(Training);
    pvbxLayout->addWidget(Arcade);

    setLayout(pvbxLayout);

    slotButtonClicked();
}

void Mods::slotButtonClicked()
{
    QPalette pal = palette();

    if(Training->isChecked()){
        pal.setColor(backgroundRole(), QColor(Qt::red));
    }
    else if(Arcade->isChecked()){
        pal.setColor(backgroundRole(), QColor(Qt::green));
    }
    setPalette(pal);
}