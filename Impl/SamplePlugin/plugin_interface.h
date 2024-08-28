// plugin_interface.h
#ifndef PLUGIN_INTERFACE_H
#define PLUGIN_INTERFACE_H

class PluginInterface {
public:
    virtual ~PluginInterface() {}
    virtual void execute() = 0;
};

extern "C" {
    PluginInterface* create();
    void destroy(PluginInterface* p);
}

#endif // PLUGIN_INTERFACE_H
