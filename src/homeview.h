/* $BEGIN_LICENSE

This file is part of Minitube.
Copyright 2009, Flavio Tordini <flavio.tordini@gmail.com>

Minitube is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Minitube is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Minitube.  If not, see <http://www.gnu.org/licenses/>.

$END_LICENSE */

#ifndef HOMEVIEW_H
#define HOMEVIEW_H

#include <QtWidgets>

#include "view.h"

class SegmentedControl;
class SearchView;
class StandardFeedsView;
class ChannelView;

class HomeView : public View {
    Q_OBJECT

public:
    HomeView(QWidget *parent = 0);
    void disappear();
    const QString &getDescription() {
        static const QString s = tr("Make yourself comfortable");
        return s;
    }
    void showWidget(QWidget *widget);
    QWidget *currentWidget() { return stackedWidget->currentWidget(); }
    SearchView *getSearchView() { return searchView; }
    StandardFeedsView *getStandardFeedsView() { return standardFeedsView; }

public slots:
    void showSearch();
    void showStandardFeeds();
    void showChannels();

private slots:
    void appear();
    void unwatchedCountChanged(int count);

private:
    void setupBar();
    SegmentedControl *bar;
    QStackedWidget *stackedWidget;

    SearchView *searchView;
    StandardFeedsView *standardFeedsView;
    ChannelView *channelsView;

    QAction *subscriptionsAction;
};

#endif // HOMEVIEW_H
