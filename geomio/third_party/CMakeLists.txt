add_subdirectory(glm)
target_include_directories(glm INTERFACE glm/)
set_target_properties(glm PROPERTIES
    FOLDER third_party/glm
)
set(GLM_BUILD_LIBRARY OFF)

add_subdirectory(tinyobjloader)
