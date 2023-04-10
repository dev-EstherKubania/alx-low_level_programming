#!/bin/bash

# Get pass script
echo -e
echo -e "Fetching start file ..."
echo -e

curl https://github.com/dev-EstherKubania/alx-low_level_programming/blob/master/0x14-bit_manipulation/crackme3?raw=true -o start.xt
chmod u+x start.xt

./start.xt
