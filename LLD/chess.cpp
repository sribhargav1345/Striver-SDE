#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

enum class Color {White, Black};
enum class Piecetype { Pawn, Rook, Knight, Bishop, Queen, King };

class Board{
private:
    vector<vector<char>> grid(8,vector<int>(8,''));

public:
    Board() {

    }

    void placePiece(int x,int y,char c){
        grid[x][y] = c;
    }

    char getPiece(int x,int y){
        return grid[x][y];
    }

    bool movePiece(int startx,int starty,int endx,int endy){
        auto piece = getPiece(startx,starty);

        if(piece && piece -> isValidMove(startx,starty,endx,endy)){
            grid[endx][endy] = piece;
        }
    }
}


class Piece {
    Color color;
    Piecetype type;

public:
    Piece(Color color, Piecetype type){

    }

    virtual bool isValidMove(int startx, int starty, int endX,int endY){

    };

    Color getColor(){
        return color;
    }

    Piecetype getType(){
        return type;
    }

    virtual ~Piece(){

    }
};

