#!/bin/bash
set -euo pipefail # 开启严格模式，任何错误都中断脚本

BUILD_DIR="cmake_build"

echo "🔧 Step 1: [CMake]"
cmake -S . -B ${BUILD_DIR}  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
                            -DCMAKE_BUILD_TYPE=Debug
ln -sf "${BUILD_DIR}/compile_commands.json" "compile_commands.json"

echo "🛠️  Step 2: [Build]"
cmake --build ${BUILD_DIR}

echo "🧪 Step 3: [Test]"
ctest --test-dir ${BUILD_DIR} --output-on-failure

echo "✅ All steps completed successfully!"
