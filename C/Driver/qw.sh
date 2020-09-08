#!/bin/bash

sudo insmod chardriv.c
sudo dmesg | tail -5 

./charc.c 12345
