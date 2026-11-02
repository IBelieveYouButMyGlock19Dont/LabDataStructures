add_executable(03_task
        main.cpp
        tracked_string.cpp
        wrapper.cpp
        tracked_string.h
        wrapper.h
)

target_include_directories(03_task PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(03_task PRIVATE logger)