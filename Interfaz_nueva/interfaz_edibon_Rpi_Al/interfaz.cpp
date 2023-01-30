#include "interfaz.h"
#include "ui_interfaz.h"

#include <string>

#include <stdlib.h>
#include <iostream>
using   namespace std;

//MODIFICABLE
Interfaz::Interfaz(uint8_t modo, QWidget *parent, ControladorMotor *ctrl) : QMainWindow (parent),
    ui(new Ui::Interfaz),
    modo_control_(modo)
{
    minAxeY=0;
    maxAxeY=0;

    /// Inicialización de elementos de interfaz.ui
    ui->setupUi(this);
    controlador = ctrl;
    modo_control_ = MODO_CONTROL_VEL;
    setEnabledControlVel(true);
    setEnabledControlPos(false);
    settingAreaGraph();
    settingAreaGraphVel();
    setInitialParameters();
    timerDibujo = new (QTimer);
    connect (timerDibujo,SIGNAL(timeout()),this,SLOT(onTimeout()));
    timerDibujo->start(Tms);
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
    ui->dVelocidad->setMinimum(VEL_MIN);
    ui->dVelocidad->setMaximum(VEL_MAX);
    ui->dVelocidad->setValue(0);
    // Rueda posición real.
    ui->dPosicion->setMinimum(POS_MIN);
    ui->dPosicion->setMaximum(POS_MAX);
    ui->dPosicion->setValue(0);
}

void Interfaz::settingAreaGraph() {    // COMPLETO
    ui->plot->xAxis->setLabel("tiempo	s");
    ui->plot->legend->setVisible(true);
    ui->plot->legend->setFont(QFont("Helvetica",9));
    ui->plot->axisRect()->setupFullAxesBox();

    ui->plot->addGraph(ui->plot->xAxis,ui->plot->yAxis);
    ui->plot->graph(0)->setPen(QPen(Qt::blue));

    ui->plot->addGraph(ui->plot->xAxis,ui->plot->yAxis);
    ui->plot->graph(1)->setPen(QPen(Qt::red));

    ui->plot->addGraph(ui->plot->xAxis,ui->plot->yAxis);
    ui->plot->graph(2)->setPen(QPen(Qt::green));

    ui->plot->graph(0)->setName("Referencia	");
    ui->plot->graph(2)->setName("PID->u	");

    ui->plot->graph(0)->rescaleKeyAxis(true);
    ui->plot->graph(1)->rescaleKeyAxis(true);
    ui->plot->graph(2)->rescaleKeyAxis (true);

    ui->plot->graph(0)->setName("Referencia	");
    ui->plot->graph(2)->setName("PID->u	");
}

void Interfaz::settingAreaGraphVel() {    // COMPLETO
    ui->plot->yAxis->setLabel("Salida	rpm");
    ui->plot->graph(1)->setName("Salida rpm	");
}

void Interfaz::settingAreaGraphPos(){    // COMPLETO
    ui->plot->yAxis->setLabel("Salida	º");
    ui->plot->graph(1)->setName("Salida	º");
}

void Interfaz::setEnabledControlPos(bool estado) {    // COMPLETO
    ui->labelControlPos->setEnabled(estado);
    ui->sbCPosicionKp->setEnabled(estado);
    ui->sbCPosicionKi->setEnabled(estado);
    ui->sbCPosicionKd->setEnabled(estado);
    ui->labelKpPos->setEnabled(estado);
    ui->labelKiPos->setEnabled(estado);
    ui->labelKdPos->setEnabled(estado);
    if (modo_control_ == MODO_CONTROL_POS) {
        ui->dialRefVelPos->setRange(POS_MIN,POS_MAX);
        ui->dialRefVelPos->update();
        cout<<"el rango es"<< ui->dialRefVelPos->minimum() <<"  "<<
              ui->dialRefVelPos->maximum()<<endl;
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
    if (modo_control_ == MODO_CONTROL_VEL) {
        ui->dialRefVelPos->setRange(VEL_MIN,VEL_MAX);
        ui->dialRefVelPos->update();
        cout<<"el rango es"<< ui->dialRefVelPos->minimum() <<"  "<<
              ui->dialRefVelPos->maximum()<<endl;
    }
}

Interfaz::~Interfaz()
{
    delete ui;
}

void Interfaz::onTimeout(void){
    static double t=0;
    t= t + Tms /1000.0;
    cout<< "el tiempo es "<< t<< endl;
    if ( modo_control_ == MODO_CONTROL_VEL){
        muestraDatoSlot(t,controlador->reg_vel.get_consigna(), controlador->reg_vel.get_uk()/20,
                        controlador->reg_vel.get_y());
    }
    else{
        muestraDatoSlot(t,controlador->reg_pos.get_consigna(), controlador->reg_pos.get_uk()/20,
                        controlador->reg_pos.get_y());
    }
}
void Interfaz::muestraDatoSlot(double t, double ref, double u, double y)
{
    // Customplot
    repaintPlot(t, ref, u, y);
    if ( modo_control_ == MODO_CONTROL_VEL){
        ui->dVelocidad->setValue(y);
    }
    else{
        ui->dPosicion->setValue(y);
    }
}


void Interfaz::repaintPlot(double tiempo, double ref, double u, double y)
{

    if (ref> maxAxeY) maxAxeY= ref;
    if (y> maxAxeY) maxAxeY= y;
    if (u> maxAxeY) maxAxeY= u;

    if (ref <  minAxeY) minAxeY= ref;
    if (y < minAxeY) minAxeY= y;
    if (u < minAxeY) minAxeY= u;

    // añadir nuevos pares de datos al gráfico:
    ui->plot->graph(0)->addData(tiempo, ref);  // dibujar ref
    ui->plot->graph(1)->addData(tiempo, y);    // dibujar salida
    ui->plot->graph(2)->addData(tiempo, u);    // dibujar
    // Sin Reescalado de los ejes, la curva se comprime porque se
    // aumenta la ventana temporal
    ui->plot->graph(0)->rescaleAxes(true);
    ui->plot->graph(1)->rescaleAxes(true);
    ui->plot->graph(2)->rescaleAxes(true);

    ui->plot->xAxis->setRange(tiempo,10, Qt::AlignRight);
    ui->plot->yAxis->setRange ( minAxeY*1.1,maxAxeY*1.1);
    ui->plot->replot();
}


void Interfaz::on_botonParar_clicked()   //A  RELLENAR
{
    ui->ptLog->appendPlainText("El sistema se encuentra parado haciendo parpadear un LED");
}

void Interfaz::on_botonReanudar_clicked()  //A  RELLENAR
{
    ui->ptLog->appendPlainText("Se reanuda el control previo");
}

void Interfaz::on_botonFinalizar_clicked()
{
    exit(0);
}


void Interfaz::on_botonSetReferencia_clicked()  //A  RELLENAR
{
    if (modo_control_ == MODO_CONTROL_VEL ) {
        controlador->reg_vel.set_consigna(ui->dialRefVelPos->value());
    }
//    else {
//        controlador->reg_pos.set_consigna(ui->dialRefVelPos->value());
//    }
}

void Interfaz::on_botonSetParametros_clicked()   //A RELLENAR
{
    if (modo_control_ == MODO_CONTROL_VEL ) {
        controlador->reg_vel.set_KP(ui->sbCVelocidadKp->value());
        controlador->reg_vel.set_KI(ui->sbCVelocidadKi->value());
        controlador->reg_vel.set_KD(ui->sbCVelocidadKd->value());
    }
    else {
        controlador->reg_pos.set_KP(ui->sbCPosicionKp->value());
        controlador->reg_pos.set_KI(ui->sbCPosicionKi->value());
        controlador->reg_pos.set_KD(ui->sbCPosicionKd->value());
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
    minAxeY=0;
    maxAxeY=0;
}

int Interfaz::getModoControl()  {   //COMPLETO PERO MEJOR CAMBIAR LA ESTRATEGIA
    return modo_control_;
}

void Interfaz::on_dVelocidad_valueChanged(int value)
{
    ui->labelValueVel->setNum(value);
}

void Interfaz::on_dPosicion_valueChanged(int value)
{
    ui->labelValuePos->setNum(value);
}
void Interfaz::on_bSetPeriodo_clicked()
{
    if (modo_control_ == MODO_CONTROL_VEL ) {
        controlador->reg_vel.set_T(ui->sbRepaintInterval->value());
        QString mens = "El nuevo Tm (Control de velocidad) es de " + QString::number(ui->sbRepaintInterval->value());
        ui->ptLog->appendPlainText(mens);
    }
    else {
        controlador->reg_pos.set_T(ui->sbRepaintInterval->value());
        QString mens = "El nuevo Tm (Control de posicion) es de " + QString::number(ui->sbRepaintInterval->value());
        ui->ptLog->appendPlainText(mens);
    }
}
