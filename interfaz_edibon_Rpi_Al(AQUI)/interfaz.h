#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QPlainTextEdit>
#include <QTimer>
#include <QCloseEvent>
#include <stdint.h>
#include "qcustomplot.h"
#include "controladormotor.h"
#include "ui_interfaz.h"




namespace Ui {
class Interfaz;
}

class Interfaz : public QMainWindow
{
    Q_OBJECT

public:
    ControladorMotor *controlador = nullptr;
    explicit Interfaz(uint8_t modo=MODO_CONTROL_VEL, QWidget *parent = nullptr, ControladorMotor *ctrl = nullptr);
    ~Interfaz();
    int getModoControl();
    ControladorMotor * getControlMotor(){return controlador;}
    Ui::Interfaz *ui;

public slots:
    void muestraDatoSlot(double t, double ref, double u, double y);

private:
    uint8_t modo_control_;
    QTimer *timerDibujo;
    double minAxeY;
    double maxAxeY;

    void repaintPlot(double tiempo, double ref, double u, double y);
    void settingAreaGraph();
    void settingAreaGraphVel();
    void settingAreaGraphPos();
    void setEnabledControlPos(bool);
    void setEnabledControlVel(bool);
    void setInitialParameters();


private slots:
    void on_botonParar_clicked();
    void on_botonReanudar_clicked();
    void on_botonFinalizar_clicked();
    void on_botonSetReferencia_clicked();
    void on_botonSetParametros_clicked();
    void on_toggleModoControl_clicked();
    void on_dVelocidad_valueChanged(int value);
    void on_dPosicion_valueChanged(int value);
    void onTimeout(void);
    void on_bSetPeriodo_clicked();
};

#endif // INTERFAZ_H
