#ifndef BANKER_HPP
#define BANKER_HPP

#include "User.hpp"
#include <vector>
#include "Customer.hpp"

class Banker : public User
{
public:
    Banker(int id, const std::string &pass);

    void createCustomer(std::vector<Customer> &customers, const std::string &name, int customerID, const std::string &password);

    void viewAllCustomers(const std::vector<Customer> &customers) const;
};

#endif
