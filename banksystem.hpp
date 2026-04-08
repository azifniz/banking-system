#ifndef BANKSYSTEM_HPP
#define BANKSYSTEM_HPP

#include <vector>
#include "Banker.hpp"
#include "Customer.hpp"

class BankSystem
{
private:
    Banker banker;
    std::vector<Customer> customers;

    Customer* findCustomer(int id);

    void bankerMenu();
    void customerMenu(Customer &customer);

public:
    BankSystem();
    void start();
    void loadData();
    void saveData();

};

#endif
