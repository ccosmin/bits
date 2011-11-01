#include <iostream>
#include <vector>

template<class T, class Comparator>
class Heap
{
public:
  typedef T ValueType;
  typedef std::vector<ValueType> Data;
  void Insert(const T& value)
  {
#ifdef BASE_DEBUG
    std::cout << "Inserting: " << value << std::endl;
#endif
    m_data.push_back(value);
    BubbleUp(m_data.size() - 1);
  }

  bool Extract(T& value)
  {
    if ( m_data.empty() )
      return false;
    value = m_data[0];
    std::swap(m_data[0], m_data[m_data.size() - 1]);
    m_data.resize(m_data.size() - 1);
    BubbleDown(0);
    return true;
  }

private:
  int Parent(int n)
  {
    return n == 0 ? -1 : (n - 1) / 2;
  }
  int FirstChild(int n)
  {
    return n * 2 + 1;
  }
  void BubbleUp(int idx)
  {
    int parent = Parent(idx);
    if ( parent != -1 )  
    {
      Comparator comparator;
      if ( comparator(m_data[idx], m_data[parent]) )
      {
#ifdef BASE_DEBUG
        std::cout << "swapping " << m_data[idx] << " with " <<  m_data[parent] << std::endl;
#endif
        std::swap(m_data[parent], m_data[idx]);

        BubbleUp(parent);
      }
      else
      {
#ifdef BASE_DEBUG
        std::cout << "not swapping " << m_data[idx] << " with " <<  m_data[parent] << std::endl;
#endif
      }
    }
  }
  void BubbleDown(int idx)
  {
#ifdef BASE_DEBUG
    std::cout << "BubbleDown: " << idx << std::endl;
#endif
    Comparator comparator;
    int firstChild = FirstChild(idx);
#ifdef BASE_DEBUG
    //std::cout << "firstChild: " << firstChild << std::endl;
#endif
    int minIdx = idx;
    for ( int i = 0; i <= 1 && (firstChild + i) < m_data.size(); ++i )
    {
#ifdef BASE_DEBUG
    std::cout << "compare: " << m_data[idx] << " and " << m_data[firstChild + i] << std::endl;
#endif
      if ( !comparator(m_data[minIdx], m_data[firstChild + i]) )
      {
#ifdef BASE_DEBUG
        std::cout << "minIdx " << minIdx << std::endl;
#endif
        minIdx = firstChild + i;
      }
    }
    if ( minIdx != idx )
    {
      std::swap(m_data[idx], m_data[minIdx]);
      BubbleDown(minIdx);
    }
  }
  Data m_data;

  friend std::ostream& operator<<(std::ostream& out, const Heap<T, Comparator>& heap)
  {
    for ( typename Heap<T, Comparator>::Data::const_iterator pos = heap.m_data.begin(); pos != heap.m_data.end(); ++pos )
    {
      if ( pos != heap.m_data.begin() )
        out << " ";
      out << *pos;
    }
    return out;
  }
};

