#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    // Finds size of file
    fseek(input_file, 0, SEEK_END);
    long length = ftell(input_file);
    rewind(input_file);

    char* input_content = malloc(length + 1);
    if (input_content == NULL)
    {
        fprintf(stderr, "FATAL ERROR: out of memory");
        return 1;
    }

    // Reads file to char buffer
    size_t bytes_read = fread(input_content, 1, length, input_file);
    input_content[bytes_read] = '\0';

    fclose(input_file);
    free(input_content);

    // Creates assembly file
    FILE *out = fopen("data/out.s", "w");
    if (out == NULL)
    {
        fprintf(stderr, "FATAL ERROR: Could not open file");
        return 1;
    }

    // Inserts assembly code
    fprintf(out, ".globl main\nmain:\n    movl $42, %%eax\n    ret\n");         // Placeholder assembly code
    fclose(out);
    
    // Reads custom output file name, if empty assigns 'data/a.out'
    const char *output_filename = "data/a.out";
    if ((argc >= 4) && (strcmp(argv[2], "-o") == 0))
    {
        output_filename = argv[3];
    }
    
    // Creates command string up to 255 characters.
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "gcc data/out.s -o %s", output_filename);
    
    // Runs command
    int status = system(cmd);
    if (status != 0)
    {
        // Handle compilation error
        return 1;
    }
    return 0;
}