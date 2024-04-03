#include <stdio.h>
#include <string.h>

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = key[plaintext[i] - 'A'];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int index = 0;
            while (key[index] != ciphertext[i]) {
                index++;
            }
            plaintext[i] = 'A' + index;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';
}

int main() {
    char plaintext[100];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char ciphertext[100];
    char decryptedText[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    encrypt(plaintext, key, ciphertext);
    printf("Encrypted: %s\n", ciphertext);

    decrypt(ciphertext, key, decryptedText);
    printf("Decrypted: %s\n", decryptedText);

    return 0;
}
