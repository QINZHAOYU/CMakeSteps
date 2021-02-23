# 生成链接库。
add_library(MathSqrt mysqrt.cxx)

# 添加库依赖。
target_include_directories(MathSqrt 
INTERFACE 
${CMAKE_CURRENT_SOURCE_DIR}
)

# 安装库和头文件
install(TARGETS MathSqrt DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)