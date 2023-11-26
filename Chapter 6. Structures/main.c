//
//  main.c
//  Chapter 6. Structures
//
//  Created by Brian Chen on 22/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  srand( time(NULL) );

  /* 指定亂數範圍 */
  double min = 3.6;
  double max = 7.8;

  /* 產生 [min , max) 的浮點數亂數 */
  double x = (max - min) * rand() / (RAND_MAX + 1.0) + min;

  printf("x = %f\n", x);
  return 0;
}
