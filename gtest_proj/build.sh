#!/bin/sh
# build.sh

set -e

ABS_DIR=$(cd $(dirname "$0"); pwd)
cd "$ABS_DIR"

third_party_install_dir="$ABS_DIR/third_party/install"
export PKG_CONFIG_PATH="$third_party_install_dir/lib/pkgconfig"
export PATH=$PATH:"$third_party_install_dir/bin/"
mkdir -p "$third_party_install_dir/lib"
mkdir -p "$third_party_install_dir/bin"

commit_id=$(git rev-parse --short HEAD)
build_time=$(date +"%Y%m%d%H%M%S")

prog_name=`basename $0`
help=0
on_compile_info=0

# use gnu-getopt on Mac
ARGS=`getopt -o o,h --long on_compile_info,help -n "$prog_name" -- "$@"`
[ $? -ne 0 ] && echo "param error, terminating ..."

eval set -- "${ARGS}"

while true; do
    case "$1" in
        -o|--on_compile_info) on_compile_info=1; shift;;
        -h|--help) help=1; shift;;
        --) shift; break;;
        *) error "internal error"; exit 1;;
    esac
done

CONFIG_HEADER="$ABS_DIR/src/config.h"
function gen_compile_info() {
    rm -rf "$CONFIG_HEADER"
    echo "#define COMMIT_ID "'"'$commit_id'"' >>"$CONFIG_HEADER"
    echo "#define BUILD_TIME "'"'$build_time'"' >>"$CONFIG_HEADER"
}

function show_help() {
    echo "usage: $prog_name [-o] [-h]"
}

[ $on_compile_info -ne 0 -o ! -f "$CONFIG_HEADER" ] && gen_compile_info
[ $help -ne 0 ] && show_help && exit 0

export TARGET_NAME="ci_ut"
[ ! -d build ] && mkdir build
cd build && cmake .. && make -j8 #VERBOSE=1
