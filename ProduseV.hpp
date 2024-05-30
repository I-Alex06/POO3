#pragma once
#include<vector>
#include<memory>
#include "produs.hpp"
#include <string>

class ProduseV{
    private:
        std::string nume_magazin;
        std::vector<std::shared_ptr<Produs<>>> produse;
        static ProduseV* produsev;
        ProduseV(){};

    public:
        ProduseV(const ProduseV& obj)=delete;
        static ProduseV* getInstance();
        void adaugaProdus(std::shared_ptr<Produs<>> produs);
        void stergeProdus(const int index);
        std::vector<std::shared_ptr<Produs<>>>* get_produse();
};