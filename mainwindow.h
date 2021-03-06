#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QAction>

#include "qcustomplot.h"
#include "thermoplot.h"
//#include "profiles/profile.h"

#include "gparcer/gcodeworker.h"
#include "gconsole.h"
#include "coordinatuswindow.h"

class GConsole;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void editProfile();
    void openFileDo();
    void updateCoordinatus(const Status_t* status);

//    void on_checkBox_immediately_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    void createActions(MainWindow *w);

//    Profile* profile;

    QAction* newAct;

    QMenu *fileMenu;

    QMenu *optionsMenu;

    QAction* optionEditAct; // Profile

    QMenu * menuTools;

    QMenu * menuView;

    QMenu * menuHelp;

    QAction* actThermo;

    QAction* pidParams;

    void pidParamsDo();

    void aboutWindowDo();

    void actTermoDo();

    QAction* actConfig;

    QAction* actFileOpen;

    GcodeWorker* gcodeworker;

    GConsole* gconsole;

    ThermoPlot* plotter;

    CoordinatusWindow* coordinatusWin;


    void setupPlot(QCustomPlot *customPlot);

    void setupGconsole(Ui::MainWindow *ui);

    void setupCoordinatusWindow(Ui::MainWindow *ui);

};

#endif // MAINWINDOW_H
