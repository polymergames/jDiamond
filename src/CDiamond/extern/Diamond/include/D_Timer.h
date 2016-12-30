/*
    Copyright 2015 Ahnaf Siddiqui

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef D_TIMER_H
#define D_TIMER_H

#include "D_typedefs.h"

namespace Diamond {
    class Timer {
    public:
        virtual ~Timer() {};

        virtual tD_time msElapsed() const = 0;

        tD_delta getDelta() const { return delta; }

        void setDelta(tD_delta delta) { this->delta = delta; }

        float getFPS() const { return fps; }

        void setFPS(float fps) { this->fps = fps; }

    private:
        float fps;
        tD_delta delta;
    };
}

#endif // D_TIMER_H
