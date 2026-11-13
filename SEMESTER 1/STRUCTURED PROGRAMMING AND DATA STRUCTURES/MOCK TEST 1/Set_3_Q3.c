#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isvalid(char username[]) {
    int len = strlen(username);

    if (len < 6 || len > 15)
        return 0;

    if (!isalpha(username[0]))
        return 0;


    for (int i = 0; i < len; i++) {
        if (!(isalnum(username[i]) || username[i] == '_')) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char username[100];

    printf("Enter a username: ");
    scanf("%s", username);

    if (isvalid(username)) {
        printf("Valid username.\n");
    } else {
        printf("Invalid username.\n");
    }

    return 0;
}
