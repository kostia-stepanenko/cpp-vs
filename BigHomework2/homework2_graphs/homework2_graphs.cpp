

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <exception>

using namespace std;

class DirectedGraph {
private:
	map<char, set<char>> adjList;

	/*
	a => {d, n}
	n => {d, o}
	i => {a}
	o => {d}
	d => {}

	*/

public:

	set<char> getAdjVertexes(char ver) {
		return adjList.find(ver) -> second;
	}

	vector<char> getVertexes() {
		vector<char> res;

		for (const auto val : adjList) {
			res.push_back(val.first);
		}

		return res;
	}

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
			cout << verPair.first << " => { "; 

			for (const auto destVer : verPair.second) {
				cout << destVer << ", ";
			}

			cout << " } " << endl;
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

DirectedGraph buildDependencyGraph(vector<string> words) {

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

vector<char> topoligicalOrder(DirectedGraph g) {
	vector<char> res;

	// track IN degree for each vertex
	map<char, int> inDegree;

	// set all IN degree values to 0
	for (const auto ver : g.getVertexes()) {
		inDegree.insert({ver, 0});
	}

	// calculate IN degree for every vertex using Graph
	for (const auto ver : g.getVertexes()) {
		for (const auto adjVer : g.getAdjVertexes(ver)) {
			inDegree.find(adjVer)->second += 1;
		}
	}
	queue<char> vertexesForProcessing;

	for (const auto baseVer : inDegree) {
		if (baseVer.second == 0) {
			vertexesForProcessing.push(baseVer.first);
		}
	}

	while (! vertexesForProcessing.empty()) {
		char curVer = vertexesForProcessing.front();
		vertexesForProcessing.pop();

		res.push_back(curVer);

		for (const auto adjVer : g.getAdjVertexes(curVer)) {
			inDegree.find(adjVer)->second -= 1;
			if (inDegree.find(adjVer)->second == 0) {
				vertexesForProcessing.push(adjVer);
			}
		}
	}

	if (res.size() != g.getVertexes().size()) {
		throw invalid_argument("Invalid Graph, can't complete topological sorting");
	}

	return res;
}

string toString(vector<char> res) {

	string str;

	for (const auto val : res) {
		str += val;
	}

	return str;
}


vector<string> readWordsFromFile(string fileName) {
	vector<string> words;

	ifstream inFile(fileName);

	int lineIndex = 0;
	string line;
	while (getline(inFile, line)) {
		if (line == ".") {
			break;
		}

		if (line.length() > 10) {
			throw invalid_argument("line is longer than 10 characters");
		}
		if (lineIndex > 50) {
			throw invalid_argument("more than 50 words detected");
		}

		words.push_back(line);
		++lineIndex;
	}

	return words;
}

void writeToFile(string fileName, string valueToWrite) {

	ofstream outFile(fileName);

	if (outFile.is_open()) {
		outFile << valueToWrite << endl;
		outFile.close();
	}
}

int main(){

	try {
		vector<string> words = readWordsFromFile("index.in");
		/*
		words.push_back("ion");
		words.push_back("ana");
		words.push_back("adonia");
		words.push_back("doina");
		words.push_back("doinn");
		words.push_back("ddan");
		words.push_back("ddao");
		*/

		DirectedGraph graph = buildDependencyGraph(words);

		cout << " ======================  Graph of chars ====================== " << endl;
		cout << graph << endl;
		cout << " ============================================================= " << endl << endl;

		vector<char> topologicalOrderRes = topoligicalOrder(graph);

		string outIndex = toString(topologicalOrderRes);

		cout << "OUT index: " << outIndex << endl << endl;

		cout << "Saving index into file" << endl;
		writeToFile("index.out", outIndex);
		cout << "Index saved" << endl;

		cout << "homework 2 graphs completed" << endl;
	}
	catch (const exception& ex) {
		cerr << ex.what() << endl;
	}
}
