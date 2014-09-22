cmake_minimum_required (VERSION 2.6)
project (fileDamper)
add_executable(fileDamper src/main.c)
target_link_libraries(fileDamper z)
ADD_DEFINITIONS(
-std=gnu99
# Other flags
)




