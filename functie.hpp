#pragma once
#include <string>
template <typename T>
float f(double pret,T cantitate);

template <>
float f(double pret,std::string cantitate);