/*
    Final Class
*/

#include<bits/stdc++.h>
using namespace std;

namespace own
{
    class FinalBase
    {
        public:
        private:
            FinalBase() = default;
        friend class Final;
    };
    class Final : public virtual FinalBase
    {
        public:
            Final() = default;
        private:
    };

    class Derived : public Final
    {
        public:
            Derived() = default;
        private:
    };
};

/*
    Since Final is deriving FinalBase as Virtual it means
    that when we create object of Derived class it will directly talk to FinalBase rather than talking through Final
    Since the Final Constructor is private it will fail and will not be able to create object 
    Reason : Due to virtual inheritance

    If we remove virtual from Final: public virtual then while creating derived class object it will call the Final class
    constructor since it will be just public inheritance will reach out to it's parent FinalBase for calling constructor
    that will FinalBase will initialised first followed for Final and then Derived hence it worked.

*/

int main()
{
    own::Final obj;
    own::Derived objDerived;
}


/*
    A->B->C
    C obj;

    class B: public A

        A (int i)
    B       C
        D



*/