//MATRIX

//2 1 0 4 3
//0 1 0 4 3
//0 0 2 3 3
//4 5 0 1 2
//4 1 2 2 4

//OPERATIONS
//1 1
//3 3
//2 2
//3 0 

//FINAL STATE
//

//ON THE ABOVE MATRIX , EACH NUMBER IS A COLOURS BALL AND OPERATIONS ARE PERFORMED AND YOU HAVE TO SIMULATE THEM AND RETURN THE FINAL STATE OF THE MATRIX AFTER YOU PERFORM ALL THE OPERATIONS : 
// WHICHEVER OPERATIONS (CELL) IS SELECTED , THAT IS SET = 0 AND IF ITS DIAGONAL NEIGHBOURS ARE ALSO THE SAME COLOUR THEY ARE ALSO SET = 0;
// AFTER THIS, ALL THE BUBBLES ABOVE THESE FRESHLY SET ZEROES SHOULD COME DOWN TO FILL THE GAP
//OPERATIONS IS VECTOR OF 2D VECTORS THAT CONTAIN THE X AND Y INDEX INDICATING THE LOCATION THAT IS TO BE POPPED IN THE MATRIX


#include <bits/stdc++.h>

using namespace std;

void downFall(vector<vector<int>> & matrix, int x, int y){
    while(x>0){
        swap(matrix[x][y], matrix[x-1][y]);
        x--;
    }
}

void doubleDownFall(vector<vector<int>> & matrix, int x, int y){
    swap(matrix[x+1][y], matrix[x][y]);
    while(x>1){
        swap(matrix[x-2][y], matrix[x][y]);
    }
}

void changeState(vector<vector<int>> & matrix, vector<vector<int>> & operations){
    int rows = matrix.size();
    int columns = matrix[0].size();
    for(auto i : operations){
        int x = i[0], y = i[1];
        int colour = matrix[x][y];
        matrix[x][y] = 0;
        int leftUp = x>0 and y>0 ? matrix[x-1][y-1] : -1;
        int rightUp = x>0 and y<columns-1 ? matrix[x-1][y+1] : -1;
        int leftDown = x<rows-1 and y>0 ? matrix[x+1][y-1] : -1;
        int rightDown = x<rows-1 and y < columns-1 ? matrix[x+1][y+1] : -1;
        
        downFall(matrix, x, y);
        
        if(leftUp == colour or leftDown == colour){
            if(leftUp == colour and leftDown == colour){
                matrix[x-1][y-1] = 0;
                matrix[x+1][y-1] = 0;
                doubleDownFall(matrix, x, y-1);
            }
            else if(leftUp == colour){
                matrix[x-1][y-1] = 0;
                downFall(matrix, x-1, y-1);
            } 
            else{
                matrix[x+1][y-1] = 0;
                downFall(matrix, x-1, y+1);  
            } 
        }
        if(rightDown == colour or rightUp == colour){
            if(rightDown == colour and rightUp == colour){
                matrix[x-1][y+1] = 0;
                matrix[x+1][y+1] = 0;
                doubleDownFall(matrix, x, y+1);
            }
            else if(rightDown == colour){
                matrix[x+1][y+1] = 0;
                downFall(matrix, x+1, y+1);  
            } 
            else{
                matrix[x-1][y+1] = 0;
                downFall(matrix, x-1, y+1);  
            } 
        }
        else continue;
    }
}

void printMatrix(vector<vector<int>> & matrix){
    cout<<endl;
    for(auto a : matrix){
        for(auto b : a) cout <<b<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    vector<vector<int>> bubbles = {{1, 1, 1, 4, 3}, {4, 1, 2, 3, 3}, {1, 5, 1, 1, 2}, {4, 3, 2, 2, 4}};
    printMatrix(bubbles);
    vector<vector<int>> operations = {{1, 1}, {3, 3}, {2, 2}, {3, 0}};
    changeState(bubbles, operations);
    printMatrix(bubbles);
    return 0;
}