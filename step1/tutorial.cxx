// 一个简单的模块，计算输入数值的平方根。
#include <cmath>
#include <iostream>
#include <string>

#include "TutorialConfig.h"  //通过CMakeLists.txt中target_include_directories()导入。

int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cout << argv[0] << "Version" << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // 将输入转化为浮点数。
  const double inputValue = std::stod(argv[1]); 

  // 计算平方根。
  const double outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}