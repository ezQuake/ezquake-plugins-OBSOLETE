gcc -fpic -g -c -Wall dummyplugin/dummyplugin.c
gcc -fpic -g -c -Wall namemaker/namemaker.c

gcc -fpic -g -c -Wall plugin.c
gcc -fpic -g -c -Wall qvm_api.c

gcc -shared -Wl,-soname,dummyplugin.so -o dummyplugin.so \
dummyplugin.o \
plugin.o \
qvm_api.o \
-lc

gcc -shared -Wl,-soname,namemaker.so -o namemaker.so \
namemaker.o \
plugin.o \
qvm_api.o \
-lc

