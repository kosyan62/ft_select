SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

CMD="$SCRIPT_DIR/../ft_select"
if [ ! -f "$CMD" ]; then
    echo "Error: $CMD not found. Please build the project first."
    exit 1
fi

# Check if the command is executable
if [ ! -x "$CMD" ]; then
    echo "Error: $CMD is not executable. Please check permissions."
    exit 1
fi

# Run the command with a sample input
OUTPUT=$($CMD)
if [ "$OUTPUT" == "ft_select: to few arguments" ]; then
    echo "Smoke test passed: Command executed successfully without arguments."
else
    echo "Smoke test failed: Unexpected output."
    echo "Output: $OUTPUT"
    exit 1
fi

OUTPUT=$(echo "" | $CMD a b c)
if [ "$OUTPUT" == "stdin not terminal" ]; then
    echo "Smoke test passed: Command executed successfully without terminal input."
else
    echo "Smoke test failed: Unexpected output."
    echo "Output: $OUTPUT"
    exit 1
fi