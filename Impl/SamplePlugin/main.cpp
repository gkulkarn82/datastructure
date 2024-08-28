// main.cpp
#include <iostream>
#include <dlfcn.h>  // For dynamic loading on Unix-like systems
#include <windows.h>  // For dynamic loading on Windows
#include "plugin_interface.h"

int main() {
    // Load the plugin
    #ifdef _WIN32
    HMODULE handle = LoadLibrary("myplugin.dll");
    #else
    void* handle = dlopen("./libmyplugin.so", RTLD_LAZY);
    #endif

    if (!handle) {
        std::cerr << "Failed to load plugin." << std::endl;
        return 1;
    }

    // Load the create and destroy functions
    PluginInterface* (*create)();
    void (*destroy)(PluginInterface*);

    #ifdef _WIN32
    create = (PluginInterface*(*)())GetProcAddress(handle, "create");
    destroy = (void(*)(PluginInterface*))GetProcAddress(handle, "destroy");
    #else //dlsym means dynamic library symbol
    create = (PluginInterface*(*)())dlsym(handle, "create");
    destroy = (void(*)(PluginInterface*))dlsym(handle, "destroy");
    #endif

    if (!create || !destroy) {
        std::cerr << "Failed to load functions." << std::endl;
        #ifdef _WIN32
        FreeLibrary(handle);
        #else
        dlclose(handle);
        #endif
        return 1;
    }

    // Create and use the plugin
    PluginInterface* plugin = create();
    plugin->execute();
    destroy(plugin);

    // Unload the plugin
    #ifdef _WIN32
    FreeLibrary(handle);
    #else
    dlclose(handle);
    #endif

    return 0;
}
