#!/bin/bash
# Refresh compile_commands.json for VS Code IntelliSense

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
cd "$PROJECT_ROOT"

echo "🔄 Refreshing compile_commands.json for C++ IntelliSense..."
bazel run @hedron_compile_commands//:refresh_all

echo "✅ Done! VS Code IntelliSense should now have up-to-date information."
echo ""
echo "Note: VS Code will automatically detect the compile_commands.json file."
echo "If you don't see IntelliSense working, try:"
echo "  1. Reload VS Code window (Ctrl+Shift+P -> 'Developer: Reload Window')"
echo "  2. Check .vscode/c_cpp_properties.json points to the correct file"
