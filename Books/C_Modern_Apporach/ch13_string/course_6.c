//
// Created by Administrator on 2023/2/28.
//

#include <stdio.h>
#include <string.h>

/*
 * 存储字符串数组最佳方式
 */
int main() {
  //方式一：数组式（废空间）
  char plant_a[][8] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};
  //方式二：指针式
  char *pant_b = {"Mercury", "Venus", "Earth",
                  "Mars", "Jupiter", "Saturn",
                  "Uranus", "Neptune", "Pluto"};
  return 0;
}