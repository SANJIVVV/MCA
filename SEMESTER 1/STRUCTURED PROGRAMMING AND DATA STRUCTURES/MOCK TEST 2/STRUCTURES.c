#include<stdio.h>
#include<string.h>

struct Student{
    int reg;
    char name[20];
    float marks[3];
    float total,avg;
};

void calculate(struct Student *s) {
    s->total = 0;
    for (int i = 0; i < 3; i++) {
        s->total += s->marks[i];
    }
    s->avg = s->total / 3.0;
}

int main() {

    struct Student s[3];
    int i, j;

    for (i = 0; i < 3; i++) {

        printf("Enter Register Number: ");
        scanf("%d", &s[i].reg);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        printf("Enter marks in 3 subjects:\n");
        for (j = 0; j < 3; j++) {
            scanf("%f", &s[i].marks[j]);
        }

        calculate(&s[i]);
    }

    for (i = 0; i < 3; i++) {
        printf("\n\nRegister Number: %d", s[i].reg);
        printf("\nName: %s", s[i].name);
        printf("\nTotal: %f", s[i].total);
        printf("\nAverage: %f", s[i].avg);
    }
    printf("\n");

    return 0;
}
