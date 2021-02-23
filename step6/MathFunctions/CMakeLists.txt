# 将预定义表生成可执行文件。
add_executable(MakeTable MakeTable.cxx)
# 自定义的命令指定如何通过MakeTable产生Table.h。
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    DEPENDS MakeTable
    )
    
# 加载库。
add_library(MathSqrt
mysqrt.cxx
${CMAKE_CURRENT_BINARY_DIR}/Table.h
)

# 添加库依赖。
target_include_directories(MathSqrt 
INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
)

# 安装库和头文件
install(TARGETS MathSqrt DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)