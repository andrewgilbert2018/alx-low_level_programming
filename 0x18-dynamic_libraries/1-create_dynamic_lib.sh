#!/bin/bash
gcc -Wall -Werror -pedantic -Wextra -std=gnu89 *.c -c -fPIC
gcc -Wall -Werror -pedantic -Wextra -std=gnu89 *.o -shared -o liball.so
export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH
