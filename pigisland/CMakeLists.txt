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
  src/kmint/pigisland/actor/pig.cpp src/kmint/pigisland/state/State.cpp src/kmint/pigisland/state/State.h src/kmint/pigisland/state/StateMachine.cpp src/kmint/pigisland/state/StateMachine.h src/kmint/pigisland/state/shark/WanderingState.cpp src/kmint/pigisland/state/shark/WanderingState.h src/kmint/pigisland/algorithm/Pathfinder.cpp src/kmint/pigisland/algorithm/Pathfinder.h src/kmint/pigisland/algorithm/Astar.cpp src/kmint/pigisland/algorithm/Astar.h src/kmint/pigisland/state/shark/HuntingState.cpp src/kmint/pigisland/state/shark/HuntingState.h src/kmint/pigisland/state/boat/BoatWanderingState.cpp src/kmint/pigisland/state/boat/BoatWanderingState.h src/kmint/pigisland/state/boat/BoatDamagedState.cpp src/kmint/pigisland/state/boat/BoatDamagedState.h src/kmint/pigisland/state/EntityWithState.cpp src/kmint/pigisland/state/EntityWithState.h src/kmint/pigisland/domain/DNAString.cpp src/kmint/pigisland/domain/DNAString.h src/kmint/pigisland/force/SteeringBehaviors.cpp src/kmint/pigisland/force/SteeringBehaviors.h src/kmint/pigisland/force/EntityWithForce.cpp src/kmint/pigisland/force/EntityWithForce.h src/kmint/pigisland/math.cpp src/kmint/pigisland/math.h src/kmint/pigisland/domain/Random.h src/kmint/pigisland/actor/Obstacle.cpp src/kmint/pigisland/actor/Obstacle.h src/kmint/pigisland/domain/Port.cpp src/kmint/pigisland/domain/Port.h src/kmint/pigisland/state/shark/TiredState.cpp src/kmint/pigisland/state/shark/TiredState.h src/kmint/pigisland/state/shark/global/NormalState.cpp src/kmint/pigisland/state/shark/global/NormalState.h src/kmint/pigisland/state/shark/global/EmptyState.cpp src/kmint/pigisland/state/shark/global/EmptyState.h src/kmint/pigisland/state/boat/global/InWaterState.cpp src/kmint/pigisland/state/boat/global/InWaterState.h src/kmint/pigisland/algorithm/Farm.cpp src/kmint/pigisland/algorithm/Farm.h src/kmint/pigisland/state/shark/ScaredState.cpp src/kmint/pigisland/state/shark/ScaredState.h src/kmint/pigisland/algorithm/EntityWithDNA.cpp src/kmint/pigisland/algorithm/EntityWithDNA.h src/kmint/pigisland/algorithm/Dijkstra.cpp src/kmint/pigisland/algorithm/Dijkstra.h)

target_compile_features(pigisland PUBLIC cxx_std_17)
target_link_libraries(pigisland PRIVATE kmint)
target_include_directories(pigisland PRIVATE 
  src
  include)

add_custom_target(pigisland-resources ALL
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/resources" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources")
