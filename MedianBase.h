#pragma once

#include <string>

/*
Base class for median calculation.
*/
class MedianBase
{
public:
	// Constructor, destructor
	MedianBase() {};
	virtual ~MedianBase() {};

	// Calculates the median for the new and all previous values
	virtual double calculateMedian(int newVal) = 0;

	// Reinitializes the structure, allows to start from sratch
	virtual void reset() = 0;

	// Print information about specific implementation
	virtual std::string printInfo() = 0;
};

