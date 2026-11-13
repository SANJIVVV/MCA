#include <stdio.h>

float calculateBonus(float salary, int score) {
    if (score >= 90)
        return salary * 0.20;
    else if (score >= 75)
        return salary * 0.15;
    else if (score >= 60)
        return salary * 0.10;
    else
        return salary * 0.05;
}

int main() {
    float salary;

    int score;

    scanf("%f %d", &salary, &score);

    printf("Bonus: %.2f", calculateBonus(salary, score));

    return 0;
}