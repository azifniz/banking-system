#include "Customer.hpp"
#include <iostream>

Customer::Customer(const std::string &name, int id, const std::string &pass) : User(id, pass)
{
    this->name = name;
    this->balance = 0.0;
}

std::string Customer::getName() const
{
    return name;
}

void Customer::viewAccountDetails() const
{
    std::cout << "\n--- Account Details ---\n";
    std::cout << "Name       : " << name << std::endl;
    std::cout << "Customer ID: " << id << std::endl;
    std::cout << "Balance    : ₹" << balance << std::endl;
}

void Customer::deposit(double amount)
{
    if (amount <= 0)
    {
        std::cout << "Invalid deposit amount.\n";
        return;
    }

    balance += amount;
    transactions.emplace_back("Deposit", amount);

    std::cout << "Deposit successful.\n";
}

bool Customer::withdraw(double amount)
{
    if (amount <= 0)
    {
        std::cout << "Invalid withdrawal amount.\n";
        return false;
    }

    if (amount > balance)
    {
        std::cout << "Insufficient balance.\n";
        return false;
    }

    balance -= amount;
    transactions.emplace_back("Withdraw", amount);

    std::cout << "Withdrawal successful.\n";
    return true;
}

void Customer::viewTransactionHistory() const
{
    if (transactions.empty())
    {
        std::cout << "No transactions found.\n";
        return;
    }

    std::cout << "\n--- Transaction History ---\n";
    for (const auto &t : transactions)
    {
        std::cout << t.date << " | " << t.type << " | ₹" << t.amount << std::endl;
    }
}


//file parsing
double Customer::getBalance() const
{
    return balance;
}

void Customer::setBalance(double bal)
{
    balance = bal;
}

const std::vector<Transaction>& Customer::getTransactions() const
{
    return transactions;
}

void Customer::addTransaction(const Transaction& t)
{
    transactions.push_back(t);
}



