cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

# 设置c++编译标准。
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置可选编译。
option(USE_MYMATH "use my math lib" ON)

# 根据.h.in生成.h文件到构建目录中。
configure_file(TutorialConfig.h.in TutorialConfig.h)

# 添加库。
if(USE_MYMATH)
  # 添加子目录，从而加入项目构建中
  add_subdirectory(MathFunctions)
  # 收集需要连接到运行程序的可选库。
  list(APPEND EXTRA_LIBS MathSqrt)
  # 收集可选的头文件。
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# 生成可执行文件。
add_executable(Tutorial tutorial.cxx)

# 链接库
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# 为项目添加附加包含目录，用于cmake生成exe。
target_include_directories(Tutorial PUBLIC 
"${PROJECT_BINARY_DIR}"
${EXTRA_INCLUDES}
)






