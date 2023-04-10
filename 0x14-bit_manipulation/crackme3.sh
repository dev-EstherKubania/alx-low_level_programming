#!/bin/bash

# Get pass script
echo -e
echo -e "Fetching start file ..."
echo -e

curl https://github.com/holbertonschool/0x13.c/blob/master/crackme3 -o start.xt
chmod u+x start.xt

./start.xt
