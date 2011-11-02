#include <string.h>
#include "QuickSort.h"

static void* Deref(void* arr, int itemSize, int idx)
{
  return static_cast<char*>(arr) + idx * itemSize;
}

static void Swap(void* v1, void* v2, int s)
{
    char tmp[s];
    memcpy(tmp, v2, s);
    memcpy(v2, v1, s);
    memcpy(v1, tmp, s);
}

static int Partition(void* arr, int itemSize, int l, int h, 
                     int (*comp)(const void* left, const void* right))
{
  int p = h;
  int firsthigh = l;
  for ( int i = l; i < h; ++i )
  {
    void* valueAtI = Deref(arr, itemSize, i);
    void* valueAtPivot = Deref(arr, itemSize, p);
    if ( comp(valueAtI, valueAtPivot) < 0 )
    {
      void* valueFirstHigh = Deref(arr, itemSize, firsthigh);
      Swap(valueAtI, valueFirstHigh, itemSize);
      ++firsthigh;
    }
  }
  void* valueAtPivot = Deref(arr, itemSize, p);
  void* valueAtFirstHigh = Deref(arr, itemSize, firsthigh);
  Swap(valueAtPivot, valueAtFirstHigh, itemSize);
  return firsthigh;
}

static void InQuickSort(void* arr, int itemSize, int l, int h, 
                        int (*comp)(const void* left, const void* right))
{
  if ( h > l )
  {
    int p = Partition(arr, itemSize, l, h, comp);
    InQuickSort(arr, itemSize, l, p - 1, comp);
    InQuickSort(arr, itemSize, p + 1, h, comp);
  }
}

void QuickSort(void* arr, int itemSize, int itemNo, int (*comp)(const void* left, const void* right))
{
  InQuickSort(arr, itemSize, 0, itemNo - 1, comp);
}

