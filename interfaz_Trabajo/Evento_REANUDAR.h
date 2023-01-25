#ifndef EVENTO_REANUDAR_H
#define EVENTO_REANUDAR_H

#include <QEvent>

class	Evento_REANUDAR	:	public	QEvent
{
public:
    Evento_REANUDAR(): QEvent(QEvent::Type(QEvent::User+2)){}

};
#endif // EVENTO_REANUDAR_H
