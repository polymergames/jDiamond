/*
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

#ifndef D_ENTITY_H
#define D_ENTITY_H

#include <map>
#include "D_Component.h"

namespace Diamond {
    /**
     Holds and updates a table of components indexed by type.
     The purpose of this class is to handle component ownership.
     Therefore, it takes ownership of any component added to it
     and destroys all of its components at the end of its lifetime.
    */
    class Entity {
    public:
        Entity() = default;

        virtual ~Entity() {
            for (auto i = m_components.begin(); i != m_components.end(); ++i) {
                i->second.free();
            }
        }

        // We don't think it's a good idea to copy ownership for a set of unknown components
        Entity(const Entity&) = delete;
        Entity& operator=(const Entity&) = delete;

        // But moving is OK
        Entity(Entity &&other) : m_components(std::move(other.m_components)) {}
        Entity& operator=(Entity &&other) {
            if (this != &other) {
                for (auto i = m_components.begin(); i != m_components.end(); ++i) {
                    i->second.free();
                }

                m_components = std::move(other.m_components);
            }
            return *this;
        }


        /**
         Call this once a frame to update all of this entity's components.
        */
        void updateComponents(tD_delta delta) const {
            for (auto it = m_components.begin(); it != m_components.end(); ++it)
                it->second->update(delta);
        }

        void postPhysicsUpdateComponents(tD_delta delta) const {
            for (auto it = m_components.begin(); it != m_components.end(); ++it)
                it->second->postPhysicsUpdate(delta);
        }


        void addComponent(const std::string &name, Component &component) {
            addComponent(name, &component);
        }

        void addComponent(const std::string &name, const DumbPtr<Component> &component) {
            m_components[name] = component;
        }

        // TODO: make const get functions return const pointers!
        Component *getComponent(const std::string &name) const {
            // need to use find instead of []
            // because [] is not const
            auto i = m_components.find(name);
            if (i != m_components.end())
                return i->second;
            else
                return nullptr;
        }

        template <class T>
        T *getComponent(const std::string &name) const {
            return dynamic_cast<T*>(getComponent(name));
        }

        void removeComponent(const std::string &name) {
            m_components[name].free();
            m_components.erase(name);
        }

    protected:
        std::map<std::string, DumbPtr<Component> > m_components;
    };
}


#endif // D_ENTITY_H
