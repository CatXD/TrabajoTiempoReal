#ifndef EVENTO_PARAR_H
#define EVENTO_PARAR_H

#include <QEvent>

class	Evento_PARAR	:	public	QEvent
{
public:
    Evento_PARAR(): QEvent(QEvent::Type(QEvent::User+1)){}

};
#endif // EVENTO_PARAR_H
