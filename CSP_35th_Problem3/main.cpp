#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;

// Helper function to split a string by a delimiter
vector<string> split(const string& s, char delimiter) {
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

int main() {
	int n;
	cin >> n;
	cin.ignore(); // Ignore the newline after the number

	vector<string> originalFile(n);
	for (int i = 0; i < n; ++i) {
		getline(cin, originalFile[i]);
	}

	vector<string> patchLines;
	string line;
	while (getline(cin, line)) {
		if (!line.empty()) {
			patchLines.push_back(line);
		}
	}

	vector<string> updatedFile = originalFile;

	for (size_t i = 0; i < patchLines.size(); ++i) {
		// Skip comments
		if (patchLines[i][0] == '#') continue;

		// Look for @@ block
		if (patchLines[i][0] == '@') {
			// Parse block header manually
			int NN, MM, nn, mm;
			string header = patchLines[i];
			if (sscanf(header.c_str(), "@@ -%d,%d +%d,%d @@", &NN, &MM, &nn, &mm) != 4) {
				cout << "Patch is damaged." << endl;
				return 0;
			}

			vector<string> originalChunk, newChunk;

			// Read block content
			++i;
			while (i < patchLines.size() && patchLines[i][0] != '@') {
				if (patchLines[i][0] == '-') {
					originalChunk.push_back(patchLines[i].substr(1));
				}
				else if (patchLines[i][0] == '+') {
					newChunk.push_back(patchLines[i].substr(1));
				}
				else if (patchLines[i][0] == ' ') {
					originalChunk.push_back(patchLines[i].substr(1));
					newChunk.push_back(patchLines[i].substr(1));
				}
				else if (patchLines[i][0] == '#') {
					// Skip comments within a block
				}
				else {
					cout << "Patch is damaged." << endl;
					return 0;
				}
				++i;
			}
			--i; // Adjust index after exiting the loop

			// Validate block sizes
			if (originalChunk.size() != MM || newChunk.size() != mm) {
				cout << "Patch is damaged." << endl;
				return 0;
			}

			// Apply the patch
			int delta = -1;
			for (int d = -MM; d <= MM; ++d) {
				if (NN + d - 1 >= 0 && NN + d - 1 + MM <= updatedFile.size()) {
					bool match = true;
					for (int j = 0; j < MM; ++j) {
						if (originalChunk[j] != updatedFile[NN + d - 1 + j]) {
							match = false;
							break;
						}
					}
					if (match) {
						delta = d;
						break;
					}
				}
			}

			if (delta == -1) {
				cout << "Patch is damaged." << endl;
				return 0;
			}

			updatedFile.erase(updatedFile.begin() + (NN + delta - 1), updatedFile.begin() + (NN + delta - 1 + MM));
			updatedFile.insert(updatedFile.begin() + (NN + delta - 1), newChunk.begin(), newChunk.end());
			NN += delta;
		}
	}

	for (const auto& line : updatedFile) {
		cout << line << endl;
	}

	return 0;
}
