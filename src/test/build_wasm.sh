#!/bin/bash

OUTPUT_DIR=`dirname $1`

emcc $1 -s WASM=1 -s LEGACY_VM_SUPPORT=1 -o ${OUTPUT_DIR}/../output_wasm/test_wasm.html
