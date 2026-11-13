#include <stdio.h>

int classifyResponse(int responseTime) {
    if (responseTime <= 200)
        return 1;
    else if (responseTime <= 500)
        return 2;
    else
        return 3;
}

int main() {
    int responseTime, result;

    scanf("%d", &responseTime);

    result = classifyResponse(responseTime);

    if (result == 1)
        printf("Response: FAST");
    else if (result == 2)
        printf("Response: ACCEPTABLE");
    else
        printf("Response: SLOW");

    return 0;
}