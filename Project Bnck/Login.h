#pragma once
#include "Menue.h"
//Login to System
void Login()
{
	stUsers user;
    bool LoginFaild = false;
    do
    {
        ShowHeader("\tLogin Screen");
        if (LoginFaild)
        {
            ShowMessage("Invlaid Username / Password", MessageType::Error);
        }
        user=ReadInfoLogin(user);
        LoginFaild = !FindUserByUsernameAndPassword(user, CurrentUser);

    } while (LoginFaild);
     ShowMainMenue();
}