#!/bin/bash
echo "Compiling..."
g++ \
    src/main.cpp \
    src/player.cpp \
    src/ground.cpp \
    src/animation.cpp \
    -I include \
    -o build \
    -lraylib -lm -ldl -lGL -pthread
if [ $? -ne 0 ]; then
    echo "Compile failed! exiting..."
    exit 1
fi
./build