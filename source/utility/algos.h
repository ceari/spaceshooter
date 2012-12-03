/*
 * algos.h
 *
 *  Created on: Apr 7, 2009
 *      Author: daniel
 */

#ifndef ALGOS_H_
#define ALGOS_H_

#include <vector>
#include <cstdlib>

namespace algorithms
{
	int uniform_rand(int min, int max);

	/**
	 * generic insertion sort, the comparison functor has to implement the () operator and realize a strict weak ordering '<'
	 */
	template <class T, class ComparisonFunctor>
	void insertion_sort(std::vector<T>& arr, ComparisonFunctor cmpFnc)
	{
		for (std::size_t i = 1; i < arr.size(); i++)
		{
			T val = arr[i];
			std::size_t j = i;

			while (j > 0 && !cmpFnc(arr[j - 1], val))
			{
				arr[j] = arr[j - 1];
				j--;
			}
			arr[j] = val;
		}
	}
}


#endif /* ALGOS_H_ */
