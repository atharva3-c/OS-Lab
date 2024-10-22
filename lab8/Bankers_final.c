#include <stdio.h>
#include <stdlib.h>

int check(int re[], int avail[], int n) {
    for (int i = 0; i < n; i++) {
        if (re[i] > avail[i]) {
            return 0; // Not enough resources available
        }
    }
    return 1; // Resources are available
}

void Bankers(int remainingNeed[][10], int allocation[][10], int rem[], int m, int n) {
    int flag[m], order[m];
    int start = 0;

    for (int i = 0; i < m; i++) {
        flag[i] = 0; // Initialize all processes as not finished
    }

    printf("Available Resources at start: ");
    for (int k = 0; k < n; k++) {
        printf("%d ", rem[k]);
    }
    printf("\n");

    int stopFlag;
    for (int i = 0; i < m; i++) {
        stopFlag = 1;

        for (int j = 0; j < m; j++) {
            if (flag[j] == 1) {
                continue; // Process already finished
            }
            if (check(remainingNeed[j], rem, n)) {
                stopFlag = 0;
                for (int l = 0; l < n; l++) {
                    rem[l] += allocation[j][l]; // Release resources
                }
                flag[j] = 1; // Mark process as finished
                order[start++] = j + 1; // Store the order of finished processes
                break;
            }
        }
        if (stopFlag) {
            printf("\nDEADLOCK\n");
            return; // Exit if a deadlock is detected
        }

        printf("Available Resources after process %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", rem[k]);
        }
        printf("\n");
    }

    printf("SAFE SEQUENCE: ");
    for (int i = 0; i < start; i++) {
        printf("%d ", order[i]);
    }
    printf("\n");
}

int main() {
    int m, n, sum;

    printf("Enter the number of Processes: ");
    scanf("%d", &m);

    printf("Enter the number of Resources: ");
    scanf("%d", &n);

    int allocation[m][10], maxNeed[m][10], available[10], remainingNeed[m][10];
    int maxResources[10];

    printf("Enter maximum available resource numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &maxResources[i]);
    }

    printf("\nEnter values of Allocation:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    int totalResources[10] = {0}; // Initialize total resources to zero

    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < m; j++) {
            sum += allocation[j][i]; // Calculate total allocated resources
        }
        totalResources[i] = sum;
    }

    printf("\nEnter values of Max Need:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maxNeed[i][j]);
        }
    }

    int rem[10]; // Declare available resources array
    for (int i = 0; i < n; i++) {
        rem[i] = maxResources[i] - totalResources[i]; // Calculate remaining resources
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            remainingNeed[i][j] = maxNeed[i][j] - allocation[i][j]; // Calculate remaining need
        }
    }

    Bankers(remainingNeed, allocation, rem, m, n); // Call Banker's algorithm

    return 0;
}

