cmake_minimum_required(VERSION 3.30.0 FATAL_ERROR)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(raylib)

add_compile_definitions(ASSETS_DIR=\"${CMAKE_SOURCE_DIR}/assets\")

add_executable(Client "./src/main.cpp")

target_sources(Client PRIVATE
    "./src/game.cpp"
    "./src/assetManager.cpp"
    "./src/enemy.cpp"
    "./Menus/menu.cpp"
    "./Menus/pauseMenu.cpp"
    "./Menus/UIManager.cpp"
    "./Menus/titleScreen.cpp"
)

target_include_directories(Client PRIVATE
    "./assets"
    "./Menus"
    "./src"
)

target_link_libraries(Client PRIVATE raylib)

add_custom_target(run_client
    COMMENT "Run client application"
    COMMAND $<TARGET_FILE:Client>
    DEPENDS raylib
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
