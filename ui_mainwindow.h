/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *mainLayout;
    QVBoxLayout *gameLayout;
    QVBoxLayout *setLayout;
    QHBoxLayout *controlLayout;
    QPushButton *startButton;
    QPushButton *clearButton;
    QLabel *label;
    QSpinBox *cellsControl;
    QSlider *cellsSlider;
    QLabel *label2;
    QSpinBox *iterInterval;
    QSlider *iterSlider;
    QLabel *redLimitLabel;
    QSpinBox *redLimitSpin;
    QSlider *redLimitSlider;
    QHBoxLayout *fileLayout;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *statsLayout;
    QSpacerItem *horizontalSpacer;
    QGroupBox *labelsBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *stAllLab;
    QLabel *stBlackLab;
    QLabel *stGreenLab;
    QLabel *stRedLab;
    QGroupBox *statsBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *stAll;
    QLabel *stBlack;
    QLabel *stGreen;
    QLabel *stRed;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 451);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 8, 681, 441));
        mainLayout = new QHBoxLayout(layoutWidget);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        gameLayout = new QVBoxLayout();
        gameLayout->setSpacing(6);
        gameLayout->setObjectName(QStringLiteral("gameLayout"));

        mainLayout->addLayout(gameLayout);

        setLayout = new QVBoxLayout();
        setLayout->setSpacing(6);
        setLayout->setObjectName(QStringLiteral("setLayout"));
        setLayout->setSizeConstraint(QLayout::SetFixedSize);
        controlLayout = new QHBoxLayout();
        controlLayout->setSpacing(6);
        controlLayout->setObjectName(QStringLiteral("controlLayout"));
        startButton = new QPushButton(layoutWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        controlLayout->addWidget(startButton);

        clearButton = new QPushButton(layoutWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        controlLayout->addWidget(clearButton);


        setLayout->addLayout(controlLayout);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        setLayout->addWidget(label);

        cellsControl = new QSpinBox(layoutWidget);
        cellsControl->setObjectName(QStringLiteral("cellsControl"));
        cellsControl->setMinimum(5);
        cellsControl->setMaximum(100);
        cellsControl->setValue(50);

        setLayout->addWidget(cellsControl);

        cellsSlider = new QSlider(layoutWidget);
        cellsSlider->setObjectName(QStringLiteral("cellsSlider"));
        cellsSlider->setMinimum(5);
        cellsSlider->setMaximum(100);
        cellsSlider->setSliderPosition(50);
        cellsSlider->setOrientation(Qt::Horizontal);

        setLayout->addWidget(cellsSlider);

        label2 = new QLabel(layoutWidget);
        label2->setObjectName(QStringLiteral("label2"));

        setLayout->addWidget(label2);

        iterInterval = new QSpinBox(layoutWidget);
        iterInterval->setObjectName(QStringLiteral("iterInterval"));
        iterInterval->setMinimum(20);
        iterInterval->setMaximum(1000);
        iterInterval->setSingleStep(10);
        iterInterval->setValue(100);

        setLayout->addWidget(iterInterval);

        iterSlider = new QSlider(layoutWidget);
        iterSlider->setObjectName(QStringLiteral("iterSlider"));
        iterSlider->setMinimum(20);
        iterSlider->setMaximum(1000);
        iterSlider->setSingleStep(10);
        iterSlider->setSliderPosition(100);
        iterSlider->setOrientation(Qt::Horizontal);

        setLayout->addWidget(iterSlider);

        redLimitLabel = new QLabel(layoutWidget);
        redLimitLabel->setObjectName(QStringLiteral("redLimitLabel"));

        setLayout->addWidget(redLimitLabel);

        redLimitSpin = new QSpinBox(layoutWidget);
        redLimitSpin->setObjectName(QStringLiteral("redLimitSpin"));
        redLimitSpin->setMinimum(1);
        redLimitSpin->setMaximum(200);
        redLimitSpin->setValue(20);

        setLayout->addWidget(redLimitSpin);

        redLimitSlider = new QSlider(layoutWidget);
        redLimitSlider->setObjectName(QStringLiteral("redLimitSlider"));
        redLimitSlider->setMinimum(1);
        redLimitSlider->setMaximum(200);
        redLimitSlider->setValue(20);
        redLimitSlider->setOrientation(Qt::Horizontal);
        redLimitSlider->setInvertedAppearance(false);
        redLimitSlider->setInvertedControls(false);
        redLimitSlider->setTickPosition(QSlider::NoTicks);

        setLayout->addWidget(redLimitSlider);

        fileLayout = new QHBoxLayout();
        fileLayout->setSpacing(6);
        fileLayout->setObjectName(QStringLiteral("fileLayout"));
        loadButton = new QPushButton(layoutWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        fileLayout->addWidget(loadButton);

        saveButton = new QPushButton(layoutWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        fileLayout->addWidget(saveButton);


        setLayout->addLayout(fileLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        setLayout->addItem(verticalSpacer);

        statsLayout = new QHBoxLayout();
        statsLayout->setSpacing(6);
        statsLayout->setObjectName(QStringLiteral("statsLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        statsLayout->addItem(horizontalSpacer);

        labelsBox = new QGroupBox(layoutWidget);
        labelsBox->setObjectName(QStringLiteral("labelsBox"));
        verticalLayout_3 = new QVBoxLayout(labelsBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        stAllLab = new QLabel(labelsBox);
        stAllLab->setObjectName(QStringLiteral("stAllLab"));

        verticalLayout_3->addWidget(stAllLab);

        stBlackLab = new QLabel(labelsBox);
        stBlackLab->setObjectName(QStringLiteral("stBlackLab"));

        verticalLayout_3->addWidget(stBlackLab);

        stGreenLab = new QLabel(labelsBox);
        stGreenLab->setObjectName(QStringLiteral("stGreenLab"));

        verticalLayout_3->addWidget(stGreenLab);

        stRedLab = new QLabel(labelsBox);
        stRedLab->setObjectName(QStringLiteral("stRedLab"));

        verticalLayout_3->addWidget(stRedLab);


        statsLayout->addWidget(labelsBox);

        statsBox = new QGroupBox(layoutWidget);
        statsBox->setObjectName(QStringLiteral("statsBox"));
        verticalLayout_2 = new QVBoxLayout(statsBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        stAll = new QLabel(statsBox);
        stAll->setObjectName(QStringLiteral("stAll"));
        stAll->setMinimumSize(QSize(34, 17));
        stAll->setMaximumSize(QSize(34, 17));

        verticalLayout_2->addWidget(stAll);

        stBlack = new QLabel(statsBox);
        stBlack->setObjectName(QStringLiteral("stBlack"));
        stBlack->setMinimumSize(QSize(34, 17));
        stBlack->setMaximumSize(QSize(34, 17));

        verticalLayout_2->addWidget(stBlack);

        stGreen = new QLabel(statsBox);
        stGreen->setObjectName(QStringLiteral("stGreen"));
        stGreen->setMinimumSize(QSize(34, 17));
        stGreen->setMaximumSize(QSize(34, 17));

        verticalLayout_2->addWidget(stGreen);

        stRed = new QLabel(statsBox);
        stRed->setObjectName(QStringLiteral("stRed"));
        stRed->setMinimumSize(QSize(34, 17));
        stRed->setMaximumSize(QSize(34, 17));

        verticalLayout_2->addWidget(stRed);


        statsLayout->addWidget(statsBox);


        setLayout->addLayout(statsLayout);


        mainLayout->addLayout(setLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Evolution v 0.1", 0));
        startButton->setText(QApplication::translate("MainWindow", "Start", 0));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", 0));
        label->setText(QApplication::translate("MainWindow", "Universe Size", 0));
        cellsControl->setSuffix(QApplication::translate("MainWindow", " cells", 0));
        label2->setText(QApplication::translate("MainWindow", "Generation interval (in msec)", 0));
        iterInterval->setSuffix(QApplication::translate("MainWindow", " ms", 0));
        redLimitLabel->setText(QApplication::translate("MainWindow", "Red Hungry Limit (turns to die)", 0));
        loadButton->setText(QApplication::translate("MainWindow", "Load", 0));
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0));
        labelsBox->setTitle(QApplication::translate("MainWindow", "Color", 0));
        stAllLab->setText(QApplication::translate("MainWindow", "All", 0));
        stBlackLab->setText(QApplication::translate("MainWindow", "Black", 0));
        stGreenLab->setText(QApplication::translate("MainWindow", "Green", 0));
        stRedLab->setText(QApplication::translate("MainWindow", "Red", 0));
        statsBox->setTitle(QApplication::translate("MainWindow", "Now", 0));
        stAll->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        stBlack->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        stGreen->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        stRed->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
