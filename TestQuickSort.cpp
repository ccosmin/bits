#include <string.h>
#include <stdio.h>
#include "Testing.h"
#include "QuickSort.h"

int Comparator(const void* v1, const void* v2)
{
  const char* vc1 = *(const char**)v1; 
  const char* vc2 = *(const char**)v2; 
  return strcmp(vc1, vc2);
}

TEST(TestQuickSort, TestSort)
{
  const char* a[] = { "ab", "abc", "zz", "acc", "mm" };
  QuickSort(a, sizeof(const char*), sizeof(a) / sizeof(a[0]), Comparator);
  for ( int i = 0; i < sizeof(a) / sizeof(a[0]); ++i )
  {
    printf("%s ", a[i]);
  }
}

