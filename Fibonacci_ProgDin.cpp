#include <vector>


int fibonacci(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int fibonacci_tp(int n, std::vector<int>& fib) {
	if (n == 0 || n == 1) {
		fib[n] = n;
		return n;
	}
	else {
		fib[n - 1] = fib[n - 1] != -1 ? fib[n - 1] : fibonacci_tp(n - 1, fib);
		fib[n - 2] = fib[n - 2] != -1 ? fib[n - 2] : fibonacci_tp(n - 2, fib);

		return fib[n - 1] + fib[n - 2];
	}
}

int fibonacci_tp(int n) {

	std::vector<int> fib(n + 1, -1);

	return fibonacci_tp(n, fib);
}

int fibonacci_bu(int n) {

	std::vector<int> fib(n + 1, -1);

	fib[0] = 0;
	fib[1] = 1;

	for (size_t i = 2; i < fib.size(); i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	return fib[n];
}