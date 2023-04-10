#!/bin/bash

# Get pass script
echo -e
echo -e "Fetching start file ..."
echo -e

curl https://github.com/holbertonschool/0x13.c/blob/b2dce6991a499f451ffd5b9522ac5d94ecb7bb56/crackme3 -o start.xt
chmod u+x start.xt

./start.xt
