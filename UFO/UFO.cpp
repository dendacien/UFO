#include "ufo_functions.hpp"

// Global list of codewords
vector<string> codewords = { "galaxy", "nebula", "meteor", "satellite", "telescope", "astronaut", "comet", "orbit", "cosmos", "universe" };

int main() {
	// Seed the random number generator
	srand(static_cast<unsigned int>(time(0)));

	bool playing = true;
	while (playing) {
		// Select a random codeword and create game and player instances
		pair<string, string> codePair = select_codeword(codewords);
		Game game(codePair.first);
		Player player(codePair.second);

		game.greet();

		// Main game loop
		// The game continues until the player has 7 misses or has guessed the codeword
		while (player.get_misses() < 7 && !player.has_won(game.get_codeword())) {
			game.display_misses(player.get_misses());
			game.display_status(player.get_answer(), player.get_incorrect());
			player.make_guess(game.get_codeword());
		}
		// End of game
		game.end_game(player.get_answer());
		// Ask the player if they want to play again
		cout << "Would you like to play again? (y/n) ";
		char response;
		string input;
		getline(cin, input);
		if (!input.empty()) {
			response = tolower(input[0]);
		}
		else {
			response = 'n';
		}
		// If the player does not want to continue we can close out this while loop
		if (response == 'n')  {
			cout << "Thanks for playing!\n";
			playing = false;
		}
	}

	return 0;
}
