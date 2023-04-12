project (LoadLibraryTest)

if (DEFINED PUBLISH)
  add_definitions(-DPUBLISH)
endif()

add_executable(${PROJECT_NAME} LoadLibraryTest.c)

install (TARGETS ${PROJECT_NAME} RUNTIME DESTINATION tests)