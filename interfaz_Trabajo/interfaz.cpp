#include "interfaz.h"
#include "ui_interfaz.h"
#include <string>

#include <stdlib.h>
#include <iostream>
using   namespace std;

//MODIFICABLE
Interfaz::Interfaz(uint8_t modo, QWidget *parent) : QMainWindow (parent),
    ui(new Ui::Interfaz),
    modo_control_(modo)
{

    ui->setupUi(this);
    modo_control_ = MODO_CONTROL_VEL;

    setEnabledControlVel(true);
    setEnabledControlPos(false);
    setInitialParameters();

    settingAreaGraphComun();
    settingAreaGraphVel();
}

void Interfaz::settingAreaGraphComun(){
    areaGrafica = ui->widgetChart;
    grafica1_= new QChart();         // objeto de gráfico
    areaGrafica->setChart(grafica1_);
    grafica1_->createDefaultAxes();

    serie1 = new QLineSeries();
    serie2= new QLineSeries();

    grafica1_->addSeries(serie1);
    grafica1_->addSeries(serie2);

    ejeX = new QValueAxis();    // Línea de tiempo
    ejeYLeft = new QValueAxis();   // Eje Y a la izquierda
    grafica1_->addAxis(ejeX, Qt::AlignBottom);
    grafica1_->addAxis(ejeYLeft, Qt::AlignLeft);

    serie1->attachAxis(ejeX);
    serie1->attachAxis(ejeYLeft);
    serie2->attachAxis(ejeX);
    serie2->attachAxis(ejeYLeft);

    serie1->append(0, 0);
    serie2->append(0 , 0);
}

void Interfaz::settingAreaGraphVel() {
    minAxeY_=0;
    maxAxeY_=0;

    ejeX->setTitleText("Tiempo s");
    ejeX->setRange(0, 10);
    ejeX->setTickCount(11);// Division cuadrículas

    ejeYLeft->setTitleText("Velocidad rpm");
    ejeYLeft->setRange(0,1);
    ejeYLeft->setTickCount(9);

    serie1->setName("Velocidad ");
    serie2->setName("Ref Velocidad");
    grafica1_->setTitle("Gráfica control de velocidad");
}

void Interfaz::settingAreaGraphPos(){
    minAxeY_=0;
    maxAxeY_=0;

    ejeX->setTitleText("Tiempo s");
    ejeX->setRange(0, 10);
    ejeX->setTickCount(11);

    ejeYLeft->setTitleText("Posicion º");
    ejeYLeft->setRange(0,1);
    ejeYLeft->setTickCount(9);

    serie1->setName("Posición");
    serie2->setName("Ref Posición");
    grafica1_->setTitle("Gráfica control de posición");
}

void Interfaz::setEnabledControlPos(bool estado) {    // COMPLETO
    ui->labelControlPos->setEnabled(estado);
    ui->sbCPosicionKp->setEnabled(estado);
    ui->sbCPosicionKi->setEnabled(estado);
    ui->sbCPosicionKd->setEnabled(estado);
    ui->labelKpPos->setEnabled(estado);
    ui->labelKiPos->setEnabled(estado);
    ui->labelKdPos->setEnabled(estado);
    if ( estado){
        ui->dialRefVelPos->setRange(POS_MIN,POS_MAX);
    ui->dialRefVelPos->update();
    }
}

void Interfaz::setEnabledControlVel(bool estado) {   // COMPLETO
    ui->labelControlVel->setEnabled(estado);
    ui->sbCVelocidadKp->setEnabled(estado);
    ui->sbCVelocidadKi->setEnabled(estado);
    ui->sbCVelocidadKd->setEnabled(estado);
    ui->labelKpVel->setEnabled(estado);
    ui->labelKiVel->setEnabled(estado);
    ui->labelKdVel->setEnabled(estado);
        if (estado) {

      ui->dialRefVelPos->setRange(VEL_MIN,VEL_MAX);
        ui->dialRefVelPos->update();

    }

}

void Interfaz::setInitialParameters(){   // COMPLETO
    ui->sbCVelocidadKp->setValue(CONTROL_VELKP);
    ui->sbCVelocidadKi->setValue(CONTROL_VELKI);
    ui->sbCVelocidadKd->setValue(CONTROL_VELKD);
    ui->sbCPosicionKp->setValue(CONTROL_POSKP);
    ui->sbCPosicionKi->setValue(CONTROL_POSKI);
    ui->sbCPosicionKd->setValue(CONTROL_POSKD);

    /// Parámetros velocidad
    ui->dialRefVelPos->setMinimum(VEL_MIN);
    ui->dialRefVelPos->setMaximum(VEL_MAX);
    ui->dialRefVelPos->setValue(0);

    // Rueda velocidad real.
    ui->dialVelocidad->setMinimum(VEL_MIN);
    ui->dialVelocidad->setMaximum(VEL_MAX);
    ui->dialVelocidad->setValue(0);
    // Rueda posición real.
    ui->dialPosicion->setMinimum(POS_MIN);
    ui->dialPosicion->setMaximum(POS_MAX);
    ui->dialPosicion->setValue(0);
}


Interfaz::~Interfaz()
{
    delete ui;
}

void Interfaz::muestraDatoSlot(double t, double ref, double y)
{
    repaintPlot(t, ref, y);
    if ( modo_control_ == MODO_CONTROL_VEL){
           ui->dialVelocidad->setValue(y);
    }
    else{
    ui->dialPosicion->setValue(y);
    }
}


void Interfaz::repaintPlot(double tiempo, double ref,  double y)
{
    if (ref> maxAxeY_) maxAxeY_= ref;
    if (y> maxAxeY_) maxAxeY_= y;

    if (ref <  minAxeY_) minAxeY_= ref;
    if (y < minAxeY_) minAxeY_= y;

    ejeYLeft->setRange(minAxeY_,maxAxeY_);

    if(tiempo > 10) {
        ejeX->setRange(tiempo - 10, tiempo);
    }
    serie1->append(tiempo, y);
    serie2->append(tiempo, ref);
}


void Interfaz::on_botonParar_clicked()   //A  RELLENAR
{
    cout << "el sistema deberia parar manteniendo el estado"<<endl;
}

void Interfaz::on_botonReanudar_clicked()  //A  RELLENAR
{
    cout << "el sistema deberia reanudarse según el estado anterior" << endl;
}

 void Interfaz::on_botonFinalizar_clicked()
{
    exit(0);
}


void Interfaz::on_botonSetReferencia_clicked()  //A  RELLENAR
{

}

void Interfaz::on_botonSetParametros_clicked()   //A RELLENAR
{
    double Kp, Ki, Kd;
    if (modo_control_ == MODO_CONTROL_VEL ) {
        Kp = ui->sbCVelocidadKp->value();
        Ki = ui->sbCVelocidadKi->value();
        Kd = ui->sbCVelocidadKd->value();
    }
    else {
        Kp = ui->sbCPosicionKp->value();
        Ki = ui->sbCPosicionKi->value();
        Kd = ui->sbCPosicionKd->value();
    }
}

void Interfaz::on_toggleModoControl_clicked()   //COMPLETO
{
    modo_control_ = modo_control_ ^1;
    if (modo_control_ == MODO_CONTROL_VEL ) {
        setEnabledControlPos(false);
        setEnabledControlVel (true);
        settingAreaGraphVel();
    }
    else {
        setEnabledControlPos(true);
        setEnabledControlVel (false);
        settingAreaGraphPos();
    }
}

int Interfaz::getModoControl()  {   //COMPLETO PERO MEJOR CAMBIAR LA ESTRATEGIA
    return modo_control_;
}

void Interfaz::on_dialVelocidad_valueChanged(int value)
{
    ui->labelValueVel->setNum(value);
}

void Interfaz::on_dialPosicion_valueChanged(int value)
{
       ui->labelValuePos->setNum(value);
}
