/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QLabel *label;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QLineEdit *lineEdit_10;
    QLabel *label_16;
    QWidget *tab2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QLabel *label_20;
    QLineEdit *lineEdit_13;
    QWidget *tab3;
    QLabel *label_8;
    QComboBox *comboBox_3;
    QLabel *label_18;
    QLineEdit *lineEdit_11;
    QLabel *label_19;
    QLineEdit *lineEdit_12;
    QWidget *tab4;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_12;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QWidget *tab5;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QSpinBox *spinBox_3;
    QLabel *label_17;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QMenu *menuGestion_des_personnels;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(699, 324);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        label = new QLabel(tab1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 56, 16));
        label_3 = new QLabel(tab1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 70, 61, 21));
        comboBox = new QComboBox(tab1);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(150, 70, 101, 22));
        label_4 = new QLabel(tab1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 120, 121, 20));
        spinBox_2 = new QSpinBox(tab1);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(150, 120, 61, 22));
        lineEdit_10 = new QLineEdit(tab1);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(150, 20, 113, 22));
        label_16 = new QLabel(tab1);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 20, 101, 20));
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        label_2 = new QLabel(tab2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 40, 56, 16));
        lineEdit_2 = new QLineEdit(tab2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 40, 151, 22));
        label_5 = new QLabel(tab2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(15, 40, 91, 20));
        label_6 = new QLabel(tab2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 90, 61, 20));
        label_7 = new QLabel(tab2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 140, 56, 16));
        lineEdit = new QLineEdit(tab2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 90, 151, 22));
        lineEdit_3 = new QLineEdit(tab2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(150, 140, 151, 22));
        pushButton_2 = new QPushButton(tab2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 90, 101, 28));
        label_20 = new QLabel(tab2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(0, 190, 151, 16));
        lineEdit_13 = new QLineEdit(tab2);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(160, 190, 151, 22));
        tabWidget->addTab(tab2, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QStringLiteral("tab3"));
        label_8 = new QLabel(tab3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 30, 51, 16));
        comboBox_3 = new QComboBox(tab3);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(140, 30, 111, 22));
        label_18 = new QLabel(tab3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 80, 91, 16));
        lineEdit_11 = new QLineEdit(tab3);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(140, 80, 113, 22));
        label_19 = new QLabel(tab3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 130, 91, 16));
        lineEdit_12 = new QLineEdit(tab3);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(140, 130, 113, 22));
        tabWidget->addTab(tab3, QString());
        tab4 = new QWidget();
        tab4->setObjectName(QStringLiteral("tab4"));
        label_9 = new QLabel(tab4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(5, 40, 91, 20));
        label_10 = new QLabel(tab4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(25, 90, 71, 20));
        label_11 = new QLabel(tab4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 140, 56, 16));
        lineEdit_4 = new QLineEdit(tab4);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(150, 40, 151, 22));
        lineEdit_5 = new QLineEdit(tab4);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(150, 90, 151, 22));
        lineEdit_6 = new QLineEdit(tab4);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(150, 140, 151, 22));
        label_12 = new QLabel(tab4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(40, 190, 81, 20));
        spinBox = new QSpinBox(tab4);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(170, 190, 42, 22));
        pushButton = new QPushButton(tab4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(410, 80, 101, 28));
        tabWidget->addTab(tab4, QString());
        tab5 = new QWidget();
        tab5->setObjectName(QStringLiteral("tab5"));
        label_13 = new QLabel(tab5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(15, 30, 91, 20));
        label_14 = new QLabel(tab5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(45, 80, 61, 20));
        label_15 = new QLabel(tab5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(60, 130, 56, 16));
        lineEdit_7 = new QLineEdit(tab5);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(140, 30, 151, 22));
        lineEdit_8 = new QLineEdit(tab5);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(140, 80, 151, 22));
        lineEdit_9 = new QLineEdit(tab5);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(140, 130, 151, 22));
        spinBox_3 = new QSpinBox(tab5);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(170, 180, 61, 22));
        label_17 = new QLabel(tab5);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 180, 141, 20));
        pushButton_3 = new QPushButton(tab5);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(410, 80, 101, 28));
        tabWidget->addTab(tab5, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 699, 26));
        menuGestion_des_personnels = new QMenu(menubar);
        menuGestion_des_personnels->setObjectName(QStringLiteral("menuGestion_des_personnels"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuGestion_des_personnels->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\303\211tat", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Termin\303\251", Q_NULLPTR)
         << QApplication::translate("MainWindow", "En cours", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("MainWindow", "Num\303\251ro de la t\303\242che", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Nom de la t\303\242che", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("MainWindow", "Gestion des t\303\242ches", Q_NULLPTR));
        label_2->setText(QString());
        lineEdit_2->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Nom et prenom", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Mail", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", " Description du probl\303\250me", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("MainWindow", "R\303\251clamation", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "P\303\251riode", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Mensuelle", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Trimestrielle", Q_NULLPTR)
        );
        label_18->setText(QApplication::translate("MainWindow", "Salaire moyen", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "Jours travaill\303\251s", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QApplication::translate("MainWindow", "Statistiques", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Nom et prenom", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Mail", Q_NULLPTR));
        lineEdit_4->setText(QString());
        lineEdit_5->setText(QString());
        lineEdit_6->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "Dur\303\251e (jour)", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab4), QApplication::translate("MainWindow", "Cong\303\251s", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Nom et prenom", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Mail", Q_NULLPTR));
        lineEdit_7->setText(QString());
        lineEdit_8->setText(QString());
        lineEdit_9->setText(QString());
        label_17->setText(QApplication::translate("MainWindow", "Heures suppl\303\251mentaires", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab5), QApplication::translate("MainWindow", "Primes", Q_NULLPTR));
        menuGestion_des_personnels->setTitle(QApplication::translate("MainWindow", "Gestion des personnels", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
