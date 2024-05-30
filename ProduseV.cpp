#include "ProduseV.hpp"

void ProduseV::adaugaProdus(std::shared_ptr<Produs<>> produs)
{
    produse.push_back(std::shared_ptr<Produs<>>( produs));
}
void ProduseV::stergeProdus(const int index)
{
    produse.erase(produse.begin()+index);
}
std::vector<std::shared_ptr<Produs<>>>* ProduseV::get_produse()
{
    return &produse;
}
ProduseV* ProduseV::getInstance()
{
    if(produsev==nullptr)
    {
        produsev=new ProduseV();
        return produsev;
    }
    else
    {
        return produsev;
    }
}
ProduseV* ProduseV::produsev=nullptr;