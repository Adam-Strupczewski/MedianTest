#include <iostream>
#include <chrono>
#include <iomanip>
#include <random>

#include "MedianInsertSort.h"
#include "MedianTwoTrees.h"
#include "MedianTwoHeaps.h"

#include "Heap.h"
#include "BST.h"

static const int NUM_ELEMS_PRINT = 20;
static const int NUM_ELEMS_MAX1 = 10000;
static const int NUM_ELEMS_MAX2 = 40000;

static int test1[] = { 12, 4, 5, 3, 8, 7, -5, -9, 5 };
static double result1[] = { 12.0, 8.0, 5.0, 4.5, 5.0, 6.0, 5.0, 4.5, 5.0 };
static const int NUM_ELEMS_TEST1 = sizeof(test1)/sizeof(int);

static int test2[] = { -1, -1, -1, -1, 1, 2, 3, 4, 5, 6, 7 };
static double result2[] = { -1, -1, -1, -1, -1, -1, -1, 0, 1, 1.5, 2};
static const int NUM_ELEMS_TEST2 = sizeof(test2) / sizeof(int);


int main() {

	MedianBase* medianAlg[3];
	medianAlg[0] = new MedianInsertSort();
	medianAlg[1] = new MedianTwoTrees();
	medianAlg[2] = new MedianTwoHeaps();

	srand(static_cast<unsigned int>(time(NULL)));

	for (int alg=0; alg<3; ++alg) {

		///////////////////////////////////////////////////////////////////////
		std::cout << "*********** TESTING ACCURACY " << medianAlg[alg]->printInfo() << " ***********" << std::endl;
		std::cout << "Accuracy test 0: " << std::endl;
		for (int i = 0; i < NUM_ELEMS_PRINT; ++i) {
			std::cout << std::setprecision(1) << std::fixed << medianAlg[alg]->calculateMedian(i) << " ";
		}
		std::cout << std::endl;
		medianAlg[alg]->reset();

		///////////////////////////////////////////////////////////////////////
		std::cout << "Accuracy test 1: " << std::endl;
		for (int i = 0; i < NUM_ELEMS_TEST1; ++i) {
			std::cout << std::setprecision(1) << std::fixed << medianAlg[alg]->calculateMedian(test1[i]) << " ";
		}
		std::cout << std::endl;
		medianAlg[alg]->reset();

		///////////////////////////////////////////////////////////////////////
		std::cout << "Accuracy test 2: " << std::endl;
		for (int i = 0; i < NUM_ELEMS_TEST2; ++i) {
			std::cout << std::setprecision(1) << std::fixed << medianAlg[alg]->calculateMedian(test2[i]) << " ";
		}
		std::cout << std::endl;
		medianAlg[alg]->reset();

		///////////////////////////////////////////////////////////////////////
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int<int> dist(-5000, 5000);
		std::cout << "Accuracy test 3: " << std::endl;
		long long int r = 0;
		for (int i = 0; i < NUM_ELEMS_MAX1; ++i) {
			int ra = dist(gen);	// std::rand() % 10000 - 5000;
			r += ra;
			double m = medianAlg[alg]->calculateMedian(ra);
			if (i % 1000 == 0)
				std::cout << std::setprecision(1) << std::fixed << m << " ";
		}
		// The median and average value should be close to 0 for uniform distribution
		std::cout << std::endl << "Average value: " << r / NUM_ELEMS_MAX1;
		std::cout << std::endl;
		medianAlg[alg]->reset();

		///////////////////////////////////////////////////////////////////////
		std::cout << "*********** TESTING RUNTIME " << medianAlg[alg]->printInfo() << " ***********" << std::endl;
		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < NUM_ELEMS_MAX1; ++i) {
			medianAlg[alg]->calculateMedian(std::rand() % 10000 - 5000);
		}
		auto diff = std::chrono::high_resolution_clock::now() - start;
		std::cout << "Duration " << NUM_ELEMS_MAX1 << " elems: " << std::setprecision(2) << std::fixed <<
			std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;
		medianAlg[alg]->reset();

		///////////////////////////////////////////////////////////////////////
		start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < NUM_ELEMS_MAX2; ++i) {
			medianAlg[alg]->calculateMedian(std::rand() % 10000 - 5000);
		}
		diff = std::chrono::high_resolution_clock::now() - start;
		std::cout << "Duration " << NUM_ELEMS_MAX2 << " elems: " << std::setprecision(2) << std::fixed <<
			std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;

		std::cout << std::endl << std::endl;
		delete medianAlg[alg];
	}

	// Heap test
	/*{
		Heap h(true);
		h.insertValue(3);
		h.insertValue(2);
		h.insertValue(1);
		h.insertValue(15);
		h.insertValue(5);
		h.insertValue(4);
		h.insertValue(45);
		std::cout << "Min heap: ";
		std::cout << h.extractTop() << " ";
		std::cout << h.getTop() << " " << std::endl;
	}
	{
		Heap h(false);
		h.insertValue(3);
		h.insertValue(2);
		h.insertValue(1);
		h.insertValue(15);
		h.insertValue(5);
		h.insertValue(4);
		h.insertValue(45);
		std::cout << "Max heap: ";
		std::cout << h.extractTop() << " ";
		std::cout << h.getTop() << " ";
	}*/

	//Tree test
	/*{
		BST bst;
		bst.insertValue(3);
		bst.insertValue(2);
		bst.insertValue(1);
		bst.insertValue(15);
		bst.insertValue(5);
		bst.insertValue(4);
		bst.insertValue(45);
		bst.insertValue(-1);
		bst.insertValue(-2);
		while (bst.getCount()>0)
			std::cout << bst.extractMin() << " ";
		std::cout << std::endl;
	}
	{
		BST bst;
		bst.insertValue(3);
		bst.insertValue(2);
		bst.insertValue(1);
		bst.insertValue(15);
		bst.insertValue(5);
		bst.insertValue(4);
		bst.insertValue(45);
		bst.insertValue(-1);
		bst.insertValue(-2);
		while (bst.getCount()>0)
			std::cout << bst.extractMax() << " ";
		std::cout << std::endl;
	}*/

	std::cout << std::endl;
	std::cin.ignore();

	return 0;
}