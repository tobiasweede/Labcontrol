/*
 * Copyright 2014-2016 Markus Prasser
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

#include <memory>

#include <QMessageBox>

#include "localzleafstarter.h"
#include "ui_localzleafstarter.h"
#include "Lib/settings.h"

extern std::unique_ptr< lc::Settings > settings;

lc::LocalzLeafStarter::LocalzLeafStarter( QWidget *argParent ) :
    QWidget{ argParent },
    ui{ new Ui::LocalzLeafStarter }
{
    ui->setupUi( this );

    if ( settings->GetChosenZTreePort() ) {
        ui->SBzLeafPort->setValue( settings->GetChosenZTreePort() );
    }

    ui->CBzLeafVersion->addItem( tr( "Please choose a version" ) );
    if ( !settings->installedZTreeVersions.isEmpty() ) {
        ui->CBzLeafVersion->addItems( settings->installedZTreeVersions );
    }
}

lc::LocalzLeafStarter::~LocalzLeafStarter() {
    delete ui;
}

void lc::LocalzLeafStarter::on_PBStartLocalzLeaf_clicked() {
    if ( ui->CBzLeafVersion->currentIndex() == 0 ) {
        QMessageBox::information( this, tr( "No z-Tree version chosen" ),
                                  tr( "The was not chosen a z-Tree version, yet. This is"
                                      " mandatory, so please set one" ) , QMessageBox::Ok );
        return;
    }

    emit LocalzLeafRequested( ui->LEzLeafName->text(), ui->CBzLeafVersion->currentText(),
                              ui->SBzLeafPort->value() );
}