//#pragma once
//
//#include<iostream>
//#include<string>
//#include<iomanip>
//#include<vector>
//#include<fstream>
//using namespace std;
//
//struct stClient
//{
//	string AccountNumber = "";
//	string PinCode = "";
//	string Name = "";
//	string Phone = "";
//	int AccountBalance = 0;
//
//};
//
//enum emChoose { Show = 1, Add = 2, Delete = 3, Update = 4, Find = 5, Exit = 6 };
//const string ClientsFileName = "Clients.txt";
/////////
//void ChooseOpretion();
//void MainMenueScreen();
//
//
//
//void RestScreen()
//{
//	system("cls");
//
//}
//void Header(string Tital)
//{
//	RestScreen();
//	cout << "------------------------------------------------------------" << endl;
//	cout << "                       "<< Tital<<"                         " << endl;
//	cout << "------------------------------------------------------------" << endl;
//}
//void PreesAnyKey()
//{
//	cout << "Press Any Key To go Back to Main Meune....";
//	system("pause>0");
//	cout << endl;
//	MainMenueScreen();
//}
//
//
//short ReadShort(string Message="")
//{
//	cout << Message;
//	short number=0;
//	cin >> number;
//	return number;
//}
//int ReadNumber(string Message="")
//{
//	cout << Message;
//	int number=0;
//	cin >> number;
//	return number;
//}
//string ReadString(string Message = "")
//{
//	cout << Message;
//	string S1 = "";
//	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // تصحيح هنا
//	getline(cin, S1);
//
//	return S1;
//}
//char ReadChar(string Message = "")
//{
//	cout << Message;
//	char ch = ' ';
//	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
//	cin >> ch;
//	return ch;
//}
//
//vector <string> SplitString(string S9, string Delim)
//{
//	vector <string> vString;
//
//	short pos = 0;
//	string sWord; 
//	while ((pos = S9.find(Delim)) != std::string::npos)
//	{
//		sWord = S9.substr(0, pos);
//
//
//		if (sWord != "")
//		{
//			vString.push_back(sWord);
//		}
//		S9.erase(0, pos + Delim.length());
//	}
//
//	if (S9 != "")
//	{
//		vString.push_back(S9);
//
//	}
//	return vString;
//
//}
//
//stClient CounvertLineToRecord(string Line, string Separator = "#//#")
//{
//	stClient Client;
//	vector <string> vClientData;
//
//	vClientData = SplitString(Line, Separator);
//
//	Client.AccountNumber = vClientData[0];
//	Client.PinCode = vClientData[1];
//	Client.Name = vClientData[2];
//	Client.Phone = vClientData[3];
//	Client.AccountBalance = stod(vClientData[4]); // case string to double 
//
//	return Client;
//
//}
//
//bool LoadClientsDataFromFile(vector <stClient>& vClient , string FileName)
//{
//	fstream MyFile;
//
//	MyFile.open(FileName, ios::in);
//
//	if (MyFile.is_open())
//	{
//		string Line;
//		stClient Clinet;
//
//		while (getline(MyFile, Line))
//		{
//			Clinet = CounvertLineToRecord(Line);
//
//			vClient.push_back(Clinet);
//		}
//		MyFile.close();
//		return true;
//	}
//		return false;
//}
//
//
//bool FindClientByAccountNumber(string AccountNumber, stClient& Client)
//{
//	vector <stClient> vClients;
//	if (LoadClientsDataFromFile(vClients, ClientsFileName))
//	{
//		for (stClient C : vClients)
//	    {
//	    	if (C.AccountNumber == AccountNumber)
//	    	{
//	    		Client = C;
//	    		return true;
//	    	}
//	    }
//
//	}
//	else {
//		cout << "!Error to load File." << endl;
//		cout << "Press Any Key To go Back to Main Meune....";
//		system("pause>0");
//		MainMenueScreen();
//	}
//
//
//
//void ShowAllClients();
//{
//
//
//		Header("Show All Clients");
//		////string filename = NameFile();
//		//vector<stClient> vClient;
//		////vClient=LoadClientsDataFromFile("Clients.txt");
//		////if (LoadClientsDataFromFile(vClient, ClientsFileName + ".txt"))
//		//if (LoadClientsDataFromFile(vClient, ClientsFileName ))
//		//{
//		//    PrintAllClientsData(vClient);
//		//}
//		//else {
//		//	cout << "!Error Can`t  Access the File [" << ClientsFileName << "] Maybe the name is wrong or doesn`t exist." << endl;
//		//}
//
//}
//	
//	PreesAnyKey();
//
//void AddClients();
//{
//	Header("Add Clients");
//	
//
//	PreesAnyKey();
//}
//
//void DeleteClients();
//{
//	Header("Delete Client");
//	
//	
//	PreesAnyKey();
//}
//void UpdateClients();
//{
//	Header("Update Client");
//
//	
//	PreesAnyKey();
//}
//
//void  FindClient();
//{
//	Header("Find Client");
//	stClient Client;
//	Client.AccountNumber = ReadString("Entter Account number: ");
//	if (FindClientByAccountNumber(Client.AccountNumber,Client))
//	{
//
//	}
//	else
//	{
//		cout << " Can no found the client" << endl;
//	}
//
//	PreesAnyKey();
//}
//	
//
//
//void ChooseOpretion(emChoose choose);
//{
//	switch (choose)
//	{
//	case emChoose::Show :
//		ShowAllClients();
//	case emChoose::Add:
//		AddClients();
//	case emChoose::Delete :
//		DeleteClients();
//	case emChoose::Update :
//		UpdateClients();
//	case emChoose::Find :
//		FindClient();
//	case emChoose::Exit :
//		system("close");
//	default:
//		MainMenueScreen();
//		break;
//	}
//}
//
//void MainMenueScreen()
//{
//	Header("Main Meune Screen");
//
//	cout << "      [1] Show Client List." << endl;
//	cout << "      [2] Add New Client." << endl;
//	cout << "      [3] Delete Client." << endl;
//	cout << "      [4] Update Client Info." << endl;
//	cout << "      [5] Find Client." << endl;
//	cout << "      [6] Exit." << endl;
//	cout << "==========================================================" << endl;
//	ChooseOpretion( (emChoose) ReadNumber("Choose number of Opertions do you went to do [1 ,6 ]: "));
//
//
//}