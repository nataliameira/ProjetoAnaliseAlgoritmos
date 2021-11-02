#include <vector>

std::vector<float> minmax(std::vector<float>& v) {

	std::vector<float> mm({ v[0],v[0] });

	for (size_t i = 1; i < v.size(); i++)
	{
		if (v[i] < mm[0]) {
			mm[0] = v[i];
		}
		else if (v[i] > mm[1]) {
			mm[1] = v[i];
		}
	}

	return mm;
}



void dec_minmax(std::vector<float>& v, int begin, int end, std::vector<float>& mm) {

	if ((end - begin) == 1) {
		mm[0] = v[begin];
		mm[1] = v[begin];
	}
	else {

		dec_minmax(v, begin + 1, end, mm);

		if (v[begin] < mm[0]) {
			mm[0] = v[begin];
		}
		else if (v[begin] > mm[1]) {
			mm[1] = v[begin];
		}

	}

}

std::vector<float> dec_minmax(std::vector<float>& v) {

	std::vector<float> mm(2);
	dec_minmax(v, 0, v.size(), mm);
	return mm;
}

void div_minmax(std::vector<float>& v, int begin, int end, std::vector<float>& mm) {

	if ((end - begin) == 1) {
		if (v[begin] < mm[0]) {
			mm[0] = v[begin];
		}
		else if (v[begin] > mm[1]) {
			mm[1] = v[begin];
		}
	}
	else {

		div_minmax(v, begin, (begin + end) / 2, mm);
		div_minmax(v, (begin + end) / 2, end, mm);
	}

}

std::vector<float> div_minmax(std::vector<float>& v) {

	std::vector<float> mm({ v[0],v[0] });
	div_minmax(v, 0, v.size(), mm);
	return mm;
}