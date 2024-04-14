#include <bits/stdc++.h>
using namespace std;

vector<string> removeLeftRecursion(vector<string> grammar) {
    vector<string> newGrammar;
    for (string production : grammar) {
        stringstream ss(production);
        string part;
        vector<string> parts;
        while (getline(ss, part, '-'))
            parts.push_back(part);
        string nonTerminal = parts[0];
        stringstream ss2(parts[1]);
        vector<string> alternatives;
        while (getline(ss2, part, '|'))
            alternatives.push_back(part);
        vector<string> withRecursion;
        vector<string> withoutRecursion;
        for (string alt : alternatives) {
            if (alt.find(nonTerminal) == 0) {
                withRecursion.push_back(alt.substr(nonTerminal.length()) + " " + nonTerminal + "'");
            } else {
                withoutRecursion.push_back(alt + " " + nonTerminal + "'");
            }
        }
        for (string alt : withoutRecursion) {
            newGrammar.push_back(alt);
        }
        if (!withRecursion.empty()) {
            string newNonTerminal = nonTerminal + "'";
            string newProduction = "";
            for (string alt : withoutRecursion) {
                newProduction += alt + " " + newNonTerminal + "|";
            }
            newProduction += "epsilon";
            newGrammar.push_back(newProduction);
            for (string alt : withRecursion) {
                newGrammar.push_back(alt);
            }
        }
    }
    return newGrammar;
}

int main() {
    int numProductions;
    cout << "Enter the number of productions: ";
    cin >> numProductions;
    cin.ignore(); // Consume the newline character

    vector<string> grammar;
    cout << "Enter the productions:" << endl;
    for (int i = 0; i < numProductions; ++i) {
        string production;
        getline(cin, production);
        grammar.push_back(production);
    }

    vector<string> newGrammar = removeLeftRecursion(grammar);
    cout << "New Grammar:" << endl;
    for (string production : newGrammar) {
        cout << production << endl;
    }
    return 0;
}
