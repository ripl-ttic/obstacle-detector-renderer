find_package(PkgConfig REQUIRED)
pkg_check_modules(BOT2_VIS bot2-vis)
if(NOT BOT2_VIS_FOUND)
    message("\n\n")
    message("bot2-vis not found.  Not building obstacle renderer")
    message("\n")
    return()
endif()

add_definitions(-std=gnu99)
add_library(obstacle-detector-renderer SHARED renderer_tracks.c)

target_link_libraries(obstacle-detector-renderer ${OPENGL_LIBRARIES})

set(REQUIRED_LIBS image-utils bot2-vis bot2-param-client bot2-frames)

pods_use_pkg_config_packages(obstacle-detector-renderer ${REQUIRED_LIBS})

pods_install_headers(renderer_tracks.h DESTINATION obstacle_detector_renderer)
pods_install_libraries(obstacle-detector-renderer)
pods_install_pkg_config_file(obstacle-detector-renderer
    CFLAGS
    LIBS -lobstacle-detector-renderer
    REQUIRES ${REQUIRED_LIBS}
    VERSION 0.0.1)
