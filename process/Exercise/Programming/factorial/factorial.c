#include "factorial.h"

int factorial(const int aNumber) {
	if(aNumber == 0 || aNumber == 1) return aNumber;

	return aNumber*factorial(aNumber-1);
}
