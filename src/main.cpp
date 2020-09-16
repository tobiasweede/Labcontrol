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
#include <string.h>
#include <QApplication>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


#include "mainwindow.h"
#include "Lib/settings.h"

std::unique_ptr< lc::Settings > settings;

int main( int argc, char *argv[] ) {
    QApplication a{ argc, argv };
    std::string filename = "./Labcontrol.json";
    std::ifstream f(filename.c_str());
    pt::ptree root;
    if (f.good()) {
        pt::read_json(f, root);
    }
    settings.reset( root );
    lc::MainWindow w;
    w.show();
    
    return a.exec();
}
