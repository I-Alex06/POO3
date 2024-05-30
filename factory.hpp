#pragma once
#include "user.hpp"
#include "admin.hpp"
#include "usern.hpp"
#include <string>
#include <memory>

class UserFactory
{
    public:
        static std::shared_ptr<User> createUser(const std::string& tip,const std::string& nume,const std::string& parola,const std::string& email);
        
};