#include <vector>
#include "ConvexHull.h"

std::vector<std::vector<int>> get_convex_hull(std::vector<int>& x, std::vector<int>& y) {

	std::vector<std::vector<int>> segments;

	for (size_t i = 0; i < x.size(); i++)
	{
		for (size_t j = i + 1; j < x.size(); j++)
		{
			int a = y[j] - y[i];
			int b = x[i] - x[j];
			int c = x[i] * y[j] - y[i] * x[j];


			int current_sign = 0;
			bool sign_changed = false;

			for (size_t k = 0; k < x.size(); k++)
			{
				if (k != i && k != j) {

					int sign = (a * x[k] + b * y[k] - c < 0) ? -1 : 1;

					if (current_sign == 0) {
						current_sign = sign;
					}
					else if (current_sign + sign == 0) {
						sign_changed = true;
						break;
					}

				}
			}

			if (!sign_changed) {
				segments.push_back({ x[i],y[i],x[j],y[j] });
			}
		}
	}

	return segments;

}