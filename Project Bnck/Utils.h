#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h> 
#include <regex>

using namespace std;

enum class MessageType {
    Error,
    Success,
    Warning,
    Info
};

//Declaration
void ShowMessage(string message, MessageType type);

/**
        Header of screen
**/
void ShowHeader(string Tital)
{
    system("cls");
    cout << "\n-----------------------------------\n";
    cout << Tital;
    cout << "\n-----------------------------------\n";
}


/**
        Check functions
**/
bool Confirmation(string message)
{
    char confirm = 'N';
    cout << message << "? Y/N?";
    cin >> confirm;
    return (toupper(confirm) == 'Y');
}

/**
 * @brief Checks if the given string is a valid number (integer or decimal).
 * @param input The input string to check.
 * @return True if the input represents a valid number, otherwise false.
 */
bool IsNumber(const string& input)
{
    // Trim spaces first (optional)
    if (input.empty())
        return false;

    // Regular expression for numbers (integer or decimal)
    static const regex numberPattern(R"(^[+-]?(\d+(\.\d+)?|\.\d+)$)");

    return regex_match(input, numberPattern);
}

/**
 * @brief Reads an integer safely from user input, checking that the input is numeric.
 * @param prompt The message shown to the user.
 * @return A valid integer entered by the user.
 */
bool IsNumber(int value)
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        ShowMessage("Enter A Valid Number.", MessageType::Error);
        return false;
    }
    else
    {
        cin.ignore(1000, '\n');
        return true;
    }
}

/**
        Messages for System
**/

void ShowMessage(string message, MessageType type)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    switch (type)
    {
    case MessageType::Error:
        SetConsoleTextAttribute(hConsole, 12);
        cout << "❌ [ERROR] " << message << endl;
        Beep(700, 300);
        break;

    case MessageType::Success:
        SetConsoleTextAttribute(hConsole, 10);
        cout << "✅ [SUCCESS] " << message << endl;
        break;

    case MessageType::Warning:
        SetConsoleTextAttribute(hConsole, 14); 
        cout << "⚠️ [WARNING] " << message << endl;
        Beep(900, 200);
        break;

    case MessageType::Info:
        SetConsoleTextAttribute(hConsole, 11);
        cout << "ℹ️ [INFO] " << message << endl;
        break;

    default:
        SetConsoleTextAttribute(hConsole, 7);
        cout << message << endl;
        break;
    }

    SetConsoleTextAttribute(hConsole, 7);
}

/**
 * @brief Splits a given string into a vector of substrings based on a delimiter.
 */
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;
}

string TrimLeft(string Text)
{
	for (short i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ')
		{
			return  Text.substr(i, Text.length() - i);
		}
	}
	return "";

}

string TrimRight(string Text)
{
	for (int i = Text.length() - 1; i >= 0; i--)
	{
		if (Text[i] != ' ')
		{
			return  Text.substr(0, i + 1);

		}
	}
	return "";

}

string Trim(string Text)
{
    return TrimLeft(TrimRight(Text));
}

string ReadText()
{
    string user;
    getline(cin >> ws, user);
    return Trim(user);
}

string EncryptPassword(const string& password) {
    string encrypted = password;
    for (char& c : encrypted) c += 3;
    return encrypted;
}

string DecryptPassword(const string& encrypted) {
    string decrypted = encrypted;
    for (char& c : decrypted) c -= 3;
    return decrypted;
}
