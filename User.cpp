#include "User.h"
#include "Treap.h"

User::User()
{
    friendsList = new Treap();
}

User::User(string username, string fullname, string email)
    : username(username), fullname(fullname), email(email)
{
    friendsList = new Treap();
}

bool User::AddFriend(User &user)
{
    friendsList->add(user.getUsername(), &user);
    return true;
}

bool User::RemoveFriend(User &user)
{
    friendsList->remove(user.username);
    return true;
}

void User::ListFriends()
{
    friendsList->printInOrder();
}

bool User::IsAFriend(User& user)
{
    return friendsList->find(user.username);
}
