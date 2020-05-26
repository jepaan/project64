#include "notificationimplementation.h"

NotificationImplementation::NotificationImplementation(QObject *parent) : QObject(parent)
{

}


void NotificationImplementation::DisplayError(const char *Message) const
{
}

void NotificationImplementation::DisplayError(LanguageStringID StringID) const
{
}

void NotificationImplementation::FatalError(const char *Message) const
{
}

void NotificationImplementation::FatalError(LanguageStringID StringID) const
{
}

void NotificationImplementation::DisplayWarning(const char *Message) const
{
}

void NotificationImplementation::DisplayWarning(LanguageStringID StringID) const
{
}

void NotificationImplementation::DisplayMessage(int DisplayTime, const char *Message) const
{
}

void NotificationImplementation::DisplayMessage(int DisplayTime, LanguageStringID StringID) const
{
}

void NotificationImplementation::DisplayMessage2(const char *Message) const
{
}

bool NotificationImplementation::AskYesNoQuestion(const char *Question) const
{
}

void NotificationImplementation::BreakPoint(const char *FileName, int32_t LineNumber)
{
}

void NotificationImplementation::AppInitDone()
{
}

bool NotificationImplementation::ProcessGuiMessages() const
{
}

void NotificationImplementation::ChangeFullScreen() const
{
}
