/*
 * Gamedev Framework (gf)
 * Copyright (C) 2016-2018 Julien Bernard
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */
#include <gf/PostProcessing.h>

#include <gf/Effect.h>
#include <gf/RenderTarget.h>
#include <gf/Texture.h>

namespace gf {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
inline namespace v1 {
#endif

  PostProcessing::PostProcessing()
  : m_texture(nullptr)
  , m_textureRect(0, 0, 1, 1)
  , m_effect(nullptr)
  {
    updateTexCoords();
  }

  void PostProcessing::setTexture(const Texture& texture) {
    m_texture = &texture;
    updatePositions();
  }

  void PostProcessing::setTextureRect(const RectF& textureRect) {
    m_textureRect = textureRect;
    updatePositions();
    updateTexCoords();
  }

  void PostProcessing::draw(RenderTarget& target, const RenderStates& states) {
    if (m_texture == nullptr) {
      return;
    }

    RenderStates localStates = states;

    localStates.shader = m_effect;
    localStates.texture = m_texture;
    target.draw(m_vertices, 4, PrimitiveType::TriangleStrip, localStates);
  }

  void PostProcessing::updatePositions() {
    if (m_texture == nullptr) {
      return;
    }

    auto texSize = m_texture->getSize();
    float width = texSize.width * m_textureRect.width;
    float height = texSize.height * m_textureRect.height;

    m_vertices[0].position = {  0.0f,   0.0f };
    m_vertices[1].position = {  0.0f, height };
    m_vertices[2].position = { width,   0.0f };
    m_vertices[3].position = { width, height };
  }

  void PostProcessing::updateTexCoords() {
    /* use the usual texture coordinates (0,0) in the bottom left as the
     * texture has been generated by a RenderTexture.
     */
    m_vertices[0].texCoords = { m_textureRect.left,                       m_textureRect.top + m_textureRect.height };
    m_vertices[1].texCoords = { m_textureRect.left,                       m_textureRect.top };
    m_vertices[2].texCoords = { m_textureRect.left + m_textureRect.width, m_textureRect.top + m_textureRect.height };
    m_vertices[3].texCoords = { m_textureRect.left + m_textureRect.width, m_textureRect.top };
  }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
}
#endif
}