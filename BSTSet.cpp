#include "BSTSet.h"
#include <iostream>

int main()
{
BSTSet<int> mySet;
 mySet.insert(5);
 mySet.insert(2);
 mySet.insert(8);
 mySet.insert(7);
 mySet.insert(5); // Duplicate insert (replaces old 5 with new 5)
 // Now let's find the first element not smaller than 4
 BSTSet<int>::SetIterator it = mySet.find_first_not_smaller(4);
 const int* p;
 while ((p = it.get_and_advance()) != nullptr){

 
 std::cout << *p << ' ';
 std::cout << std::endl;
 }
 // Output is 5 7 8
 // It would also have been 5 7 8 if instead of 4, the argument
 // passed to find_first_not_smaller had been 5 or 39
//  it = mySet.find(4);
//  if (it.get_and_advance() == nullptr)
//  std::cout << "No 4 in the set" << std::endl
}