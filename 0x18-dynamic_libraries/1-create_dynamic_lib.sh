!#/bin/bash
ggc *.c -c fPIC
gcc *.o -shared -o liball.so
