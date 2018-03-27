#!/bin/bash

OUTPUT_DIR=`dirname $0`
cd ${OUTPUT_DIR}

emcc test.cpp -s LEGACY_VM_SUPPORT=1 -o ${OUTPUT_DIR}/../output_asm/test_asm.html
