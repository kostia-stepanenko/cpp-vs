// homework_1_stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <stack>

using namespace std;

template <size_t size> void  printMatrix(int(&m)[size][size]) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << m[i][j] << ", ";
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
template <size_t size> list<int> findVertexesWithoutOutputEdges(int(&m)[size][size]) {
    list<int> candidates;

    bool visitedVertexes[size] = {false};

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

    return candidates;
}

template <size_t size> int findHomerId(int(&m)[size][size]) {

    if (size == 1) {
        // assume that one element matrix always have Homer
        return 0;
    }

    list<int> candidates = findVertexesWithoutOutputEdges<size>(m);

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

int main()
{
    const int size = 6;

    //row fill first, then second
    /*
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
    */

    int m[size][size] =
    {
      {0, 0, 1, 1, 0, 1},
      {0, 0, 1, 1, 0, 1},
      {0, 1, 0, 1, 0, 1},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 1, 1, 0, 1},
      {0, 0, 0, 1, 0, 0},
    };


    //printMatrix<size>(m);

    int homerId = findHomerId<size>(m);

    if (homerId == -1) {
        cout << "Homer is not present" << endl;
    }
    else {
        cout << "Homer is the person with id " << homerId << endl;
    }
   
    cout << "homework 1 stack done" << endl;
    return 0;
}

