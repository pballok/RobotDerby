#include <QApplication>

#include "wndmain.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    wndMain main_window;
    main_window.show();

    int return_code = QApplication::exec();

    return return_code;
}