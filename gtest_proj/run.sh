#!/bin/bash
# run.sh
# usage: run.sh ['filter matcher']

ABS_DIR=$(cd $(dirname "$0"); pwd)
cd "$ABS_DIR"

EXE="ci_ut"

if [ -d build ] && [ -x "build/$EXE" ]; then
    cd build
    filter_arg=""
    [ "$#" -eq 1 ] && filter_arg="--gtest_filter=$1"
    # MacOS 下需设置下面环境变量，另外 MacOS 下暂时没法检测内存泄漏
    MallocNanoZone=0 ./"$EXE" "$filter_arg"
    exit $?
fi

echo "$EXE not exists under build dir" && exit 1
