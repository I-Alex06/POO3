//#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "user.cpp"
#include "admin.cpp"
#include "usern.cpp"
#include "UsersV.cpp"
#include "UsersV.hpp"
#include "Produs.hpp"
#include "ProduseV.hpp"
#include "ProduseV.cpp"
#include <typeinfo>
#include "factory.hpp"
#include "factory.cpp"
#include "functie.cpp"
//std::vector<std::shared_ptr<User>> users;
// std::vector<std::unique_ptr<User>>* getUsers(){
//     return &users;
// }
#include "mainMenu.cpp"

int main()
{
    std::cout << "Hello World2!\n";
    Produs<int> produs2("produs_int",20,20.8);
    std::cout<<produs2.getNume()<<" "<<produs2.getPret()<<" "<<produs2.getCantitate()<<" Pret total:"<<f(produs2.getPret(),produs2.getCantitate())<<std::endl;
    Produs<float> produs3("produs_float",31,30.8);
    std::cout<<produs3.getNume()<<" "<<produs3.getPret()<<" "<<produs3.getCantitate()<<" Pret total:"<<f(produs3.getPret(),std::to_string(produs3.getCantitate()))<<std::endl;
    Produs<std::string> produs4("produs_string",42.77,"40.8");
    //std::string cv;std::cin>>cv;
    std::cout<<produs4.getNume()<<" "<<produs4.getPret()<<" "<<produs4.getCantitate()<<" Pret total:"<<f(produs4.getPret(),produs4.getCantitate())<<std::endl;
    UserFactory uf;
    /*std::vector<std::unique_ptr<User>> users;*/
    UsersV* users=UsersV::getInstance();
    //Admin a("admin","admin","admin1@gmail.com");
    users->adaugaUser(uf.createUser("admin","admin","admin","admin1@gmail.com"));
    //UserN u("alex","alex","alex@gmail.com");
    users->adaugaUser(uf.createUser("user","alex","alex","alex@gmail.com"));
    users->adaugaUser(uf.createUser("user","a","a","a@yaoo.com"));
    users->adaugaUser(uf.createUser("user","alex2","alex2","alex2@yaoo.com"));
    users->adaugaUser(uf.createUser("user","adew3","fwefwe3","wfe3w@hotmail.com"));
    users->adaugaUser(uf.createUser("user","alex4","alex4","wfew4@hotmail.com"));
    users->adaugaUser(uf.createUser("user","ade5w","fwefwe5","wfew@5hotmail.com"));
    users->adaugaUser(uf.createUser("user","ad6ew","fwefwe6","wfew@h6otmail.com"));
    users->adaugaUser(uf.createUser("admin","a7dew","fwefwe7","wfew@ho7tmail.com"));
    users->adaugaUser(uf.createUser("user","8adew","fwefwe8","wfew@hot8mail.com"));
    users->adaugaUser(uf.createUser("user","adew9","fwefwe9","wfew9@hotmail.com"));
    users->adaugaUser(uf.createUser("user","ad10ew","fwefw10e","wfew10@hotmail.com"));
    std::cout<<"------------------"<<std::endl;
    //std::cout<<users.get_users()<<std::endl;
    users->modificaUser(1,std::static_pointer_cast<UserN>(users->get_users()->at(0)));
    for(auto& user:*users->get_users())
    {
        //std::cout<<typeid(*user).name()<<std::endl;
        //std::cout<<"OK\n"<<user<<std::endl;
        user->PrintInfo();
    }
    std::cout<<"------------------"<<std::endl;
    //std::vector<std::shared_ptr<User>>* usr=users->get_users();
    //std::vector<std::shared_ptr<User>> usr2=*users->get_users();
    //usr2[4]->showOptiuni();
    // std::cout<<usr2.size()<<std::endl;
    //Mainloop m;
    MainMenu m;
    return 0;
}