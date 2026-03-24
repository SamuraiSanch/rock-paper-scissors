#include <iostream>
#include <random>
#include <string>

enum class RoundResult {
    WIN,
    LOSE,
    DRAW
};

enum GameOptions {
    STONE,
    SCISSORS,
    PAPER,
};

int generateRandomNumber(const int min, const int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

int getPlayerChoice() {
    int playerChoice;
    while (true) {
        std::cin >> playerChoice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            playerChoice = -1;
            std::cerr << "Error! You must enter a choice 1, 2 or 3\n";
        }
        if (playerChoice >= 1 && playerChoice <= 3)
            break;
        std::cerr << "Incorrect option! Choose right please.\n";
    }
    return playerChoice;
}

GameOptions convertChoice(const int choice) {
    switch (choice) {
    case 1: return STONE;
    case 2: return SCISSORS;
    case 3: return PAPER;
    default: throw std::runtime_error("Incorrect choice");
    }
}

RoundResult wonARound(const GameOptions &p, const GameOptions &c) {
    if (p == c)
        return RoundResult::DRAW;
    switch (p) {
    case STONE: switch (c) {
    case SCISSORS: return RoundResult::WIN;
    case PAPER: return RoundResult::LOSE;
    default: throw std::runtime_error("Unexpected choice");
    }
    case SCISSORS: switch (c) {
    case STONE: return RoundResult::LOSE;
    case PAPER: return RoundResult::WIN;
    default: throw std::runtime_error("Unexpected choice");
    }
    case PAPER: switch (c) {
    case STONE: return RoundResult::WIN;
    case SCISSORS: return RoundResult::LOSE;
    default: throw std::runtime_error("Unexpected choice");
    }
    default: throw std::runtime_error("Unexpected player choice");
    }
    throw std::runtime_error("Unexpected behavior: nobody play a round");
}

bool isPlayerWinner(const int livesPerRound = 3) {
    int playerLives = livesPerRound, computerLives = livesPerRound;
    std::cout << "Welcome to the game Rock Paper Scissors!\n";
    do {
        std::cout << "=== Game statistics now ===\nPlayer lives: " << playerLives << "\nComputer lives: " << computerLives << '\n';
        std::cout << "What you choose?\nOptions:\n1) Stone,\n2) Scissors,\n3) Paper.\n:";

        // 1 - 3 numbers of correct options in this game (stone, scissors, paper)
        GameOptions player = convertChoice(getPlayerChoice());
        GameOptions computer = convertChoice(generateRandomNumber(1, 3));

        std::cout << "Computer chose: " << computer + 1 << " option\n";

        switch (wonARound(player, computer)) {
        case RoundResult::WIN: std::cout << "You won this round, congrats!\n"; --computerLives; break;
        case RoundResult::LOSE: std::cout << "You lost this round, unlucky >.<\n"; --playerLives; break;
        case RoundResult::DRAW: std::cout << "Draw in this round, strange things hapenning!\n"; break;
        default: throw std::runtime_error("Unexpected error while playing a game, oopps...");
        }
    } while (playerLives > 0 && computerLives > 0);
    return playerLives > 0;
}

int main()
{
    char playerChoice;
    try {
        do {
            if (isPlayerWinner(3))
                std::cout << "You're winner, congrats!\n";
            else
                std::cout << "Computer won, AI > human now...\n";
            while (true) {
                std::cout << "Do you want to play again? (Y)es, (N)o: ";
                std::cin >> playerChoice;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Error! You must enter a choice (Y)es or (N)o.\n";
                }
                else if (playerChoice == 'Y' || playerChoice == 'N')
                    break;
            }
        } while (playerChoice != 'N');
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what();
    }
    return 0;
}

