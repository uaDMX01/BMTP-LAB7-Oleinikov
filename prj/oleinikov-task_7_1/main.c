#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#endif

// Функція для приведення рядка до нижнього регістру
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Функція для розділення речення на окремі слова
void split_sentence(const char *sentence, char words[100][100], int *word_count) {
    char buffer[1000];
    strcpy(buffer, sentence);

    char *token = strtok(buffer, " .!");
    *word_count = 0;

    while (token != NULL) {
        strcpy(words[*word_count], token);
        (*word_count)++;
        token = strtok(NULL, " .!");
    }
}

int main() {
    // Налаштування локалі та кодування консолі для Windows
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif
    setlocale(LC_ALL, "uk_UA.UTF-8");

    // Введення речення
    char sentence[1000];
    printf("Введіть речення: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Видалення символу нового рядка, який додається fgets
    sentence[strcspn(sentence, "\n")] = '\0';

    // Приведення тексту до нижнього регістру
    to_lowercase(sentence);

    // Виділення окремих слів
    char words[100][100];
    int word_count;
    split_sentence(sentence, words, &word_count);

    // Порівняння кожного слова зі словом "сайт"
    int contains_word = 0;
    for (int i = 0; i < word_count; i++) {
        if (strcmp(words[i], "сайт") == 0) {
            contains_word = 1;
            break;
        }
    }

    // Вихідні дані
    if (contains_word) {
        printf("Речення містить слово 'сайт'.\n");
    } else {
        printf("Речення не містить слово 'сайт'.\n");
    }

    return 0;
}
