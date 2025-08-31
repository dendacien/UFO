#include "ufo_functions.hpp"

// Function to select a random codeword from the list and create the initial answer string
pair<string, string> select_codeword(vector<string> codewords) {
	int index = rand() % codewords.size();
	string code = codewords[index];
	string answer(code.length(), '_');
	return make_pair(code, answer);
}

// Method for the Player class to make a guess
void Player::make_guess(string codeword) {
	string input;
	char letter;
	bool validInput = false;

	cout << "\nPlease enter your guess: ";

	while (!validInput) {
		// Get user input
		getline(cin, input);

		// Validate for any input
		if (input.empty()) {
			cout << "Please enter a letter: ";
			continue;
		}
		// Validate for single alphabetic character
		if (isalpha(input[0]) && input.length() == 1) {
			letter = tolower(input[0]); // Convert to lowercase
		}
		else {
			cout << "Invalid input. Please enter a letter: ";
			continue;
			// clear the error state
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		// Check if letter was already guessed
		if (find(incorrect.begin(), incorrect.end(), letter) != incorrect.end() || answer.find(letter) != string::npos) {
			cout << "You already guessed that letter. Try a new letter: ";
			continue;
		}
		// Check if the guessed letter is in the codeword
		bool correctGuess = false;
		for (int i = 0; i < codeword.length(); i++) {
			if (letter == codeword[i]) {
				answer[i] = letter;
				correctGuess = true;
			}
		}
		// Provide feedback
		if (correctGuess) {
			cout << "Correct!\n";
		}
		else {
			cout << "Incorrect! The tractor beam pulls the person in further.\n";
			incorrect.push_back(letter);
			misses++;
		}
		validInput = true;
	}
}

// Method for the Game class to greet the player
void Game::greet() {
	std::cout << "============= \n";
	std::cout << "UFO: The Game \n";
	std::cout << "============= \n";
	std::cout << "Instructions : save your friend from alien abduction by guessing the letters in the codeword. \n";

}

// Method for the Game class to end the game and display the result
void Game::end_game(string answer) {
	if (answer == codeword) {
		cout << "Hooray! You saved the person and earned a medal of honor!\n";
	}
	else {
		cout << "Oh no! The UFO just flew away with another person!\n";
	}
}

// Method for the Game class to display the current status of the game
void Game::display_status(string answer, vector<char> incorrect) {
	cout << "Incorrect guesses: ";
	for (char letter : incorrect) {
		cout << letter << " ";
	}
	cout << "\nCodeword: " << answer << "\n";
}

// Method for the Game class to display the UFO and the abuction status based on the number of misses
void Game::display_misses(int misses) {

	if (misses == 0 || misses == 1) {

		std::cout << "                 .                            \n";
		std::cout << "                 |                            \n";
		std::cout << "              .-\"^\"-.                       \n";
		std::cout << "             /_....._\\                       \n";
		std::cout << "         .-\"`         `\"-.                  \n";
		std::cout << "        (  ooo  ooo  ooo  )                   \n";
		std::cout << "         '-.,_________,.-'    ,-----------.   \n";
		std::cout << "              /     \\        (  Send help! ) \n";
		std::cout << "             /   0   \\      / `-----------'  \n";
		std::cout << "            /  --|--  \\    /                 \n";
		std::cout << "           /     |     \\                     \n";
		std::cout << "          /     / \\     \\                    \n";
		std::cout << "         /               \\                   \n";

	}
	else if (misses == 2) {

		std::cout << "                 .                            \n";
		std::cout << "                 |                            \n";
		std::cout << "              .-\"^\"-.                       \n";
		std::cout << "             /_....._\\                       \n";
		std::cout << "         .-\"`         `\"-.                  \n";
		std::cout << "        (  ooo  ooo  ooo  )                   \n";
		std::cout << "         '-.,_________,.-'    ,-----------.   \n";
		std::cout << "              /  0  \\        (  Send help! ) \n";
		std::cout << "             / --|-- \\      / `-----------'  \n";
		std::cout << "            /    |    \\    /                 \n";
		std::cout << "           /    / \\    \\                     \n";
		std::cout << "          /             \\                    \n";
		std::cout << "         /               \\                   \n";

	}
	else if (misses == 3) {

		std::cout << "                 .                            \n";
		std::cout << "                 |                            \n";
		std::cout << "              .-\"^\"-.                       \n";
		std::cout << "             /_....._\\                       \n";
		std::cout << "         .-\"`         `\"-.                  \n";
		std::cout << "        (  ooo  ooo  ooo  )                   \n";
		std::cout << "         '-.,_________,.-'    ,-----------.   \n";
		std::cout << "              /--|--\\        (  Send help! ) \n";
		std::cout << "             /   |   \\      / `-----------'  \n";
		std::cout << "            /   / \\   \\    /                 \n";
		std::cout << "           /           \\                     \n";
		std::cout << "          /             \\                    \n";
		std::cout << "         /               \\                   \n";

	}
	else if (misses == 4) {

		std::cout << "                 .                            \n";
		std::cout << "                 |                            \n";
		std::cout << "              .-\"^\"-.                       \n";
		std::cout << "             /_....._\\                       \n";
		std::cout << "         .-\"`         `\"-.                  \n";
		std::cout << "        (  ooo  ooo  ooo  )                   \n";
		std::cout << "         '-.,_________,.-'    ,-----------.   \n";
		std::cout << "              /  |  \\        (  Send help! ) \n";
		std::cout << "             /  / \\  \\      / `-----------' \n";
		std::cout << "            /         \\    /                 \n";
		std::cout << "           /           \\                     \n";
		std::cout << "          /             \\                    \n";
		std::cout << "         /               \\                   \n";

	}
	else if (misses == 5) {

		std::cout << "                 .                            \n";
		std::cout << "                 |                            \n";
		std::cout << "              .-\"^\"-.                       \n";
		std::cout << "             /_....._\\                       \n";
		std::cout << "         .-\"`         `\"-.                  \n";
		std::cout << "        (  ooo  ooo  ooo  )                   \n";
		std::cout << "         '-.,_________,.-'    ,-----------.   \n";
		std::cout << "              / / \\ \\        (  Send help! )\n";
		std::cout << "             /       \\      / `-----------'  \n";
		std::cout << "            /         \\    /                 \n";
		std::cout << "           /           \\                     \n";
		std::cout << "          /             \\                    \n";
		std::cout << "         /               \\                   \n";

	}
	else if (misses == 6) {

		std::cout << "                 .                            \n";
		std::cout << "                 |                            \n";
		std::cout << "              .-\"^\"-.                       \n";
		std::cout << "             /_....._\\                       \n";
		std::cout << "         .-\"`         `\"-.                  \n";
		std::cout << "        (  ooo  ooo  ooo  )                   \n";
		std::cout << "         '-.,_________,.-'    ,-----------.   \n";
		std::cout << "              /     \\        (  Send help! ) \n";
		std::cout << "             /       \\      / `-----------'  \n";
		std::cout << "            /         \\    /                 \n";
		std::cout << "           /           \\                     \n";
		std::cout << "          /             \\                    \n";
		std::cout << "         /               \\                   \n";

	}

}