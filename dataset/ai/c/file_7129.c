#include <stdio.h>
int main(void) {
    FILE *stream = tmpfile();
    if (stream == NULL) return 1;
    fprintf(stream, "%d\n", 42);
    rewind(stream);
    int read_value = 0; fscanf(stream, "%d", &read_value);
    printf("%d\n", read_value);
    fclose(stream);
    return 0;
}
