/********************************************************************************
** Form generated from reading UI file 'ajoutercamiongui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERCAMIONGUI_H
#define UI_AJOUTERCAMIONGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ajouterCamionGUIClass
{
public:
    QLabel *generic;
    QLineEdit *NIV;
    QLineEdit *Immat;
    QLineEdit *Poids;
    QLineEdit *NbEssieux;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *OK;
    QPushButton *Annuler;

    void setupUi(QDialog *ajouterCamionGUIClass)
    {
        if (ajouterCamionGUIClass->objectName().isEmpty())
            ajouterCamionGUIClass->setObjectName(QString::fromUtf8("ajouterCamionGUIClass"));
        ajouterCamionGUIClass->resize(400, 235);
        generic = new QLabel(ajouterCamionGUIClass);
        generic->setObjectName(QString::fromUtf8("generic"));
        generic->setGeometry(QRect(140, 20, 101, 20));
        NIV = new QLineEdit(ajouterCamionGUIClass);
        NIV->setObjectName(QString::fromUtf8("NIV"));
        NIV->setGeometry(QRect(200, 60, 113, 27));
        Immat = new QLineEdit(ajouterCamionGUIClass);
        Immat->setObjectName(QString::fromUtf8("Immat"));
        Immat->setGeometry(QRect(200, 90, 113, 27));
        Poids = new QLineEdit(ajouterCamionGUIClass);
        Poids->setObjectName(QString::fromUtf8("Poids"));
        Poids->setGeometry(QRect(200, 120, 113, 27));
        NbEssieux = new QLineEdit(ajouterCamionGUIClass);
        NbEssieux->setObjectName(QString::fromUtf8("NbEssieux"));
        NbEssieux->setGeometry(QRect(200, 150, 113, 27));
        label = new QLabel(ajouterCamionGUIClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 60, 31, 17));
        label_2 = new QLabel(ajouterCamionGUIClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(102, 90, 91, 20));
        label_3 = new QLabel(ajouterCamionGUIClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 120, 31, 20));
        label_4 = new QLabel(ajouterCamionGUIClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 150, 101, 20));
        OK = new QPushButton(ajouterCamionGUIClass);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setGeometry(QRect(110, 190, 80, 28));
        Annuler = new QPushButton(ajouterCamionGUIClass);
        Annuler->setObjectName(QString::fromUtf8("Annuler"));
        Annuler->setGeometry(QRect(210, 190, 80, 28));

        retranslateUi(ajouterCamionGUIClass);
        QObject::connect(OK, SIGNAL(clicked()), ajouterCamionGUIClass, SLOT(validerEnregistrement()));
        QObject::connect(Annuler, SIGNAL(clicked()), ajouterCamionGUIClass, SLOT(close()));

        QMetaObject::connectSlotsByName(ajouterCamionGUIClass);
    } // setupUi

    void retranslateUi(QDialog *ajouterCamionGUIClass)
    {
        ajouterCamionGUIClass->setWindowTitle(QApplication::translate("ajouterCamionGUIClass", "ajouterCamionGUI", 0, QApplication::UnicodeUTF8));
        generic->setText(QApplication::translate("ajouterCamionGUIClass", "Ajouter un Camion", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ajouterCamionGUIClass", "NIV", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ajouterCamionGUIClass", "Immatriculation", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ajouterCamionGUIClass", "Poids", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ajouterCamionGUIClass", "Nombre d'essieux", 0, QApplication::UnicodeUTF8));
        OK->setText(QApplication::translate("ajouterCamionGUIClass", "OK", 0, QApplication::UnicodeUTF8));
        Annuler->setText(QApplication::translate("ajouterCamionGUIClass", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ajouterCamionGUIClass: public Ui_ajouterCamionGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERCAMIONGUI_H
