// Problem 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* This prgram is designed to find a solution to ProjectEuler Problem 7:

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

	* This program will be run with a more efficient version of the algorithm I've used previously. We'll be adding
	* in the theorem that a number must have a factor less than or equal to it's square root. To keep things effiecnt,
	* we'll be keeping track of the square root of the next perfect square greater than the number we're using, since
	* a factor must be an integer, checking against a non-decimal is wasteful and unnecessary.
*/

#define PRIME_TO_FIND	10001	// This is the prime we want, starting low in case algorithm could break computer...
#define FIRST_PRIME		2	// This is the first prime, here's to hoping it's two...

int _tmain(int argc, _TCHAR* argv[])
{
	// The main variables
	unsigned int primes[PRIME_TO_FIND];		// Array of all found primes of size PRIME_TO_FIND
	unsigned int root;						// The square root we're using
	unsigned int square;					// The square we're using

	// We'll be nice and start the program off with the first prime
	primes[0] = FIRST_PRIME;	// Here's to hoping it's two and not one...
	root = 2;		// This is the root of the next perfect square
	square = 4;		// This is the next perfect square

	// This for loop runs through until we've found the number of primes asked for
	for(int i = 1; i < PRIME_TO_FIND; i++) {
		static int num = FIRST_PRIME;	// This is the current number, initialized to the first prime
		bool isPrime = false;			// Is the number prime? Don't know, so it's false

		// But is it prime?
		while (!isPrime) {
			num++;
			// If num is the square...
			if (num == square) {
				root++;					// Need a new root as sqrt(num++) is greater than old root
				square = root * root;	// Need a new sqare for the new root
				isPrime = false;		// If num == square, can't be prime, just a sanity check
				continue;
			}

			// check against all known primes less than the root
			// Also, make sure j isn't bigger than or equal to i, cause that's all the primes we've found! dumbass...
			for (int j = 0; j < i && primes[j] <= root; j++) {
				// If we're testing the root, this should be all that matters...
				if (primes[j] == root && (num % primes[j]) != 0) {
					isPrime = true;
					break;
				}

				if ((num % primes[j]) == 0) {
					// In this case, the number is composite, get a new one
					isPrime = false;
					break;
				}
				// And if it ain't, then it *might* be prime
				else {
					isPrime = true;
				}
			}
		}

		primes[i] = num;
	}
	/* shouldn't need this double checker again...
	for (int i = 0; i < PRIME_TO_FIND; i++){
		if (i == PRIME_TO_FIND-1)
			printf("%d.\n", primes[i]);
		else
			printf("%d, ", primes[i]);
	}
	*/
	
	char ans[5];

	printf("The %d prime is: %d\n", PRIME_TO_FIND, primes[PRIME_TO_FIND-1]);
	printf("Did we get it right? ");
	scanf("%s", ans);

	if (ans[0] == 'y' || ans[0] == 'Y')
		printf("Yay! We did it! :D\n");
	else
		printf("Oh, I see. We'll have to try harder. v_v\n");

	printf("Press Enter or Return key to exit... ");
	scanf("%2c", ans);
	return 0;
}

