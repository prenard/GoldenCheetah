/*
 * Copyright (c) 2009 Sean C. Rhea (srhea@srhea.net)
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

#ifndef _GC_CriticalPowerWindow_h
#define _GC_CriticalPowerWindow_h 1
#include "GoldenCheetah.h"

#include <QtGui>
#include "Season.h"

class CpintPlot;
class MainWindow;
class RideItem;
class QwtPlotPicker;

class CriticalPowerWindow : public GcWindow
{
    Q_OBJECT
    G_OBJECT

    // properties can be saved/restored/set by the layout manager
    Q_PROPERTY(int season READ season WRITE setSeason USER true)
    Q_PROPERTY(int mode READ mode WRITE setMode USER true)

    public:

        CriticalPowerWindow(const QDir &home, MainWindow *parent);

        void newRideAdded();
        void deleteCpiFile(QString filename);

        // set/get properties
        int season() const { return cComboSeason->currentIndex(); }
        void setSeason(int x) { cComboSeason->setCurrentIndex(x); }
        int mode() const { return seriesCombo->currentIndex(); }
        void setMode(int x) { seriesCombo->setCurrentIndex(x); }

        RideFile::SeriesType series() { 
            return static_cast<RideFile::SeriesType>
                (seriesCombo->itemData(seriesCombo->currentIndex()).toInt());
        }

    protected slots:
        void cpintTimeValueEntered();
        void cpintSetCPButtonClicked();
        void pickerMoved(const QPoint &pos);
        void rideSelected();
        void seasonSelected(int season);
        void setSeries(int index);

    private:
        void updateCpint(double minutes);

    protected:

        QDir home;
        CpintPlot *cpintPlot;
        MainWindow *mainWindow;
        QLineEdit *cpintTimeValue;
        QLineEdit *cpintTodayValue;
        QLineEdit *cpintAllValue;
        QLineEdit *cpintCPValue;
        QComboBox *seriesCombo;
        QComboBox *cComboSeason;
        QPushButton *cpintSetCPButton;
        QwtPlotPicker *picker;
        void addSeasons();
        void addSeries();
        QList<Season> seasons;
        RideItem *currentRide;
        QList<RideFile::SeriesType> seriesList;
};

#endif // _GC_CriticalPowerWindow_h

