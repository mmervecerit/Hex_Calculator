CMPE230 Project3 - Hexadecimal Calculator Implementation with QT
Merve Cerit - Kubra Eryilmaz
2012402015 - 2014400186

-----HOW TO USE HEXCALCULATOR?-----

In this calculator,

One can add and subtract hexadecimal numbers.
One can consequently add or subtract numbers, while doing this she will see the result immediately even if she did not press =.
If she press =, she can continue with the last number she computed, or she can press a new number to proceed a new computation.
Clr button clears the panel,and computation history.
Also, unary minus is welcomed in our calculator.
If she presses +,- or = consequently, the calculator will do the last operator's operation.
Maximum input bit size is 15 bits. You cannot give an input that exceeds 15 bits, and you cannot get an output that exceeds 16 bits.  Otherwise, you get an “ERROR” message.

-----SOME INFO ABOUT THE CODE-----

Our project consists of 4 code files. These are: hexcalculator.h, hexcalculator.cpp, main.cpp, hexcalculator.ui.

In hexcalculator.ui, We made use of QT Designer to create our calculator design.
hexcalculator.h is the header file for our class hexcalculator.
main.cpp only executes the code in the hexcalculator.cpp and shows the calculator.
We did all operations in the hexcalculator.cpp file.
We have 8 functions,
1.hexcalculator constructor-> from widget, it connects the buttons we created in the designer.
2.myadditem-> it takes the clicked button's name(which can be a,b,c,d,e,f) and outputs it to the Led panel.
3.myadditem2->it takes the clicked button's text(which can be numbers from 0-9) and outputs it to the LED panel.
4.clear->clears LED panel and the variables stored in the system.
5.operator->takes the operator(+,-,=) and transfers information to corresponding functions: these are sumtwo,subtracttwo or Equal.
6.sumtwo->Addition operation 
7.subtracttwo->Subtraction operation
8.Equal->Equity operation