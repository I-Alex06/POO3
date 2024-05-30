#include "factory.hpp"
#include <stdexcept>

std::shared_ptr<User> UserFactory::createUser(const std::string& tip,const std::string& nume,const std::string& parola,const std::string& email)
{
    if(tip=="admin")
    {
        return std::make_shared<Admin>(nume,parola,email);
    }
    else if(tip=="user")
    {
        return std::make_shared<UserN>(nume,parola,email);
    }
    else
    {
        throw std::invalid_argument("Tipul de utilizator nu exista");
    }
}