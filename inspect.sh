#!/bin/bash

ispcc -o ${1}.profiled ${1} &&
isp -n 4 -l ${1}.analysis.log ./${1}.profiled

