#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"


class clsLogedInUser {


private:

    string _Time;
    string _UserName;
    string _Password;
    int _Permissions;

    static clsLogedInUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsLogedInUser(vUserData[0], vUserData[1], vUserData[2], stoi(vUserData[6]));

    }

    static  vector <clsLogedInUser> _LoadUsersDataFromFile()
    {

        vector <clsLogedInUser> vUsers;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsLogedInUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }


public:

    clsLogedInUser(string Time, string UserName, string Password, int Permissions)
    {
        _Time = Time;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    string GetTime()
    {
        return _Time;
    }

    void SetTime(string Time)
    {
        _Time = Time;
    }

    __declspec(property(get = GetTime, put = SetTime)) string Time;

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;
            
    static vector <clsLogedInUser> GetLoginRegisterList()
    {
        return _LoadUsersDataFromFile();
    }


};