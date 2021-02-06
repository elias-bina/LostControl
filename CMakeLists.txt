
set(CMAKE_C_COMPILER_INIT g++)

# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté test
project(gameTest1)

SET(CFLAGS "-Wall -Wextra -pedantic -Wcast-align -Wcast-qual -Wpointer-arith -Wfloat-equal")
SET(CFLAGS_OPTI "-Wall -Wextra -pedantic -Wcast-align -Wcast-qual -Wpointer-arith -Wfloat-equal -Os -s -O2")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${CFLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LFLAGS}")

include_directories(include)

# Crée des variables avec les fichiers à compiler
set(SRCS
    src/main.cpp
    src/entity.cpp
    src/env.cpp
    src/player.cpp
    src/input.cpp
    src/keyboard_input.cpp)



set(TARGET main)
# On indique que l'on veut un exécutable "main" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(${TARGET} ${SRCS})


# Ajoute BOX2d
find_package(box2d REQUIRED)
target_link_libraries(${TARGET} box2d)

# Ajoute SFML
target_link_libraries(${TARGET} sfml-graphics sfml-window sfml-system)
