#include "User.h"
#include "Treap.h"
User::User()
{
    username="",fullname="",email="";
    friendsList = new Treap();
}

User::User(string username, string fullname, string email)
{

this -> username = username;
this -> fullname = fullname;
this -> email = email;
friendsList = new Treap();
}

bool User::AddFriend(User &user)
{
    friendsList->add(user.getUsername(), &user);
    return true;
}