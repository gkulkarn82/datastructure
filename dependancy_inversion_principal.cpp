/*
    Dependancy Inversion Principal

    Def : Class should depend on interface rather than concreate class
*/

class IKeyboard
{

};

class IMouse
{

};

class WiredKeyboard: IKeyboard
{

};

class BlutoothKeyboard: IKeyboard
{

};

class WiredMouse: IMouse
{

};

class BlutoothMouse: IMouse
{

};


/*
    Here we are using WiredKeyboard and WiredMouse as concrete classes 
    So If i need to enhance it to use blooth keyboard or mouse i can not do it

    Hence to improve it we need to use the interface rather than concrete classees
*/
class MacBook
{
    private WiredKeyboard keyboard
    private WiredMouse mouse;

    MacBook()
    {
        keyboard = new WiredKeyboard();
        mouse = new WiredMouse();
    }
};


/*
    corrected version
*/
class MacBook
{
    private IKeyboard keyboard
    private IMouse mouse;

    MacBook(IKeyboard keyboard, IMouse mouse)
    {
        keyboard = keyboard;
        mouse = mouse;
    }
};