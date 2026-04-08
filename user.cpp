#include "User.hpp"

User::User(int id, const std::string &pass)
{
    this->id = id;
    this->password = pass;
}

bool User::authenticate(int inputID, const std::string &inputPass) const
{
    return (id == inputID && password == inputPass);
}

int User::getID() const
{
    return id;
}


std::string User::getPassword() const
{
    return password;
}
