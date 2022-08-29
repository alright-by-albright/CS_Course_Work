cmake_minimum_required(VERSION 2.4)

#set the project name
project(containerTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../../include)

file(GLOB all_SRCS
  "../../include/*.h"
  "${PROJECT_SOURCE_DIR}/include/Bag.h"
  "${PROJECT_SOURCE_DIR}/include/Vector.h"
  "${PROJECT_SOURCE_DIR}/include/ReceiptBag.h"
  )

#add the executable
add_executable(bagTest bagTest.cpp)
add_executable(myVectorTest myVectorTest.cpp)
add_executable(vectorVsMyVector vectorVsMyVector.cpp)
add_executable(receiptBagTest receiptBagTest.cpp)
