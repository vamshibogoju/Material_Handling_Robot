/**
 *  MIT License
 *
 *  Copyright (c) 2019 Vamshi Bogoju, Raja Srinivas Iskala
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without
 *  limitation the rights to use, copy, modify, merge, publish, distribute,
 *  sublicense, and/or sell copies of the Software, and to permit persons to
 *  whom the Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall be included
 *  in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 */

/*
 * @copyright 2019
 * @copyright MIT License
 * @file ObstacleChangeTest.cpp
 * Design (iteration 1)
 * @author Vamshi - Navigator
 * @author Raja - Driver
 * @date 4/12/2019
 * @version 1.0
 * @brief Tests the member methods of ObstacleChange class.
 */

#include "gtest/gtest.h"
#include "material_handling_robot/ObstacleChange.h"
/*
 * @brief Test function to test the string conversion.
 */
TEST(ObjectManipulationTest,stringTest) {
  ObstacleChange obs;
  EXPECT_EQ(obs.setTargetPoint(10), "10");
}
/*
 * @brief Test function to test the object spawn function.
 */
TEST(ObjectManipulationTest,showObjectTest) {
  ObstacleChange obs;
  std::string command =
      "rosrun gazebo_ros spawn_model -file src/warehouse_material_handling_turtlebot/gazebo_models/wood_cube_10cm/model.sdf -sdf -x 0 -y 0 -z 0 -model wood";
  EXPECT_EQ(obs.spawnObject(0, 0), command);
}
/*
 * @brief Test function for removing the object.
 */
TEST(ObjectManipulationTest,disappearObjectTest) {
  ObstacleChange obs;
  std::string command =
      "rosservice call /gazebo/delete_model model_name: 'wood'";
  EXPECT_EQ(obs.destroyObject(), command);
}
/*
 * @brief Test function to test the object spawn function.
 */
TEST(ObjectManipulationTest,showObjectNETest) {
  ObstacleChange obs;
  EXPECT_EQ(obs.spawnObject(0, 0), "10");
}
/*
 * @brief Test function for removing the object.
 */
TEST(ObjectManipulationTest,disappearObjectNETest) {
  ObstacleChange obs;
  EXPECT_EQ(obs.destroyObject(), "0");
}

