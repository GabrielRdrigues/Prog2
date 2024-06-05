#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copia_letras(char *S) {
  char *X = malloc((strlen(S) + 1) * sizeof(char));
  char c;
  int i, j = 0;
  j = 0;
  for (i = 0; i < strlen(S); i++) {
    if ((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z')) {
      X[j] = S[i];
      j++;
    }
  }
  X[j] = '\0';
  return X;
}

int palindromo_substring(char *S, int i, int n) {
  if (i > n)
    return 1;
  if (S[i] == S[n]) {
    if (palindromo_substring(S, i + 1, n - 1))
      return 1;
  }
  return 0;
}

int palindromo(char *String) {
  char *S = malloc(strlen(String));
  S = copia_letras(String);
  int aux = palindromo_substring(S, 0, strlen(S) - 1);
  if (aux)
    return 1;
  return 0;
}

int main() {
  if (palindromo("socorram-me, subi no onibus em marrocos!"))
    puts("palindromo");
}