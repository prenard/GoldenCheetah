/*
 * Copyright (c) 2010 Mark Liversedge (liversedge@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _GC_GcWindowRegistry_h
#define _GC_GcWindowRegistry_h

#include "GoldenCheetah.h"

class MainWindow;

// all the windows we have defined
namespace GcWindowTypes {
enum gcwinid {
        None = 0,
        Aerolab = 1,
        AllPlot = 2,
        CriticalPower =3,
        Diary =4,
        GoogleMap =5,
        Histogram =6,
        LTM =7,
        Model =8,
        PerformanceManager =9,
        PfPv =10,
        Race =11,
        Training =12,
        RideEditor =13,
        RideSummary =14,
        Scatter =15,
        Summary =16,
        Train =17,
        TreeMap =18,
        WeeklySummary =19,
        HrPw =20,
};
};
typedef enum GcWindowTypes::gcwinid GcWinID;

struct GcWindowRegistry {
    QString name;
    GcWinID id;

    static GcWindow *newGcWindow(GcWinID id, MainWindow *main); //XXX main is gonna go
};

extern GcWindowRegistry GcWindows[];
#endif