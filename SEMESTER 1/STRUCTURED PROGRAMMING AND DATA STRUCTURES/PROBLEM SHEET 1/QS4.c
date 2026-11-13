 #include <stdio.h>

int main() {
    int severity;

    printf("Enter severity (1-5): ");
    scanf("%d", &severity);

    if (severity == 5)
        printf("Priority: Critical");
    else if (severity == 4)
        printf("Priority: High");
    else if (severity == 3)
        printf("Priority: Medium");
    else if (severity == 2)
        printf("Priority: Low");
    else if (severity == 1)
        printf("Priority: Very Low");
    else
        printf("Invalid severity");

    return 0;
}

