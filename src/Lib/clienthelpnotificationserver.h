/*
 * Copyright 2014-2018 Markus Prasser, Tobias Weiss
 *
 * This file is part of Labcontrol.
 *
 *  Labcontrol is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Labcontrol is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Labcontrol.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CLIENTHELPNOTIFICATIONSERVER_H
#define CLIENTHELPNOTIFICATIONSERVER_H

#include <QHostAddress>

class QNetworkSession;
class QTcpServer;

namespace lc {

class ClientHelpNotificationServer : public QObject
{
    Q_OBJECT

public:
    explicit ClientHelpNotificationServer(QObject *argParent = nullptr);

private:
    QTcpServer *helpMessageServer = nullptr;
    const QHostAddress hostAddress;
    QNetworkSession *networkSession = nullptr;

private slots:
    void OpenSession();
    void SendReply();
};

} // namespace lc

#endif // CLIENTHELPNOTIFICATIONSERVER_H
