add_subdirectory(glm)
target_include_directories(glm INTERFACE glm/)
set_target_properties(glm PROPERTIES
    FOLDER third_party/glm
)

add_subdirectory(tinyobjloader)
