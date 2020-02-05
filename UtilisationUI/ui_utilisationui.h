/********************************************************************************
** Form generated from reading UI file 'utilisationui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UTILISATIONUI_H
#define UI_UTILISATIONUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UtilisationUIClass
{
public:
    QAction *actionAjouter_Proprietaire;
    QAction *actionQuitter;
    QAction *actionSupprimer;
    QAction *actionVehicule_Promenade;
    QAction *actionCamion;
    QAction *actionAjouter_Proprietaire_2;
    QWidget *centralwidget;
    QTableWidget *tableProprio;
    QTextBrowser *textVehicule;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuAjouter;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *UtilisationUIClass)
    {
        if (UtilisationUIClass->objectName().isEmpty())
            UtilisationUIClass->setObjectName(QString::fromUtf8("UtilisationUIClass"));
        UtilisationUIClass->resize(811, 481);
        actionAjouter_Proprietaire = new QAction(UtilisationUIClass);
        actionAjouter_Proprietaire->setObjectName(QString::fromUtf8("actionAjouter_Proprietaire"));
        actionQuitter = new QAction(UtilisationUIClass);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionSupprimer = new QAction(UtilisationUIClass);
        actionSupprimer->setObjectName(QString::fromUtf8("actionSupprimer"));
        actionVehicule_Promenade = new QAction(UtilisationUIClass);
        actionVehicule_Promenade->setObjectName(QString::fromUtf8("actionVehicule_Promenade"));
        actionCamion = new QAction(UtilisationUIClass);
        actionCamion->setObjectName(QString::fromUtf8("actionCamion"));
        actionAjouter_Proprietaire_2 = new QAction(UtilisationUIClass);
        actionAjouter_Proprietaire_2->setObjectName(QString::fromUtf8("actionAjouter_Proprietaire_2"));
        centralwidget = new QWidget(UtilisationUIClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableProprio = new QTableWidget(centralwidget);
        if (tableProprio->columnCount() < 2)
            tableProprio->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableProprio->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableProprio->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableProprio->setObjectName(QString::fromUtf8("tableProprio"));
        tableProprio->setGeometry(QRect(20, 10, 331, 411));
        textVehicule = new QTextBrowser(centralwidget);
        textVehicule->setObjectName(QString::fromUtf8("textVehicule"));
        textVehicule->setGeometry(QRect(360, 10, 441, 411));
        UtilisationUIClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UtilisationUIClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 811, 25));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuAjouter = new QMenu(menuFichier);
        menuAjouter->setObjectName(QString::fromUtf8("menuAjouter"));
        UtilisationUIClass->setMenuBar(menubar);
        statusbar = new QStatusBar(UtilisationUIClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UtilisationUIClass->setStatusBar(statusbar);
        toolBar = new QToolBar(UtilisationUIClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        UtilisationUIClass->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFichier->menuAction());
        menuFichier->addSeparator();
        menuFichier->addAction(actionAjouter_Proprietaire_2);
        menuFichier->addAction(menuAjouter->menuAction());
        menuFichier->addAction(actionSupprimer);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuAjouter->addAction(actionVehicule_Promenade);
        menuAjouter->addAction(actionCamion);

        retranslateUi(UtilisationUIClass);
        QObject::connect(actionQuitter, SIGNAL(triggered()), UtilisationUIClass, SLOT(close()));
        QObject::connect(tableProprio, SIGNAL(cellClicked(int,int)), UtilisationUIClass, SLOT(selectionProprietaire()));
        QObject::connect(actionCamion, SIGNAL(triggered()), UtilisationUIClass, SLOT(dialogAjouterCamion()));
        QObject::connect(actionVehicule_Promenade, SIGNAL(triggered()), UtilisationUIClass, SLOT(dialogAjouterVehiculePromenade()));
        QObject::connect(actionSupprimer, SIGNAL(triggered()), UtilisationUIClass, SLOT(dialogSuppression()));
        QObject::connect(actionAjouter_Proprietaire_2, SIGNAL(triggered()), UtilisationUIClass, SLOT(dialogAjouterProprietaire()));

        QMetaObject::connectSlotsByName(UtilisationUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *UtilisationUIClass)
    {
        UtilisationUIClass->setWindowTitle(QApplication::translate("UtilisationUIClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionAjouter_Proprietaire->setText(QApplication::translate("UtilisationUIClass", "Ajouter Proprietaire", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("UtilisationUIClass", "Quitter", 0, QApplication::UnicodeUTF8));
        actionSupprimer->setText(QApplication::translate("UtilisationUIClass", "Supprimer Vehicule", 0, QApplication::UnicodeUTF8));
        actionVehicule_Promenade->setText(QApplication::translate("UtilisationUIClass", "Vehicule Promenade", 0, QApplication::UnicodeUTF8));
        actionCamion->setText(QApplication::translate("UtilisationUIClass", "Camion", 0, QApplication::UnicodeUTF8));
        actionAjouter_Proprietaire_2->setText(QApplication::translate("UtilisationUIClass", "Ajouter Proprietaire", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableProprio->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("UtilisationUIClass", "Nom", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableProprio->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("UtilisationUIClass", "Prenom", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("UtilisationUIClass", "Fichier", 0, QApplication::UnicodeUTF8));
        menuAjouter->setTitle(QApplication::translate("UtilisationUIClass", "Ajouter Vehicule", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("UtilisationUIClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UtilisationUIClass: public Ui_UtilisationUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UTILISATIONUI_H
