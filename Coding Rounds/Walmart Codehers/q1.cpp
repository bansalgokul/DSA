#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

void computeLPSArray(string pat, int M, int *lps);

int KMPSearch(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();

    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            // printf("Found pattern at index %d ", i - j);
            return i - j;
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i]) {

            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    return -1;
}

void computeLPSArray(string pat, int M, int *lps) {
    int len = 0;

    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {

            if (len != 0) {
                len = lps[len - 1];

            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void solve() {
    string a;
    string b;

    cin >> a >> b;

    string replicated = a;

    int lena = a.length();
    int lenb = b.length();

    while (lena < lenb) {
        replicated += a;
        lena = replicated.length();
    }

    int patternIndex = KMPSearch(b, replicated);

    if (patternIndex == -1) {
        replicated += a;
        patternIndex = KMPSearch(b, replicated);
    }

    if (patternIndex == -1) {
        cout << a << endl;
        return;
    }

    string output = "";
    output += replicated.substr(0, patternIndex) + replicated.substr(patternIndex + lenb);

    if (output == "") {
        cout << -1 << endl;
        return;
    }
    cout << output << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}