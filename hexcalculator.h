#include <QWidget>
#include "ui_hexcalculator.h"

class hexcalculator : public QWidget
{
  Q_OBJECT

  public:
    hexcalculator() ;
    QString sumtwo(QString a, QString b);
    QString subtracttwo(QString a,QString b);
    QString Equal(QString a);
  private slots:
    void myadditem() ;
    void myadditem2();
    void Operator();
    void Clear();


private:
    Ui::hexcalculator ui ;

} ;
