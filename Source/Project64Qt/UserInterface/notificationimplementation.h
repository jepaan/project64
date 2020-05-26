#ifndef NOTIFICATIONIMPLEMENTATION_H
#define NOTIFICATIONIMPLEMENTATION_H

#include <QObject>

#include <Project64-core/Notification.h>

class NotificationImplementation : public QObject, public CNotification
{
    Q_OBJECT
public:
    explicit NotificationImplementation(QObject *parent = nullptr);

signals:


    // CNotification interface
public:
    virtual void DisplayError(const char *Message) const override;
    virtual void DisplayError(LanguageStringID StringID) const override;
    virtual void FatalError(const char *Message) const override;
    virtual void FatalError(LanguageStringID StringID) const override;
    virtual void DisplayWarning(const char *Message) const override;
    virtual void DisplayWarning(LanguageStringID StringID) const override;
    virtual void DisplayMessage(int DisplayTime, const char *Message) const override;
    virtual void DisplayMessage(int DisplayTime, LanguageStringID StringID) const override;
    virtual void DisplayMessage2(const char *Message) const override;
    virtual bool AskYesNoQuestion(const char *Question) const override;
    virtual void BreakPoint(const char *FileName, int32_t LineNumber) override;
    virtual void AppInitDone() override;
    virtual bool ProcessGuiMessages() const override;
    virtual void ChangeFullScreen() const override;
};

#endif // NOTIFICATIONIMPLEMENTATION_H
