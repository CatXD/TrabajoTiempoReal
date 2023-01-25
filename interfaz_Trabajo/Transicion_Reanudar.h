#ifndef TRANSICION_REANUDAR_H
#define TRANSICION_REANUDAR_H
#include <QAbstractTransition>
#include <QEvent>

class	Transicion_Reanudar	:	public	QAbstractTransition		//Clase	transición	propia
{
public:
     Transicion_Reanudar()	{}
protected:
    virtual	bool	eventTest(QEvent	*e)	const
    {
        if	(e->type()	!=	QEvent::Type(QEvent::User+2))
             return	false;

        return	true;
    }
    virtual	void	onTransition(QEvent	*)	{}
};
#endif // TRANSICION_REANUDAR_H
