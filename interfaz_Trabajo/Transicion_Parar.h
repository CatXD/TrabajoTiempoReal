#ifndef TRANSICION_PARAR_H
#define TRANSICION_PARAR_H
#include <QAbstractTransition>
#include <QEvent>


class	Transicion_Parar	:	public	QAbstractTransition		//Clase	transición	propia
{
public:
     Transicion_Parar()	{}
protected:
    virtual	bool	eventTest(QEvent	*e)	const
    {
        if	(e->type()	!=	QEvent::Type(QEvent::User+1))
             return	false;

        return	true;
    }
    virtual	void	onTransition(QEvent	*)	{}
};
#endif // TRANSICION_PARAR_H
