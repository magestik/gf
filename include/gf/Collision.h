/*
 * Gamedev Framework (gf)
 * Copyright (C) 2016 Julien Bernard
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
#ifndef GF_COLLISION_H
#define GF_COLLISION_H

#include "Circ.h"
#include "Portability.h"
#include "Rect.h"
#include "Vector.h"

namespace gf {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
inline namespace v1 {
#endif

  /**
   * @ingroup game
   * @brief Data about the collision between two objects
   *
   * @sa [How to Create a Custom Physics Engine](http://gamedevelopment.tutsplus.com/series/how-to-create-a-custom-physics-engine--gamedev-12715)
   */
  struct Manifold {
    Vector2f normal; ///< Collision normal
    float penetration; ///< Penetration depth
  };

  /**
   * @relates Manifold
   * @brief Check if two circles collides
   *
   * @param lhs First circle
   * @param rhs Second circle
   * @param m Data to fill if there is a collision
   * @return True if there is a collision
   */
  GF_API bool collides(const CircF& lhs, const CircF& rhs, Manifold& m);

  /**
   * @relates Manifold
   * @brief Check if a rectangle collides with a circle
   *
   * @param lhs The rectangle
   * @param rhs The circle
   * @param m Data to fill if there is a collision
   * @return True if there is a collision
   */
  GF_API bool collides(const RectF& lhs, const CircF& rhs, Manifold& m);

  /**
   * @relates Manifold
   * @brief Check if a circle collides with a rectangle
   *
   * @param lhs The circle
   * @param rhs The rectangle
   * @param m Data to fill if there is a collision
   * @return True if there is a collision
   */
  GF_API bool collides(const CircF& lhs, const RectF& rhs, Manifold& m);

  /**
   * @relates Manifold
   * @brief Check if two rectangles collides
   *
   * @param lhs First rectangle
   * @param rhs Second rectangle
   * @param m Data to fill if there is a collision
   * @return True if there is a collision
   */
  GF_API bool collides(const RectF& lhs, const RectF& rhs, Manifold& m);


#ifndef DOXYGEN_SHOULD_SKIP_THIS
}
#endif
}

#endif // GF_COLLISION_H