PROJECT(main)

SET(CURRENT_PATH .)
MESSAGE(STATUS "CURRENT_PATH: "${CURRENT_PATH})
SET(EXECUTABLE_OUTPUT_PATH ${CURRENT_PATH}/bin)
SET(CMAKE_C_FLAGS "$ENV{CFLAGS} -rdynamic")
ADD_EXECUTABLE(main main.c)
TARGET_LINK_LIBRARIES(main dl)

