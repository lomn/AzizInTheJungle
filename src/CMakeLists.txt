cmake_minimum_required(VERSION 3.10)

project(bugsim)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")
# set(CMAKE_VERBOSE_MAKEFILE on)

find_package(X11 REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG true)
find_package(Threads REQUIRED)

add_library(bugsim_lib STATIC
  Accessoire/Accessoire.cpp
  Accessoire/Camouflage.cpp
  Accessoire/Carapace.cpp
  Accessoire/Nageoire.cpp
  Perception/Oreilles.cpp
  Perception/Perception.cpp
  Perception/Yeux.cpp
  Comportement/Comportement.cpp
  Comportement/Gregaire.cpp
  Comportement/Kamikaze.cpp
  Comportement/Peureux.cpp
  Comportement/Prevoyant.cpp
  Aquarium.cpp
  Bestiole.cpp
  BestioleUtil.cpp
  Fabrique.cpp
  LifeManager.cpp
  Milieu.cpp
)

target_include_directories(bugsim_lib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Accessoire
)

list(APPEND CImg_INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(bugsim main.cpp)

target_link_libraries(bugsim_lib PRIVATE X11 pthread)
target_link_libraries(bugsim PRIVATE bugsim_lib)
