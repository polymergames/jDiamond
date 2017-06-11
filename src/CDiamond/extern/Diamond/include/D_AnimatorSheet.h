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

#ifndef D_ANIMATOR_SHEET_H
#define D_ANIMATOR_SHEET_H

#include <memory>
#include "D_AnimationSheet.h"
#include "D_Component.h"
#include "D_RenderComponent2D.h"

namespace Diamond {
    class AnimatorSheet : public Component {
    public:
        AnimatorSheet(RenderComponent2D *rcomp,
                      const AnimationSheet *anim,
                      bool loop = true);


        const AnimationSheet *getAnimation() const { return m_anim; }
        void setAnimation(const AnimationSheet *anim);
        
        void setLoop(bool loop) { m_loop = loop; }
        bool isLoop() const { return m_loop; }
        
        // animation is never done if it is looped,
        // otherwise it is done when it's on the last frame
        bool isDone() const { return !m_loop && (m_cur_frame + 1 >= m_anim->num_frames); }

        RenderComponent2D *getRenderComponent() { return m_render_comp; }
        const RenderComponent2D *getRenderComponent() const { return m_render_comp; }
        void setRenderComponent(RenderComponent2D *rcomp);


        tD_index getCurFrame() const { return m_cur_frame; }
        tD_delta getCurFrameElapsed() const { return m_elapsed; }

        void update(tD_delta delta) override;

    private:
        RenderComponent2D                   *m_render_comp;
        const AnimationSheet                *m_anim;
        bool                                m_loop;

        int16_t                             m_frame_width, m_frame_height;
        tD_index                            m_cur_frame;
        tD_delta                            m_elapsed;

        void initClip();
    };
}

#endif // D_ANIMATOR_SHEET_H
