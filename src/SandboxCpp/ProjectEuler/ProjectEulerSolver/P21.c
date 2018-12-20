#include <stdio.h>
 
/*
Amicable numbers
Problem 21
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/


#define TargetAmicableNumber (10000)
#define ProperDivisorsResultsSize ((TargetAmicableNumber)/2)
#define ProperDivisorsStop 0

#define BOOL char
#define FALSE (0)


void reset_array_to(int i, int* arr, int count);
int* get_proper_divisors(int n, int* result);
int sum_of_ints(const int* array, int stop);

void P21Solver()
{
	printf("Project-Euler-Solver, Problem 21, Amicable numbers (2018-08-27)\n");
	printf("Language: Ansi-C, compiled with 'Microsoft (R) C/C++ Optimizing Compiler Version 19.15.26726 for x86'\n\n\n");

	int properDivisorsResults[ProperDivisorsResultsSize];

	int sumOfAmicableNumbers[TargetAmicableNumber + 1];
	reset_array_to(0, sumOfAmicableNumbers, TargetAmicableNumber);

	printf("---| Starting tests |-------------------------\n");
	start_tests(properDivisorsResults);
	printf("**************************************************\n\n");


	printf("---| Evaluating the sum of all the amicable numbers under %d |-------------------------\n", TargetAmicableNumber);
	int i;
	for (i = 2; i < TargetAmicableNumber + 1; i++)
	{
		get_proper_divisors(i, properDivisorsResults);
		const int properDivisorsSum = sum_of_ints(properDivisorsResults, ProperDivisorsStop);

		sumOfAmicableNumbers[i] = properDivisorsSum;
	}

	printf("**************************************************\n");
	printf("\n");

	int sumOfTargetAmicableNumber = 0;
	for (i = 2; i < TargetAmicableNumber + 1; i++)
	{
		const int sumAtIndex = sumOfAmicableNumbers[i];
		if (sumAtIndex > TargetAmicableNumber)
			continue;
		if (sumAtIndex == i)
			continue;

		if (sumOfAmicableNumbers[sumOfAmicableNumbers[i]] == i)
		{
			sumOfTargetAmicableNumber += sumAtIndex;
			printf("[%d, %d]=%d\n", i, sumAtIndex, sumOfAmicableNumbers[sumAtIndex]);
		}
	}

	printf("The sum of all the amicable numbers under %d is %d\n", TargetAmicableNumber, sumOfTargetAmicableNumber);
}

int sum_of_ints(const int* array, int stop)
{
	int sum = 0;
	for (int i = 0; array[i] != stop; i++)
		sum += array[i];

	return sum;
}

int* get_proper_divisors(int n, int* result)
{
	int dividor = 1;
	int resultIndex = 0;

	while (dividor <= (n / 2))
	{
		if ((n % (dividor)) == 0)
			result[resultIndex++] = dividor;
		dividor++;
	}

	result[resultIndex] = ProperDivisorsStop;
	return result;
}

void start_tests(int* properDivisorsResults)
{
	get_proper_divisors(220, properDivisorsResults);
	printf("Proper Divisors of 220: ");
	for (int i = 0; properDivisorsResults[i] != ProperDivisorsStop; i++)
		printf("%d, ", properDivisorsResults[i]);
	printf("\n");
	printf("TEST: Compare with '1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110'\n");
	printf("\n");

	const int properDivisorsSum = sum_of_ints(properDivisorsResults, ProperDivisorsStop);
	printf("ProperDivisorsSum of 220 is %d\n", properDivisorsSum);
	printf("TEST: Compare with 284\n");
}

/* consule output: 
[220, 284]=220
[284, 220]=284
[1184, 1210]=1184
[1210, 1184]=1210
[2620, 2924]=2620
[2924, 2620]=2924
[5020, 5564]=5020
[5564, 5020]=5564
[6232, 6368]=6232
[6368, 6232]=6368
The sum of all the amicable numbers under 10000 is 31626 [correct!!]
*/