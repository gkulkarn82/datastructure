// my_plugin.cpp
#include "plugin_interface.h"
#include <iostream>

class MyPlugin : public PluginInterface {
public:
    void execute() override {
        std::cout << "MyPlugin is executing!" << std::endl;
    }
};

extern "C" PluginInterface* create() {
    return new MyPlugin();
}

extern "C" void destroy(PluginInterface* p) {
    delete p;
}
