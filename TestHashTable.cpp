#include "Testing.h"
#include "HashTable.h"

struct HashString
{
  int operator()(const std::string& str)
  {
    int acc = 11;
    for ( int i = 0; i < str.size(); ++i )
      acc = acc ^ str[i];
    return acc;
  }
};

struct StringEquals
{
  bool operator()(const std::string& str1, const std::string& str2)
  {
    return str1 == str2;
  }
};

TEST(TestHashTable, HashTableMadeOfStrings)
{
  HashTable<std::string, StringEquals, HashString> ht(16);
  ht.Insert("abc");
  ht.Insert("ytr");
  EXPECT_EQ(2, ht.Size());
}

