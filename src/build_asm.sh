#!/bin/bash

OUTPUT_DIR=`dirname $1`
mkdir -p ${OUTPUT_DIR}/build_asm

emcc $1 -s LEGACY_GL_EMULATION=1 -s LEGACY_VM_SUPPORT=1 -o ${OUTPUT_DIR}/build_asm/asm.html
