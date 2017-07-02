#include "hexcalculator.h"
#include "ui_hexcalculator.h"


QString panel="";
QString operand1="";
QString operand2="";
QString lastoperator="";
QString result="";
bool check=0;

hexcalculator::hexcalculator():QWidget()
{
    ui.setupUi(this);

    connect(ui.a,SIGNAL(clicked()),this,SLOT(myadditem()));
    connect(ui.b,SIGNAL(clicked()),this,SLOT(myadditem()));
    connect(ui.c,SIGNAL(clicked()),this,SLOT(myadditem()));
    connect(ui.d,SIGNAL(clicked()),this,SLOT(myadditem()));
    connect(ui.e,SIGNAL(clicked()),this,SLOT(myadditem()));
    connect(ui.f,SIGNAL(clicked()),this,SLOT(myadditem()));
    connect(ui.Zero,SIGNAL(clicked()),this,SLOT(myadditem2()));
    connect(ui.One,SIGNAL(clicked()),this,SLOT(myadditem2()));
    connect(ui.Two,SIGNAL(clicked()),this,SLOT(myadditem2()));
    connect(ui.Three,SIGNAL(clicked()),this,SLOT(myadditem2()));
    connect(ui.Four,SIGNAL(clicked()),this,SLOT(myadditem2()));
    connect(ui.Five,SIGNAL(clicked()),this,SLOT(myadditem2()));
    connect(ui.Six,SIGNAL(clicked()),this,SLOT(myadditem2()));
    connect(ui.Seven,SIGNAL(clicked()),this,SLOT(myadditem2()));
    connect(ui.Eight,SIGNAL(clicked()),this,SLOT(myadditem2()));
    connect(ui.Nine,SIGNAL(clicked()),this,SLOT(myadditem2()));
    connect(ui.Plus,SIGNAL(clicked()),this,SLOT(Operator()));
    connect(ui.Minus,SIGNAL(clicked()),this,SLOT(Operator()));
    connect(ui.Equal,SIGNAL(clicked()),this,SLOT(Operator()));
    connect(ui.Clear,SIGNAL(clicked()),this,SLOT(Clear()));
}
void hexcalculator::myadditem(){
    QPushButton *clickedbutton=qobject_cast<QPushButton*>(sender());
    QString s;
    s = clickedbutton->objectName();
    panel=panel+s;
   if ( s.size() > 0) {
     ui.LCD->display(panel);
}
if(check==1){
    operand1="";
    check=0;
}
}
void hexcalculator::myadditem2(){
    QPushButton *clickedbutton=qobject_cast<QPushButton*>(sender());
    QString s;
    s = clickedbutton->text();
    panel=panel+s;
   if ( s.size() > 0) {
     ui.LCD->display(panel);
}
   if(check==1){
       operand1="";
       check=0;
   }

}

void hexcalculator::Clear(){
   panel="";
   ui.LCD->display("0");
   operand1="";
   operand2="";
   lastoperator="";
   result="";
   check=0;
}


void hexcalculator::Operator(){
    QPushButton *clickedoperator=qobject_cast<QPushButton*>(sender());
    QString ouroperator;
    ouroperator=clickedoperator->objectName();
    if(check==1){
        operand1=result;
        check=0;
    }
    if(lastoperator==""){
        if(operand1==""){
        lastoperator=ouroperator;
        if(panel==""){operand1="0";}
        else{
        operand1=panel;}
        panel="";}
        else{
            lastoperator=ouroperator;
            if(panel==""){operand2="0";}
            else{
            operand2=panel;}
            panel="";
        }
    }
    else{
        if(panel==""){operand2="0";}
        else{
        operand2=panel;}
        panel="";
        if(lastoperator=="Plus"){
            operand1=sumtwo(operand1,operand2);
            ui.LCD->display(operand1);
        }
        else if(lastoperator=="Minus"){
            operand1=subtracttwo(operand1,operand2);
             ui.LCD->display(operand1);
        }
        operand2="";
        lastoperator=clickedoperator->objectName();
        if(lastoperator=="Equal"){
            result=Equal(operand1);
            lastoperator="";
            check=1;
        }
    }
}



QString hexcalculator::Equal(QString o1){
    ui.LCD->display(o1);
    panel="";
    return o1;
}

QString hexcalculator::sumtwo(QString first, QString second){

    bool ok1,ok2;
    const long long a = first.toLongLong(&ok1, 16);
    const long long b = second.toLongLong(&ok2,16);
    if(ok1==false || ok2==false){
        QString returnthis2="ERROR";
        return returnthis2;
    }
    else{
    const long long c=a+b;
    if (c>=0){
    QString returnthis=QString::number(c,16);
    return returnthis;}
    else{
       const long long d = c*(-1);
       QString returnthis=QString::number(d,16);
       returnthis="-"+returnthis;
       return returnthis;
    }}
}


QString hexcalculator::subtracttwo(QString first, QString second){
    bool ok1,ok2;
    const long long a = first.toLongLong(&ok1, 16);
    const long long b = second.toLongLong(&ok2,16);
    if(ok1==false || ok2==false){
        QString returnthis2="ERROR";
        return returnthis2;
    }
    else{
    const long long c=a-b;
    if (c>=0){
    QString returnthis=QString::number(c,16);
    return returnthis;}
    else{
       const long long d = c*(-1);
       QString returnthis=QString::number(d,16);
       returnthis="-"+returnthis;
       return returnthis;
    }}
}


