#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>

class Transaction
{
public:
    std::string type;    // "Deposit" or "Withdraw"
    double amount;
    std::string date;

    // Constructor
    // runtime transaction
    Transaction(std::string type, double amount);

    // file-loading transaction
    Transaction(std::string type, double amount, std::string date);

    // Utility function to get current date & time
    static std::string getCurrentDate();
};

#endif
