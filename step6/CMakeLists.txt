cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

# 设置安装位置。
set(CMAKE_INSTALL_PREFIX  ${PROJECT_SOURCE_DIR})

# 设置c++编译标准。
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置可选编译。
option(USE_MYMATH "use my math lib" ON)

# 根据.h.in生成.h文件到构建目录中。
configure_file(TutorialConfig.h.in TutorialConfig.h)

# 添加库。
if(USE_MYMATH)
  # 添加子目录，从而加入项目构建中。
  add_subdirectory(MathFunctions)
  # 收集需要连接到运行程序的可选库。
  list(APPEND EXTRA_LIBS MathSqrt) 
endif()

# 生成可执行文件。
add_executable(Tutorial tutorial.cxx)

# 链接库。
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# 为项目添加附加包含目录。
target_include_directories(Tutorial PUBLIC 
"${PROJECT_BINARY_DIR}"
)

# 安装可执行文件。
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
DESTINATION include
)

# 加载测试。
enable_testing()

# 测试程序能否正常运行(验证程序运行，不会出现段错误或者崩溃并且返回0)。
add_test(NAME Runs COMMAND Tutorial 144)
# 测试程序用法是否正常(PASS_REGULAR_EXPRESSION测试属性来验证对于包含特定字符串的测试输出)。
add_test(NAME Usage COMMAND Tutorial)
set_tests_properties(Usage
PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
)

# 定义一个函数(do_test)来简化测试(验证对于给定的输入，返回的结果是否正确)。
# 对于每次调用do_test，都会添加一个带有名字，输入和对于给定输入期待的结果。
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

# 加载一系列基于结果的测试算例。
do_test(Tutorial 4 "4 is 2")
do_test(Tutorial 9 "9 is 3")
do_test(Tutorial 5 "5 is 2.236")
do_test(Tutorial 7 "7 is 2.645")
do_test(Tutorial 25 "25 is 5")
do_test(Tutorial -25 "-25 is [-nan|nan|0]")
do_test(Tutorial 0.0001 "0.0001 is 0.01")


