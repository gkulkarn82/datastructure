#include<iostream>
#include<string.h>
using namespace std;

class User
{
    public:
        User(string userId, string name, string email):_userId(userId) , _name(name), _email(email)
        {
            
        }
    private:
        string _userId;
        string _name;
        string _email;

};