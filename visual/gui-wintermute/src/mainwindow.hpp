/**
 * mainwindow.hpp
 * This file is part of Wintermute Graphics.
 *
 * Copyright (C) 2011 - Wintermute Developers <wintermute-devel@lists.launchpad.net>
 *
 * Wintermute Linguistics is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Wintermute Linguistics is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Wintermute Linguistics; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */
#ifndef __MAINWINDOW_HPP__
#define __MAINWINDOW_HPP__

#include <QThread>
#include <QMainWindow>

namespace Ui { class MainWindow; } //forward decl.

namespace Wintermute {
    namespace Network { struct Message; }
    namespace Graphics {
        struct MainWindow;
        using Network::Message;

        class MainWindow : public QMainWindow {
            Q_OBJECT
        public:
            explicit MainWindow(QWidget * = 0);
            virtual ~MainWindow();

        protected:
            void changeEvent(QEvent *);

        private:
            Ui::MainWindow *ui;

        private slots:
            void on_actnAbout_clicked();
            void on_actnReply_clicked();
            void on_actnFullscreen_clicked();
            void on_atcnClose_clicked();
            void on_actnPreferences_triggered();
            void messageRecieved(const Message&);
        };
    }
}

#endif /** _MAINWINDOW_HPP_ */
// kate: indent-mode cstyle; space-indent on; indent-width 4;
