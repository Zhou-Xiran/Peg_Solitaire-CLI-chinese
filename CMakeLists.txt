cmake_minimum_required(VERSION 3.10)

project(Peg_Solitaire)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE DOCS "${CMAKE_SOURCE_DIR}/docs/*")


file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/generated)

configure_file(
	${CMAKE_SOURCE_DIR}/config.h.in
	${CMAKE_BINARY_DIR}/generated/config.h
)


add_executable(${PROJECT_NAME} ${SOURCES})


target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_BINARY_DIR}/generated
)


install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(FILES ${DOCS} DESTINATION share/doc/${PROJECT_NAME})
