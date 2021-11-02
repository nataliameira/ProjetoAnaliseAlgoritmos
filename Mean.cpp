#include <vector>

float mean(std::vector<float>& v) {

	float sum = 0;

	for (size_t i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}

	return sum / v.size();

}

// sum_{ i = 0 } ^ {n} 1 = O(n)

float dec_mean(std::vector<float>& v, int begin, int end) {

	if ((end - begin) == 1) {
		return v[begin];
	}
	else {
		return (v[begin] + dec_mean(v, begin + 1, end) * (end - begin - 1)) / (end - begin);
	}

}

// T(n) = T(n-1) + 1, T(1) = 1

float div_mean(std::vector<float>& v, int begin, int end) {

	if ((end - begin) == 1) {
		return v[begin];
	}
	else {
		return (div_mean(v, begin, (end + begin) / 2) * ((end + begin) / 2 - begin) +
			div_mean(v, (end + begin) / 2, end) * (end - ((end + begin) / 2)))
			/ (end - begin);
	}

}

// T(n) = 2T(n/2) + 1, T(1) = 1