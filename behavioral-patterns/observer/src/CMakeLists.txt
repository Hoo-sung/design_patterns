cmake_minimum_required(VERSION 3.10)

project(ObserverPatternExample VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#헤더 파일 경로 지정
include_directories(${CMAKE_SOURCE_DIR}/observer/include)

#소스 파일들을 변수로 설정
set(SOURCES
    main.cpp
    Observer.cpp
    Subject.cpp
)
add_executable(ObserverPatternExample ${SOURCES})

#헤더 파일 포함 디렉토리 설정
target_include_directories(ObserverPatternExample PRIVATE ${CMAKE_SOURCE_DIR})

install(TARGETS ObserverPatternExample DESTINATION ${CMAKE_SOURCE_DIR}/bin)
