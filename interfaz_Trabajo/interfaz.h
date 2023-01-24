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
#include <QtCharts>
#include "controladormotor.h"


namespace Ui {
class Interfaz;
}

class Interfaz : public QMainWindow
{
    Q_OBJECT
    ControladorMotor *controlador = nullptr;


public:
    explicit Interfaz(uint8_t modo=MODO_CONTROL_VEL, QWidget *parent = nullptr, ControladorMotor *ctrl = nullptr);
    //explicit Interfaz(uint8_t modo=MODO_CONTROL_VEL, QWidget *parent = nullptr);
    ~Interfaz();
    int getModoControl();
    ControladorMotor * getControlMotor(){return controlador;};
    Ui::Interfaz *ui;

public slots:
    void muestraDatoSlot(double t, double ref,  double y);

private:
    QChartView *areaGrafica;
    QChart *grafica1_;
    QValueAxis* ejeX;// Línea de tiempo
    QValueAxis* ejeYLeft;// Eje Y a la izquierda

    QLineSeries* serie1; // Conjunto de datos de gráfico de líneas
    QLineSeries* serie2;

    QHBoxLayout *hbox;
    QElapsedTimer *tEjecucion;

    uint8_t modo_control_;
    double minAxeY_;
    double maxAxeY_;
    double tiempo_;

    void repaintPlot(double tiempo, double ref, double y);
    void settingAreaGraphComun();
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
    void on_dialVelocidad_valueChanged(int value);
    void on_dialPosicion_valueChanged(int value);
};

#endif // INTERFAZ_H
