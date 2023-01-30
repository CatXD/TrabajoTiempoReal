/********************************************************************************
** Form generated from reading UI file 'interfaz.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFAZ_H
#define UI_INTERFAZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Interfaz
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QCustomPlot *plot;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QPushButton *botonParar;
    QSpacerItem *verticalSpacer;
    QPushButton *botonReanudar;
    QSpacerItem *verticalSpacer_2;
    QPushButton *botonFinalizar;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *toggleModoControl;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelControlVel;
    QFrame *line_2;
    QLabel *labelControlPos;
    QGridLayout *gridLayout;
    QLabel *labelKpVel;
    QDoubleSpinBox *sbCVelocidadKp;
    QLabel *labelKiVel;
    QDoubleSpinBox *sbCVelocidadKi;
    QLabel *labelKdVel;
    QDoubleSpinBox *sbCVelocidadKd;
    QGridLayout *gridLayout_2;
    QLabel *labelKpPos;
    QDoubleSpinBox *sbCPosicionKp;
    QLabel *labelKiPos;
    QDoubleSpinBox *sbCPosicionKi;
    QLabel *labelKdPos;
    QDoubleSpinBox *sbCPosicionKd;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *botonSetParametros;
    QSpacerItem *horizontalSpacer_8;
    QPlainTextEdit *ptLog;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *bSetPeriodo;
    QDoubleSpinBox *sbRepaintInterval;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_9;
    QLabel *labelRefVelPos;
    QDial *dialRefVelPos;
    QLabel *labelUnidadesVelPos;
    QLabel *labelValueRefVelPos;
    QPushButton *botonSetReferencia;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelUnidadesVel;
    QLabel *labelValueVel;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelUnidadesPos;
    QLabel *labelValuePos;
    QHBoxLayout *horizontalLayout;
    QDial *dVelocidad;
    QDial *dPosicion;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelRangoVel;
    QLabel *labelRangoPos;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Interfaz)
    {
        if (Interfaz->objectName().isEmpty())
            Interfaz->setObjectName(QStringLiteral("Interfaz"));
        Interfaz->resize(935, 861);
        centralwidget = new QWidget(Interfaz);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QStringLiteral("plot"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(plot, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        botonParar = new QPushButton(centralwidget);
        botonParar->setObjectName(QStringLiteral("botonParar"));
        QPalette palette;
        QBrush brush(QColor(170, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        botonParar->setPalette(palette);

        verticalLayout->addWidget(botonParar);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        botonReanudar = new QPushButton(centralwidget);
        botonReanudar->setObjectName(QStringLiteral("botonReanudar"));
        QPalette palette1;
        QBrush brush2(QColor(0, 0, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        botonReanudar->setPalette(palette1);

        verticalLayout->addWidget(botonReanudar);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        botonFinalizar = new QPushButton(centralwidget);
        botonFinalizar->setObjectName(QStringLiteral("botonFinalizar"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        QBrush brush4(QColor(185, 185, 185, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush4);
        QBrush brush5(QColor(154, 154, 154, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        QBrush brush6(QColor(61, 61, 61, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush6);
        QBrush brush7(QColor(82, 82, 82, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        QBrush brush8(QColor(0, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush8);
        QBrush brush9(QColor(123, 123, 123, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        QBrush brush10(QColor(255, 255, 220, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush8);
        botonFinalizar->setPalette(palette2);

        verticalLayout->addWidget(botonFinalizar);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        toggleModoControl = new QPushButton(centralwidget);
        toggleModoControl->setObjectName(QStringLiteral("toggleModoControl"));
        sizePolicy.setHeightForWidth(toggleModoControl->sizePolicy().hasHeightForWidth());
        toggleModoControl->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(toggleModoControl, 0, 1, 1, 5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 6, 1, 1);

        labelControlVel = new QLabel(centralwidget);
        labelControlVel->setObjectName(QStringLiteral("labelControlVel"));
        labelControlVel->setEnabled(false);

        gridLayout_3->addWidget(labelControlVel, 1, 0, 1, 3);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 1, 3, 2, 1);

        labelControlPos = new QLabel(centralwidget);
        labelControlPos->setObjectName(QStringLiteral("labelControlPos"));
        labelControlPos->setEnabled(false);
        sizePolicy.setHeightForWidth(labelControlPos->sizePolicy().hasHeightForWidth());
        labelControlPos->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(labelControlPos, 1, 4, 1, 3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelKpVel = new QLabel(centralwidget);
        labelKpVel->setObjectName(QStringLiteral("labelKpVel"));
        labelKpVel->setEnabled(false);

        gridLayout->addWidget(labelKpVel, 0, 0, 1, 1);

        sbCVelocidadKp = new QDoubleSpinBox(centralwidget);
        sbCVelocidadKp->setObjectName(QStringLiteral("sbCVelocidadKp"));
        sbCVelocidadKp->setEnabled(false);

        gridLayout->addWidget(sbCVelocidadKp, 0, 1, 1, 1);

        labelKiVel = new QLabel(centralwidget);
        labelKiVel->setObjectName(QStringLiteral("labelKiVel"));
        labelKiVel->setEnabled(false);

        gridLayout->addWidget(labelKiVel, 1, 0, 1, 1);

        sbCVelocidadKi = new QDoubleSpinBox(centralwidget);
        sbCVelocidadKi->setObjectName(QStringLiteral("sbCVelocidadKi"));
        sbCVelocidadKi->setEnabled(false);

        gridLayout->addWidget(sbCVelocidadKi, 1, 1, 1, 1);

        labelKdVel = new QLabel(centralwidget);
        labelKdVel->setObjectName(QStringLiteral("labelKdVel"));
        labelKdVel->setEnabled(false);

        gridLayout->addWidget(labelKdVel, 2, 0, 1, 1);

        sbCVelocidadKd = new QDoubleSpinBox(centralwidget);
        sbCVelocidadKd->setObjectName(QStringLiteral("sbCVelocidadKd"));
        sbCVelocidadKd->setEnabled(false);

        gridLayout->addWidget(sbCVelocidadKd, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 2, 0, 1, 3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        labelKpPos = new QLabel(centralwidget);
        labelKpPos->setObjectName(QStringLiteral("labelKpPos"));

        gridLayout_2->addWidget(labelKpPos, 0, 0, 1, 1);

        sbCPosicionKp = new QDoubleSpinBox(centralwidget);
        sbCPosicionKp->setObjectName(QStringLiteral("sbCPosicionKp"));

        gridLayout_2->addWidget(sbCPosicionKp, 0, 1, 1, 1);

        labelKiPos = new QLabel(centralwidget);
        labelKiPos->setObjectName(QStringLiteral("labelKiPos"));

        gridLayout_2->addWidget(labelKiPos, 1, 0, 1, 1);

        sbCPosicionKi = new QDoubleSpinBox(centralwidget);
        sbCPosicionKi->setObjectName(QStringLiteral("sbCPosicionKi"));

        gridLayout_2->addWidget(sbCPosicionKi, 1, 1, 1, 1);

        labelKdPos = new QLabel(centralwidget);
        labelKdPos->setObjectName(QStringLiteral("labelKdPos"));

        gridLayout_2->addWidget(labelKdPos, 2, 0, 1, 1);

        sbCPosicionKd = new QDoubleSpinBox(centralwidget);
        sbCPosicionKd->setObjectName(QStringLiteral("sbCPosicionKd"));

        gridLayout_2->addWidget(sbCPosicionKd, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 2, 4, 1, 3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 3, 0, 1, 2);

        botonSetParametros = new QPushButton(centralwidget);
        botonSetParametros->setObjectName(QStringLiteral("botonSetParametros"));

        gridLayout_3->addWidget(botonSetParametros, 3, 2, 1, 3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 3, 5, 1, 2);


        horizontalLayout_5->addLayout(gridLayout_3);


        gridLayout_4->addLayout(horizontalLayout_5, 1, 1, 1, 2);

        ptLog = new QPlainTextEdit(centralwidget);
        ptLog->setObjectName(QStringLiteral("ptLog"));

        gridLayout_4->addWidget(ptLog, 1, 4, 2, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        bSetPeriodo = new QPushButton(centralwidget);
        bSetPeriodo->setObjectName(QStringLiteral("bSetPeriodo"));

        horizontalLayout_6->addWidget(bSetPeriodo);

        sbRepaintInterval = new QDoubleSpinBox(centralwidget);
        sbRepaintInterval->setObjectName(QStringLiteral("sbRepaintInterval"));
        sbRepaintInterval->setDecimals(0);
        sbRepaintInterval->setMinimum(10);
        sbRepaintInterval->setMaximum(10000);
        sbRepaintInterval->setValue(50);

        horizontalLayout_6->addWidget(sbRepaintInterval);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_6->addWidget(label_12);


        gridLayout_4->addLayout(horizontalLayout_6, 0, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_9);

        labelRefVelPos = new QLabel(centralwidget);
        labelRefVelPos->setObjectName(QStringLiteral("labelRefVelPos"));
        labelRefVelPos->setTextFormat(Qt::AutoText);
        labelRefVelPos->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelRefVelPos);

        dialRefVelPos = new QDial(centralwidget);
        dialRefVelPos->setObjectName(QStringLiteral("dialRefVelPos"));
        dialRefVelPos->setEnabled(true);
        dialRefVelPos->setFocusPolicy(Qt::WheelFocus);
        dialRefVelPos->setMinimum(0);
        dialRefVelPos->setMaximum(1022);
        dialRefVelPos->setSingleStep(10);
        dialRefVelPos->setValue(650);
        dialRefVelPos->setTracking(false);
        dialRefVelPos->setWrapping(false);
        dialRefVelPos->setNotchTarget(3.7);
        dialRefVelPos->setNotchesVisible(false);

        verticalLayout_2->addWidget(dialRefVelPos);

        labelUnidadesVelPos = new QLabel(centralwidget);
        labelUnidadesVelPos->setObjectName(QStringLiteral("labelUnidadesVelPos"));
        labelUnidadesVelPos->setTextFormat(Qt::AutoText);
        labelUnidadesVelPos->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelUnidadesVelPos);

        labelValueRefVelPos = new QLabel(centralwidget);
        labelValueRefVelPos->setObjectName(QStringLiteral("labelValueRefVelPos"));
        labelValueRefVelPos->setTextFormat(Qt::AutoText);
        labelValueRefVelPos->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelValueRefVelPos);

        botonSetReferencia = new QPushButton(centralwidget);
        botonSetReferencia->setObjectName(QStringLiteral("botonSetReferencia"));

        verticalLayout_2->addWidget(botonSetReferencia);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        labelUnidadesVel = new QLabel(centralwidget);
        labelUnidadesVel->setObjectName(QStringLiteral("labelUnidadesVel"));
        labelUnidadesVel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelUnidadesVel);

        labelValueVel = new QLabel(centralwidget);
        labelValueVel->setObjectName(QStringLiteral("labelValueVel"));
        labelValueVel->setTextFormat(Qt::AutoText);
        labelValueVel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelValueVel);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        labelUnidadesPos = new QLabel(centralwidget);
        labelUnidadesPos->setObjectName(QStringLiteral("labelUnidadesPos"));
        labelUnidadesPos->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(labelUnidadesPos);

        labelValuePos = new QLabel(centralwidget);
        labelValuePos->setObjectName(QStringLiteral("labelValuePos"));
        labelValuePos->setTextFormat(Qt::AutoText);
        labelValuePos->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(labelValuePos);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dVelocidad = new QDial(centralwidget);
        dVelocidad->setObjectName(QStringLiteral("dVelocidad"));
        dVelocidad->setEnabled(true);
        sizePolicy.setHeightForWidth(dVelocidad->sizePolicy().hasHeightForWidth());
        dVelocidad->setSizePolicy(sizePolicy);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        QBrush brush11(QColor(170, 255, 255, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush12(QColor(212, 255, 255, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush12);
        QBrush brush13(QColor(85, 127, 127, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush13);
        QBrush brush14(QColor(113, 170, 170, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush14);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush14);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush8);
        dVelocidad->setPalette(palette3);
        dVelocidad->setMinimum(-45);
        dVelocidad->setMaximum(45);
        dVelocidad->setTracking(false);
        dVelocidad->setWrapping(false);
        dVelocidad->setNotchesVisible(false);

        horizontalLayout->addWidget(dVelocidad);

        dPosicion = new QDial(centralwidget);
        dPosicion->setObjectName(QStringLiteral("dPosicion"));
        dPosicion->setEnabled(true);
        sizePolicy.setHeightForWidth(dPosicion->sizePolicy().hasHeightForWidth());
        dPosicion->setSizePolicy(sizePolicy);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush12);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush13);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush14);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush13);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush14);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush8);
        dPosicion->setPalette(palette4);
        dPosicion->setMinimum(-180);
        dPosicion->setMaximum(180);
        dPosicion->setTracking(false);
        dPosicion->setWrapping(false);
        dPosicion->setNotchesVisible(false);

        horizontalLayout->addWidget(dPosicion);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        labelRangoVel = new QLabel(centralwidget);
        labelRangoVel->setObjectName(QStringLiteral("labelRangoVel"));
        labelRangoVel->setTextFormat(Qt::AutoText);
        labelRangoVel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelRangoVel);

        labelRangoPos = new QLabel(centralwidget);
        labelRangoPos->setObjectName(QStringLiteral("labelRangoPos"));
        labelRangoPos->setTextFormat(Qt::AutoText);
        labelRangoPos->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelRangoPos);


        verticalLayout_5->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_5);


        gridLayout_4->addLayout(horizontalLayout_4, 2, 0, 1, 4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 1, 3, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 1, 0, 1, 1);

        Interfaz->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Interfaz);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 935, 28));
        Interfaz->setMenuBar(menubar);
        statusbar = new QStatusBar(Interfaz);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Interfaz->setStatusBar(statusbar);

        retranslateUi(Interfaz);
        QObject::connect(dialRefVelPos, SIGNAL(valueChanged(int)), labelRefVelPos, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(Interfaz);
    } // setupUi

    void retranslateUi(QMainWindow *Interfaz)
    {
        Interfaz->setWindowTitle(QApplication::translate("Interfaz", "MainWindow", nullptr));
        botonParar->setText(QApplication::translate("Interfaz", "PARAR", nullptr));
        botonReanudar->setText(QApplication::translate("Interfaz", "REANUDAR", nullptr));
        botonFinalizar->setText(QApplication::translate("Interfaz", "FINALIZAR", nullptr));
        toggleModoControl->setText(QApplication::translate("Interfaz", "CVelocidad / CPosici\303\263n", nullptr));
        labelControlVel->setText(QApplication::translate("Interfaz", "CONTROL VEL.", nullptr));
        labelControlPos->setText(QApplication::translate("Interfaz", "CONTROL POS.", nullptr));
        labelKpVel->setText(QApplication::translate("Interfaz", "Kp", nullptr));
        labelKiVel->setText(QApplication::translate("Interfaz", "Ki", nullptr));
        labelKdVel->setText(QApplication::translate("Interfaz", "Kd", nullptr));
        labelKpPos->setText(QApplication::translate("Interfaz", "Kp", nullptr));
        labelKiPos->setText(QApplication::translate("Interfaz", "Ki", nullptr));
        labelKdPos->setText(QApplication::translate("Interfaz", "Kd", nullptr));
        botonSetParametros->setText(QApplication::translate("Interfaz", "Modif. Param.", nullptr));
        bSetPeriodo->setText(QApplication::translate("Interfaz", "Modif. T", nullptr));
        label_12->setText(QApplication::translate("Interfaz", "ms", nullptr));
        label_9->setText(QApplication::translate("Interfaz", "REFERENCIA VEL./POS.", nullptr));
        labelRefVelPos->setText(QApplication::translate("Interfaz", "0rpm / 0\302\272", nullptr));
        labelUnidadesVelPos->setText(QApplication::translate("Interfaz", "rpm/grados", nullptr));
        labelValueRefVelPos->setText(QApplication::translate("Interfaz", "-46..42 rpm / 180\302\252", nullptr));
        botonSetReferencia->setText(QApplication::translate("Interfaz", "Modif. Vel./Pos.", nullptr));
        labelUnidadesVel->setText(QApplication::translate("Interfaz", "VELOCIDAD (rpm)", nullptr));
        labelValueVel->setText(QApplication::translate("Interfaz", "0", nullptr));
        labelUnidadesPos->setText(QApplication::translate("Interfaz", "POSICI\303\223N (\302\272)", nullptr));
        labelValuePos->setText(QApplication::translate("Interfaz", "0", nullptr));
        labelRangoVel->setText(QApplication::translate("Interfaz", "-45/45", nullptr));
        labelRangoPos->setText(QApplication::translate("Interfaz", "-180/180", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Interfaz: public Ui_Interfaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFAZ_H
