#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter()
{
	setupUi(this);
	show();
	connect(buttonSTART, SIGNAL(clicked()), this, SLOT(doStart()) );
	connect(buttonRESET, SIGNAL(clicked()), this, SLOT(doReset()) );
	connect(slideHz, SIGNAL(sliderReleased()), this, SLOT(doChangeHz()) );
	connect(&timer, SIGNAL(mySignal()), this, SLOT(doIncreaseNumber()));
	contador = 0;
	hz = 1000;
	slideHz->setMinimum(100);
	slideHz->setMaximum(2000);
	slideHz->setValue(1000);
}

ejemplo1::~ejemplo1()
{
}

void ejemplo1::doStart()
{
	static int bandera = 0;
	if(bandera == 0){
	  timer.myStart(hz);
	  qDebug() << "Iniciando";
	  buttonSTART->setText("STOP");
	  bandera = 1;
	} else {
	   timer.myStop();
	   qDebug() << "Parando";
	   buttonSTART->setText("START");
	   bandera = 0;
	}
	
}

void ejemplo1::doReset()
{
  contador = 0;
  lcdNumber->display(contador);
}


void ejemplo1::doIncreaseNumber()
{
  lcdNumber->display(contador++);
}

void ejemplo1::doChangeHz()
{
  //hz = slideHz->value();
  //qDebug() << "Valor: "+hz;
  timer.myStart(slideHz->value());
}





