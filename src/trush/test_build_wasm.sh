#!/bin/bash

OUTPUT_DIR=`dirname $0`
cd ${OUTPUT_DIR}

emcc test.cpp -s WASM=1 -s LEGACY_VM_SUPPORT=1 -o ${OUTPUT_DIR}/../output_wasm/test_wasm.html
