#pragma once
#include "Utils.h"

const string ClientsFileName = "Clients.txt";

// Struct
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

//Declaration 
void PrintClientCard(sClient Client);
string ReadClientAccountNumber();


// File operations

/**
 * @brief Converts a line from the file into a client record.
 */
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double
    return Client;
}

/**
 * @brief Converts a client record into a formatted string to save in the file.
 */
string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

/**
 * @brief Checks if a client exists in the file by account number.
 */
bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{

    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
            vClients.push_back(Client);
        }

        MyFile.close();

    }
    return false;
}

/**
 * @brief Loads all client records from the given file into a vector.
 */
vector <sClient> LoadCleintsDataFromFile(string FileName)
{
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

/**
 * @brief Saves all client records to the file, excluding those marked for deletion.
 */
vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }

        }

        MyFile.close();
    }

    return vClients;
}

/**
 * @brief Adds a single line of client data to the file.
 */
void AddDataLineToFile(string FileName, string  stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << stDataLine << endl;

        MyFile.close();
    }
}


// Client management

/**
 * @brief Reads a new client's information from the user.
 */
sClient ReadNewClient()
{
    sClient Client;
    cout << "Enter Account Number? ";

    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    do
    {
        cout << "Enter AccountBalance? ";
        cin >> Client.AccountBalance;
    } while (!IsNumber(Client.AccountBalance) || Client.AccountBalance < 1);

    return Client;
}

/**
 * @brief Searches for a client by account number and returns the record if found.
 */
bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{
    for (sClient C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }

    }
    return false;
}

/**
 * @brief Prompts the user to change a client’s data and returns the updated record.
 */
sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    do
    {
        cout << "Enter AccountBalance? ";
        cin >> Client.AccountBalance;
    } while (!IsNumber(Client.AccountBalance) || Client.AccountBalance < 1);

    return Client;
}

/**
 * @brief Marks a client for deletion by account number in the given vector.
 */
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

    for (sClient& C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }

    }

    return false;
}

/**
 * @brief Reads a new client from the user and saves it to the file.
 */
void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    if (Confirmation("Are you sure to add Client"))
    {
      AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
      ShowMessage("\nClient Added Successfully.", MessageType::Success);
    }
    else
    {
        ShowMessage("Cancel Adding.", MessageType::Info);
    }
}

/**
 * @brief Allows the user to add multiple new clients in sequence.
 */
void AddNewClients()
{
    do
    {
        //system("cls");
        cout << "Adding New Client:\n\n";

        AddNewClient();

    } while (Confirmation("Do you want to add more clients"));

}

/**
 * @brief Deletes a client by account number after user confirmation.
 */
bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    sClient Client;

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);

        if (Confirmation("\n\nAre you sure you want delete this client"))
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);
            ShowMessage("\n\nClient Deleted Successfully.", MessageType::Success);   

            //Refresh Clients 
            vClients = LoadCleintsDataFromFile(ClientsFileName);

            return true;
        }
        else
        {
            ShowMessage("Cancel delete.", MessageType::Info);
        }
    }
    else
    {
        ShowMessage("Not fond.", MessageType::Warning);
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

/**
 * @brief Updates a client’s information by account number after user confirmation.
 */
bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

    sClient Client;

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);

        if (Confirmation("\n\nAre you sure you want update this client"))
        {
            for (sClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveCleintsDataToFile(ClientsFileName, vClients);

            ShowMessage("\n\nClient Updated Successfully.", MessageType::Success);
            return true;
        }
        else
        {
           ShowMessage("Cancel Update.", MessageType::Info);
        }

    }
    else
    {
        ShowMessage("Not found.", MessageType::Warning);
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}


// Display

/**
 * @brief Prints a single client’s data in a formatted line.
 */
void PrintClientRecordLineBalance(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}
void PrintClientRecordLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

/**
 * @brief Displays all clients stored in the system.
 */
void ShowAllClientsScreen()
{
    system("cls");
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

/**
 * @brief Displays detailed information for a single client.
 */
void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";
}

/**
 * @brief Displays the “Add New Clients” screen.
 */
void ShowAddNewClientsScreen()
{
    ShowHeader("\tAdd New Clients Screen");

    AddNewClients();
}

/**
 * @brief Displays the “Find Client” screen and searches for a client by account number.
 */
void ShowFindClientScreen()
{
    ShowHeader("\tFind Client Screen");

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        ShowMessage("Cleint Is Found.", MessageType::Info);
        PrintClientCard(Client);
    }
    else 
    {
        ShowMessage("Cleint Is not Found.", MessageType::Warning);
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
    }
}

/**
 * @brief Displays the end screen of the program.
 */
void ShowEndScreen()
{
    ShowHeader("\tProgram Ends :-)");
}

/**
 * @brief Displays the “Delete Client” screen and handles the deletion process.
 */
void ShowDeleteClientScreen()
{
    ShowHeader("\tDelete Client Screen");

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
}

/**
 * @brief Displays the “Update Client Info” screen and handles updates.
 */
void ShowUpdateClientScreen()
{
    ShowHeader("\tUpdate Client Info Screen");

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);

}

/**
 * @brief Prompts the user to enter an account number.
 */
string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;

}


