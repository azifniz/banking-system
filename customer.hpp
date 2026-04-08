#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <vector>
#include "User.hpp"
#include "Transaction.hpp"

class Customer : public User
{
private:
    std::string name;
    double balance;
    std::vector<Transaction> transactions;

public:
    Customer(const std::string &name, int id, const std::string &pass);

    void viewAccountDetails() const;
    void deposit(double amount);
    bool withdraw(double amount);
    void viewTransactionHistory() const;
    std::string getName() const;

    //file parsing
    double getBalance() const;
    void setBalance(double bal);
    const std::vector<Transaction>& getTransactions() const;
    void addTransaction(const Transaction& t);


};





#endif
