/********************************************************************************
** Form generated from reading UI file 'supprimergui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERGUI_H
#define UI_SUPPRIMERGUI_H

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

class Ui_supprimerGUIClass
{
public:
    QPushButton *OK;
    QPushButton *Annuler;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *NIV;

    void setupUi(QDialog *supprimerGUIClass)
    {
        if (supprimerGUIClass->objectName().isEmpty())
            supprimerGUIClass->setObjectName(QString::fromUtf8("supprimerGUIClass"));
        supprimerGUIClass->resize(368, 186);
        OK = new QPushButton(supprimerGUIClass);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setGeometry(QRect(80, 120, 80, 28));
        Annuler = new QPushButton(supprimerGUIClass);
        Annuler->setObjectName(QString::fromUtf8("Annuler"));
        Annuler->setGeometry(QRect(190, 120, 80, 28));
        label = new QLabel(supprimerGUIClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 60, 53, 17));
        label_2 = new QLabel(supprimerGUIClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(102, 20, 221, 20));
        NIV = new QLineEdit(supprimerGUIClass);
        NIV->setObjectName(QString::fromUtf8("NIV"));
        NIV->setGeometry(QRect(140, 50, 113, 27));

        retranslateUi(supprimerGUIClass);
        QObject::connect(Annuler, SIGNAL(clicked()), supprimerGUIClass, SLOT(close()));
        QObject::connect(OK, SIGNAL(clicked()), supprimerGUIClass, SLOT(validerSuppression()));

        QMetaObject::connectSlotsByName(supprimerGUIClass);
    } // setupUi

    void retranslateUi(QDialog *supprimerGUIClass)
    {
        supprimerGUIClass->setWindowTitle(QApplication::translate("supprimerGUIClass", "supprimerGUI", 0, QApplication::UnicodeUTF8));
        OK->setText(QApplication::translate("supprimerGUIClass", "Supprimer", 0, QApplication::UnicodeUTF8));
        Annuler->setText(QApplication::translate("supprimerGUIClass", "Annuler", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("supprimerGUIClass", "NIV\n"
"", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("supprimerGUIClass", "Entrer le NIV du vehicule a supprimer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class supprimerGUIClass: public Ui_supprimerGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERGUI_H
