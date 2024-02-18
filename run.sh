#!/bin/bash

CC=gcc
LINKER=-lm
SRC="src/"
BIN="bin/"
FILE="main.c"
BINFILE="Interpolate"
DATA="data/"


$CC $SRC$FILE -o $BIN$BINFILE $LINKER

if [ $? -eq 0 ]; then

  chmod +x $BIN$BINFILE

  if [ -z "$1" ]; then

    echo "Error: Invalid operand! Must be <file>.csv"
  
    exit 1

  else

    ./$BIN$BINFILE $DATA$1

  fi

else

  echo "Compilation Failed! Program not executed."

  exit 1

fi

exit 0
