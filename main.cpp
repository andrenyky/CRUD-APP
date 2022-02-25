#include <iostream>
#include "tests.h"
#include "UI.h"

//int main() {
// test();
//UI console;
//console.main_menu();
// return 0;
//}

#include <QtWidgets/QApplication>
#include "QtWindow.h"

int main(int argc, char *argv[]){


    QApplication a(argc, argv);
    QtWindow window;
    window.resize(800, 800);
    window.show();


    return a.exec();
}