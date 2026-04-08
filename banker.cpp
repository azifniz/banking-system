#include "Banker.hpp"
#include <iostream>

Banker::Banker(int id, const std::string &pass) : User(id, pass)
{
}

void Banker::createCustomer(std::vector<Customer> &customers, const std::string &name, int customerID, const std::string &password)
{
    // Check for duplicate ID
    for (const auto &c : customers)
    {
        if (c.getID() == customerID)
        {
            std::cout << "Error: Customer ID already exists.\n";
            return;
        }
    }

    customers.emplace_back(name, customerID, password);
    std::cout << "Customer created successfully.\n";
}


void Banker::viewAllCustomers(const std::vector<Customer> &customers) const
{
    if (customers.empty())
    {
        std::cout << "No customers available.\n";
        return;
    }

    std::cout << "\n--- Customer List ---\n";
    for (const auto &c : customers)
    {
        std::cout << "Customer ID: " << c.getID() << " | Name: " << c.getName() << std::endl;


    }
}
