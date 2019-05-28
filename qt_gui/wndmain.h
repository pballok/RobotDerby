#ifndef QTGUI_WNDMAIN_H
#define QTGUI_WNDMAIN_H

#include <QMainWindow>

#include "ui/ui_wndMain.h"

class wndMain : public QMainWindow {
    Q_OBJECT

public:
    explicit wndMain(QWidget* parent = nullptr);

private:
    Ui::wndMain ui{};
};

#endif // QTGUI_WNDMAIN_H