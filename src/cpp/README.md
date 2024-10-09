## How to build and run the code in this directory?
- All files in this directory are written C++. As of this writing, I've compiled them with this version: g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
  This version supports C++17 standard.
- **General g++ command:** `g++ -Wall -g <FILE_NAME> -o <FILE_NAME_WITHOUT_EXTENSION>`
- **Example:** `$ g++ -Wall -g min_max_sum.cpp -o min_max_sum`
- This will create a C++ executable named min_max_sum in the current directory which can be run like this: `./min_max_sum`
- This file is an ELF format 64-bit executable on my system. Here's a sample output from my system:<BR>
`$ file min_max_sum
min_max_sum: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=1e53dc53c4df21a335bf45330346da7fe12b696c, for GNU/Linux 3.2.0, with debug_info, not stripped`
