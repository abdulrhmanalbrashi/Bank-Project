#pragma once
const string UserFile = "Users.txt";

//Declaration-------------
void GoBackToMainMenue();
void  ShowManageUsersMenu();
void AddDataLineToFile(string FileName, string  stDataLine);
//------------------------


struct stUsers
{
    string UserName = "";
    string Password = "";
    int Permissions = 0;
    bool MarkForDelete = false;
};
stUsers CurrentUser;

enum enUserMenueOptions
{
    eShowListUsers = 1, eAddNewUser = 2,
    eDeleteUser = 3, eUpdateUser = 4,
    eFindUser = 5, eBack = 6
};
enum enPermissions
{
    epShowListClients = 1, epAddNewClients = 2,
    epDeleteClients = 4, epUpdateClients = 8,
    epFindClients = 16, epManageUsers = 32,  epLoginToSystem=64, epTransactios=128, epAll=256
};


//File
stUsers ConvertLineUsertoRecord(string Line, string Seperator = "#//#")
{
    stUsers User;
    vector<string> vUserData;
    vUserData = SplitString(Line, Seperator);

    User.UserName = vUserData[0];
    User.Password = vUserData[1];
    User.Permissions = stoi( vUserData[2]);
    return User;
}
string ConvertRecordToLine(stUsers User, string Seperator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += User.UserName + Seperator;
    stClientRecord += EncryptPassword(User.Password) + Seperator;
    stClientRecord += to_string(User.Permissions)+ Seperator;
    return stClientRecord;
}
vector <stUsers> SaveUsersDataToFile(string FileName, vector <stUsers> vUsers)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (stUsers C : vUsers)
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

    return vUsers;
}
vector<stUsers> LoadUsersDataFromFile(string FileName)
{
    vector <stUsers> vUsers;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        stUsers Users;

        while (getline(MyFile, Line))
        {
            Users = ConvertLineUsertoRecord(Line);
            vUsers.push_back(Users);
        }
        MyFile.close();
    }
    return vUsers;
}

bool CheckAccessPermission(enPermissions permission)
{
    if (CurrentUser.Permissions  == enPermissions::epAll)
        return true;
    if ((permission & CurrentUser.Permissions) == permission)
        return true;
    else
        return false;
}
bool FindUserByUsernameAndPassword(stUsers User , stUsers& CurrentUser)
{
    vector<stUsers> vUsers = LoadUsersDataFromFile(UserFile);

    for (stUsers user : vUsers)
    {
        if (User.UserName == user.UserName && EncryptPassword(User.Password) == user.Password)
        {
            CurrentUser = user;
            return true;
        }
    }
    return false;
}
bool UserExsistByUsername(string Username, stUsers& user)
{
    vector<stUsers> vUser = LoadUsersDataFromFile(UserFile);
    
    for (stUsers User : vUser)
    {
        if (User.UserName == Username)
        {
            user = User;
            return true;
        }
    }
    return false;
}
bool FindUserByUsername(string Username)
{
    vector<stUsers> vUser = LoadUsersDataFromFile(UserFile);

    for (stUsers User : vUser)
    {
        if (User.UserName == Username)
        {
            return true;
        }
    }
    return false;
}
bool MarkUserForDeleteByUsername(string username, vector <stUsers>& vUsers)
{

    for (stUsers& C : vUsers)
    {

        if (C.UserName == username)
        {
            C.MarkForDelete = true;
            return true;
        }

    }
    return false;
}

//Read Functions

short ReadUserMenueOption()
{
    short Choice = 0;
    do
    {
        cout << "Choose what do you want to do? [1 to 6]? ";
        cin >> Choice;
    } while (!IsNumber(Choice) || (Choice > 7 || Choice < 1));

    return Choice;
}
stUsers ReadInfoLogin(stUsers User)
{
    do
    {
        cout << "\n🟢 Please enter the username: ";
        User.UserName = ReadText();
    } while (User.UserName.length()<1);
    do {
        cout << "🔑 Enter a password (at least 4 characters): ";
        User.Password = ReadText();
    } while (User.Password.length() < 4);

    return User;
}
int ReadPermissions()
{
    int Permission = 0;
    if (!Confirmation("Do you went to Login to System"))
    {
        return Permission;
    }
    Permission += enPermissions::epLoginToSystem;
    if (Confirmation("Do you went to give full access"))
    {
        Permission = enPermissions::epAll;
        return Permission;
    }
    if (Confirmation("Do you went to give Show Clients List"))
    {
        Permission += enPermissions::epShowListClients;
    }
    if (Confirmation("Do you went to give Add Clients"))
    {
        Permission += enPermissions::epAddNewClients;
    }
    if (Confirmation("Do you went to give Delete Clients"))
    {
        Permission += enPermissions::epDeleteClients;
    }
    if (Confirmation("Do you went to give Update Clients "))
    {
        Permission += enPermissions::epUpdateClients;
    }
    if (Confirmation("Do you went to give Find Clients"))
    {
        Permission += enPermissions::epFindClients;
    }
    if (Confirmation("Do you went to give Manage Users"))
    {
        Permission += enPermissions::epManageUsers;
    }
    return Permission;
}
stUsers ReadNewUsers()
{
    stUsers User;
    cout << "Enter UserName? ";
    User.UserName=ReadText();
    while (FindUserByUsername(User.UserName))
    {
        ShowMessage("The User already exists.", MessageType::Warning);
        cout << "Enter UserName? ";
        User.UserName = ReadText();
    }
    do {
        cout << "🔑 Enter a password (at least 4 characters): ";
        User.Password = ReadText();
    } while (User.Password.length() < 4);

    User.Permissions = ReadPermissions();

    return User;
}

//Display
void PrintUsersRecordLine(stUsers User)
{
    cout << "| " << left << setw(15) << User.UserName;
    cout << "| " << left << setw(10) << User.Password;
    cout << "| " << left << setw(40) << User.Permissions;
}
void PrintUserCard(stUsers user)
{
    cout << "\nThe following are the user  details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << user.UserName;
    cout << "\nPin Code     : " << user.Password;
    cout << "\nName         : " << user.Permissions;
    cout << "\n-----------------------------------\n";
}
void GoBackToManageUserMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowManageUsersMenu();

}


void ShowAllUserScreen()
{
    ShowHeader("\tList Of Users Screen");
    vector<stUsers> vUsers = LoadUsersDataFromFile(UserFile);
    cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(40) << "Permissions";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    if (vUsers.size() == 0)
        cout << "\t\t\t\tNo User Available In the System!";
    else

        for (stUsers User : vUsers)
        {
            PrintUsersRecordLine(User);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

void AddNewUsers()
{
    stUsers User;
    User = ReadNewUsers();
    if (Confirmation("Are you sure To add User"))
    {
        AddDataLineToFile(UserFile, ConvertRecordToLine(User));
        ShowMessage("User Add Successfuly.", MessageType::Success);
    }
}
void ShowAddNewUsersScreen()
{
    do
    {
        ShowHeader("Add New User Screen");
        AddNewUsers();
    } while (Confirmation("Do You Went To Add More User"));
}

void  DeleteUserByUsername(string username)
{
    vector<stUsers> vUser;
    vUser = LoadUsersDataFromFile(UserFile);
    if (FindUserByUsername(username))
    {
        if (username != "Admin" && username!=CurrentUser.UserName)
        {
            if (Confirmation("Are you sure to Delete user"))
            {
                MarkUserForDeleteByUsername(username, vUser);
                SaveUsersDataToFile(UserFile, vUser);
                ShowMessage("Delete Successfuly.", MessageType::Success);
            }
            else
            {
                ShowMessage("Cancel Delete.", MessageType::Info);
            }
        }
        else
        {
            ShowMessage("Can't Delete (Admin or Current) User!.", MessageType::Error);
        }
        
    }
    else
    {
        ShowMessage("Can't Find User.", MessageType::Error);
    }
}
void ShowDeleteUserScreen()
{
    do
    {
        ShowHeader("Delete User Screen");
        string Username;
        cout << "Enter User Name: ";
        //gitline(cin >> ws, Username);
        cin >> Username;
        DeleteUserByUsername(Username);
    } while (Confirmation("Do you went to Delete more User"));
}

void UpdateUserByUsername(string username , vector<stUsers> vUser)
{
    if (FindUserByUsername(username))
    {
        if (username != "Admin")
        {
            for (stUsers& user : vUser)
            {
                if (user.UserName == username)
                {
                    user = ReadNewUsers();
                }
            }
            SaveUsersDataToFile(UserFile, vUser);

            ShowMessage("\n\nClient Updated Successfully.", MessageType::Success);
        }
        else
        {
            ShowMessage("Can't Update Admin User.", MessageType::Error);
        }
    }
    else
    {
        ShowMessage("Cancel Update.", MessageType::Info);
    }
}

void ShowUpdateUserScreen()
{
    ShowHeader("Update User Screen");
    vector<stUsers> vUser;
    vUser = LoadUsersDataFromFile(UserFile);
    string Username;
    cout << "Enter User Name: ";
    //gitline(cin >> ws, Username);
    cin >> Username;
    UpdateUserByUsername(Username, vUser);

}

void ShowFindUserScreen()
{
    ShowHeader("Find User Screen");
    stUsers user;
    string Username;
    cout << "Enter User Name: ";
    //gitline(cin >> ws, Username);
    cin >> Username;
    if (UserExsistByUsername(Username,user))
    {
        ShowMessage("User found.", MessageType::Success);
        if (Confirmation("Do you went to show info of this user"))
        {
            PrintUserCard(user);
        }
    }

}

/**
 * @brief Executes the selected option from the main menu.
 */
void PerfromUserMenueOption(enUserMenueOptions UserMenueOption)
{
    switch (UserMenueOption)
    {
    case enUserMenueOptions::eShowListUsers:
        ShowAllUserScreen();
        GoBackToManageUserMenue();
        break;

    case enUserMenueOptions::eAddNewUser:
        ShowAddNewUsersScreen();
        GoBackToManageUserMenue();
        break;

    case enUserMenueOptions::eDeleteUser:
        ShowDeleteUserScreen();
        GoBackToManageUserMenue();
        break;

    case enUserMenueOptions::eUpdateUser:
        ShowUpdateUserScreen();
        GoBackToManageUserMenue();
        break;

    case enUserMenueOptions::eFindUser:
        ShowFindUserScreen();
        GoBackToManageUserMenue();
        break;

        case enUserMenueOptions::eBack:
        GoBackToMainMenue();
        break;
    }
}

/**
 * @brief Displays the main menu and handles user navigation.
 */
void ShowManageUsersMenu()
{
    if (!CheckAccessPermission(enPermissions::epManageUsers))
    {
        ShowMessage("Access Denied.\nYou do'nt have permission to Manage Users.", MessageType::Warning);
        GoBackToMainMenue();
    }
    ShowHeader("\tManage Users Menue Screen");
    cout << "\t[1] Show Users List.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User Info.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Back Main Menu.\n";
    cout << "===========================================\n";
    PerfromUserMenueOption((enUserMenueOptions)ReadUserMenueOption());
}