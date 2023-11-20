#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // error handling for inapropriate command
    if (argc != 2) {
        printf("Usage: %s <Unix command>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];


    int len = strlen(command);
    for (int i = 0; i < len; i++) {
        if (command[i] == '&') { // replacing the value of the & with the %
            command[i] = '%';
        }
    }

    printf("Modified command: %s\n", command);

    int result = system(command); //executing the command here
    // error handling for a bad command, exit status is -1
    if (result == -1) {
        perror("Command execution failed");
        return 1;
    }

    return 0;
}
