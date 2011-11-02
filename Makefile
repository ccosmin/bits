Heap.o : Heap.cpp Heap.hpp
		g++ -g -c Heap.cpp

Main.o : Main.cpp
		g++ -g -c Main.cpp

LinkedList.o : LinkedList.cpp
		g++ -g -c LinkedList.cpp

TestLinkedList.o : TestLinkedList.cpp
		g++ -g -c TestLinkedList.cpp

TestMergeSort.o : TestMergeSort.cpp
		g++ -g -c TestMergeSort.cpp

MergeSort.o : MergeSort.cpp MergeSort.h
		g++ -g -c MergeSort.cpp

QuickSort.o : QuickSort.cpp QuickSort.h
		g++ -g -c QuickSort.cpp

TestQuickSort.o : TestQuickSort.cpp
		g++ -g -c TestQuickSort.cpp

BinaryTree.o : BinaryTree.cpp BinaryTree.h
		g++ -g -c BinaryTree.cpp

TestBinaryTree.o : TestBinaryTree.cpp
		g++ -g -c TestBinaryTree.cpp

TestHashTable.o : TestHashTable.cpp
		g++ -g -c TestHashTable.cpp

test_compile : Heap.o Main.o TestLinkedList.o MergeSort.o TestMergeSort.o LinkedList.o QuickSort.o TestQuickSort.o BinaryTree.o TestBinaryTree.o TestHashTable.o
		g++ -g -o test Main.o Heap.o LinkedList.o TestLinkedList.o TestMergeSort.o MergeSort.o TestQuickSort.o QuickSort.o BinaryTree.o TestBinaryTree.o TestHashTable.o

test : test_compile 
		./test

all : test

clean : 
	rm *.o test	

