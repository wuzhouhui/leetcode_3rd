#include <string.h>

int nthSuperUglyNumber(int n, int *primes, int primesSize)
{
	int uglies[n];
	int idx[primesSize], mul[primesSize];
	int i, j, next;

	memset(uglies, 0, sizeof(uglies));
	memset(idx, 0, sizeof(idx));
	uglies[0] = 1;
	for (i = 1; i < n; i++) {
		next = mul[0] = uglies[idx[0]] * primes[0];
		for (j = 1; j < primesSize; j++) {
			mul[j] = uglies[idx[j]] * primes[j];
			if (mul[j] < next)
				next = mul[j];
		}
		uglies[i] = next;
		for (j = 0; j < primesSize; j++)
			if (mul[j] == next)
				idx[j]++;
	}
	return(uglies[n - 1]);
}
main(){}
