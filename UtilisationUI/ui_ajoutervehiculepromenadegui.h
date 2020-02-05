/********************************************************************************
** Form generated from reading UI file 'ajoutervehiculepromenadegui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERVEHICULEPROMENADEGUI_H
#define UI_AJOUTERVEHICULEPROMENADEGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ajouterVehiculePromenadeGUIClass
{
public:
    QPushButton *OK;
    QPushButton *Annuler;
    QLineEdit *NIV;
    QLineEdit *Immat;
    QLineEdit *NbPlaces;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *ajouterVehiculePromenadeGUIClass)
    {
        if (ajouterVehiculePromenadeGUIClass->objectName().isEmpty())
            ajouterVehiculePromenadeGUIClass->setObjectName(QString::fromUtf8("ajouterVehiculePromenadeGUIClass"));
        ajouterVehiculePromenadeGUIClass->resize(377, 232);
        OK = new QPushButton(ajouterVehiculePromenadeGUIClass);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setGeometry(QRect(100, 180, 80, 28));
        Annuler = new QPushButton(ajouterVehiculePromenadeGUIClass);
        Annuler->setObjectName(QString::fromUtf8("Annuler"));
        Annuler->setGeometry(QRect(210, 180, 80, 28));
        NIV = new QLineEdit(ajouterVehiculePromenadeGUIClass);
        NIV->setObjectName(QString::fromUtf8("NIV"));
        NIV->setGeometry(QRect(200, 60, 113, 27));
        Immat = new QLineEdit(ajouterVehiculePromenadeGUIClass);
        Immat->setObjectName(QString::fromUtf8("Immat"));
        Immat->setGeometry(QRect(200, 100, 113, 27));
        NbPlaces = new QLineEdit(ajouterVehiculePromenadeGUIClass);
        NbPlaces->setObjectName(QString::fromUtf8("NbPlaces"));
        NbPlaces->setGeometry(QRect(200, 140, 113, 27));
        label = new QLabel(ajouterVehiculePromenadeGUIClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 60, 53, 17));
        label_2 = new QLabel(ajouterVehiculePromenadeGUIClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 100, 91, 20));
        label_3 = new QLabel(ajouterVehiculePromenadeGUIClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 140, 101, 20));
        label_4 = new QLabel(ajouterVehiculePromenadeGUIClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 20, 201, 17));

        retranslateUi(ajouterVehiculePromenadeGUIClass);
        QObject::connect(Annuler, SIGNAL(clicked()), ajouterVehiculePromenadeGUIClass, SLOT(close()));
        QObject::connect(OK, SIGNAL(clicked()), ajouterVehiculePromenadeGUIClass, SLOT(validerEnregistrement()));

        QMetaObject::connectSlotsByName(ajouterVehiculePromenadeGUIClass);
    } // setupUi

    void retranslateUi(QWidget *ajouterVehiculePromenadeGUIClass)
    {
        ajouterVehiculePromenadeGUIClass->setWindowTitle(QApplication::translate("ajouterVehiculePromenadeGUIClass", "ajouterVehiculePromenadeGUI", 0, QApplication::UnicodeUTF8));
        OK->setText(QApplication::translate("ajouterVehiculePromenadeGUIClass", "OK", 0, QApplication::UnicodeUTF8));
        Annuler->setText(QApplication::translate("ajouterVehiculePromenadeGUIClass", "Annuler", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ajouterVehiculePromenadeGUIClass", "NIV:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ajouterVehiculePromenadeGUIClass", "Immatriculation", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ajouterVehiculePromenadeGUIClass", "Nombre de places", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ajouterVehiculePromenadeGUIClass", "Ajout d'un vehicule promenade", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ajouterVehiculePromenadeGUIClass: public Ui_ajouterVehiculePromenadeGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERVEHICULEPROMENADEGUI_H
