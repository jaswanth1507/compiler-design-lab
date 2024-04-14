#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> leftFactor(const vector<string>& prodleft, const vector<string>& prodright) {
    vector<string> newProdleft;
    vector<string> newProdright;
    int n = prodleft.size();
    for (int i = 0; i < n; ++i) {
        unordered_map<char, int> prefixCount;
        char commonPrefix = '\0';
        int maxPrefixCount = 0;
        // Count prefixes of the current production
        for (char c : prodright[i]) {
            if (c == '|' || c == '^') continue;
            prefixCount[c]++;
            if (prefixCount[c] > maxPrefixCount) {
                maxPrefixCount = prefixCount[c];
                commonPrefix = c;
            }
        }
        if (maxPrefixCount <= 1) { // No common prefix found
            newProdleft.push_back(prodleft[i]);
            newProdright.push_back(prodright[i]);
        } else { // Common prefix found, perform left factoring
            string newLeft = prodleft[i] + "'";
            string newRight1 = "";
            string newRight2 = "";
            bool firstAlt = true;
            for (char c : prodright[i]) {
                if (c == '|' || c == '^') {
                    if (newRight1.empty()) {
                        newRight1 += "^";
                    }
                    firstAlt = false;
                } else if (c == commonPrefix && firstAlt) {
                    newRight1 += c;
                } else {
                    newRight2 += c;
                }
            }
            newProdleft.push_back(prodleft[i]);
            newProdleft.push_back(newLeft);
            newProdright.push_back(newRight1 + newLeft);
            newProdright.push_back(newRight2 + newLeft);
        }
    }
    // Ensure the size of newProdright matches the size of prodleft
    while (newProdright.size() < prodleft.size()) {
        newProdright.push_back("");
    }
    return newProdright;
}

int main() {
    cout << "\nEnter number of productions: ";
    int p;
    cin >> p;
    vector<string> prodleft(p);
    vector<string> prodright(p);
    cout << "\nEnter productions one by one: ";
    for (int i = 0; i < p; ++i) {
        cout << "\nLeft of production " << i + 1 << ": ";
        cin >> prodleft[i];
        cout << "\nRight of production " << i + 1 << ": ";
        cin >> prodright[i];
    }
    vector<string> newProdright = leftFactor(prodleft, prodright);
    cout << "\n\nNew productions:\n";
    for (int i = 0; i < prodleft.size(); ++i) {
        cout << prodleft[i] << " -> " << newProdright[i] << endl;
    }
    return 0;
}
