#!/usr/bin/env bash
# Run clang-tidy on the project files
# Usage: ./scripts/run_clang_tidy.sh [--fix]

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"

cd "${PROJECT_ROOT}"

FIX_FLAG=""
if [[ "$1" == "--fix" ]]; then
    FIX_FLAG="-fix"
fi

echo "Running clang-tidy on C++ files..."

find italian-card-games -type f \( -name "*.cpp" -o -name "*.hpp" \) \
    -not -path "*/bazel-*" \
    -exec clang-tidy ${FIX_FLAG} {} \;

echo "clang-tidy check complete!"
