/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2013, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Acorn Pooley, Ioan Sucan */

#ifndef MOVEIT_COLLISION_DETECTION_COLLISION_DETECTOR_FCL_H_
#define MOVEIT_COLLISION_DETECTION_COLLISION_DETECTOR_FCL_H_

#include <moveit/collision_detection/collision_detector_allocator.h>
#include <moveit/collision_detection_fcl/collision_robot_fcl.h>
#include <moveit/collision_detection_fcl/collision_world_fcl.h>


// Import/export for windows dll's and visibility for gcc shared libraries.

#ifdef ROS_BUILD_SHARED_LIBS // ros is being built around shared libraries
  #ifdef moveit_collision_detection_fcl_EXPORTS // we are building a shared lib/dll
    #define MOVEIT_COLLISION_DETECTION_FCL_DECL ROS_HELPER_EXPORT
  #else // we are using shared lib/dll
    #define MOVEIT_COLLISION_DETECTION_FCL_DECL ROS_HELPER_IMPORT
  #endif
#else // ros is being built around static libraries
  #define MOVEIT_COLLISION_DETECTION_FCL_DECL
#endif

namespace collision_detection
{
/** \brief An allocator for FCL collision detectors */
class CollisionDetectorAllocatorFCL
  : public CollisionDetectorAllocatorTemplate<CollisionWorldFCL, CollisionRobotFCL, CollisionDetectorAllocatorFCL>
{
public:
  MOVEIT_COLLISION_DETECTION_FCL_DECL static const std::string NAME;  // defined in collision_world_fcl.cpp
};
}  // namespace collision_detection

#endif
