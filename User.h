#ifndef USER_H
#define USER_H


#include <iostream>
#include "Treap.h"
using namespace std;

class Treap;  //forward definition

class User
{
    private:
        string username;
        string fullname;
        string email;
        Treap *friendsList;
    public:
        User(string username, string fullname, string email)
        {
            this -> username = username;
            this -> fullname = fullname;
            this -> email = email;
            this -> friendsList = 0;
        }

        string getusername(){ return username; }
        string getfullname(){ return fullname; }
        string getEmail(){ return email; }

        void setusername(string username){ this -> username = username; }
        void setfullname(string fullname){ this -> fullname = fullname; }
        void setEmail(string email){ this -> email = email; }

        friend ostream& operator<<(ostream& os, const User& user)
        {
            os << "Fullname: " << user.fullname << endl
            << "Username: " << user.username << endl
            << "Email: " << user.email << endl;

            return os;
        }
};

#endif