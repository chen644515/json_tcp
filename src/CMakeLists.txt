aux_source_directory (. SRC_LIST)

find_package(
    OpenCV REQUIRED
)

include_directories (
    ../include
    /usr/local/include
    /usr/include/opencv4
    /usr/include/gstreamer-1.0
    /usr/include/glib-2.0
    /usr/lib/x86_64-linux-gnu/glib-2.0/include
)


add_executable (test test)
target_link_libraries(test
  -ljsoncpp
)

add_executable (sendtest sendtest)
target_link_libraries(sendtest
  -ljsoncpp
)


add_executable (revtest revtest)
target_link_libraries(revtest
  -ljsoncpp
)



# add_executable (json_send json_send)
# target_link_libraries(json_send
#   -ljsoncpp
# )


# add_executable (json_rev json_rev)
# target_link_libraries(json_rev
#   -ljsoncpp
# )

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
