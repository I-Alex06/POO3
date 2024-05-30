#pragma once
#include <string>
#include "meniu.hpp"
class User:public Meniu{
    protected:
        bool admn;
        std::string username;
        std::string password;
        std::string email;
    public:
        User(const std::string& _username,const std::string& _password,const std::string& _email);
        virtual void PrintInfo();
        virtual std::string getUsername();
        virtual std::string getPassword();
        virtual bool isAdmin();
};