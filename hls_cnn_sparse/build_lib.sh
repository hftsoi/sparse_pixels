#!/bin/bash
set -e

CC=g++
if [[ "$OSTYPE" == "linux-gnu" ]]; then
    CFLAGS="-O3 -fPIC -std=c++11 -fno-gnu-unique"
elif [[ "$OSTYPE" == "darwin"* ]]; then
    CFLAGS="-O3 -fPIC -std=c++11"
fi
LDFLAGS=
INCFLAGS="-Ifirmware/ap_types/"
PROJECT=hls_cnn_sparse
LIB_STAMP=81491520
BASEDIR="$(cd "$(dirname "$0")" && pwd)"
WEIGHTS_DIR="\"${BASEDIR}/firmware/weights\""

${CC} ${CFLAGS} ${INCFLAGS} -D WEIGHTS_DIR="${WEIGHTS_DIR}" -c firmware/${PROJECT}.cpp -o ${PROJECT}.o
${CC} ${CFLAGS} ${INCFLAGS} -D WEIGHTS_DIR="${WEIGHTS_DIR}" -c ${PROJECT}_bridge.cpp -o ${PROJECT}_bridge.o
${CC} ${CFLAGS} ${INCFLAGS} -shared ${PROJECT}.o ${PROJECT}_bridge.o -o firmware/${PROJECT}-${LIB_STAMP}.so
rm -f *.o
