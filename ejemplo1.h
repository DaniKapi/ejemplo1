#ifndef ejemplo1_H
#define ejemplo1_H

#include <QtGui>
#include "ui_counterDlg.h"
#include "myqtimer.h"

class ejemplo1 : public QWidget, public Ui_Counter
{
Q_OBJECT
public:
    ejemplo1();
    virtual ~ejemplo1();
    
private:
    MyQTimer timer;
    int contador;
    int hz;
    
public slots:
	void doStart();
	void doReset();
	void doChangeHz();
	void doIncreaseNumber();

};

#endif // ejemplo1_H
