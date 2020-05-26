#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Project64-core/Plugin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public RenderWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // RenderWindow interface
public:
    virtual void GfxThreadInit() override;
    virtual void GfxThreadDone() override;
    virtual void SwapWindow() override;
};

#endif // MAINWINDOW_H
