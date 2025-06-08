#!/bin/bash
# run.sh

ABS_DIR=$(cd $(dirname "$0"); pwd)
cd "$ABS_DIR"

run_dir="v1tests"
[ -d "$run_dir" ] && mkdir -p "$run_dir"
cd "$run_dir"

CXX="g++"
CXX_FLAGS="-Wall -Werror -Wno-error=comment -fno-rtti -std=c++17 -Wno-deprecated-declarations"

for f in "$ABS_DIR"/[0-9][0-9]*.cc; do
    bname=`basename $f`
    exe_name=`echo $bname | cut -d. -f1`
    number=`echo $bname | cut -d_ -f1`
    echo "[$number] ==> $f"
    $CXX "$f" $CXX_FLAGS -o "$exe_name" || { echo "error occurred" && exit 1; }
    ./$exe_name
done
