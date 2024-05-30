#include "produs.hpp"
#include <iostream>
#include <string>
template <typename T>
Produs<T>::Produs(const std::string& _nume,const double _pret,const T _cantitate)
{
    nume=_nume;
    pret=_pret;
    cantitate=_cantitate;
}
template <typename T>
std::string Produs<T>::getNume()
{
    return nume;
}
template <typename T>
double Produs<T>::getPret()
{
    return pret;
}
template <typename T>
T Produs<T>::getCantitate()
{
    return cantitate;
}
// template <>
// float Produs<std::string,float>::getCantitate()
// {
//     return std::stof(cantitate);
// }
template <typename T>
void Produs<T>::setNume(const std::string& _nume)
{
    nume=_nume;
}
template <typename T>
void Produs<T>::setPret(const double _pret)
{
    pret=_pret;
}
template <typename T>
void Produs<T>::setCantitate(const T _cantitate)
{
    cantitate=_cantitate;
}
// Produs::~Produs()
// {
//     std::cout<<"Produsul "<<nume<<" a fost sters"<<std::endl;
// }

// Produs<int>;
// Produs<float>;
Produs<std::string>::Produs(const std::string& _nume,const double _pret,const std::string& _cantitate)
{
    nume=_nume;
    pret=_pret;
    cantitate= std::stof(_cantitate);
}

std::string Produs<std::string>::getNume()
{
    return nume;
}
double Produs<std::string>::getPret()
{
    return pret;
}
float Produs<std::string>::getCantitate()
{
    return cantitate;
}
void Produs<std::string>::setNume(const std::string& _nume)
{
    nume=_nume;
}
void Produs<std::string>::setPret(const double _pret)
{
    pret=_pret;
}
void Produs<std::string>::setCantitate(const float _cantitate)
{
    cantitate=_cantitate;
}