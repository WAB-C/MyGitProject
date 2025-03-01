#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

// Функция для вывода текущего состояния слова
void printWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Функция для вывода виселицы
void printHangman(int mistakes) {
    vector<string> hangman = {
        "  ____",
        " |    |",
        " |    " + string(mistakes > 0 ? "O" : ""),
        " |   " + string(mistakes > 2 ? "/" : " ") + string(mistakes > 1 ? "|" : "") + string(mistakes > 3 ? "\\" : ""),
        " |   " + string(mistakes > 4 ? "/" : " ") + string(mistakes > 5 ? " \\" : ""),
        "_|_"
    };

    for (const string& line : hangman) {
        cout << line << endl;
    }
}

int main() {
    // Список слов для угадывания
    vector<string> words = {"programming", "hangman", "computer", "algorithm", "developer"};
    srand(static_cast<unsigned int>(time(0)));
    string word = words[rand() % words.size()]; // Выбор случайного слова
    vector<bool> guessed(word.length(), false); // Вектор для отслеживания угаданных букв
    int mistakes = 0; // Количество ошибок
    const int maxMistakes = 6; // Максимальное количество ошибок

    cout << "Welcome to Hangman!" << endl;

    while (mistakes < maxMistakes) {
        cout << "\nWord: ";
        printWord(word, guessed);

        cout << "Guess a letter: ";
        char letter;
        cin >> letter;

        bool found = false;
        for (size_t i = 0; i < word.length(); ++i) {
            if (word[i] == letter) {
                guessed[i] = true;
                found = true;
            }
        }

        if (!found) {
            mistakes++;
            cout << "Wrong! Mistakes: " << mistakes << "/" << maxMistakes << endl;
        }

        printHangman(mistakes);

        // Проверка, все ли буквы угаданы
        if (all_of(guessed.begin(), guessed.end(), [](bool b) { return b; })) {
            cout << "\nCongratulations! You guessed the word: " << word << endl;
            return 0;
        }
    }

    cout << "\nYou lost! The word was: " << word << endl;
    return 0;
}
