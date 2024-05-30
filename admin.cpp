//#pragma once
#include "admin.hpp"
#include "meniu.cpp"
#include <iostream>
#include <string>
#include <functional>
//#include "UsersV.cpp"
#include "UsersV.hpp"
#include "Produs.hpp"
#include "Produs.cpp"
#include "ProduseV.hpp"
//#include "main.cpp"
//#include "glob.h"

Admin::Admin(const std::string& _username,const std::string& _password,const std::string& _email):User(_username,_password,_email)
{
    //std::cout<<"Admin constructor"<<std::endl;;
    admn=true;
    // std::function<void()> PrintInfo=std::bind(&Admin::PrintInfo,this);
    // addOptiune("Afiseaza informatii admin",PrintInfo);
    // std::function<void()> PrintEmail=std::bind(&Admin::PrintEmail,this);
    // addOptiune("Afiseaza email admin",PrintEmail);
    std::function<void()> ShowUsers=std::bind(&Admin::ShowUsers,this);
    addOptiune("Afiseaza utilizatori",ShowUsers);
    std::function<void()> ShowAdmins=std::bind(&Admin::ShowAdmins,this);
    addOptiune("Afiseaza admini",ShowAdmins);
    std::function<void()> adaugaProd=std::bind(&Admin::adaugaProd,this);
    addOptiune("Adauga produs",adaugaProd);
    std::function<void()> VizualizareProduse=std::bind(&Admin::VizualizareProduse,this);
    addOptiune("Vizualizare produse",VizualizareProduse);
    std::function<void()> stergeProd=std::bind(&Admin::stergeProd,this);
    addOptiune("Sterge produs",stergeProd);
    std::function<void()> modificaProd=std::bind(&Admin::modificaProd,this);
    addOptiune("Modifica produs",modificaProd);
    //showOptiuni();
};
void Admin:: PrintInfo()
{
    std::cout<<"adminul:"<<username<<" "<<password<<" "<<email<<std::endl;
};
void Admin:: PrintEmail()
{
    std::cout<<"emailul adminului este:"<<email<<std::endl;
};
bool Admin:: isAdmin()
{
    return true;
};
void Admin::adaugaProd(){
    ProduseV* produse=ProduseV::getInstance();
    std::string nume;
    double pret;
    float cantitate;
    system("cls");
    std::cout<<"Introduceti numele produsului"<<std::endl;
    std::cin>>nume;
    std::cout<<"Introduceti pretul produsului"<<std::endl;
    std::cin>>pret;
    std::cout<<"Introduceti cantitatea produsului"<<std::endl;
    std::cin>>cantitate;
    produse->adaugaProdus(std::make_shared<Produs<>>(nume,pret,cantitate));
}
void Admin::VizualizareProduse(){
    ProduseV* produse=ProduseV::getInstance();
    system("cls");
    for(int i = 0; i<produse->get_produse()->size();i++){
        std::cout<<i<<" "<<produse->get_produse()->at(i)->getNume()<<" "<<produse->get_produse()->at(i)->getPret()<<" RON   "<<produse->get_produse()->at(i)->getCantitate()<<std::endl;
    }
    std::cout<<"\n\n\n";
}
void Admin::stergeProd(){
    ProduseV* produse=ProduseV::getInstance();
    int id;
    system("cls");
    VizualizareProduse();
    std::cout<<"Introduceti id-ul produsului pe care doriti sa il stergeti"<<std::endl;
    std::cin>>id;
    if (id>=produse->get_produse()->size() || id<0){
        std::cout<<"Id-ul introdus nu este valid"<<std::endl;
    }else
    {
    produse->stergeProdus(id);
    }
}
void Admin:: ShowUsers()
{
    UsersV* users2=UsersV::getInstance();
    std::vector<std::shared_ptr<User>> users=*users2->get_users();
    bool empty=true;
    for(int i=0;i<users.size();i++)
    {
        //std::cout<<users[i]->isAdmin()<<std::endl;
        if(users[i]->isAdmin()==false){
            std::cout<<users[i]->getUsername()<<std::endl;
            empty=false;
        }
    }
    if(empty==true)
    {
        std::cout<<"Nu exista utilizatori"<<std::endl;
    }
};
void Admin:: modificaProd(){
    ProduseV* produse=ProduseV::getInstance();
    int id;
    system("cls");
    VizualizareProduse();
    std::cout<<"Introduceti id-ul produsului pe care doriti sa il modificati"<<std::endl;
    std::cin>>id;
    if (id>=produse->get_produse()->size() || id<0){
        std::cout<<"Id-ul introdus nu este valid"<<std::endl;
    }else
    {
    Meniu tmp;
    std::function<void()> modificaNume=[&](){
        std::string nume;
        std::cout<<"Introduceti noul nume al produsului"<<std::endl;
        std::cin>>nume;
        produse->get_produse()->at(id)->setNume(nume);
    };
    tmp.addOptiune("Modifica nume",modificaNume);
    std::function<void()> modificaPret=[&](){
        double pret;
        std::cout<<"Introduceti noul pret al produsului"<<std::endl;
        std::cin>>pret;
        produse->get_produse()->at(id)->setPret(pret);
    };
    tmp.addOptiune("Modifica pret",modificaPret);
    std::function<void()> modificaCantitate=[&](){
        float cantitate;
        std::cout<<"Introduceti noua cantitate a produsului"<<std::endl;
        std::cin>>cantitate;
        produse->get_produse()->at(id)->setCantitate(cantitate);
    };
    tmp.addOptiune("Modifica cantitate",modificaCantitate);
    tmp.showOptiuni();
    }

}
void Admin:: ShowAdmins()
{
    UsersV* users2=UsersV::getInstance();
    std::vector<std::shared_ptr<User>> users=*users2->get_users();
    // std::cout<<users2->get_users()->size()<<std::endl;
    // std::cout<<users.size()<<std::endl<<std::endl;
    for(int i=0;i<users.size();i++)
    {
        //std::cout<<users[i]->isAdmin()<<std::endl;
        //std::cout<<(users[i]->isAdmin()==true);
        //std::cout<<std::endl;
        bool ok=users[i]->isAdmin();
        //std::cout<<ok<<std::endl;
        if(ok==true)
            {
                //std::cout<<"ok=true"<<std::endl;
                if(ok==false){
                    //std::cout<<"ok=false"<<std::endl;
                //std::cout<<"^^^^^^^^^^^"<<std::endl;
                ok=false;
                //std::cout<<ok<<std::endl;
                }
            }
        if(ok){
            std::cout<<users[i]->getUsername()<<std::endl;
        }
    }
};
