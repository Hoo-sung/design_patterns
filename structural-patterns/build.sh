#!/bin/bash

ROOT_DIR=$(pwd)

BUILD_DIR="${ROOT_DIR}/build"
BIN_DIR="${ROOT_DIR}/bin"

if [ "$1" == "--clean" ]; then
  echo "Cleaning up build and bin directories..."
  rm -rf "$BUILD_DIR" "$BIN_DIR"
  echo "Clean complete!"
fi

if [ ! -d "$BIN_DIR" ]; then
  echo "Creating bin directory..."
  mkdir -p "$BIN_DIR"
fi

if [ ! -d "$BUILD_DIR" ]; then
  echo "Creating build directory..."
  mkdir "$BUILD_DIR"
fi

cd "$BUILD_DIR"

echo "Running cmake..."
cmake "$ROOT_DIR"

echo "Building the project..."
make

make install

echo "Build completed successfully!"
echo "Executable is in $BIN_DIR"
