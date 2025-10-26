//#pragma once
//
//#include <iostream> 
//#include <string> 
//#include <iomanip> 
//#include <vector>
//#include <fstream>
//
//using namespace std;
//
//
//int RandomNumber(int From, int To)
//{
//	//Function to generate a random number  
//	int randNum = rand() % (To - From + 1) + From;
//
//	return randNum;
//}
//
//// Problem #1
//void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
//{
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			arr[i][j] = RandomNumber(1, 100);
//		}
//	}
//}
//
//void PrintMatrix(int arr[3][3], short Rows, short Cols)
//{
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			//  زجح ثلاث  تاغارف  عضول ماقرلأا  اهيف setw(3) 
//			cout << setw(3) << arr[i][j] << "     ";
//		}
//		cout << "\n";
//	}
//}
//// Problem #2
//int RowSum(int arr[3][3], short RowNumber, short Cols)
//{
//	int Sum = 0;
//
//	// Cols  ةقلح راركتلا يف  ةدمعلأا 
//
//	for (short j = 0; j <= Cols - 1; j++)
//	{
//		Sum += arr[RowNumber][j];
//	}
//	return Sum;
//}
//
//void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
//{
//
//	cout << "\nThe following are the sum of each row in the matrix : \n";
//
//	// Row ةقلح راركتلا  يف فوفصلا 
//
//	for (short i = 0; i < Rows; i++)
//	{
//		cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) <<
//			endl;
//	}
//}
//
//// Problem #3
//void SumMatrixRowsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
//{
//
//	// Array  عمج رصانع  فصلا يف  ةفوفصم  ةدحاو 
//
//	for (short i = 0; i < Rows; i++)
//	{
//		arrSum[i] = RowSum(arr, i, Cols);
//	}
//}
//
//void PrintRowsSumArray(int arr[3], short Rows)
//{
//	// Array  ةعابط رصانع ةفوفصملا  
//
//	cout << "\nThe following are the sum of each row in the matrix : \n";
//
//	for (short i = 0; i < Rows; i++)
//	{
//		cout << " Row " << i + 1 << " Sum = " << arr[i] << endl;
//	}
//}
//
//// Problem #4
//int ColSum(int arr[3][3], short Rows, short ColNumber)
//{
//	// عمج  رصانع  دومعلا 
//
//	int Sum = 0;
//
//	for (short i = 0; i <= Rows - 1; i++)
//	{
//		Sum += arr[i][ColNumber];
//	}
//	return Sum;
//}
//
//void PrintEachColSum(int arr[3][3], short Rows, short Cols)
//{
//	//  ةعابط عومجم لك  دومع 
//
//	cout << "\nThe following are the sum of each Col in the matrix : \n";
//
//	for (short j = 0; j < Cols; j++)
//	{
//		cout << " Col " << j + 1 << " Sum = " << ColSum(arr, Rows, j) <<
//			endl;
//	}
//}
//
//// Problem #5 
//void SumMatrixColsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
//{
//	for (short i = 0; i < Cols; i++)
//	{
//		arrSum[i] = ColSum(arr, Rows, i);
//	}
//}
//
//void PrintColsSumArray(int arr[3], short Cols)
//{
//	cout << "\nThe following are the sum of each Col in the matrix : \n";
//
//	for (short j = 0; j < Cols; j++)
//	{
//		cout << " Col " << j + 1 << " Sum = " << arr[j] << endl;
//	}
//}
//
//// Problem #6 
//void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
//{
//	int Counter = 0;
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			Counter++;
//			arr[i][j] = Counter;
//		}
//	}
//}
//
//// Problem #7 
//void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short	Cols)
//{
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			arrTransposed[i][j] = arr[j][i];
//		}
//	}
//}
//
//// problem #8
//void MultiplyMatrix(int Matrix1[3][3], int Matrix2[3][3], int MatrixResults[3][3], short Rows, short Cols)
//{
//
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			MatrixResults[i][j] = Matrix1[i][j] * Matrix2[i][j];
//
//		}
//	}
//}
//
//
//// Problem #9 
//void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols)
//{
//	short MiddleRow = Rows / 2;
//
//	for (short j = 0; j < Cols; j++)
//	{
//		printf(" %0*d  ", 2, arr[MiddleRow][j]);
//
//	}
//	cout << "\n";
//}
//
//void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols)
//{
//	short MiddleCol = Cols / 2;
//
//	for (short j = 0; j < Cols; j++)
//	{
//		printf(" %0*d  ", 2, arr[j][MiddleCol]);
//
//	}
//	cout << "\n";
//}
//
//// Problem #10 
//int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols)
//{
//	int Sum = 0;
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			Sum += Matrix1[i][j];
//		}
//	}
//	return Sum;
//}
//
//// Problem #11 
//bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short	Cols)
//{
//	return (SumOfMatrix(Matrix1, Rows, Cols) == SumOfMatrix(Matrix2, Rows,
//		Cols));
//}
//
//// problem #12
//bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short	Cols)
//{
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			if (Matrix1[i][j] != Matrix2[i][j])
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
//// Problem #13 
//bool IsIdentityMatrix(int Matrix[3][3], short Rows, short Cols)
//{
//	// Check Diagonal elements are 1 and rest elements are 0 
//
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			// check for diagonals element 
//			if (i == j && Matrix[i][j] != 1)
//			{
//				return false;
//			}
//			// check for rest elements 
//			else if (i != j && Matrix[i][j] != 0)
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
//// Problem #14 
//bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
//{
//	int FirstDiagElement = Matrix[0][0];
//
//	// Check Diagonal elements are 1 and rest elements are 0 
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			// check for diagonals element 
//			if (i == j && Matrix[i][j] != FirstDiagElement)
//			{
//				return false;
//			}
//			// check for rest elements 
//			else if (i != j && Matrix[i][j] != 0)
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
//
//// Problem #15 
//short CountNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
//{
//	short NumberCount = 0;
//
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			if (Matrix[i][j] == Number)
//				NumberCount++;
//		}
//	}
//	return NumberCount;
//}
//
//// Problem #16 
//short IsSparseMatrix(int Matrix[3][3], short Rows, short Cols)
//{
//	short MatrixSize = Rows * Cols;
//
//	return (CountNumberInMatrix(Matrix, 0, 3, 3) >= (MatrixSize / 2));
//}
//
//// problem #17
//bool IsNumberInMatrix(int Matrix[3][3], int Number,
//	short Rows, short Cols)
//{
//
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			if (Matrix[i][j] == Number)
//				return true;
//		}
//	}
//	return false;
//
//}
//
//// Problem #18 
//void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
//{
//	int Number;
//
//	for (short i = 0; i <= Rows - 1; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			Number = Matrix1[i][j];
//
//			if (IsNumberInMatrix(Matrix2, Number, Rows, Cols))
//			{
//				cout << setw(3) << Number << "   ";
//			}
//		}
//	}
//
//}
//
//// Problem #19 
//int MinNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
//{
//	int Min = Matrix[0][0];
//
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			if (Matrix[i][j] < Min)
//				Min = Matrix[i][j];
//		}
//	}
//	return Min;
//}
//
//int MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
//{
//	int Max = Matrix[0][0];
//
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			if (Matrix[i][j] > Max)
//				Max = Matrix[i][j];
//		}
//	}
//	return Max;
//}
//
//// Problem #20 
//bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols)
//{
//
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols / 2; j++)
//		{
//			if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
//				return false;
//		}
//	}
//
//	return true;
//
//}
//
//// Problem #21 
//void PrintFibonacciUsingLoop(short Number)
//{
//	int  FebNumber = 0;
//	int Prev2 = 0, Prev1 = 1;
//
//	cout << "1   ";
//
//	for (short i = 2; i <= Number; i++)
//	{
//		FebNumber = Prev1 + Prev2;
//
//		cout << FebNumber << "   ";
//
//		Prev2 = Prev1;
//		Prev1 = FebNumber;
//
//	}
//
//}
//
//// Problem #22 
//void PrintFibonacciUsingRecurssion(short Number, int Prev1, int Prev2)
//{
//	int  FebNumber = 0;
//
//	if (Number > 0)
//	{
//		FebNumber = Prev2 + Prev1;
//
//		Prev2 = Prev1;
//		Prev1 = FebNumber;
//
//		cout << FebNumber << "   ";
//
//		PrintFibonacciUsingRecurssion(Number - 1, Prev1, Prev2);
//	}
//
//}
//
/////////////////////////////////////////+++string+++/////////////////////////////
//
//// Problem #23 
//string ReadString()
//{
//	string S1 = " ";
//
//	cout << "Pleas Enter your string ? \n";
//	getline(cin, S1);
//
//	return S1;
//
//}
//
//void PrintFirstLetterOfEachWord(string S1)
//{
//	bool isFirstLetter = true;
//
//	cout << "\n First letters of this string : \n";
//
//	for (int i = 0; i < S1.length(); i++)
//	{
//		if (S1[i] != ' ' && isFirstLetter)
//		{
//			cout << S1[i] << endl;
//		}
//
//		isFirstLetter = (S1[i] == ' ' ? true : false);
//	}
//}
//
//// Problem #24 
//string  UpeerFirstLetterOfEachWord(string S1)
//{
//	bool isFirstLetter = true;
//
//	cout << "\n First letters of this string : \n";
//
//	for (int i = 0; i < S1.length(); i++)
//	{
//		if (S1[i] != ' ' && isFirstLetter)
//		{
//			S1[i] = toupper(S1[i]);
//		}
//
//		isFirstLetter = (S1[i] == ' ' ? true : false);
//	}
//	return S1;
//}
//
//// Problem #25 
//string LowerFirstLetterOfEachWord(string S2)
//{
//	bool isFirstLetter = true;
//
//	for (int i = 0; i < S2.length(); i++)
//	{
//		if (S2[i] != ' ' && isFirstLetter)
//		{
//			S2[i] = tolower(S2[i]);
//		}
//
//		isFirstLetter = (S2[i] == ' ' ? true : false);
//	}
//	return S2;
//}
//
//// Problem #26 
//string UpperAllString(string S3)
//{
//
//	for (int i = 0; i < S3.length(); i++)
//	{
//		S3[i] = toupper(S3[i]);
//	}
//	return S3;
//}
//
//string LowerAllString(string S3)
//{
//
//	for (int i = 0; i < S3.length(); i++)
//	{
//		S3[i] = tolower(S3[i]);
//	}
//	return S3;
//}
//
//// Problem #27 
//char ReadChar()
//{
//	char Ch1;
//
//	cout << "Pleas Enter a Character ? \n";
//	cin >> Ch1;
//
//	return Ch1;
//
//}
//
//char InvertLetterCase(char Char1)
//{
//
//	//  اذإ ناك  فرحلا اريغص false اذإ ناك فرحلا اريبك  لإو true عجرت isupper(Char1) 
//
//	return isupper(Char1) ? tolower(Char1) : toupper(Char1);
//}
//
//// Problem #28 
//string InvertAllStringLetterCase(string S1)
//{
//	for (int i = 0; i < S1.length(); i++)
//	{
//		S1[i] = InvertLetterCase(S1[i]);
//	}
//	return S1;
//}
//
////problem #29
//enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
//
//int CountLetters(string S5, enWhatToCount WhatToCount = enWhatToCount::All)
//{
//	// enWhatToCount WhatToCount = enWhatToCount::All 
//	// All اذإ مل ددحت رايخ ةناقملل  عجري لكشب يئاقلت    
//	if (WhatToCount == enWhatToCount::All)
//	{
//		return  S5.length();
//	}
//
//	int Counter = 0;
//
//	for (int i = 0; i < S5.length(); i++)
//	{
//		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S5[i]))
//			Counter++;
//
//		if (WhatToCount == enWhatToCount::SmallLetters && islower(S5[i]))
//			Counter++;
//	}
//	return  Counter;
//
//}
//
//
//// Problem #31 
//short CountLetter(string S6, char Letter, bool MatchCase = true)
//{
//	short Counter = 0;
//
//	for (short i = 0; i <= S6.length(); i++)
//	{
//		if (MatchCase)
//		{
//			if (S6[i] == Letter)
//				Counter++;
//		}
//		else
//		{
//			// ةنراقملل طقف Small ليوحت  فرحلأا ىلا  
//			if (tolower(S6[i]) == tolower(Letter))
//				Counter++;
//
//		}
//	}
//	return Counter;
//}
//
//// Problem #32 
//bool IsVowel(char Ch4)
//{
//	Ch4 = tolower(Ch4);
//
//	return ((Ch4 == 'a') || (Ch4 == 'e') || (Ch4 == 'i') || (Ch4 == 'o') || (Ch4 == 'u'));
//}
//
//// Problem #33 
//short CountVowels(string S7)
//{
//	short Counter = 0;
//
//	for (short i = 0; i < S7.length(); i++)
//	{
//		if (IsVowel(S7[i]))
//		{
//			Counter++;
//		}
//	}
//	return Counter;
//}
//
//// Problem #34 
//void PrintVowels(string S8)
//{
//	cout << "\nVowels in string are : ";
//
//	for (short i = 0; i < S8.length(); i++)
//	{
//		if (IsVowel(S8[i]))
//		{
//			cout << S8[i] << "   ";
//		}
//	}
//}
//
//// Problem #35 
//void PrintEachWordInString(string S9)
//{
//	string delim = " "; // Delimiter  
//
//	cout << "\nYour string words are : \n\n";
//	short pos = 0;
//	string sWord; // define a string variable 
//
//	// use fine() function to get the position of the delimiters
//	while ((pos = S9.find(delim)) != std::string::npos)
//	{
//		// دجوا  ( دحلا - غارفلا   S9.find(delim) 
//		sWord = S9.substr(0, pos);
//
//		if (sWord != "")
//		{
//			cout << sWord << endl;
//		}
//		// فذحا  نم (0 ىلا  ددع فرحلأا  + دحلا  
//		// erase() until positon and move to next word 
//		S9.erase(0, pos + delim.length());
//	}
//
//	//  ةعابط  ةملكلا  ةريخلأا نم  صنلا 
//	if (S9 != "")
//	{
//		// it print last word of the string 
//		cout << S9 << endl;
//	}
//}
//
//// Problem #36 
//short CountWords(string S9)
//{
//	string delim = " "; // Delimiter  
//	short Count = 0;
//	short pos = 0;
//	string sWord; // define a string variable 
//
//	// use fine() function to get the position of the delimiters
//	while ((pos = S9.find(delim)) != std::string::npos)
//	{
//		// دجوا  ( دحلا - غارفلا   S9.find(delim) 
//		sWord = S9.substr(0, pos);
//
//		if (sWord != "")
//		{
//			Count++;
//		}
//		// فذحا  نم (0 ىلا  ددع فرحلأا  + دحلا  
//		// erase() until positon and move to next word 
//		S9.erase(0, pos + delim.length());
//	}
//
//	//  ةعابط  ةملكلا  ةريخلأا نم  صنلا 
//	if (S9 != "")
//	{
//		// it print last word of the string 
//		Count++;
//	}
//	return Count;
//}
//
//// Problem #37 
//vector <string> SplitString(string S9, string Delim)
//{
//	vector <string> vString;
//
//	short pos = 0;
//	string sWord; // define a string variable 
//
//	// use fine() function to get the position of the delimiters
//	while ((pos = S9.find(Delim)) != std::string::npos)
//	{
//		// دجوا  ( دحلا - غارفلا   S9.find(delim) 
//		sWord = S9.substr(0, pos);
//
//
//		if (sWord != "")
//		{
//			vString.push_back(sWord);
//		}
//		// فذحا  نم (0 ىلا  ددع فرحلأا  + دحلا  
//		// erase() until positon and move to next word 
//		S9.erase(0, pos + Delim.length());
//	}
//
//	//  ةعابط  ةملكلا  ةريخلأا نم  صنلا 
//	if (S9 != "")
//	{
//		// it print last word of the string 
//		vString.push_back(S9);
//
//	}
//	return vString;
//
//}
//
//// Problem #38 
//string TrimLeft(string S10)
//{
//	for (short i = 0; i < S10.length(); i++)
//	{
//		if (S10[i] != ' ')
//		{
//			return  S10.substr(i, S10.length() - i);
//		}
//	}
//	return "";
//
//}
//
//string TrimRight(string S10)
//{
//	for (short i = S10.length() - 1; i >= 0; i--)
//	{
//		if (S10[i] != ' ')
//		{
//			return  S10.substr(0, i + 1);
//
//		}
//	}
//	return "";
//
//}
//
//string Trim(string S10)
//{
//	return TrimLeft(TrimRight(S10));
//
//}
//
////problem #39
//string JoinString(vector <string> vString, string	Delim = " ")
//{
//	string S1 = "";
//	for (string& s : vString)
//	{
//		S1 = S1 + s + Delim;
//	}
//	// ريخلأا Delim  فذح 
//	return S1.substr(0, S1.length() - Delim.length());
//}
//
//// Problem #40 
//string JoinString(string arrString[], short	Length, string Delim)
//{
//	string S1 = "";
//	for (short i = 0; i < Length; i++)
//	{
//		S1 = S1 + arrString[i] + Delim;
//	}
//	// ريخلأا Delim  فذح 
//	return S1.substr(0, S1.length() - Delim.length());
//}
//
//// Problem #41 
//string ReverseWordsInString(string S11)
//{
//	vector<string> vString;
//	string S2 = "";
//
//	vString = SplitString(S11, " ");
//
//	// declare iterator 
//	vector<string>::iterator iter = vString.end();
//
//	// Pointer  مادختساب Vector رورملا ىلع  رصانع  
//	while (iter != vString.begin())
//	{
//		--iter;
//		S2 += *iter + " ";
//	}
//
//	S2 = S2.substr(0, S2.length() - 1); //remove last space. 
//
//	return S2;
//}
//
//// Problem #42 
//string ReplaceWordInStringUsingBuiltInFunction(string	S12, string StringToReplace, string sRepalceTo)
//{
//	//  ثحبلا نع  ةملكلا  دارملا اهليدبت  
//	short pos = S12.find(StringToReplace);
//
//	// له ةملكلا  ةدوجوم ل يواست  غارف 
//	while (pos != std::string::npos)
//	{
//		S12 = S12.replace(pos,
//			StringToReplace.length(), sRepalceTo);
//
//		//  ثحبلا نع  ةملكلا  دارملا اهليدبت  
//		pos = S12.find(StringToReplace);
//		//find next    
//	}
//
//	return S12;
//}
//
//// Problem #43 
//string ReplaceWordInStringUsingSplit(string S13, string StringToReplace, string	sRepalceTo, bool MatchCase = true)
//{
//	vector <string> vString = SplitString(S13, " ");
//
//	for (string& s : vString)
//	{
//		if (MatchCase)
//		{
//			if (s == StringToReplace)
//			{
//				s = sRepalceTo;
//			}
//		}
//		else
//		{
//			if (LowerAllString(s) == LowerAllString(StringToReplace))
//			{
//				s = sRepalceTo;
//			}
//		}
//	}
//	return JoinString(vString, " ");
//}
//
//// Problem #44 
//string RemovePunctuationsFromString(string S14)
//{
//	string S2 = "";
//
//	for (short i = 0; i < S14.length(); i++)
//	{
//		if (!ispunct(S14[i]))
//		{
//			S2 += S14[i];
//		}
//	}
//
//	return S2;
//}
//
//
////////////////////////////////// --++ client++-- //////////////////////
//
//// problem #45
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
//stClient ReadNewClient()
//{
//	stClient Client;
//
//	cout << "Enter Account Number ? ";
//
//	// Usage of std::ws will extract all the whitespace character
//	getline(cin >> ws, Client.AccountNumber);
//
//	cout << "Enter PinCode ? ";
//	getline(cin, Client.PinCode);
//
//	cout << "Enter Name ? ";
//	getline(cin, Client.Name);
//
//	cout << "Enter Phone ? ";
//	getline(cin, Client.Phone);
//
//	cout << "Enter Account Balance ? ";
//	cin >> Client.AccountBalance;
//
//	return Client;
//
//}
//
//string CounvertRecordToLine(stClient Client, string Separator = "#//#")
//{
//	string stClientRecord = "";
//
//	stClientRecord += Client.AccountNumber + Separator;
//	stClientRecord += Client.PinCode + Separator;
//	stClientRecord += Client.Name + Separator;
//	stClientRecord += Client.Phone + Separator;
//	stClientRecord += to_string(Client.AccountBalance);
//
//	return stClientRecord;
//}
//
//// problem #46
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
//void PrintClientRecord(stClient Client)
//{
//	cout << "\n\nThe following is the extracted client record : \n\n";
//
//	cout << "Account Number  : " << Client.AccountNumber << endl;
//	cout << "PinCode         : " << Client.PinCode << endl;
//	cout << "Name            : " << Client.Name << endl;
//	cout << "Phone           : " << Client.Phone << endl;
//	cout << "Account Balance : " << Client.AccountBalance << endl;
//}
//void PrintClientLine(stClient Client)
//{
//
//	cout << "| " << left << setw(15) << Client.AccountNumber;
//	cout << "| " << left << setw(10) << Client.PinCode;
//	cout << "| " << left << setw(30) << Client.Name;
//	cout << "| " << left << setw(12) << Client.Phone;
//	cout << "| " << left << setw(12) << Client.AccountBalance;
//}
//
//// Problem #47 
//const string ClientsFileName = "Clients.txt";
//
//void AddDataLineToFile(string FileName, string strDataLine)
//{
//	fstream MyFile;
//	char Revision = 'y';
//
//	MyFile.open(FileName, ios::out | ios::app);
//
//	if (MyFile.is_open())
//	{
//		MyFile << strDataLine << endl;
//		MyFile.close();
//	}
//}
//
//void AddNewClient()
//{
//	stClient Client;
//	Client = ReadNewClient();
//	AddDataLineToFile(ClientsFileName, CounvertRecordToLine(Client));
//}
//
//void AddClients()
//{
//	char AddMore = 'Y';
//
//	do
//	{
//		system("cls");
//		cout << "Adding New Client : \n\n";
//		AddNewClient();
//
//		cout << "\nClient Added Successfully , do you want to add more clients ? ";
//		cin >> AddMore;
//
//	} while (toupper(AddMore) == 'Y');
//
//}
//
//// Problem #48 
//vector <stClient> LoadClientsDataFromFile(string FileName)
//{
//	vector <stClient> vClient;
//
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
//	}
//
//	return vClient;
//}
//
//void PrintAllClientsData(vector <stClient> vClients)
//{
//	cout << "\n\t\t\t\t\t Client List (" << vClients.size() << ")  Client(s). ";
//	cout << "\n---------------------------------------------------------";
//	cout << "-------------------------------------------\n" << endl;
//
//	cout << "| " << left << setw(15) << "Account Number";
//	cout << "| " << left << setw(10) << "Pin Code ";
//	cout << "| " << left << setw(30) << "Client Name";
//	cout << "| " << left << setw(12) << "Phone ";
//	cout << "| " << left << setw(12) << "Balance ";
//
//	cout << "\n---------------------------------------------------------";
//	cout << "-------------------------------------------\n" << endl;
//
//	for (stClient Client : vClients)
//	{
//		PrintClientLine(Client);
//
//		cout << endl;
//	}
//
//	cout << "\n---------------------------------------------------------";
//	cout << "-------------------------------------------\n" << endl;
//}
//
//// Problem #49 
//bool FindClientByAccountNumber(string AccountNumber, vector <stClient> Clients, stClient& Client)
//{
//	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
//
//	for (stClient C : vClients)
//	{
//		if (C.AccountNumber == AccountNumber)
//		{
//			Client = C;
//			return true;
//		}
//	}
//	return false;
//}
//
//bool FindClientByAccountNumber(string AccountNumber, stClient& Client)
//{
//	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
//
//	for (stClient C : vClients)
//	{
//		if (C.AccountNumber == AccountNumber)
//		{
//			Client = C;
//			return true;
//		}
//	}
//	return false;
//}
//
//string ReadClientAccountNumber()
//{
//	string AccountNumber = "";
//
//	cout << "\nPlease enter AccountNumber ? ";
//	cin >> AccountNumber;
//
//	return AccountNumber;
//}
//
//// Problem #50 
//
//vector <stClient> SaveClientsDataToFile(string FileName, vector <stClient> vClients)
//{
//	fstream MyFile;
//
//	MyFile.open(FileName, ios::out); //overwrite 
//
//	string DataLine;
//	if (MyFile.is_open())
//	{
//
//		for (stClient C : vClients)
//		{
//			// we only write record that are not marked for delete 
//			DataLine = CounvertRecordToLine(C);
//			MyFile << DataLine << endl;
//		}
//		MyFile.close();
//	}
//	return vClients;
//}
//
//
//// Problem #51 
//stClient ChangeClientRecord(string AccountNumber)
//{
//	stClient Client;
//
//	Client.AccountNumber = AccountNumber;
//
//	// Uasge of std::ws will extract allthe whitespace character 
//	// whitespace  دنع راركت  لاخدلإا - يف ضعب  نايحلأا متي زواجت  لاخدلإا  هنلأ دق نزخي  
//
//	cout << "Enter PinCode ? ";
//	getline(cin >> ws, Client.PinCode);
//
//	cout << "Enter Name ? ";
//	getline(cin, Client.Name);
//
//	cout << "Enter Phone ? ";
//	getline(cin, Client.Phone);
//
//	cout << "Enter Account Balance ? ";
//	cin >> Client.AccountBalance;
//
//	return Client;
//
//}
//
//bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
//{
//	stClient Client;
//	char Answer = 'n';
//
//	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
//	{
//		PrintClientRecord(Client);
//
//		cout << "\n\nAre you sure you want Update client ? n/y ? ";
//		cin >> Answer;
//
//		if (Answer == 'y' || Answer == 'Y')
//		{
//			for (stClient& C : vClients)
//			{
//				if (C.AccountNumber == AccountNumber)
//				{
//					C = ChangeClientRecord(AccountNumber);
//					break;
//				}
//			}
//			SaveClientsDataToFile(ClientsFileName, vClients);
//
//
//			// Refresh Clients 
//			vClients = LoadClientsDataFromFile(ClientsFileName);
//
//			cout << "\n\n Client Updated Successfully. \n";
//			return true;
//		}
//	}
//	else
//	{
//		cout << "\nClient with Account Number (" << AccountNumber << ") is NOT Found!\n";
//		return false;
//	}
//
//
//}
