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

#ifndef D_ENGINE_H
#define D_ENGINE_H

#if defined __ANDROID__ || defined IOS
#include "SDL.h" // Has to be included with game's main function for SDL_main to work. TODO: include for iOS as well?
#endif

#include <fstream>
#include "duPoolManager.h"
#include "D_Component.h"
#include "D_Config.h"
#include "D_DiskJockey2D.h"
#include "D_EventHandler.h"
#include "D_PhysicsWorld2D.h"
#include "D_Renderer2D.h"
#include "D_Timer.h"
#include "D_Transform2.h"

namespace Diamond {
    class Game2D;

    class Engine2D {
    public:
        Engine2D(const Config &config, bool &success);
        ~Engine2D();

        virtual void        launch(Game2D &game);

        Config              &getConfig() { return config; }
        const Config        &getConfig() const { return config; }

        Renderer2D          *getRenderer() const { return renderer; }

        DiskJockey2D        *getDJ() const { return dj; }

        Timer               *getTimer() const { return timer; }

        EventHandler        *getEventHandler() const { return event_handler; }

        PhysicsWorld2D      *getPhysWorld() const { return phys_world; }

        virtual bool        isRunning() const { return is_running; }

        virtual void        quit() { is_running = false; }

        /**
         * The transform pointers generated here are automatically freed when there are no longer
         * any references to them. Therefore, it is important to keep at least one copy
         * of the smart pointer somewhere for the duration of the transform's use 
         * as other subsystems (ex. rendering, physics) may not make their own copy of the smart pointer
         * (ie. they might use a reference or raw pointer instead).
         * A wrapper gameobject class (like an Entity2D) that manages the lifetime of 
         * a transform and associated components takes care of this.
         */
        template <typename... Args>
        SharedPtr<DTransform2> makeTransform(Args&&... args) {
            return transformPool.make(std::forward<Args>(args)...);
        }

    protected:
        bool                is_running;

        Config              config;
        Renderer2D          *renderer;
        DiskJockey2D        *dj;
        Timer               *timer;
        EventHandler        *event_handler;
        PhysicsWorld2D      *phys_world;
        
        std::ofstream       logstream;

        PoolManager<DTransform2, SharedPtr<DTransform2> > transformPool;

        virtual bool initSDL();
        virtual bool initQuantum();

        virtual bool initWindows();
        virtual bool initMac();
        virtual bool initAndroid();
        virtual bool initIOS();
        
        void shutDown();
    };
}

#endif // D_ENGINE_H
