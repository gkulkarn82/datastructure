 /*
 
    1. Do not allow duplicate value and it is sorted
    2. This is associative container which is associate with something
    3. It is usually implemented in RED- BLACK TREE 
    4. Insertion ,removal and search have logarithmic complexity
    5. if we want to store user defined objects  then we need to provide comparator functions
 
 */
 
 #include<iostream>
 #include<set>
 #include<string>
 #include<functional>
 using namespace std;

class Person
{
    public:
        float age;
        string name;

    bool operator <(const Person& rhs) const
    {
        return age < rhs.age;
    }

    bool operator > (const Person& rhs) const
    {
        return age > rhs.age;
    }
};

 int main()
 {
    //set<int> Set = {1,2,5,4,3,1,2,3,4,5};
    
    set<Person,greater<>> Set = {{20, "Rupesh"}, {25, "Hitesh"}, {22, "John"}};
    for(const auto& s: Set)
        cout << s.age << " " << s.name << endl;

    return 0;
 }