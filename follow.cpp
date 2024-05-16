#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **productions;

int findPos(char NonTer) {
    int i = 0;
    while (productions[i][0] != NonTer)
        i++;
    return i;
}

char* findGenerating(char Ter) {
    int i = 0;
    while (productions[i][0] != Ter)
        i++;
    return productions[i];
}

char findFirst(char *prod) {
    int i;
    for (i = 3; i < strlen(prod); i++) {
        if ((prod[i] >= 'a' && prod[i] <= 'z') || prod[i] == ')' || prod[i] == '(' || prod[i] == ',') {
            printf(" %c ", prod[i]);
            while (prod[i] != '/' && prod[i] != '\0')
                i++;
            return prod[i]; // return the last processed character, for example
        } else if (prod[i] >= 'A' && prod[i] <= 'Z') {
            printf("  %c", findFirst(productions[findPos(prod[i])]));
            return prod[i];  // return the non-terminal or another meaningful character
        } else if (prod[i] == '#') {
            printf("  #");
            return '#'; // return when it's a specific symbol like '#'
        }
    }
    return '\0'; // default return when none of the conditions are met
}

void findFollow(char GeneratingSymbol, int n) {
    int i, j = 0;
    if (GeneratingSymbol == 'S')
        printf(" $ ");
    for (j = 0; j < n; j++) {
        for (i = 3; i < strlen(productions[j]); i++) {
            if (GeneratingSymbol == productions[j][i]) {
                if ((productions[j][i + 1] >= 'a' && productions[j][i + 1] <= 'z') || productions[j][i + 1] == ')' || productions[j][i + 1] == '(' || productions[j][i + 1] == ',') {
                    printf(" %c ", productions[j][i + 1]);
                } else if (productions[j][i + 1] >= 'A' && productions[j][i + 1] <= 'Z') {
                    char ans = findFirst(findGenerating(productions[j][i + 1]));
                } else if (i + 1 == strlen(productions[j])) {
                    findFollow(productions[j][0], n);
                } else {
                    continue;
                }
            }
        }
    }
}

int main() {
    int i, n;
    printf("Enter the number of productions: ");
    scanf("%d\n", &n);
    productions = (char**) malloc(sizeof(char*) * n);
    for (i = 0; i < n; i++)
        productions[i] = (char*) malloc(sizeof(char) * 20);

    char temp[20];  // Buffer to read input
    for (i = 0; i < n; i++) {
        fgets(temp, 20, stdin);
        temp[strcspn(temp, "\n")] = 0;  // Remove newline character
        strcpy(productions[i], temp);
    }

    // First Computation
    for (i = 0; i < n; i++) {
        printf("\nFIRST(%c)={  ", productions[i][0]);
        char ans = findFirst(productions[i]);
        printf("}\n");
    }

    for (i = 0; i < n; i++) {
        printf("\nFOLLOW(%c)={", productions[i][0]);
        findFollow(productions[i][0], n);
        printf("}\n");
    }
    printf("\nThe End");
    return 0;
}
