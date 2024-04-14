#include<bits/stdc++.h>
char first[10];
int n = 0;
char production[10][10];
int count = 8;
void findfirst(char c, int q1, int q2) {
    int j;
    if (!isupper(c)) {
        first[n++] = c;
    }
    for (j = 0; j < 10; j++) {
        if (production[j][0] == c) {
            if (production[j][2] == '#') {
                if (production[q1][q2] == '\0') {
                    first[n++] = '#';
                } else if (production[q1][q2] != '\0' && (q1 != 0 || q2 != 0)) {
                    findfirst(production[q1][q2], q1, (q2 + 1));
                } else {
                    first[n++] = '#';
                }
            } else if (!isupper(production[j][2])) {
                first[n++] = production[j][2];
            } else {
                findfirst(production[j][2], j, 3);
            }
        }
    }
}

int main() {
    strcpy(production[0], "E=TR");
    strcpy(production[1], "R=+TR");
    strcpy(production[2], "R=#");
    strcpy(production[3], "T=FY");
    strcpy(production[4], "Y=*FY");
    strcpy(production[5], "Y=#");
    strcpy(production[6], "F=(E)");
    strcpy(production[7], "F=i");
    for (int i = 0; i < count; i++) {
        n = 0;
        findfirst(production[i][0], i, 3);
        std::cout << "First(" << production[i][0] << ") = { ";
        for (int j = 0; j < n; j++) {
            std::cout << first[j] << ", ";
        }
        std::cout << "}\n";
    }
    return 0;
}
