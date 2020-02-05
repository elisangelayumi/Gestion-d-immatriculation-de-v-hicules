/********************************************************************************
** Form generated from reading UI file 'ajouterpropriogui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERPROPRIOGUI_H
#define UI_AJOUTERPROPRIOGUI_H

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

class Ui_ajouterProprioGUIClass
{
public:
    QPushButton *OK;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *nomPro;
    QLineEdit *prenomPro;
    QPushButton *Annuler;

    void setupUi(QDialog *ajouterProprioGUIClass)
    {
        if (ajouterProprioGUIClass->objectName().isEmpty())
            ajouterProprioGUIClass->setObjectName(QString::fromUtf8("ajouterProprioGUIClass"));
        ajouterProprioGUIClass->resize(290, 180);
        OK = new QPushButton(ajouterProprioGUIClass);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setGeometry(QRect(40, 110, 80, 28));
        label = new QLabel(ajouterProprioGUIClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 53, 17));
        label_2 = new QLabel(ajouterProprioGUIClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 70, 53, 17));
        nomPro = new QLineEdit(ajouterProprioGUIClass);
        nomPro->setObjectName(QString::fromUtf8("nomPro"));
        nomPro->setGeometry(QRect(100, 40, 113, 27));
        prenomPro = new QLineEdit(ajouterProprioGUIClass);
        prenomPro->setObjectName(QString::fromUtf8("prenomPro"));
        prenomPro->setGeometry(QRect(100, 70, 113, 27));
        Annuler = new QPushButton(ajouterProprioGUIClass);
        Annuler->setObjectName(QString::fromUtf8("Annuler"));
        Annuler->setGeometry(QRect(150, 110, 80, 28));

        retranslateUi(ajouterProprioGUIClass);
        QObject::connect(Annuler, SIGNAL(clicked()), ajouterProprioGUIClass, SLOT(close()));
        QObject::connect(OK, SIGNAL(clicked()), ajouterProprioGUIClass, SLOT(validerEnregistrement()));

        QMetaObject::connectSlotsByName(ajouterProprioGUIClass);
    } // setupUi

    void retranslateUi(QDialog *ajouterProprioGUIClass)
    {
        ajouterProprioGUIClass->setWindowTitle(QApplication::translate("ajouterProprioGUIClass", "ajouterProprioGUI", 0, QApplication::UnicodeUTF8));
        OK->setText(QApplication::translate("ajouterProprioGUIClass", "OK", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ajouterProprioGUIClass", "Nom:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ajouterProprioGUIClass", "Prenom:", 0, QApplication::UnicodeUTF8));
        Annuler->setText(QApplication::translate("ajouterProprioGUIClass", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ajouterProprioGUIClass: public Ui_ajouterProprioGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERPROPRIOGUI_H
