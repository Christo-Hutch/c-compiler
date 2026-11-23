#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{   
    if (argc < 2)
    {
        fprintf(stderr, "FATAL ERROR: no input files\n");
        return 1;
    }
    // Verifies input file exists
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        fprintf(stderr, "FATAL ERROR: file could not be opened\n");
        return 1;
    }
    fclose(input_file);

    // Creates assembly file
    FILE *out = fopen("data/out.s", "w");
    if (out == NULL)
    {
        fprintf(stderr, "FATAL ERROR: Could not open file");
        return 1;
    }

    // Insert assembly code
    fprintf(out, ".globl main\nmain:\n    movl $42, %%eax\n    ret\n");         // Placeholder assembly code
    fclose(out);

    int status = system("gcc data/out.s -o data/a.out");
    if (status != 0)
    {
        // Handle compilation error
        return 1;
    }
    return 0;
}