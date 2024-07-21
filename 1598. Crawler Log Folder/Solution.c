int minOperations(char** logs, int logsSize) {
    int i, depth = 0;

    for (i = 0; i < logsSize; i++) {
        if (strcmp (logs[i], "../") == 0) {
            if (depth > 0) {
                depth--;
            }
        } else if (strcmp (logs[i], "./") != 0) {
            depth++;
        }
    }

    return depth;
}