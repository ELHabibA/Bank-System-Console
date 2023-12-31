#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"

class clsTransferScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cin >> AccountNumber;
        return AccountNumber;
    }

    static  string _PrepareLogInRecord(float Amout, clsBankClient ClientFrom, clsBankClient ClientTo,  string Seperator = "#//#")
    {
        string LoginRecord = "";
        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += ClientFrom.AccountNumber() + Seperator;
        LoginRecord += ClientTo.AccountNumber() + Seperator;
        LoginRecord += to_string(Amout) + Seperator;
        LoginRecord += to_string(ClientFrom.AccountBalance) + Seperator;
        LoginRecord += to_string(ClientTo.AccountBalance) + Seperator;
        LoginRecord += CurrentUser.GetUserName();
        return LoginRecord;
    }

    static void _RegisterTransfer(float Amout, clsBankClient ClientFrom, clsBankClient ClientTo)
    {

        string stDataLine = _PrepareLogInRecord(Amout, ClientFrom, ClientTo);

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t   Transfer Screen");

        cout << "\nPlease enter Account number to transfer From: ";

        string AccountFromNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExist(AccountFromNumber))
        {
            cout << "\nClient with [" << AccountFromNumber << "] does not exist.\n";
            AccountFromNumber = _ReadAccountNumber();
        }

        clsBankClient ClientFrom = clsBankClient::Find(AccountFromNumber);
        _PrintClient(ClientFrom);

        cout << "\nPlease enter Account number to transfer To: ";


        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient ClientTo = clsBankClient::Find(AccountNumber);
        _PrintClient(ClientTo);


        double Amount = 0;
        cout << "\nPlease enter Transfer amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        while (Amount > ClientFrom.AccountBalance)
        {
            cout << "\nAmount Exceeds the available account balance, Enter an other amount ! ";
        }

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            ClientFrom.Withdraw(Amount);
            ClientTo.Deposit(Amount);

         
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

        cout << "\nTransfer Done Successfully \n ";


        _RegisterTransfer(Amount, ClientFrom, ClientTo);

        _PrintClient(ClientFrom);
        _PrintClient(ClientTo);

    }

};

