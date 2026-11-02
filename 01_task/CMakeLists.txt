add_executable(01_task
        main.cpp
)

target_include_directories(01_task PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(01_task PRIVATE logger)