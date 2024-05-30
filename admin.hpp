#pragma once
#include <string>
#include "user.hpp"
#include "meniu.hpp"
#include "UsersV.hpp"
#include "ProduseV.hpp"
class Admin:public User{
    private:
        bool admn=true;
    public:
        Admin(const std::string& _username,const std::string& _password,const std::string& _email);
        void PrintInfo();
        void PrintEmail();
        void ShowUsers();
        void ShowAdmins();
        void adaugaProd();
        void VizualizareProduse();
        void stergeProd();
        void modificaProd();
        bool isAdmin() override;
};