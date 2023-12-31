#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen :protected clsScreen

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

    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\Find Currency Screen");

        cout << "\nFind Currency by : (1) Code or (2) Country ? ";

        short Answer = 1;
        string CurrencyCode = "";
        string CurrencyCountry = "";

        cin >> Answer;

        if(Answer == 1)
        {

            cout << "\n\nPlease Enter Currency Code :";
            cin >> CurrencyCode;


            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

            if (!Currency.IsEmpty())
            {
                cout << "\n\nCurrency Found :) \n";

                _PrintCurrency(Currency);

            }

            else
            {
                cout << "\n\nCurrency NOT Found !! \n";
            }

        }

        else if (Answer == 2)
        {
            cout << "\n\nPlease Enter Currency Country :";
            cin >> CurrencyCountry;


            clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCountry);

            if (!Currency.IsEmpty())
            {
                cout << "\n\nCurrency Found :) \n";

                _PrintCurrency(Currency);

            }

            else
            {
                cout << "\n\nCurrency NOT Found !! \n";
            }

        }

        else
        {
            cout << "\n\nInvalid Input !! \n";
        }

    }
};