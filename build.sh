#!/bin/sh

# Load .env file, ignoring comments and empty lines
export $(grep -v '^#' .env | xargs)

mkdir -p lib/SFML
if [ "$OS_TYPE" = "Linux" ]; then
    wget -qO- https://www.sfml-dev.org/files/SFML-3.0.0-linux-gcc-64-bit.tar.gz | tar -xz -C lib/SFML --strip-components=1
elif [ "$OS_TYPE" = "Windows" ]; then
    wget -qO- https://www.sfml-dev.org/files/SFML-3.0.0-windows-gcc-14.2.0-mingw-64-bit.zip | unzip -o lib/SFML.zip -d lib/SFML && rm lib/SFML.zip
elif [ "$OS_TYPE" = "macOS" ]; then
    wget -qO- https://www.sfml-dev.org/files/SFML-3.0.0-macOS-clang-64-bit.tar.gz | tar -xz -C lib/SFML --strip-components=1
elif [ "$OS_TYPE" = "macOS-ARM" ]; then
    wget -qO- https://www.sfml-dev.org/files/SFML-3.0.0-macOS-clang-arm64.tar.gz | tar -xz -C lib/SFML --strip-components=1
else
    echo "Unknown OS."
fi

