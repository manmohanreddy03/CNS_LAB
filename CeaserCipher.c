#include <stdio.h>

void caesarCipherEncrypt(char *message, int shift) {
    char ch;
    int i;

    shift = shift % 26;
    if (shift < 0) {
        shift += 26;
    }

    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + shift) % 26;
            message[i] = ch;
        } else if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + shift) % 26;
            message[i] = ch;
        }
    }
}

int main() {
    char message[100];
    int shift;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter shift value: ");
    scanf("%d", &shift);

    caesarCipherEncrypt(message, shift);

    printf("Encrypted message: %s\n", message);

    return 0;
}
