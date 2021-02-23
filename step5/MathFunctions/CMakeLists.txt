# 生成链接库。
add_library(MathSqrt mysqrt.cxx)

# 添加库依赖。
target_include_directories(MathSqrt 
INTERFACE 
${CMAKE_CURRENT_SOURCE_DIR}
)

# 检查当前系统是否提供log和exp函数
include(CheckSymbolExists)
check_symbol_exists(log "math.h" HAVE_LOG)
check_symbol_exists(exp "math.h" HAVE_EXP)
if(NOT (HAVE_LOG AND HAVE_EXP))
  unset(HAVE_LOG CACHE)
  unset(HAVE_EXP CACHE)
  set(CMAKE_REQUIRED_LIBRARIES "m")
  check_symbol_exists(log "math.h" HAVE_LOG)
  check_symbol_exists(exp "math.h" HAVE_EXP)
  if(HAVE_LOG AND HAVE_EXP)
    target_link_libraries(MathSqrt PRIVATE m)
  endif()
endif()

# 添加编译定义
if(HAVE_LOG AND HAVE_EXP)
  target_compile_definitions(MathSqrt
  PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()

# 安装库和头文件
install(TARGETS MathSqrt DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)