# Setting GLM_BUILD_LIBRARY option to OFF
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(GLM_BUILD_LIBRARY OFF)
add_subdirectory(glm)
target_include_directories(glm INTERFACE glm/)
set_target_properties(glm PROPERTIES
    FOLDER third_party/glm
)

add_subdirectory(tinyobjloader)
