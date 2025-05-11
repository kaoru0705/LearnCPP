#include <iostream>

int main() {
	int a;         // default-initialization (no initializer)

	// Traditional initialization forms:
	int b = 5;     // copy-initialization (initial value after equals sign)
	int c(6);   // direct-initialization (initial value in parenthesis)

	// Modern initialization forms (preferred):
	int d{ 7 };   // direct-list-initialization (initial value in braces)
	int e{};      // value-initialization (empty braces)

	// An integer can only hold non-fractional values.
   // Initializing an int with fractional value 4.5 requires the compiler to convert 4.5 to a value an int can hold.
   // Such a conversion is a narrowing conversion, since the fractional part of the value will be lost.

	int w1{ 4.5 }; // compile error: list-init does not allow narrowing conversion

	int w2 = 4.5;   // compiles: w2 copy-initialized to value 4
	int w3(4.5);   // compiles: w3 direct-initialized to value 4

	return 0;
}