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

#ifndef D_TEXTURE_H
#define D_TEXTURE_H

#include "D_Config.h"

namespace Diamond {
    class Texture {
    public:
        virtual ~Texture() {}

        virtual int getWidth() const = 0;

        virtual int getHeight() const = 0;
        
        virtual RGBA getColor() const = 0;

        virtual void setColor(RGBA color) = 0;
    };
}

#endif // D_TEXTURE_H
