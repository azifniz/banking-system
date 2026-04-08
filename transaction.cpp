#include "Transaction.hpp"
#include <ctime>

// Constructor
Transaction::Transaction(std::string type, double amount)
{
    this->type = type;
    this->amount = amount;
    this->date = getCurrentDate();
}

Transaction::Transaction(std::string type, double amount, std::string date)
{
    this->type = type;
    this->amount = amount;
    this->date = date;
}



// Get current date & time as string
std::string Transaction::getCurrentDate()
{
    time_t now = time(nullptr);
    tm *localTime = localtime(&now);

    char buffer[30];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", localTime);

    return std::string(buffer);
}



