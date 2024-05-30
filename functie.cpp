
#include "functie.hpp"
template <typename T>
float f(double pret,T cantitate){
    return pret*cantitate;
};
template <>
float f(double pret,std::string cantitate){
    return pret*std::stof(cantitate);
};