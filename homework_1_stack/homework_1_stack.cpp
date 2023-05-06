// homework_1_stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

void  printMatrix(int** m, size_t size) {
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            cout << m[row][col] << ", ";
        }
        cout << "\n";
    }
}

template<typename T> void showList(list<T> myList) {
    for (auto const& val : myList) {
        cout << val << ", ";
    }
    cout << endl;
}

/*
* Use Depth First Search for each connected component to find all vertexes without OUT edges.
*/
list<int> findVertexesWithoutOutputEdges(int** m, int size) {
    list<int> candidates;

    bool* visitedVertexes = new bool[size];
    memset(visitedVertexes, false, sizeof(bool) * size); // set all value to 'false'

    for (int startVer = 0; startVer < size; ++startVer) {

        if ( !visitedVertexes[startVer]) {

            // start DFS using curVertex as starting point
            stack<int> dfsStack;

            dfsStack.push(startVer);
            visitedVertexes[startVer] = true;

            while(!dfsStack.empty()){
                int curVer = dfsStack.top();
                dfsStack.pop();

                int adjVertexCount = 0;

                for (int adjVer = 0; adjVer < size; ++adjVer) {

                    // we have edge curVer -> adjVer
                    if (adjVer != curVer && m[curVer][adjVer] == 1) {
                        if (!visitedVertexes[adjVer]) {
                            dfsStack.push(adjVer);
                            visitedVertexes[adjVer] = true;
                        }
                        ++adjVertexCount;
                    }
                }

                // found vertex without output edges
                if (adjVertexCount == 0) {
                    candidates.push_back(curVer);
                }       
            }
        }
    }

    delete[] visitedVertexes;

    return candidates;
}

int findHomerId(int** m, int size) {

    if (size == 1) {
        // assume that one element matrix always have Homer
        return 0;
    }

    list<int> candidates = findVertexesWithoutOutputEdges(m, size);

    //cout << "Found candidates: " << endl;
    //showList(candidates);

    if (candidates.size() == 1) {

        int homerId = candidates.front();

        // check if everyone talked with Homer, check Homer column

        for (int row = 0; row < size; ++row) {
            if (row == homerId) {
                // skip edge for self
                continue;
            }
            if(m[row][homerId] == 0){
                return -1;
            }
        }

        return homerId;
    }
    else {
        return -1;
    }
}

list<string> tokenize(string str, char delimiter){

    size_t start;
    size_t end = 0;

    list<string> tokens;

    while ((start = str.find_first_not_of(delimiter, end)) != string::npos){
        end = str.find(delimiter, start);
        tokens.push_back(str.substr(start, end - start));
    }

    return tokens;
}

int main()
{
    /*
    const int size = 6;
    
    // present 
    int m[size][size] =
    {
      {0, 0, 1, 1, 0, 1},
      {0, 0, 1, 1, 0, 1},
      {0, 1, 0, 1, 0, 1},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 1, 1, 0, 1},
      {0, 0, 0, 1, 0, 0},
    };
    
    // not present case
    int m[size][size] =
    {
      {0, 0, 1, 1, 0, 1},
      {0, 0, 1, 1, 0, 1},
      {0, 1, 0, 1, 0, 1},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 1, 1, 0, 1},
      {0, 1, 0, 0, 0, 0},
    };

    int m[size][size] =
    {
      {0, 0, 1, 1, 0, 1},
      {0, 0, 1, 1, 0, 1},
      {0, 1, 0, 1, 0, 1},
      {0, 1, 0, 0, 0, 0},
      {0, 0, 1, 1, 0, 1},
      {0, 0, 0, 1, 0, 0},
    };

    
    int m[size][size] =
    {
      {0, 0, 1, 1, 0, 1},
      {0, 0, 1, 1, 0, 1},
      {0, 1, 0, 1, 0, 1},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 1, 1, 0, 1},
      {0, 0, 0, 1, 0, 0},
    };
    */

    try {
        cout << "Input matrix size: ";
        int matrixSize;
        cin >> matrixSize;

        if (matrixSize <= 0 || matrixSize > 100) {
            throw invalid_argument("matrix size should be positive value less than 100");
        }

        int** matrix = new int*[matrixSize];

        cout << "Row format example: 1,0,1,0" << endl;

        for (int i = 0; i < matrixSize; i++) {

            cout << "row[" << i << "]: " << flush;

            string line;
            cin >> line;

            list<string> tokens = tokenize(line, ',');

            if (tokens.size() != matrixSize) {
                throw invalid_argument("row size is incorrect");
            }

            matrix[i] = new int[matrixSize]; // allocate single row

            list<string>::iterator it = tokens.begin();

            for (int col = 0; col < matrixSize && it != tokens.end(); ++col, ++it) {

                int slotValue = stoi(*it);

                if (slotValue != 0 && slotValue != 1) {
                    throw invalid_argument("incorrect value inside matrix, should be 0 or 1");
                }

                matrix[i][col] = slotValue;
            }
        }

        //printMatrix(matrix, matrixSize);

        int homerId = findHomerId(matrix, matrixSize);

        if (homerId == -1) {
            cout << "Homer is not present" << endl;
        }
        else {
            cout << "Homer is the person with id " << homerId << endl;
        }

        for (int i = 0; i < matrixSize; ++i) {
            delete[] matrix[i];
        }

        delete[] matrix;
    }
    catch (const exception& ex) {
        cerr << ex.what() << endl;
    }
    catch (...) {
        cerr << "Some unknown exception" << endl;
    }
   
    cout << "homework 1 stack done" << endl;
    return 0;
}

