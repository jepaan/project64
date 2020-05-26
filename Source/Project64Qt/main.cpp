#include <iostream>

#include <QApplication>
#include <QDir>
#include <QStandardPaths>


#include "Common/path.h"
#include "Common/Trace.h"

#include "Project64-core/AppInit.h"
#include "Project64-core/N64System/SystemGlobals.h"
#include "Project64-core/Plugin.h"
#include "Project64-core/N64System/N64Class.h"
#include "Project64-core/TraceModulesProject64.h"

#include "UserInterface/mainwindow.h"
#include "UserInterface/notificationimplementation.h"


int main(int argc, char* argv[])
{
    constexpr size_t s = sizeof(unsigned int);
    NotificationImplementation* notify = new NotificationImplementation(nullptr);

    QApplication application(argc, argv);
    //Windows application writes to directory where binary is located.
    //This is likely not to be writeable, use AppDataLocation instead.
    QString location = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if(!QDir(location).exists())
    {
        QDir().mkdir(location);
    }

    AppInit(notify, location.toStdString().c_str(), argc, argv);

    //Windows application has language handling here

    //Create the main window with Menu
    WriteTrace(TraceUserInterface, TraceDebug, "Create Main Window");
    MainWindow mainWindow(nullptr);
    MainWindow hiddenWindow(nullptr);

    //Windows application makes debugger here.


    g_Plugins->SetRenderWindows(&mainWindow, &hiddenWindow);
    //notify->SetMainWindow(&MainWindow);

    WriteTrace(TraceUserInterface, TraceDebug, "Show Main Window");
    mainWindow.show();

    //Process Messages till program is closed
    WriteTrace(TraceUserInterface, TraceDebug, "Entering Message Loop");
    int returnValue = application.exec();
    WriteTrace(TraceUserInterface, TraceDebug, "Message Loop Finished");

    if (g_BaseSystem)
    {
        g_BaseSystem->CloseCpu();
        delete g_BaseSystem;
        g_BaseSystem = NULL;
    }
    WriteTrace(TraceUserInterface, TraceDebug, "System Closed");
    AppCleanup();
    return returnValue;
}
