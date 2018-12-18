# Author: Jeroen de Haas <jah.dehaas@avans.nl>
cmake_minimum_required(VERSION 3.1.3)
project(pigisland)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MSVC)
    add_compile_options(/W3)
else()
    add_compile_options(-Wall -Wpedantic)#  -Werror)
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
endif()

  
add_executable(pigisland
  src/kmint/pigisland/main.cpp
  src/kmint/pigisland/node_algorithm.cpp
  src/kmint/pigisland/resources.cpp
  src/kmint/pigisland/actor/shark.cpp
  src/kmint/pigisland/actor/boat.cpp
  src/kmint/pigisland/actor/pig.cpp src/kmint/pigisland/state/State.cpp src/kmint/pigisland/state/State.h src/kmint/pigisland/state/StateMachine.cpp src/kmint/pigisland/state/StateMachine.h src/kmint/pigisland/state/shark/WanderingState.cpp src/kmint/pigisland/state/shark/WanderingState.h src/kmint/pigisland/algorithm/Pathfinder.cpp src/kmint/pigisland/algorithm/Pathfinder.h src/kmint/pigisland/algorithm/Astar.cpp src/kmint/pigisland/algorithm/Astar.h src/kmint/pigisland/state/shark/HuntingState.cpp src/kmint/pigisland/state/shark/HuntingState.h src/kmint/pigisland/state/boat/BoatWanderingState.cpp src/kmint/pigisland/state/boat/BoatWanderingState.h src/kmint/pigisland/state/boat/BoatDamagedState.cpp src/kmint/pigisland/state/boat/BoatDamagedState.h src/kmint/pigisland/state/EntityWithState.cpp src/kmint/pigisland/state/EntityWithState.h src/kmint/pigisland/domain/DNAString.cpp src/kmint/pigisland/domain/DNAString.h src/kmint/pigisland/force/SteeringBehaviors.cpp src/kmint/pigisland/force/SteeringBehaviors.h src/kmint/pigisland/force/EntityWithForce.cpp src/kmint/pigisland/force/EntityWithForce.h src/kmint/pigisland/math.cpp src/kmint/pigisland/math.h src/kmint/pigisland/domain/Random.h src/kmint/pigisland/actor/Obstacle.cpp src/kmint/pigisland/actor/Obstacle.h)

target_compile_features(pigisland PUBLIC cxx_std_17)
target_link_libraries(pigisland PRIVATE kmint)
target_include_directories(pigisland PRIVATE 
  src
  include)

add_custom_target(pigisland-resources ALL
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/resources" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources")
