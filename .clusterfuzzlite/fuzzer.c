#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "tiny-json.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    // Create an input string with null-termination
    char* input_string = (char*)malloc(size + 1);
    if (input_string == NULL) {
        return 0;
    }
    memcpy(input_string, data, size);
    input_string[size] = '\0';

    // Create an array of json_t for the second argument
    json_t json_array[10]; // Assuming max size of 10 for simplicity

    // Call the target function with the input data
    json_create(input_string, json_array, 10);

    free(input_string);
    return 0;
}
  
