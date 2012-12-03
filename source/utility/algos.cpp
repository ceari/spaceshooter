#include "algos.h"

namespace algorithms
{
	int uniform_rand(int min, int max)
	{
		double d = rand() * ( 1.0 / ( RAND_MAX + 1.0 ) );
		return min + d * (max - min);
	}
}
