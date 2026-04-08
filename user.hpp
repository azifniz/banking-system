#ifndef USER_HPP
#define USER_HPP

#include <string>

class User
{
protected:
    int id;
    std::string password;

public:
    User(int id, const std::string &pass);
    bool authenticate(int inputID, const std::string &inputPass) const;

    int getID() const;
    std::string getPassword() const;


};

#endif
