#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <string>
#include <algorithm>
using namespace std;

// Function to select a random codeword from the list and create the initial answer string
pair<string, string> select_codeword(vector<string> codewords);

// Class definitions
class Game {
private:
	string codeword;
public:
	Game(string codeword) : codeword(codeword) {}
	void greet();
	void end_game(string answer);
	void display_status(string answer, vector<char> incorrect);
	void display_misses(int misses);
	string get_codeword() const { return codeword; }
};

class Player {
private:
	string answer;
	vector<char> incorrect;
	int misses;
public:
	Player(string answer) : answer(answer), misses(0) {}
	void make_guess(string codeword);
	string get_answer() const { return answer; }
	int get_misses() const { return misses; }
	vector<char> get_incorrect() const { return incorrect; }
	bool has_won(string codeword) const { return answer == codeword; }
};