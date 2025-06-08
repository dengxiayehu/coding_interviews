#!/bin/bash
# run.sh

ABS_DIR=$(cd $(dirname "$0"); pwd)
cd "$ABS_DIR"

EXE="ci_ut"

if [ -d build ] && [ -x "build/$EXE" ]; then
    cd build
    # MacOS 下需设置下面环境变量，另外 MacOS 下暂时没法检测内存泄漏
    MallocNanoZone=0 ./"$EXE"
    exit $?
fi

echo "$EXE not exists under build dir" && exit 1
