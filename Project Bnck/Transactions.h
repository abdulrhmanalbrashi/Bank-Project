#pragma once
#include "Clients.h"

enum enMainMenueTransactions
{
    eDeposit = 1, eWithdraw = 2,
    eTotalBalances = 3, eMainMenue = 4,
};

// Declaration 
void ShowTransactionScreen();
void  GoBackToMainMenue();
/**
 * @brief Calculates the total balance of all clients.
 */
double GetTotalBalance(vector <sClient> vClients)
{
    double totalbalance = 0;
    for (sClient& client : vClients)
    {
        totalbalance += client.AccountBalance;
    }
    return totalbalance;
}

/**
 * @brief Prints the account number, name, and balance for each client.
 */
void ListBalance(vector <sClient> vClients)
{
    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else
        for (sClient Client : vClients)
        {
            PrintClientRecordLineBalance(Client);
            cout << endl;
        }
}

/**
 * @brief Displays all client balances and the total balance of the bank.
 */
void ShowTotalBalanceScreen()
{
    system("cls");
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_____________________________________________";
    cout << "_______________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_____________________________________________";
    cout << "_______________________________\n" << endl;

    ListBalance(vClients);

    cout << "\n_____________________________________________";
    cout << "_______________________________\n" << endl;
    cout << "\t\t\t\tTotal Balance= " << GetTotalBalance(vClients) << endl;

}

/**
 * @brief Deposits and withdraw a specific amount into a client’s account by account number.
 */
bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <sClient>& vClients)
{
    if (Confirmation("\n\nAre you sure you want perfrom this transaction"))
    {
        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                ShowMessage("\n\nDone Successfully." , MessageType::Success);
                cout << "New balance is: " << C.AccountBalance << endl;

                return true;
            }
        }
        ShowMessage("Error Account Number not found.",MessageType::Error);
        return false;
    }
    ShowMessage("Cancel the operation.",MessageType::Info);
    return false;
}

/**
 * @brief Displays the withdrawal screen and handles withdrawal transactions.
 */
void ShowWithdrawScreen()
{
    ShowHeader("\Withdraw Screen");
    sClient Client;
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    do
    {
        string AccountNumber = ReadClientAccountNumber();
        if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        {
            double Amount = 0;
            
            do
            {
                cout << "you can withdraw up to : " << Client.AccountBalance << endl;
                cout << "Please enter amount? ";
                cin >> Amount;
            } while (!IsNumber(Amount) || Amount > Client.AccountBalance || Amount < 1);
            DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);
        }
        else
        {
            cout << "Client With[" << AccountNumber << "] does not Exist." << endl;
        }

    } while (Confirmation("Do you went To find Account"));
}

/**
 * @brief Displays the deposit screen and handles deposit transactions.
 */
void ShowDepositScreen()
{
    ShowHeader("\tDeposit Screen");
    sClient Client;
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    do
    {
        string AccountNumber = ReadClientAccountNumber();
        if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        {
            PrintClientCard(Client);
            double Amount = 0;

            do
            {
                cout << "Please enter amount? ";
                cin >> Amount;
            } while (!IsNumber(Amount) || Amount < 1);
            DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);
        }
        else
        {
            cout << "Client With[" << AccountNumber << "] does not Exist." << endl;
        }

    } while (Confirmation("Do you went To find Account"));
}

/**
 * @brief Waits for user input and returns to the transaction menu.
 */
void GoBackToMenueTransactions()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowTransactionScreen();
}

/**
 * @brief Reads the user’s selected option from the transactions menu.
 */
short ReadMainMenueTransactions()
{
    short Choice = 0;
    do
    {
        cout << "Choose what do you want to do? [1 to 4]? ";
        cin >> Choice;
    } while (!IsNumber(Choice) || (Choice > 4 || Choice < 1));

    return Choice;
}

/**
 * @brief Executes the selected transaction menu option (Deposit, Withdraw, etc.).
 */
void PerfromMainMenueTransaction(enMainMenueTransactions MainMenueTransaction)
{
    switch (MainMenueTransaction)
    {

    case enMainMenueTransactions::eDeposit:
        ShowDepositScreen();
        GoBackToMenueTransactions();
        break;

    case enMainMenueTransactions::eWithdraw:
        ShowWithdrawScreen();
        GoBackToMenueTransactions();
        break;


    case enMainMenueTransactions::eTotalBalances:
        ShowTotalBalanceScreen();
        GoBackToMenueTransactions();
        break;

    case enMainMenueTransactions::eMainMenue:
        GoBackToMainMenue();
        break;
    }
}

/**
 * @brief Displays the transaction main menu and manages user navigation between transaction options.
 */
void ShowTransactionScreen()
{
    ShowHeader("\tTransaction Menue Screen");
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Back to main.\n";
    cout << "===========================================\n";
    PerfromMainMenueTransaction((enMainMenueTransactions)ReadMainMenueTransactions());
}
