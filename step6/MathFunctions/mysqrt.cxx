#include <iostream>

#include "MathFunctions.h"
#include "Table.h"

// 自定义实现的平方根求解算法。
double mysqrt(double x)
{
  if (x <= 0) {
    return 0;
  }

  double result = x;

  if(x >= 1 && x < 10){
      std::cout<<"Use the table to help find and initial value\n";
      result = sqrtTable[static_cast<int>(x)];
  }

  // 十次迭代
  for (int i = 0; i < 10; ++i) {
    if (result <= 0) {
      result = 0.1;
    }
    double delta = x - (result * result);
    result = result + 0.5 * delta / result;
    std::cout << "Computing sqrt of " << x << " to be " << result << std::endl;
  }
  return result;
}