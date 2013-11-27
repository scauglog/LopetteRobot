CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(LopetteRobot C)

IF(MODE MATCHES ARDUINO)
  MESSAGE("ARDUINO MODE")
  SET(CMAKE_SYSTEM_NAME Generic)
  SET(CMAKE_C_COMPILER avr-gcc)
  SET(CMAKE_CXX_COMPILER avr-g++)
  SET(CSTANDARD "-std=gnu99")
  SET(CDEBUG "-gstabs")
  SET(CWARN "-Wall -Wstrict-prototypes")
  SET(CTUNING "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums")
  SET(COPT "-Os")
  SET(CINCS "-I${Candi_SOURCE_DIR}/libarduino")
  SET(CMCU "-mmcu=atmega8")
  SET(CDEFS "-DF_CPU=16000000 -DARDUINO")
  SET(CFLAGS "${CMCU} ${CDEBUG} ${CDEFS} ${CINCS} ${COPT} ${CWARN} ${CSTANDARD} ${CEXTRA}")
  SET(CXXFLAGS "${CMCU} ${CDEFS} ${CINCS} ${COPT}")
  SET(CMAKE_C_FLAGS ${CFLAGS})
  SET(CMAKE_CXX_FLAGS ${CXXFLAGS})
  SET(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
  # **********************
  # Context
  # SET(CMAKE_C_COMPILER avr-gcc)
  # # search for programs in the build host directories
  # SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
  # # for libraries and headers in the target directories
  # SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
  # SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
  # SET(CSTANDARD "-std=gnu99")
  # SET(CDEBUG "-gstabs")
  # SET(CWARN "-Wall")
  # SET(CTUNING "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums")
  # SET(COPT "-Os")
  # SET(CMCU "-mmcu=atmega8")
  # SET(CDEFS "-DF_CPU=32000000")
  # SET(CFLAGS "${CMCU} ${CDEBUG} ${CDEFS} ${CINCS} ${COPT} ${CWARN} ${CSTANDARD} ${CEXTRA}") 
  # SET(CMAKE_C_FLAGS  ${CFLAGS})
  # SET(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
ELSE(MODE MATCHES ARDUINO)
  MESSAGE("PC MODE")
ENDIF(MODE MATCHES ARDUINO)

# Locate the sources
#FIND_PACKAGE(OpenCV 2 REQUIRED opencv_core opencv_highgui opencv_imgproc)
FILE(GLOB_RECURSE source_files src/*.c)

# Libraries headers
#INCLUDE_DIRECTORIES(/usr/include/opencv2) # (manually)
#INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIR})

# Libraries to link
#LINK_DIRECTORIES(/usr/lib) # (manually)
#LINK_DIRECTORIES(${OpenCV_LIBRARIES})

# Define the executable
ADD_EXECUTABLE(LopetteRobot ${source_files})
SET_PROPERTY(TARGET LopetteRobot PROPERTY RUNTIME_OUTPUT_DIRECTORY bin)

# Compile options
#TARGET_LINK_LIBRARIES(LopetteRobot opencv_core opencv_highgui opencv_imgproc) # (manually)
#TARGET_LINK_LIBRARIES(LopetteRobot ${OpenCV_LINK_DIRECTORIES})


#******************DEBUG******************
#SET(CMAKE_VERBOSE_MAKEFILE on)

#GET_CMAKE_PROPERTY(_variableNames VARIABLES)
#FOREACH (_variableName ${_variableNames})
#    MESSAGE(STATUS "${_variableName}=${${_variableName}}")
#ENDFOREACH()
#*****************END***************


# IF(MODE MATCHES ARDUINO)
#   ADD_CUSTOM_COMMAND(
#     OUTPUT LopetteRobot.bin
#     COMMAND avr-objcopy -O binary bin/LopetteRobot bin/LopetteRobot.bin && avrdude -p m8 -c arduino -P /dev/ttyUSB0 -U flash:w:bin/LopetteRobot.bin
#     DEPENDS LopetteRobot
#     )
#   ADD_CUSTOM_TARGET(LopetteRobot.bin)
# ENDIF(MODE MATCHES ARDUINO)
