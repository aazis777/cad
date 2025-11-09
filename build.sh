#!/usr/bin/env bash
# cad — build script (for UNIX/LINUX)
# A simple wrapper around gcc for quick local builds

APP_NAME="cad"
APP_VERSION="0.1.0"
BUILD_DATE=$(date +"%Y-%m-%d")
BUILD_TIME=$(date +"%H:%M:%S")

echo "Building $APP_NAME v$APP_VERSION..."

gcc -O2 -Wall -Wextra -std=c99 \
    -DAPP_NAME="\"$APP_NAME\"" \
    -DAPP_VERSION="\"$APP_VERSION\"" \
    -DAPP_BUILD_DATE="\"$BUILD_DATE\"" \
    -DAPP_BUILD_TIME="\"$BUILD_TIME\"" \
    -o $APP_NAME cad.c

if [ $? -eq 0 ]; then
    echo "Build complete!"
    echo "Run ./$APP_NAME --help"
else
    echo "Build failed."
    exit 1
fi
