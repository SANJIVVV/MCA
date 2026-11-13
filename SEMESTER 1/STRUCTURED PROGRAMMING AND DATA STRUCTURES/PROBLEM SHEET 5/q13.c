#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int a[r][c];
    int teamTotal[r];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int maxTeamLoad = 0, maxTeam = 1;

    for (int i = 0; i < r; i++) {
        teamTotal[i] = 0;

        for (int j = 0; j < c; j++) {
            teamTotal[i] += a[i][j];
        }

        printf("Team %d Total: %d\n", i + 1, teamTotal[i]);

        if (teamTotal[i] > maxTeamLoad) {
            maxTeamLoad = teamTotal[i];
            maxTeam = i + 1;
        }
    }

    int peakDay = 1, peakIncidents = 0;
    int highLoadDays = 0;

    for (int j = 0; j < c; j++) {
        int dayTotal = 0;

        for (int i = 0; i < r; i++) {
            dayTotal += a[i][j];
        }

        if (dayTotal > peakIncidents) {
            peakIncidents = dayTotal;
            peakDay = j + 1;
        }

        if (dayTotal > 100)
            highLoadDays++;
    }

    printf("Peak Day: %d\n", peakDay);
    printf("Peak Day Incidents: %d\n", peakIncidents);
    printf("High-Load Days: %d\n", highLoadDays);
    printf("Highest Workload Team: %d\n", maxTeam);

    return 0;
}