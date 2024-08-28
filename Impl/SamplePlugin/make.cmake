#for linux and macos
g++ -shared -fPIC -o libmyplugin.so my_plugin.cpp

#for windows
cl /LD my_plugin.cpp /link /out:myplugin.dll
