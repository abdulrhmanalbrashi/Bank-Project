#pragma once
#include "Transactions.h"


enum enMainMenueOptions
{
    eListClients = 1, eAddNewClient = 2,
    eDeleteClient = 3, eUpdateClient = 4,
    eFindClient = 5, eTransactions = 6, eExit = 7
};

// Declaration
void ShowMainMenue();

/**
 * @brief Waits for user input and returns to the main menu.
 */
void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();

}

/**
 * @brief Reads the user’s choice from the main menu.
 */
short ReadMainMenueOption()
{
    short Choice = 0;
    do
    {
        cout << "Choose what do you want to do? [1 to 7]? ";
        cin >> Choice;
    } while (!IsNumber(Choice) || (Choice > 7 || Choice < 1));

    return Choice;
}

/**
 * @brief Executes the selected option from the main menu.
 */
void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenueOptions::eListClients:
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eAddNewClient:
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eDeleteClient:
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eUpdateClient:
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eFindClient:
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eTransactions:
        ShowTransactionScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eExit:
        ShowEndScreen();
        break;
    }
}

/**
 * @brief Displays the main menu and handles user navigation.
 */
void ShowMainMenue()
{
    ShowHeader("\tMain Menue Screen");
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Exit.\n";
    cout << "===========================================\n";
    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}