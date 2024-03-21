#include<bits/stdc++.h>
using namespace std;
#define DELIM "."

bool validate_part(char* s)
{
    int n = strlen(s);

    //after seperating value with dot each value should have a length 3 as max
    // 10.210.7.1  max is 3 
    if (n > 3)
        return false;

    for(int i =0 ; i < n; i++)
    {
        if(s[i] >= '0' && s[i] <= '9' == false)
            return false;        
    }

    string str(s);
    if(str.find('0') == 0 && n > 1)
    {
       cout << "landed here for string " << s << endl;
       return false;
    }

    stringstream test(str);
    int x;
    test >> x;

    return (x >= 0 && x <= 255);
}

int is_valid_ip(char* ip_str)
{
    if(ip_str == NULL)
        return 0;

    int i, num, dots = 0;
    int len = strlen(ip_str);
    int count = 0;

    //get the number of dots IPV4 addresses are seperated by 3 dots
    //10.207.1.1
    for(int i = 0 ; i < len; i++)
        if(ip_str[i] == '.')
            count++;

    //ipv4 address is seperated by 3 dots it should not exceed or should not be lesser than that
    if(count != 3)
        return false;

    char* ptr = strtok(ip_str, DELIM);
    if(ptr == NULL)
        return 0;

    while(ptr)
    {
        if(validate_part(ptr))
        {
            ptr = strtok(NULL, ".");
            if(ptr != NULL)
                ++dots;
        }
        else
            return 0;
    }

    // after first strtok there should be only 2 dot hence this condition
    if(dots != 3)
        return 0;
    return 1;
}


int main()
{
    char ip1[] = "128.0.0.1";
    char ip2[] = "125.16.100.1";
    char ip3[] = "125.512.100.1";
    char ip4[] = "125.512.100.abc";
    is_valid_ip(ip1) ? cout<<"Valid\n" : cout<<"Not valid\n";
    is_valid_ip(ip2) ? cout<<"Valid\n" : cout<<"Not valid\n";
    is_valid_ip(ip3) ? cout<<"Valid\n" : cout<<"Not valid\n";
    is_valid_ip(ip4) ? cout<<"Valid\n" : cout<<"Not valid\n";
    return 0;
}