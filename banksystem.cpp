#include "BankSystem.hpp"
#include <iostream>

// Hardcoded banker credentials
BankSystem::BankSystem() : banker(1111, "admin")
{
    loadData();
}


void BankSystem::start()
{
    int choice;

    while (true)
    {
        std::cout << "\n===== ABC BANK =====\n";
        std::cout << "1. Login as Banker\n";
        std::cout << "2. Login as Customer\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }


        if (choice == 1)
        {
            int id;
            std::string pass;

            std::cout << "Enter Banker ID: ";
            std::cin >> id;
            std::cout << "Enter Password: ";
            std::cin >> pass;

            if (banker.authenticate(id, pass))
                bankerMenu();
            else
                std::cout << "Invalid banker credentials.\n";
        }
        else if (choice == 2)
        {
            int id;
            std::string pass;

            std::cout << "Enter Customer ID: ";
            std::cin >> id;
            std::cout << "Enter Password: ";
            std::cin >> pass;

            Customer *cust = findCustomer(id);

            if (cust && cust->authenticate(id, pass))
                customerMenu(*cust);
            else
                std::cout << "Invalid customer credentials.\n";
        }
        else if (choice == 3)
        {
            saveData();
            std::cout << "Thank you for using ABC Bank.\n";
            break;
        }
        else
        {
            std::cout << "Invalid option.\n";
        }
    }
}


void BankSystem::bankerMenu()
{
    int choice;

    while (true)
    {
        std::cout << "\n--- Banker Menu ---\n";
        std::cout << "1. Create Customer\n";
        std::cout << "2. View All Customers\n";
        std::cout << "3. Logout\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (!std::cin)
        {
            std::cin.clear();                    // clear fail state
            std::cin.ignore(10000, '\n');        // discard bad input
            std::cout << "Invalid input. Try again.\n";
            continue;
        }


        if (choice == 1)
        {
            std::string name, pass;
            int id;

            std::cout << "Enter Customer Name: ";
            std::cin.ignore();                 // clear leftover newline
            std::getline(std::cin, name);      // read full name with spaces

            std::cout << "Enter Customer ID: ";
            std::cin >> id;
            std::cout << "Enter Password: ";
            std::cin >> pass;

            std::cin.ignore(10000, '\n');


            banker.createCustomer(customers, name, id, pass);
        }
        else if (choice == 2)
        {
            banker.viewAllCustomers(customers);
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            std::cout << "Invalid option.\n";
        }
    }
}


void BankSystem::customerMenu(Customer &customer)
{
    int choice;
    double amount;

    while (true)
    {
        std::cout << "\n--- Customer Menu ---\n";
        std::cout << "1. View Account Details\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. View Transaction History\n";
        std::cout << "5. Logout\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }


        if (choice == 1)
            customer.viewAccountDetails();
        else if (choice == 2)
        {
            std::cout << "Enter amount: ";
            std::cin >> amount;
            customer.deposit(amount);
        }
        else if (choice == 3)
        {
            std::cout << "Enter amount: ";
            std::cin >> amount;
            customer.withdraw(amount);
        }
        else if (choice == 4)
            customer.viewTransactionHistory();
        else if (choice == 5)
            break;
        else
            std::cout << "Invalid option.\n";
    }
}


Customer* BankSystem::findCustomer(int id)
{
    for (auto &c : customers)
    {
        if (c.getID() == id)
            return &c;
    }
    return nullptr;
}


//file parsing
#include <fstream>

void BankSystem::saveData()
{
    std::ofstream custFile("customers.txt");
    std::ofstream txnFile("transactions.txt");

    for (const auto &c : customers)
    {
        custFile << c.getID() << "|"
                 << c.getPassword() << "|"        // password hidden? optional
                 << c.getName() << "|"
                 << c.getBalance()
                 << "\n";

        for (const auto &t : c.getTransactions())
        {
            txnFile << c.getID() << "|"
                    << t.type << "|"
                    << t.amount << "|"
                    << t.date
                    << "\n";
        }
    }
}


#include <sstream>

void BankSystem::loadData()
{
    std::ifstream custFile("customers.txt");
    std::ifstream txnFile("transactions.txt");

    if (!custFile) return;

    std::string line;

    // Load customers
    while (std::getline(custFile, line))
    {
        std::stringstream ss(line);
        std::string idStr, pass, name, balStr;

        std::getline(ss, idStr, '|');
        std::getline(ss, pass, '|');
        std::getline(ss, name, '|');
        std::getline(ss, balStr);

        int id = std::stoi(idStr);
        double bal = std::stod(balStr);

        customers.emplace_back(name, id, pass);
        customers.back().setBalance(bal);
    }

    // Load transactions
    while (std::getline(txnFile, line))
    {
        std::stringstream ss(line);
        std::string idStr, type, amtStr, date;

        std::getline(ss, idStr, '|');
        std::getline(ss, type, '|');
        std::getline(ss, amtStr, '|');
        std::getline(ss, date);

        int id = std::stoi(idStr);
        double amt = std::stod(amtStr);

        Customer* c = findCustomer(id);
        if (c)
            c->addTransaction(Transaction(type, amt, date));
    }
}


