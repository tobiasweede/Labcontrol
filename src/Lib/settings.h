#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings : public QObject {
    Q_OBJECT

public:
    explicit Settings( QObject *argParent = nullptr );
};

#endif // SETTINGS_H