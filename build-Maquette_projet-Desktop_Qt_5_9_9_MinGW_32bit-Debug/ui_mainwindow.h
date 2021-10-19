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
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QToolBox *toolBox;
    QWidget *page;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label_5;
    QWidget *tab_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QWidget *page_2;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QLabel *label_7;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QSlider *verticalSlider;
    QWidget *page_4;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QLabel *label_8;
    QComboBox *comboBox;
    QWidget *tab_4;
    QLabel *label_9;
    QStackedWidget *stackedWidget_2;
    QWidget *page_7;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QWidget *page_8;
    QLabel *label_12;
    QSpinBox *spinBox;
    QWidget *page_9;
    QLabel *label_13;
    QLineEdit *lineEdit_7;
    QWidget *tab_5;
    QLabel *label_14;
    QLineEdit *lineEdit_8;
    QLabel *label_15;
    QLineEdit *lineEdit_9;
    QWidget *tab_6;
    QComboBox *comboBox_2;
    QLabel *label_16;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1177, 627);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(120, 30, 961, 511));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 961, 451));
        tabWidget = new QTabWidget(page);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(60, 20, 511, 311));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 80, 101, 31));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 150, 91, 21));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 80, 161, 31));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 150, 161, 31));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 230, 93, 28));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 10, 371, 41));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 90, 81, 16));
        lineEdit_3 = new QLineEdit(tab_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 80, 161, 31));
        lineEdit_3->setFrame(true);
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 150, 101, 16));
        lineEdit_4 = new QLineEdit(tab_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(130, 150, 161, 31));
        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 230, 93, 28));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 20, 261, 20));
        tabWidget->addTab(tab_3, QString());
        toolBox->addItem(page, QStringLiteral("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 961, 451));
        stackedWidget = new QStackedWidget(page_2);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(30, 20, 881, 401));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 20, 131, 16));
        scrollArea = new QScrollArea(page_3);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(110, 90, 631, 271));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 629, 269));
        scrollArea->setWidget(scrollAreaWidgetContents_3);
        verticalSlider = new QSlider(page_3);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(750, 90, 21, 261));
        verticalSlider->setOrientation(Qt::Vertical);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        tabWidget_2 = new QTabWidget(page_4);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(60, 40, 781, 321));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 20, 101, 41));
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(120, 30, 241, 31));
        tabWidget_2->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 30, 151, 31));
        stackedWidget_2 = new QStackedWidget(tab_4);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(70, 20, 591, 211));
        stackedWidget_2->setLineWidth(2);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        label_10 = new QLabel(page_7);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(25, 30, 81, 31));
        label_11 = new QLabel(page_7);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 90, 81, 21));
        lineEdit_5 = new QLineEdit(page_7);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(120, 31, 151, 31));
        lineEdit_6 = new QLineEdit(page_7);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(120, 90, 151, 31));
        stackedWidget_2->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        label_12 = new QLabel(page_8);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 40, 301, 41));
        spinBox = new QSpinBox(page_8);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(360, 50, 91, 22));
        spinBox->setMaximum(10000);
        stackedWidget_2->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName(QStringLiteral("page_9"));
        label_13 = new QLabel(page_9);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(60, 40, 91, 41));
        lineEdit_7 = new QLineEdit(page_9);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(150, 50, 131, 31));
        stackedWidget_2->addWidget(page_9);
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_14 = new QLabel(tab_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(90, 50, 161, 41));
        lineEdit_8 = new QLineEdit(tab_5);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(240, 60, 271, 31));
        label_15 = new QLabel(tab_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(90, 140, 111, 16));
        lineEdit_9 = new QLineEdit(tab_5);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(242, 130, 261, 31));
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        comboBox_2 = new QComboBox(tab_6);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(120, 20, 81, 31));
        label_16 = new QLabel(tab_6);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(50, 20, 91, 31));
        radioButton = new QRadioButton(tab_6);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(170, 90, 211, 20));
        radioButton_2 = new QRadioButton(tab_6);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(170, 130, 221, 20));
        radioButton_3 = new QRadioButton(tab_6);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(170, 180, 211, 20));
        tabWidget_2->addTab(tab_6, QString());
        stackedWidget->addWidget(page_4);
        toolBox->addItem(page_2, QStringLiteral("Page 2"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1177, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(3);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Mot de passe", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Confirmer", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Veuillez entrer vos coordonn\303\251es:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter une facture", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Mot de passe", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Confirmer", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Veuillez entrer vos coordonn\303\251es", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Modifier une facture", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow", "Page 1", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Liste des factures", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Trier selon", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Date ( les factures les plus r\303\251centes )", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Montant ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Num\303\251ro de factures", Q_NULLPTR)
        );
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("MainWindow", "Trier des factures", Q_NULLPTR));
        label_9->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Pr\303\251nom", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Intervalle de prix ( Entrer le maximum montant )", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Date", Q_NULLPTR));
        lineEdit_7->setText(QApplication::translate("MainWindow", "          /         /", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Rechercher des factures", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Mail du destinataire", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Contenu du mail", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Mailing", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Mensuelle ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Annuelle", Q_NULLPTR)
        );
        label_16->setText(QApplication::translate("MainWindow", "Dur\303\251e", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "Les factures les plus couteuses", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "Les factures les moins couteuses", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MainWindow", "Les clients les plus fid\303\250les", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "Statistiques", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MainWindow", "Page 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
