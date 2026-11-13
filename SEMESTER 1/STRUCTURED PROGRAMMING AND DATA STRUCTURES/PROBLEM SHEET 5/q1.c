#include <stdio.h>
int main() {
int R, C;
scanf("%d %d", &R, &C);
int cpu[R][C];
for (int i = 0; i < R; i++) {
for (int j = 0; j < C; j++) {
scanf("%d", &cpu[i][j]);
}
}
for (int i = 0; i < R; i++) {
int total = 0;
for (int j = 0; j < C; j++) {
total += cpu[i][j];
}
printf("Server %d: %d\n", i + 1, total);
}
return 0;}