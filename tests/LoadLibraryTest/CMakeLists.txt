project (LoadLibraryTest)

if (DEFINED PUBLISH)
  add_definitions(-DPUBLISH)
endif()

add_executable(LoadLibraryTest LoadLibraryTest.c)

install (TARGETS LoadLibraryTest RUNTIME DESTINATION tests)