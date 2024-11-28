#include <QApplication>
#include "mainwindow.h"
#include "core.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    initializeCore();

    return app.exec();
}