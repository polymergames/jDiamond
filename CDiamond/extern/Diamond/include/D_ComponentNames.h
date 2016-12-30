/*
    This header defines some default constants that can be used as Component names
    ex. for managing components in Entities.
    This header is guaranteed to not be used by Diamond engine
    and can be edited, moved around, deleted, etc. without modifying or rebuilding Diamond.
    

    Copyright 2016 Ahnaf Siddiqui

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

#ifndef D_COMPONENT_NAMES_H
#define D_COMPONENT_NAMES_H

#include <string>

namespace {
    using tDCompNameType = std::string;


    const tDCompNameType ANIMATOR = "Animator";

    const tDCompNameType COLLIDER = "Collider";
    const tDCompNameType RIGIDBODY = "Rigidbody";

    const tDCompNameType RENDERCOMPONENT = "RenderComponent";

    const tDCompNameType MUSIC = "Music";
    const tDCompNameType SOUND = "Sound";
}

#endif // D_COMPONENT_NAMES_H
