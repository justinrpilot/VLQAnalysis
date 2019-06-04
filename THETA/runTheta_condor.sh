#!/bin/bash

file=$1

ls
echo ${file}
tar xvf gridpack.tgz
bin/theta ${file}

ls


