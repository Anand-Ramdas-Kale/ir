
void computelpsArray(char *pat, int M, int *lps) {
  int len = 0; // length of previous longest prefix suffix
  int i;

  lps[0] = 0; // lps[0] is always 0
  i = 1;

  // the loop calculates lps[i] for 1 <= i <= M-1
  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        // consider example : AAACAAA and i = 7
        len = lps[len-1];
        // note that we don't icrement len here
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
}
