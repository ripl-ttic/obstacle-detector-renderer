add_definitions(-std=gnu99)

add_library(obstacle-renderer SHARED renderer_tracks.c)

target_link_libraries(obstacle-renderer ${OPENGL_LIBRARIES})

set(REQUIRED_LIBS
    image-utils
    lcmtypes_obstacle-detector
    bot2-vis
    bot2-param-client
    bot2-frames)

pods_use_pkg_config_packages(obstacle-renderer ${REQUIRED_LIBS})

pods_install_headers(renderer_tracks.h DESTINATION obstacle_renderer)

pods_install_libraries(obstacle-renderer)

pods_install_pkg_config_file(obstacle-renderer
    CFLAGS
    LIBS -lobstacle-renderer
    REQUIRES ${REQUIRED_LIBS}
    VERSION 0.0.1)
