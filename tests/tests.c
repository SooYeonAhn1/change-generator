#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../include/change.h"

char* testAmount(void * amount[], size_t size, size_t type) {
    FILE* input_file = tmpfile();
    if (input_file == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < size; ++i) {
        if (type == 0) {
            fprintf(input_file, "%lf", *((double *) amount + i));
        } else {
            fprintf(input_file, "%s", (char *) (*amount) + i);
        }
        
    }
    
    rewind(input_file);
    int original_stdin = dup(fileno(stdin));
    dup2(fileno(input_file), fileno(stdin));
    
    FILE* output_file = tmpfile();
    if (output_file == NULL) {
        fclose(input_file);
        close(original_stdin);
        return NULL;
    }
    int original_stdout = dup(fileno(stdout));
    dup2(fileno(output_file), fileno(stdout));

    setAmount();

    fflush(stdout);
    dup2(original_stdout, fileno(stdout));
    close(original_stdout);

    dup2(original_stdin, fileno(stdin));
    close(original_stdin);
    
    clearerr(stdin);

    rewind(output_file);
    long file_size;
    fseek(output_file, 0, SEEK_END);
    file_size = ftell(output_file);
    fseek(output_file, 0, SEEK_SET);

    char* buffer = (char*)malloc(file_size + 1);
    if (buffer == NULL) {
        fclose(input_file);
        fclose(output_file);
        return NULL;
    }
    
    fread(buffer, 1, file_size, output_file);
    buffer[file_size] = '\0';
    
    fclose(input_file);
    fclose(output_file);
    
    return buffer;
}


int main(int argc, char** argv) {
    printf("Running change_generator tests...\n");

    // TESTCASE 1: Testing valid input 1.23.
    printf("____________________\nTESTCASE 1: Testing valid input 1.23.\n");
    double input1[] = {1.23};
    char * output = testAmount((void *)&input1, 1, 0);
    if (output == NULL) {
        fprintf(stderr, "Error capturing output.\n");
        return 1;
    }

    char * expected_output = "Insert Amount: This can be converted to: 1 1 dollar bill, 2 dimes, 3 pennies.\n";

    if (strcmp(output, expected_output) == 0) {
        printf("Test Passed: Output matches expected value.\n");
    } else {
        printf("Test Failed: Output does not match expected value.\n");
        printf("Expected: %s", expected_output);
        printf("Actual: %s", output);
        exit(1);
    }
    free(output);
    printf("End of testcase 1.\n____________________\n");

    
    // TESTCASE 2: Testing valid input 0.
    printf("____________________\nTESTCASE 2: Testing valid input 0.\n");
    double input2[] = {0.00};
    output = testAmount((void *)&input2, 1, 0);
    if (output == NULL) {
        fprintf(stderr, "Error capturing output.\n");
        return 1;
    }

    expected_output = "Insert Amount: No change is required for this value.\n";

    if (strcmp(output, expected_output) == 0) {
        printf("Test Passed: Output matches expected value.\n");
    } else {
        printf("Test Failed: Output does not match expected value.\n");
        printf("Expected: %s", expected_output);
        printf("Actual: %s", output);
        exit(1);
    }

    free(output);
    printf("End of testcase 2.\n____________________\n");


    // TESTCASE 3: Testing invalid input -1.23.
    printf("____________________\nTESTCASE 3: Testing invalid input -1.23.\n");
    double input3[] = {-1.23, 1.0};
    output = testAmount((void *)&input3, 2, 0);
    if (output == NULL) {
        fprintf(stderr, "Error capturing output.\n");
        return 1;
    }

    expected_output = "Insert Amount: Only non-negative values are accepted. Please provide a valid value.\nInsert Amount: No change is required for this value.\n";

    if (strcmp(output, expected_output) == 0) {
        printf("Test Passed: Output matches expected value.\n");
    } else {
        printf("Test Failed: Output does not match expected value.\n");
        printf("Expected: %s", expected_output);
        printf("Actual: %s", output);
        exit(1);
    }

    free(output);
    printf("End of testcase 3.\n____________________\n");

    // TESTCASE 4: Testing invalid input abc.
    printf("____________________\nTESTCASE 4: Testing invalid input abc.\n");
    char * input4 = "abc";
    output = testAmount((void *) &input4, 1, 1);
    if (output == NULL) {
        fprintf(stderr, "Error capturing output.\n");
        return 1;
    }

    expected_output = "Insert Amount: Please provide a numeric value as input.\nTerminating the program...\n";

    if (strcmp(output, expected_output) == 0) {
        printf("Test Passed: Output matches expected value.\n");
    } else {
        printf("Test Failed: Output does not match expected value.\n");
        printf("Expected: %s", expected_output);
        printf("Actual: %s", output);
        exit(1);
    }

    free(output);
    printf("End of testcase 4.\n____________________\n");

    printf("\nAll tests passed!\n");
    return 0;
}
