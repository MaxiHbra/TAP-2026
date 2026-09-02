#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool esVocal(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    char s[105];
    scanf("%s", s);
    int n = strlen(s);

    char candidatos[100][105];  // máximo 100 traducciones posibles
    int total = 0;

    for (int i = 0; i <= n - 5; i++) {
        if (esVocal(s[i]) && s[i+1] == 'G' && s[i+2] == 'A' &&
            s[i+3] == 'S' && s[i+4] == s[i]) {

            // Construir traducción: prefix + sufijo a partir de i+4
            char tmp[105];
            int idx = 0;
            for (int k = 0; k < i; k++)
                tmp[idx++] = s[k];
            for (int k = i + 4; k < n; k++)
                tmp[idx++] = s[k];
            tmp[idx] = '\0';

            // Ver si ya existe
            bool existe = false;
            for (int j = 0; j < total; j++) {
                if (strcmp(candidatos[j], tmp) == 0) {
                    existe = true;
                    break;
                }
            }
            if (!existe) {
                strcpy(candidatos[total++], tmp);
            }
        }
    }

    if (total == 0)
        printf("-");
    else if (total == 1)
        printf("%s", candidatos[0]);
    else
        printf("+");
    printf("\n");

    return 0;
}
