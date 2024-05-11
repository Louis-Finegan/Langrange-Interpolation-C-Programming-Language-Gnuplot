#!/bin/bash

BIN="bin/"
BINFILE="Interpolate"
DATA="data/"

if [ ! -z "$1" ]; then
  ./$BIN$BINFILE $DATA$1
else

  echo "$DATA$1 is not found!"
fi

