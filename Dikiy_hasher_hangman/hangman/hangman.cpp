#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

vector<string> words = {"cat", "dog", "apple", "banana", "computer", "algorithm", "programming", "hangman"};

vector<string> getWordsByDifficulty(int difficulty) {
    vector<string> filteredWords;
    for (const string& word : words) {
        if (difficulty == 1 && word.length() <= 5) { // Легкий уровень
            filteredWords.push_back(word);
        } else if (difficulty == 2 && word.length() > 5 && word.length() <= 8) { // Средний уровень
            filteredWords.push_back(word);
        } else if (difficulty == 3 && word.length() > 8) { // Сложный уровень
            filteredWords.push_back(word);
        }
    }
    return filteredWords;
}

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

int calculateScore(int correctGuesses, int mistakes) {
    return (correctGuesses * 10) - (mistakes * 5);
}

void giveHint(const string& word, vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (!guessed[i]) {
            guessed[i] = true;
            cout << "Hint: The word contains the letter '" << word[i] << "'." << endl;
            break;
        }
    }
}

vector<pair<string, int>> scores;

void saveScore(const string& playerName, int score) {
    scores.push_back(make_pair(playerName, score));
}

void printScores() {
    cout << "\nHigh Scores:" << endl;
    for (const auto& score : scores) {
        cout << score.first << ": " << score.second << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    cout << "Welcome to Hangman!" << endl;
    cout << "Select difficulty level (1 - Easy, 2 - Medium, 3 - Hard): ";
    int difficulty;
    cin >> difficulty;

    vector<string> filteredWords = getWordsByDifficulty(difficulty);
    string word = filteredWords[rand() % filteredWords.size()];
    vector<bool> guessed(word.length(), false);
    int mistakes = 0;
    const int maxMistakes = 6;
    int correctGuesses = 0;

    while (mistakes < maxMistakes) {
        cout << "\nWord: ";
        printWord(word, guessed);

        cout << "Guess a letter (or type 'hint' for a hint): ";
        string input;
        cin >> input;

        if (input == "hint") {
            giveHint(word, guessed);
            continue;
        }

        char letter = input[0];
        bool found = false;
        for (size_t i = 0; i < word.length(); ++i) {
            if (word[i] == letter) {
                guessed[i] = true;
                found = true;
                correctGuesses++;
            }
        }

        if (!found) {
            mistakes++;
            cout << "Wrong! Mistakes: " << mistakes << "/" << maxMistakes << endl;
        }

        printHangman(mistakes);

        if (all_of(guessed.begin(), guessed.end(), [](bool b) { return b; })) {
            int score = calculateScore(correctGuesses, mistakes);
            cout << "\nCongratulations! You guessed the word: " << word << endl;
            cout << "Your score: " << score << endl;

            string playerName;
            cout << "Enter your name: ";
            cin >> playerName;
            saveScore(playerName, score);
            printScores();

            return 0;
        }
    }

    cout << "\nYou lost! The word was: " << word << endl;
    return 0;
}
