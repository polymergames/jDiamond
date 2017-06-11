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

#ifndef D_SDL_RENDER_OBJ_2D_H
#define D_SDL_RENDER_OBJ_2D_H

#include "SDL.h"

#include "D_SDLTexture.h"
#include "D_SDLtypedefs.h"
#include "duVector2.h"
#include <stdint.h>

namespace Diamond {
class SDLRenderObj2D {
public:
  SDLRenderObj2D(const DTransform2 &transform, const SDLTexture *texture,
                 const Vector2<tSDLrender_pos> &pivot)
      : m_transform(&transform), m_texture(texture->texture),
        m_color({255, 255, 255}), m_alpha(255), m_flip(SDL_FLIP_NONE) {
    m_pivot.x = pivot.x;
    m_pivot.y = pivot.y;
    m_clip.x = 0;
    m_clip.y = 0;
    m_clip.w = texture->getWidth();
    m_clip.h = texture->getHeight();
  }

  const DTransform2 &getTransform() const { return *m_transform; }

  SDL_Point &pivot() { return m_pivot; }
  const SDL_Point &pivot() const { return m_pivot; }

  SDL_Texture *texture() { return m_texture; }
  const SDL_Texture *texture() const { return m_texture; }
  void setTexture(SDL_Texture *texture) { m_texture = texture; }
  void setTexture(const SDLTexture *texture) { setTexture(texture->texture); }

  RGB &color() { return m_color; }
  const RGB &color() const { return m_color; }

  uint8_t &alpha() { return m_alpha; }
  uint8_t alpha() const { return m_alpha; }

  SDL_RendererFlip getFlip() const { return m_flip; }
  void flipX() { m_flip = (SDL_RendererFlip)(m_flip ^ SDL_FLIP_HORIZONTAL); }
  void flipY() { m_flip = (SDL_RendererFlip)(m_flip ^ SDL_FLIP_VERTICAL); }

  int isFlippedX() const { return m_flip & SDL_FLIP_HORIZONTAL; }
  int isFlippedY() const { return m_flip & SDL_FLIP_VERTICAL; }

  SDL_Rect &clip() { return m_clip; }
  const SDL_Rect &clip() const { return m_clip; }

private:
  const DTransform2 *m_transform;
  SDL_Texture *m_texture;
  RGB m_color;
  uint8_t m_alpha;
  SDL_Point m_pivot;
  SDL_Rect m_clip;
  SDL_RendererFlip m_flip;
};
} // namespace Diamond

#endif // D_SDL_RENDER_OBJ_2D_H
