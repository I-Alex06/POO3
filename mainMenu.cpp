#include "mainMenu.hpp"
#include "UsersV.hpp"
#include "usern.hpp"
#include "factory.hpp"
//#include "factory.cpp"
#include <iostream>
#include <string>
#include <functional>
#include <memory>

UsersV* users=UsersV::getInstance();

//std::vector<std::shared_ptr<User>> usr2=*users->get_users();

MainMenu::MainMenu()
{
    // for(int i=0;i<usr2.size();i++)
    // {
    //     //std::cout<<typeid(*user).name()<<std::endl;
    //     //std::cout<<"OK\n"<<user<<std::endl;
    //     std::cout<<i<<std::endl;
    //     std::cout<<usr2[i]->getUsername();
    // }
    std::function<void()> Conectare=std::bind(&MainMenu::Conectare,this);
    std::function<void()> Inregistrare=std::bind(&MainMenu::Inregistrare,this);
    addOptiune("Conectare",Conectare);
    addOptiune("Inregistrare",Inregistrare);
    showOptiuni();
    
};
MainMenu::~MainMenu()
{
};
void MainMenu::Conectare()
{
    std::string username;
    std::string password;
    std::cout<<"Introduceti username-ul:";
    std::cin>>username;
    std::cout<<"Introduceti parola:";
    std::cin>>password;
    bool exista=false;
    for(auto user:*users->get_users())
    
    {
        if(user->getUsername()==username && user->getPassword()==password)
        {
            std::cout<<"Conectare reusita"<<std::endl;
            exista=true;
            user->showOptiuni();
            break;
            //usr2[i]->showOptiuni();
        }
        //std::cout<<user->getUsername()<<" "<<user->getPassword()<<std::endl;
        
    }
    //std::cout<<exista<<std::endl;
    if(exista==false)
    {std::cout<<"Username-ul sau parola sunt gresite"<<std::endl;}
    //std::cin>>exista;
}
void MainMenu::Inregistrare()
{
    std::string username;
    std::string password;
    std::string email;
    std::cout<<"Introduceti username-ul:";
    std::cin>>username;
    std::cout<<"Introduceti parola:";
    std::cin>>password;
    std::cout<<"Introduceti email-ul:";
    std::cin>>email;
    bool exista=false;
    for(auto user:*users->get_users())
    {
        if(user->getUsername()==username)
        {
            exista=true;
            break;
        }
    }
    if(exista==true)
    {std::cout<<"Username-ul exista deja"<<std::endl;}
    else
    {
        UserFactory uf;
        users->adaugaUser(uf.createUser("user",username,password,email));};
};