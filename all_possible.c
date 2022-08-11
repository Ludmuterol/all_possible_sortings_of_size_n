#include <stdlib.h>
#include <stdio.h>

void print_one(int *nums, int max)
{
  for (int i = 0; i < max; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
}

int inside_test (int *nums, int test, int max)
{
  for (int i = 0; i < max;  i++) {
    if (nums[i] == test)
      return (1);
  }
  return (0);
}

void print_all(int *nums, int index,int max){ 
  if (index == max)
    print_one(nums, max);
  else
  {
    int *tmp = (int *)malloc(sizeof(int) * max);
    for (int i = 1; i <= max; i++) {
      if (!inside_test(nums, i, max)) {
        for (int j = 0; j < max; j++) {
          if (j < index)
            tmp[j] = nums[j];
          else
            tmp[j] = 0;
        }
        tmp[index] = i;
        print_all(tmp, index + 1, max);
      }
    }
    free(tmp);
  }
}

int main(int argc, char **argv)
{
  int max = 1;
  if (argc == 2)
    max = atoi(argv[1]);
  
  int *nums = (int *)malloc(sizeof(int) * max);
  for (int i = 0; i < max; i++)
    nums[i]=0;
  
  print_all(nums, 0, max);
  
  free(nums);
  return (0);
}
