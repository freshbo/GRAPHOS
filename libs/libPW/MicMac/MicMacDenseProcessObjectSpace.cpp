/**
*-------------------------------------------------
*  Copyright 2016 by Tidop Research Group <daguilera@usal.se>
*
* This file is part of GRAPHOS - inteGRAted PHOtogrammetric Suite.
*
* GRAPHOS - inteGRAted PHOtogrammetric Suite is free software: you can redistribute
* it and/or modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation, either
* version 3 of the License, or (at your option) any later version.
*
* GRAPHOS - inteGRAted PHOtogrammetric Suite is distributed in the hope that it will
* be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*
* @license GPL-3.0+ <http://spdx.org/licenses/GPL-3.0+>
*-------------------------------------------------
*/
#include "MicMacDenseProcessObjectSpace.h"
#include "MicMacProcess.h"
#include "Nuage2PlyProcess.h"

using namespace PW;

MicMacDenseProcessObjectSpace::MicMacDenseProcessObjectSpace(QString projectPath,QString distortionModel,QString paramsPath,int DeZoom)
{
    setStartupMessage("Generating Dense Model...");

    appendProcess(new MicMacProcess());
    at(0)->addIntputs(QStringList()<< paramsPath );
    appendProcess(new Nuage2PlyProcess());
    switch (DeZoom) {
    case 1:
        at(1)->addIntputs(QStringList()<<projectPath+"/MEC-0-PW/NuageImProf_PW_RESULTS_Etape_8.xml" <<"Attr="+projectPath+"/ORTHO/Ortho.tif");
        break;
    case 2:
        at(1)->addIntputs(QStringList()<<projectPath+"/MEC-0-PW/NuageImProf_PW_RESULTS_Etape_7.xml" <<"Attr="+projectPath+"/ORTHO/Ortho.tif");
        break;
    case 4:
        at(1)->addIntputs(QStringList()<<projectPath+"/MEC-0-PW/NuageImProf_PW_RESULTS_Etape_6.xml" <<"Attr="+projectPath+"/ORTHO/Ortho.tif");
        break;
    default:
        at(1)->addIntputs(QStringList()<<projectPath+"/MEC-0-PW/NuageImProf_PW_RESULTS_Etape_7.xml" <<"Attr="+projectPath+"/ORTHO/Ortho.tif");
        break;
    }
}

MicMacDenseProcessObjectSpace::~MicMacDenseProcessObjectSpace()
{

}

