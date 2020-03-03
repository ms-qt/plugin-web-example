cmake_minimum_required(VERSION 3.5)

project(plugin-web LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if (UNIX AND NOT APPLE)
    set(LINUX 1)
endif (UNIX AND NOT APPLE)


set(LIB 1)


if (WIN32)
    # 插件输出路径
    SET(LIBRARY_OUTPUT_PATH D:/deploy/qt/plugins)
endif (WIN32)

if (APPLE)
    SET(LIBRARY_OUTPUT_PATH /Users/maohuawei/project/app/qt/doper-dapp/cmake-build-debug/app.app/Contents/MacOS/plugins)

endif (APPLE)

if (LINUX)
endif (LINUX)


if (WIN32)
    include_directories("D:/Local/libs/include")
    link_directories("D:/Local/libs/lib")
endif (WIN32)


if (UNIX)

    include_directories("/usr/local/include")
    link_directories("/usr/local/lib")

endif (UNIX)


if (APPLE)
    include_directories("/usr/local/include")
    link_directories("/usr/local/lib")
endif (APPLE)

if (LINUX)

endif (LINUX)

find_package(Qt5 COMPONENTS Core Qml Quick WebEngine REQUIRED)

set(SRC
        src/plugin-web_global.h
        src/Web.cpp
        src/Web.h
        src/Document.cpp
        src/Document.h
        qml.qrc
        image.qrc
        )
if (LIB)
    add_library(${PROJECT_NAME} SHARED
            ${SRC}
            )
else ()
    add_executable(${PROJECT_NAME}
            ${SRC})
endif ()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Qml Qt5::Quick Qt5::WebEngine)
target_link_libraries(${PROJECT_NAME} PRIVATE PluginInterface)

target_compile_definitions(${PROJECT_NAME} PRIVATE PLUGINWEB_LIBRARY)

set(pluginconfig.json)