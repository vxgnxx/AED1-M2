#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool checkNice(char* s, int start, int end) {
    int lower[26] = {0};
    int upper[26] = {0};

    for (int i = start; i <= end; i++) {
        if (islower(s[i])) {
            lower[s[i] - 'a'] = 1;
        } else if (isupper(s[i])) {
            upper[s[i] - 'A'] = 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (lower[i] != upper[i]) {
            return false;
        }
    }

    return true;
}

char* longestNiceSubstring(char* s) {
    int sizeS = strlen(s);
    int subS = 0;
    int subStringStart = 0;

    for (int i = 0; i < sizeS; i++) {
        for (int j = i; j < sizeS; j++) {
            int len = j - i + 1;
            if (checkNice(s, i, j) && len > subS) {
                subS = len;
                subStringStart = i;
            }
        }
    }

    if (subS > 0) {
        char* subString = (char*)malloc((subS + 1) * sizeof(char));
        for (int j = 0; j < subS; j++) {
            subString[j] = s[subStringStart + j];
        }
        subString[subS] = '\0';
        return subString;
    }

    char* empty = (char*)malloc(1);
    empty[0] = '\0';
    return empty;
}

int main(void)
{
    char *test_cases[] = {
        "xLeElzxgHzcWslEdgMGwEOZCXwwDMwcEhgJHLL",  // mixed, has nice substrings
        "YazaAay",                                // expected: "aAa"
        "Bb",                                     // expected: "Bb"
        "c",                                      // expected: ""
        "",                                       // expected: ""
        "aAbBcCdD",                               // expected: entire string
        "abBAc",                                  // expected: "abBA"
        "abcdEFGH",                               // expected: ""
        "Aaaaa",                                  // expected: "Aa"
        "aAAbBBbCc",                              // expected: "aAAbBBbCc"
        "ZzYyXxWwVvUuTtSsRrQqPpOoNnMmLlKkJjIiHhGgFfEeDdCcBbAa" // full alphabet, expected: entire string
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        char *result = longestNiceSubstring(test_cases[i]);
        printf("Test case %d: \"%s\"\n", i + 1, test_cases[i]);
        printf("Longest nice substring: \"%s\"\n\n", result);
        free(result);
    }

    return 0;
}
