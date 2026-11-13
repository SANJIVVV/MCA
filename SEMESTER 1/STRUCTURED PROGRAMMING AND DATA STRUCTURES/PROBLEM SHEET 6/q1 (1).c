#include <stdio.h>

float calculateUptime(int availableHours, int totalHours) {
    return ((float)availableHours / totalHours) * 100;
}

int main() {
    int availableHours, totalHours;

    scanf("%d %d", &availableHours, &totalHours);

    printf("Uptime: %.2f%%", calculateUptime(availableHours, totalHours));

    return 0;
}