project (CustomNativeDllMain)

add_library (${PROJECT_NAME} STATIC CustomNativeDllMain.cpp)

install (TARGETS ${PROJECT_NAME} DESTINATION)