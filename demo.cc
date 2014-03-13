#include <string.h>

#include <iostream>
#include <vector>

#include "kmp-cpp.h"

using namespace std;

void kmp_c_string() {
    const char* needle = "iloveny";
    const char* haystack = "oh yes iloveny";
    kmp::pattern<const char*> kmp(needle, needle + strlen(needle));
    cout << kmp.match_first(haystack, haystack + strlen(haystack)) << endl;
}

void kmp_c_int_array() {
    int needle[] = {1, 9, 8, 7};
    int haystack[] = {-1, 0, 1, 9, 8, 0, 1, 9, 8, 7, 1987};
    kmp::pattern<int*> kmp(needle, needle + 4);
    cout << kmp.match_first(haystack, haystack + 11) << endl;
}

void kmp_std_string() {
    string needle = "iloveny";
    const string haystack = "oh yes iloveny";

    kmp::pattern<string::const_iterator> kmp(needle.begin(), needle.end());
    cout << kmp.match_first(haystack.begin(), haystack.end()) << endl;

    kmp::pattern<string::iterator> kmp2(needle.begin(), needle.end());
    cout << kmp2.match_first(haystack.begin(), haystack.end()) << endl;
}

void kmp_mixed_string() {
    const char* needle = "iloveny";
    kmp::pattern<const char*> kmp(needle, needle + strlen(needle));
    const string haystack = "oh yes iloveny";
    cout << kmp.match_first(haystack.begin(), haystack.end()) << endl;
}

void kmp_match_first() {
    string needle = "abc";
    string haystack = "abc abc abc aabbcc aabcc";
    cout << kmp::match_first(needle.begin(), needle.end(), haystack.begin(), haystack.end()) << endl;
}

void kmp_match_all() {
    string needle = "abc";
    string haystack = "abc abc abc aabbcc aabcc";
    vector<long> matches = kmp::match_all(needle.begin(), needle.end(), haystack.begin(), haystack.end());
    cout << matches.size() << endl;
}

// #include <list>
// void kmp_cannot_compile() {
//     list<int> needle;
//     list<int> haystack;
//     kmp::pattern<list<int>::iterator> kmp(needle.begin(), needle.end());
// }

// void kmp_cannot_compile_2() {
//     vector<int> needle;
//     vector<unsigned> haystack;
//     kmp::pattern<vector<int>::iterator> kmp(needle.begin(), needle.end());
//     cout << kmp.match_first(haystack.begin(), haystack.end()) << endl;
// }

int main() {
    kmp_c_string();
    kmp_std_string();
    kmp_mixed_string();
    kmp_c_int_array();
    kmp_match_first();
    kmp_match_all();
    // kmp_cannot_compile();
    // kmp_cannot_compile_2();
    return 0;
}
