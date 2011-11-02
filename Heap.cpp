#include <functional> 

#include "Heap.hpp"
#include "Testing.h"

TEST(TestHeap, Test1)
{
  Heap<int, std::less<int> > heap;
  heap.Insert(1492);
  heap.Insert(1783);
  heap.Insert(1776);
  heap.Insert(1804);
  heap.Insert(1865);
  heap.Insert(1945);
  heap.Insert(1963);
  heap.Insert(1918);
  heap.Insert(2001);
  heap.Insert(1941);
  std::cout << heap;
  std::cout << std::endl;
  int element;
  while ( heap.Extract(element) )
  {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

