#pragma once
#include <string>
#include "user.hpp"
#include "meniu.hpp"
#include "UsersV.hpp"
#include "ProduseV.hpp"
class UserN:public User{
    private:
        bool admn=false;
        std::vector<std::shared_ptr<Produs<>>> cos;
    public:
        UserN(const std::string& _username,const std::string& _password,const std::string& _email);
        //void PrintInfo() override;
        std::vector<std::shared_ptr<Produs<>>>* getCos();
        void PrintTest();
        void AfiseazaProduse();
        void AdaugaInCos();
        void VizualizareCos();
        void StergeCos();
        void FinalizeazaComanda();

};