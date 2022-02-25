cmake_minimum_required(VERSION 3.17)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp Event.h Event.cpp DynamicVector.h tests.cpp tests.h UI.h UI.cpp Services.cpp Services.h repoEvent.h repoEvent.cpp exceptions.cpp exceptions.h validators.cpp validators.h eventList.cpp eventList.h QtWindow.cpp QtWindow.h TableModel.cpp TableModel.h Action.cpp Action.h DerivedActions.cpp DerivedActions.h Undo.cpp Undo.h ServiceVect.cpp ServiceVect.h)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.1\\mingw81_64")
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

target_link_libraries(Project Qt5::Widgets Qt5::Sql)