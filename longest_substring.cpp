#include <bits/stdc++.h>

using namespace std;

int longestSubstrWithoutDupliOptimal(string s, int n) {
  int start = 0, end = -1, maxLen = 0;
  int present[26] = {
    -1
  };

  for (int i = 0; i < 26; i++)
    present[i] = -1;

  for (int i = 0; i < n; i++) {
    int character = s[i], prevFoundIndex = present[character - 'a'];
    end++;

    for (int j = start; j <= prevFoundIndex; j++)
      present[s[j] - 'a'] = -1;

    if (prevFoundIndex != -1)
      start = prevFoundIndex + 1;

    present[character - 'a'] = i;
    maxLen = max(maxLen, end - start + 1);
  }
  return maxLen;
}

int main() {
  string s = "wewr";
  int n = s.length();

  cout << "Length of the longest substring : " << longestSubstrWithoutDupliOptimal
  (s, n);
  return 0;
}