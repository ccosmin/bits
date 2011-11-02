#ifndef HASHTABLE_H
#define HASHTABLE_H

template<class T, class Equals, class Hasher>
class HashTable
{
private:
  struct Bucket
  {
    int m_size;
    int m_reserve;
    T* m_data;
  };
public:
  HashTable(int maxBuckets)
  : m_maxBuckets(maxBuckets), m_size(0)
  {
    m_buckets = new Bucket[maxBuckets];
  }
  bool Insert(const T& element)
  {
    int hash = Hasher()(element);
    Bucket& bucket = m_buckets[hash % m_maxBuckets];
    for ( int i = 0; i < bucket.m_size; ++i )
    {
      if ( Equals()(bucket.m_data[i], element) )
        return false;
    }
    CheckGrowBucket(bucket);
    bucket.m_data[bucket.m_size++] = element;
    ++m_size;
  }
  T* Find(const T& element)
  {
    int hash = Hasher(element);
    Bucket& bucket = m_buckets[hash % m_maxBuckets];
    for ( int i = 0; i < bucket.m_size; ++i )
    {
      if ( Equals(bucket.m_data[i], element) )
        return &bucket.m_data[i];
    }
    return NULL;
  }
  int Size() const
  {
    return m_size;
  }
  ~HashTable()
  {
    for ( int i = 0; i < m_maxBuckets; ++i )
    {
      delete[] m_buckets[i].m_data;
    }
    delete[] m_buckets;
  }
private:
  void CheckGrowBucket(Bucket& bucket)
  {
    if ( bucket.m_size == bucket.m_reserve )
    {
      int newReserve = bucket.m_reserve ? bucket.m_reserve * 2 : 16;
      T* newSpace = new T[newReserve];
      bucket.m_reserve = newReserve;
      std::copy(bucket.m_data, bucket.m_data + bucket.m_size, newSpace);
      delete[] bucket.m_data;
      bucket.m_data = newSpace;
    }
  }
  Bucket* m_buckets;
  int m_maxBuckets;
  int m_size;
};

#endif

