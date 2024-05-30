//#pragma once
#include "usern.hpp"
#include "meniu.cpp"
#include <iostream>
#include <string>
#include <functional>
#include "UsersV.hpp"
#include "Produs.hpp"
#include "functie.hpp"
ProduseV* produse=ProduseV::getInstance();
Produs<> produs1("produs1",10,10.3);
UserN::UserN(const std::string& _username,const std::string& _password,const std::string& _email):User(_username,_password,_email)
{
    //std::cout<<"UserN constructor"<<std::endl;
    //std::function<void()> PrintInfo=std::bind(&UserN::PrintInfo,this);
    //addOptiune("Afiseaza informatii utilizator",PrintInfo);
    // std::function<void()> PrintTest=std::bind(&UserN::PrintTest,this);
    // addOptiune("Afiseaza test",PrintTest);
    std::function<void()> AfiseazaProduse=std::bind(&UserN::AfiseazaProduse,this);
    addOptiune("Afiseaza produse",AfiseazaProduse);
    std::function<void()> VizualizareCos=std::bind(&UserN::VizualizareCos,this);
    addOptiune("Vizualizare cos",VizualizareCos);
    std::function<void()> AdaugaInCos=std::bind(&UserN::AdaugaInCos,this);
    addOptiune("Adauga in cos",AdaugaInCos);
    std::function<void()> StergeCos=std::bind(&UserN::StergeCos,this);
    addOptiune("Sterge cos",StergeCos);
    std::function<void()> FinalizeazaComanda=std::bind(&UserN::FinalizeazaComanda,this);
    addOptiune("Finalizeaza comanda",FinalizeazaComanda);

    //showOptiuni();
};
// void UserN:: PrintInfo()
// {
//     std::cout<<"utilizatorul:"<<username<<" "<<password<<" "<<email<<std::endl;
// };
// void UserN:: PrintTest()
// {
//     std::cout<<"test"<<std::endl;
// };
std::vector<std::shared_ptr<Produs<>>>* UserN:: getCos()
{
    return &cos;
};
void UserN::AfiseazaProduse()
{
    //ProduseV* produse=ProduseV::getInstance();
    system("cls");
    for(int i = 0; i<produse->get_produse()->size();i++){
        std::cout<<i<<" "<<produse->get_produse()->at(i)->getNume()<<" "<<produse->get_produse()->at(i)->getPret()<<" RON   "<<produse->get_produse()->at(i)->getCantitate()<<std::endl;
    }
    std::cout<<"\n\n\n";
};
void UserN::AdaugaInCos()
{
    
    int index;
    //system("cls");
    AfiseazaProduse();
    std::cout<<"Introduceti indexul produsului pe care doriti sa il adaugati in cos"<<std::endl;
    std::cin>>index;
    if (index>= produse->get_produse()->size() || index<0){
        system("cls");
        std::cout<<"Indexul introdus nu este valid"<<std::endl;
    }
    else{
        float cant;
        std::cout<<"Introduceti cantitatea produsului"<<std::endl;
        std::cin>>cant;
        if(cant>produse->get_produse()->at(index)->getCantitate()||cant==0){
            system("cls");
            std::cout<<"Cantitatea introdusa este mai mare decat cantitatea disponibila"<<std::endl;
        }else{
            produs1.setNume(produse->get_produse()->at(index)->getNume());
            produs1.setPret(produse->get_produse()->at(index)->getPret());
            produs1.setCantitate(cant);
            produse->get_produse()->at(index)->setCantitate(produse->get_produse()->at(index)->getCantitate()-cant);
            bool exista=false;
            for(auto produs:cos){
                if(produs->getNume()==produs1.getNume()){
                    produs->setCantitate(produs->getCantitate()+produs1.getCantitate());
                    exista=true;
                    break;
                }
            }
            if(!exista){
            getCos()->push_back(std::make_shared<Produs<>>(produs1));
            system("cls");}}}
    
};
void UserN::VizualizareCos()
{
    system("cls");
    for(int i = 0; i<cos.size();i++){
        std::cout<<i<<" "<<getCos()->at(i)->getNume()<<" "<<getCos()->at(i)->getPret()<<" RON   "<<getCos()->at(i)->getCantitate()<<std::endl;
    }
    std::cout<<"\n\n\n";
};
void UserN::StergeCos()
{
    int id;
    float cant;
    system("cls");
    VizualizareCos();
    std::cout<<"Introduceti indexul produsului pe care doriti sa il stergeti din cos"<<std::endl;
    std::cin>>id;
    if (id>= cos.size() || id<0){
        system("cls");
        std::cout<<"Id-ul introdus nu este valid"<<std::endl;
    }else{
    std::cout<<"Introduceti cantitatea pe care doriti sa o stergeti"<<std::endl;
    std::cin>>cant;
    if(cant>cos[id]->getCantitate()||cant<=0){
        system("cls");
        std::cout<<"Cantitatea introdusa nu este valida"<<std::endl;
    }else{
        if(cant==cos[id]->getCantitate())
            {   getCos()->erase(cos.begin()+id);
                for(auto produs:*produse->get_produse()){
                    if(produs->getNume()==cos[id]->getNume()){
                        produs->setCantitate(produs->getCantitate()+cant);break;
                    }
                }
            }
        else{
            cos[id]->setCantitate(cos[id]->getCantitate()-cant);
            for(auto produs:*produse->get_produse()){
                if(produs->getNume()==cos[id]->getNume()){
                    produs->setCantitate(produs->getCantitate()+cant);break;
                }
            }
        }
        system("cls");}}
};
void UserN::FinalizeazaComanda()
{
    system("cls");
    double total=0;
    for(int i = 0; i<getCos()->size();i++){
        total+=f(cos[i]->getPret() , cos[i]->getCantitate());
    }
    std::cout<<"Totalul comenzii este:"<<total<<std::endl;
    cos.clear();
};

