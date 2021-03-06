#include <iostream>

using namespace std;

const int MAX = 4;

int main() {
    cout << "uzupelnij tablice liczbami, kolejne liczby trafiaja do tego samego wiersza" << endl;
    int t[MAX][MAX];
    for (int w = 0; w < MAX; w++) {
        cout << "wiersz " << w << endl;
        for (int k = 0; k < MAX; k++) {
            cin >> t[w][k];
        }
    }

    for (int w = 0; w < MAX; w++) {
        bool istnieje = false;
        for (int k = 0; k < MAX; k++) {
            int liczba = t[w][k];
            bool cyf_parz = false;
            while (liczba > 0) {
                if (liczba % 2 == 0) {
                    cyf_parz = true;
                    break;
                }
                liczba /= 10;
            }
            if (!cyf_parz) {
                istnieje = true;
                break;
            }
        }
        if (!istnieje) {
            cout << "nie istnieje";
            return 0;
        }
    }

    cout << "istnieje";
}