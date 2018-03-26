#!/bin/bash

OUTPUT_DIR=`dirname $1`
mkdir -p ${OUTPUT_DIR}/build_wasm

emcc $1 -s WASM=1 -s LEGACY_GL_EMULATION=1 -s LEGACY_VM_SUPPORT=1 -o ${OUTPUT_DIR}/output_wasm/wasm.html
