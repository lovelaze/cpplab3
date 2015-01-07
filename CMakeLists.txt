cmake_minimum_required(VERSION 2.8.4)
project(cppgame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CHARACTER_FILES character.cpp human.cpp monster.cpp wizard.cpp player.cpp troll.cpp priest.cpp)
set(ITEM_FILES item.cpp container.cpp backpack.cpp)
set(ENV_FILES env.cpp indoor.cpp room.cpp)
set(COMMONS object.cpp unique_storage.hpp game_storage.hpp common.cpp cli.cpp)

set(SOURCE_FILES main.cpp ${COMMONS} ${CHARACTER_FILES} ${ITEM_FILES} ${ENV_FILES} )
add_executable(cppgame ${SOURCE_FILES})
