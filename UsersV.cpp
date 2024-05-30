#include "UsersV.hpp"

void UsersV::adaugaUser(std::shared_ptr<User> user)
{
    users.push_back(std::shared_ptr<User>( user));
}
std::vector<std::shared_ptr<User>>* UsersV::get_users()
{
    return &users;
}
void UsersV::modificaUser(const int index,std::shared_ptr<User> user)
{
    users[index]=std::shared_ptr<User>( user);
}
UsersV* UsersV::getInstance()
{
    if(userv==nullptr)
    {
        userv=new UsersV();
        return userv;
    }
    else
    {
        return userv;
    }
}
UsersV* UsersV::userv=nullptr;