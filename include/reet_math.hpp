/*
 * reet_math.hpp
 *
 *  Created on: Apr 26, 2017
 *      Author: ostrelnikov
 */

#ifndef INCLUDE_REET_MATH_HPP_
#define INCLUDE_REET_MATH_HPP_

#include <cstddef>

std::size_t nlog10(uint64_t value)
{
	static const uint64_t powers[] =
	{
		0ULL, 10ULL, 100ULL, 1000ULL, 10000ULL, 100000ULL,
		1000000ULL, 10000000ULL, 100000000ULL, 1000000000ULL, 10000000000ULL,
		100000000000ULL, 1000000000000ULL, 10000000000000ULL, 100000000000000ULL, 1000000000000000ULL,
		10000000000000000ULL, 100000000000000000ULL, 1000000000000000000ULL, 10000000000000000000ULL
	};

	std::size_t lo = 0, hi = sizeof (powers) / sizeof (*powers), middle;

	while (hi - lo > 1)
	{
		middle = (lo + hi) / 2;
		if (value < powers[middle])
		{
			hi = middle;
		}
		else
		{
			lo = middle;
		}
	}
	return hi;
}


#endif /* INCLUDE_REET_MATH_HPP_ */
