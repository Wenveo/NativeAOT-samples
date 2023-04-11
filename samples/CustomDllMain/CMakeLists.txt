project (CustomDllMain)

add_library (${PROJECT_NAME} STATIC CustomDllMain.cpp)

install (TARGETS ${PROJECT_NAME} DESTINATION)