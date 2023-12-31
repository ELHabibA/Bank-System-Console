#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyRateScreen :protected clsScreen

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

public:

    static void ShowUpdateCurrencyRateScreen()
    {

        _DrawScreenHeader("\tUpdate Currency Rate Screen");

        string CurrencyCode = "";

        cout << "\nPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

        _PrintCurrency(Currency);

        cout << "\nAre you sure you want to update this Currency Rate y/n? ";

        char Answer = 'n';
        float NewRate;
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";


            cout << "\n\nEnter new Rate : ";
            cin >> NewRate;

            Currency.UpdateRate(NewRate);
            
            cout << "\nAccount Updated Successfully :)\n";

            _PrintCurrency(Currency);
        }

    }
};