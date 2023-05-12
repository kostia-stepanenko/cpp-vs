

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class DirectedGraph {
private:
	map<char, set<char>> adjList;

public:
	void addEdge(char from, char to) {

		// 'from' vertex not found, insert
		if (adjList.count(from) == 0) {
			adjList.insert({ from, set<char>()});
		}

		// 'to' vertex not found, insert 
		if (adjList.count(to) == 0) {
			adjList.insert({ to, set<char>() });
		}

		adjList.find(from)->second.insert(to);
	}

	friend ostream& operator<<(ostream& os,  const DirectedGraph& g) {
		for (const auto verPair : g.adjList) {
			cout << verPair.first << " => "; 

			for (const auto destVer : verPair.second) {
				cout << destVer << ", ";
			}

			cout << endl;
		}
		return os;
	}
};

size_t findMaxWordLength(vector<string> words) {

	size_t maxLength = 0;

	for (const auto singleWord : words) {
		maxLength = max(maxLength, singleWord.length());
	}

	return maxLength;
}

bool hasSamePrefix(string first, string second, int prefixLength) {

	if (first.length() < prefixLength || second.length() < prefixLength) {
		return false;
	}

	for (int i = 0; i < prefixLength; ++i) {
		if (first[i] != second[i]) {
			return false;
		}
	}

	return true;
}

DirectedGraph buildDepeencyGraph(vector<string> words) {

	size_t maxLength = findMaxWordLength(words);

	//cout << "maxLength: " << maxLength << endl;

	DirectedGraph graph;

	for (size_t index = 0; index < maxLength; ++index) {

		for (int i = 1; i < words.size(); ++i) {
			string prev = words[i - 1];
			string cur = words[i];

			if (index < prev.length() && index < cur.length() &&
				hasSamePrefix(prev, cur, index)) {

				if (prev[index] != cur[index]) {
					char from = prev[index];
					char to = cur[index];

					//cout << "edge: " << from << " -> " << to << endl;

					graph.addEdge(from, to);
				}
			}
		}
	}

	return graph;

}



int main(){

	vector<string> words;

	words.push_back("ion");
	words.push_back("ana");
	words.push_back("adonia");
	words.push_back("doina");
	words.push_back("doinn");
	words.push_back("ddan");
	words.push_back("ddao");

	DirectedGraph graph = buildDepeencyGraph(words);

	cout << " ======================  Graph of chars ====================== " << endl;
	cout << graph << endl;
	cout << " ============================================================= " << endl;
	

	cout << "homework 2 graphs completed" << endl;
}
