#!/bin/bash
for file in "tiny-json.c"; do
  $CC $CFLAGS -c ${file}
done

llvm-ar rcs libfuzz.a *.o


$CC $CFLAGS $LIB_FUZZING_ENGINE $SRC/fuzzer.c -Wl,--whole-archive $SRC/tiny-json/libfuzz.a -Wl,--allow-multiple-definition -I$SRC/tiny-json/  -o $OUT/fuzzer
