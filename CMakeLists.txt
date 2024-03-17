cmake_minimum_required(VERSION 3.21.1)

option(LINK_INSIGHT "Link Qt Insight Tracker library" ON)
option(BUILD_QDS_COMPONENTS "Build design studio components" ON)

project(NumberConversionsPtitApp LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Core Gui Qml Quick)

if (Qt6_VERSION VERSION_GREATER_EQUAL 6.3)
    qt_standard_project_setup()
endif()

qt_add_executable(NumberConversionsPtitApp src/main.cpp
    src/numberconversionscore.h src/numberconversionscore.cpp
    src/decimaltobinary.h src/decimaltobinary.cpp
    src/numberconversionsstrategy.h src/numberconversionsstrategy.cpp
    src/numberconversionscontext.h src/numberconversionscontext.cpp
    src/decimaltohex.h src/decimaltohex.cpp
    src/hextobinary.h src/hextobinary.cpp
    src/binarytodecimal.h src/binarytodecimal.cpp
    src/validnumberconversions.h src/validnumberconversions.cpp
    src/hextodecimal.h src/hextodecimal.cpp
    src/binarytohex.h src/binarytohex.cpp
    src/numberconversiontypes.h src/numberconversiontypes.cpp
    src/numberconversionscontroller.h src/numberconversionscontroller.cpp
    src/nullconvertnumber.h src/nullconvertnumber.cpp
)

qt_add_resources(NumberConversionsPtitApp "configuration"
    PREFIX "/"
    FILES
        qtquickcontrols2.conf
)

target_link_libraries(NumberConversionsPtitApp PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)

if (BUILD_QDS_COMPONENTS)
    include(${CMAKE_CURRENT_SOURCE_DIR}/qmlcomponents)
endif()

include(${CMAKE_CURRENT_SOURCE_DIR}/qmlmodules)

if (LINK_INSIGHT)
    include(${CMAKE_CURRENT_SOURCE_DIR}/insight)
endif ()

include(GNUInstallDirs)
install(TARGETS NumberConversionsPtitApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# make IDEs aware of the QML import path
set(QML_IMPORT_PATH ${PROJECT_BINARY_DIR}/qml CACHE PATH
    "Path to the custom QML components defined by the project")
