//#pragma once
#include "user.hpp"
#include <string>
User::User(const std::string& _username,const std::string& _password,const std::string& _email)
{
    username=_username;
    password=_password;
    email=_email;
}
std::string User::getUsername()
{
    return username;
}
std::string User::getPassword()
{
    return password;
}
bool User::isAdmin()
{
    return admn;
}
void User::PrintInfo()
{
    std::cout<<"utilizatorul:"<<username<<" "<<password<<" "<<email<<std::endl;
};

