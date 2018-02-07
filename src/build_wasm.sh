#!/bin/bash


OUTPUT_DIR=/opt/novnc/em_wasm

mkdir -p ${OUTPUT_DIR}
emcc $1 -s WASM=1 -s LEGACY_GL_EMULATION=1 -o ${OUTPUT_DIR}/index.html
