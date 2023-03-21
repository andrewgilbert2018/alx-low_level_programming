#!/bin/bash
gcc -Wall -Werror -pedantic -Wextra -std=gnu89 *.c -c -fPIC
gcc -Wall -Werror -pedantic -Wextra -std=gnu89 *.o -shared -o liball.so
