#pragma once

std::vector<float> minmax(std::vector<float>& v);
std::vector<float> dec_minmax(std::vector<float>& v);
std::vector<float> div_minmax(std::vector<float>& v);

//void dec_minmax(std::vector<float>& v, int begin, int end, std::vector<float>& mm);
//void div_minmax(std::vector<float>& v, int begin, int end, std::vector<float>& mm);

#include "MinMax.cpp"