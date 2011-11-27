/**
 * @file voice.hpp
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

#include "input.hpp"
#include "output.hpp"
#include <backend.hpp>
#include <QObject>

namespace Wintermute {
    namespace Voice {
        struct System;

        /**
         * @brief
         * @name System
         */
        class System : private Backends::AbstractFramework {
            Q_OBJECT
            Q_DISABLE_COPY(System)

            signals:
                void talkingStarted();
                void talkingStopped();
                void listeningStarted();
                void listeningStopped();
                void phraseHeard(const QString&);
                void phraseSaid(const QString&);

            public:
                ~System();
                static System* instance();

            public slots:
                void startSpeaking();
                void stopSpeaking();
                void startListening();
                void stopListening();

            protected:
                virtual void initialize();
                virtual void deinitialize();

            private:
                System();
                SynthesizedVoicesList m_voices;
                RecognizerList m_recogs;
                static System* s_inst;
        };
    }
}
