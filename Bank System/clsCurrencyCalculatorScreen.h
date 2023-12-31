#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen :protected clsScreen

{
private:

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\n Currency Card:";
        cout << "\n___________________";
        cout << "\n Country   : " << Currency.Country();
        cout << "\n Code    : " << Currency.CurrencyCode();
        cout << "\n Name   : " << Currency.CurrencyName();
        cout << "\n Rate/(1$)       : " << Currency.Rate();
        cout << "\n___________________\n";

    }

    static string  ReadtCurrencyCode()
    {
        string CurrencyCode = "";

        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        return CurrencyCode;
    }

public:

    static void ShowCurrencyCalculatorScreen()
    {

        _DrawScreenHeader("\tUpdate Currency Rate Screen");

        string Currency1Code = "";

        cout << "\nPlease Enter Currency 1 Code: ";
        Currency1Code = ReadtCurrencyCode();
        clsCurrency Currency1 = clsCurrency::FindByCode(Currency1Code);

        string Currency2Code = "";
        cout << "\nPlease Enter Currency 2 Code: ";
        Currency2Code = ReadtCurrencyCode();
        clsCurrency Currency2 = clsCurrency::FindByCode(Currency2Code);

        float Amount = 0;
        cout << "\nEnter the Amount: ";
        cin >> Amount;

        cout << "\nConvert from: ";
        _PrintCurrency(Currency1);

        cout << "\n " << Amount << " " << Currency1Code << " = " << Amount / Currency1.Rate() << "USD";


        if (Currency2Code != clsString::UpperAllString("USD"))
        {
            cout << "\n\nTo: ";
            _PrintCurrency(Currency2);

            cout << "\n " << Amount << " " << Currency1Code << " = " << (Amount / Currency1.Rate()) * Currency2.Rate() << "USD";

        }

       
    }
};