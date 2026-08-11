#include<iostream>
#include<vector>
#include<unordered_set>
#include<map>
#include<utility>
using namespace std;

int main()
{   
    map<int,unordered_set<string>> rows;
    map<int,unordered_set<string>> columns;
    map<pair<int,int>,unordered_set<string>> sections;

    vector<vector<string>> board = {
    {"5", "3", ".", ".", "7", ".", ".", ".", "."},
    {"6", ".", ".", "1", "9", "5", ".", ".", "."},
    {".", "9", "8", ".", ".", ".", ".", "6", "."},
    {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
    {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
    {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
    {".", "6", ".", ".", ".", ".", "2", "8", "."},
    {".", ".", ".", "4", "1", "9", ".", ".", "5"},
    {".", ".", ".", ".", "8", ".", ".", "7", "9"}
    };

    for(int i = 0;i < 9;i++)
    {
        rows[i];
        for(int j = 0;j < 9;j++)
        {
            if(board[i][j] == ".")
            {
                continue;
            }
            columns[j];
            sections[{i/3,j/3}];
            if((rows[i].contains(board[i][j]) || columns[j].contains(board[i][j]) || sections[{i/3,j/3}].contains(board[i][j])))
            {
                cout<<"Invalid sudoku board.\n";
                return -1;
            }
            else
            {
                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                sections[{i/3,j/3}].insert(board[i][j]);
            } 
        }
    }    
    cout<<"Valid.\n";
    return 0;
}