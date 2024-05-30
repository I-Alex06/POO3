#pragma once
#include<vector>
#include<memory>
#include "user.hpp"
#include <string>

class UsersV{
    private:
        std::vector<std::shared_ptr<User>> users;
        static UsersV* userv;
        UsersV(){};

    public:
        UsersV(const UsersV& obj)=delete;
        static UsersV* getInstance();
        void adaugaUser(std::shared_ptr<User> user);
        std::vector<std::shared_ptr<User>>* get_users();
        void modificaUser(const int index,std::shared_ptr<User> user);
};