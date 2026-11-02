add_executable(02_task
        main.cpp
        tracked_string.cpp
)

target_include_directories(02_task PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(02_task PRIVATE logger)
