#!/bin/bash
set -e   # 에러 발생하면 즉시 중단

BUILD_DIR="build"
BUILD_TYPE="Debug"
RUN_AFTER_BUILD=false

# 인자 파싱
for arg in "$@"; do
    case $arg in
        clean)
            echo "🧹 Performing clean build..."
            rm -rf "$BUILD_DIR"
            cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=$BUILD_TYPE
            ;;
        run)
            RUN_AFTER_BUILD=true
            ;;
        release)
            BUILD_TYPE="Release"
            ;;
    esac
done

# build 디렉토리가 없으면 configure 수행
if [ ! -d "$BUILD_DIR" ]; then
    echo "⚙️  Configuring with CMake..."
    cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=$BUILD_TYPE
fi

echo "🔨 Building project..."
cmake --build "$BUILD_DIR" -- -j$(nproc)

echo "✅ Build finished."

if [ "$RUN_AFTER_BUILD" = true ]; then
    echo "🚀 Running ./build/app/my_app"
    "$BUILD_DIR"/app/my_app
fi
