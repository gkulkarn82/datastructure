#include<iostream>
#include<set>
using namespace std;

class student
{
	public:
		int _age;
		std::string _name;
		long long _mobilenumber;

        explicit student(int age, string name, long long mobilenumber):_age(age), _name(name), _mobilenumber(mobilenumber)
        {}

        bool operator <(const student& obj) const
        {            
            if(this->_age == obj._age)
            {
                if(this->_name == obj._name)
                    return this->_mobilenumber < obj._mobilenumber;
                else
                    return this->_name < obj._name;
            }
            else
                return this->_age < obj._age;

        }
};

int main()
{
    // std::set<int> sint;
    // sint.emplace(11);
    // sint.emplace(20);
    // sint.emplace(8);

    // for(auto i : sint)
    // {
    //     cout << i << endl;
    // }

	std::set<student> st;
	st.emplace(20,"abc", 877987897987);
    st.emplace(20,"abc", 907987897987);
    st.emplace(20,"xyz", 807987897987);

    for(auto &i : st)
    {
        cout << i._age << " " << i._name << " " << i._mobilenumber << endl;
    }

    return 0;
}