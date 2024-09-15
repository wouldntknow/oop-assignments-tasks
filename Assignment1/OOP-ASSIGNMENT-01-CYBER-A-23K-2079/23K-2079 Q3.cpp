//23K-2079
#include<iostream>
#include<string>
using namespace std;
class ChessPiece{
    string nameofchesspiece;
    string color;
    string symbol;
public:
    ChessPiece(){
        nameofchesspiece = "pawn";
        color = "white";
        symbol = "p";
    }

    ChessPiece(string n, string c, string s){
        nameofchesspiece = n;
        color = c;
        symbol = s;
    }

    void set_name(){
        nameofchesspiece = "Queen";
    }

    void set_color(){
        color = "Black";
    }

    void set_symbol(){
        symbol = "q";
    }

    string get_name(){
        return nameofchesspiece;
    }

    string get_color(){
        return color;
    }

    string get_symbol(){
        return symbol;
    }
};

class ChessBoard{
    ChessPiece* o1[8][8];

public:
    ChessBoard(){
        //WHITE PIECES
        o1[0][0] = new ChessPiece("rook", "black", "r");
        o1[0][1] = new ChessPiece("knight", "black", "n");
        o1[0][2] = new ChessPiece("bishop", "black", "b");
        o1[0][3] = new ChessPiece("queen", "black", "q");
        o1[0][4] = new ChessPiece("king", "black", "k");
        o1[0][5] = new ChessPiece("bishop", "black", "b");
        o1[0][6] = new ChessPiece("knight", "black", "n");
        o1[0][7] = new ChessPiece("rook", "black", "r");
        for (int j = 0; j < 8; j++) {
            o1[1][j] = new ChessPiece("pawn", "black", "p");
        }
           //BLACK PIECES
        o1[7][0] = new ChessPiece("rook", "white", "R");
        o1[7][1] = new ChessPiece("knight", "white", "N");
        o1[7][2] = new ChessPiece("bishop", "white", "B");
        o1[7][3] = new ChessPiece("queen", "white", "Q");
        o1[7][4] = new ChessPiece("king", "white", "K");
        o1[7][5] = new ChessPiece("bishop", "white", "B");
        o1[7][6] = new ChessPiece("knight", "white", "N");
        o1[7][7] = new ChessPiece("rook", "white", "R");
        for (int j = 0; j < 8; j++) {
            o1[6][j] = new ChessPiece("pawn", "white", "P");
        }
        //EMPTY SPACE
        for (int i = 2; i < 6; i++) {
            for (int j = 0; j < 8; j++) {
                o1[i][j] = nullptr;
            }
        }
 
    }

    //DESTRUCTOR
 ~ ChessBoard() 
	{
        for (int i = 0; i < 8; i++)
		 {
            for (int j = 0; j < 8; j++) 
			{
                delete o1[i][j];
            }
        }
    }

    void display() {
        cout << "  a b c d e f g h" << endl;
        cout << " -----------------" << endl;
        for (int i = 0; i < 8; i++) {
            cout << 8 - i << "|";
            for (int j = 0; j < 8; j++) {
                if (o1[i][j] != nullptr) {
                    cout << o1[i][j]->get_symbol() << " ";
                } 
                else {
                    cout << ". ";
                }
            }
            cout << "|" << 8 - i << endl;
        }
        cout << " -----------------" << endl;
        cout << "  a b c d e f g h" << endl;
    }

   bool movepiece(string source,string destination){
     // Converting all alphabet into ASCII value and reversing the Y-axis;
         int sourceX=source[0]-'a';
         int sourceY=7-(source[1]-1);
         int destinationX=destination[0]-'a';
         int destinationY=7-(destination[1]-1);
         
          if (o1[sourceY][sourceX] == nullptr) {
            cout << "No piece at the source position." << endl;
            return false;
    }
   
   //MOVEMENT OF PIECES

 if (sourceX < 0 || sourceY > 7 || sourceX < 0 || sourceY > 7 ||
            destinationX < 0 || destinationX > 7 || destinationY < 0 || destinationY> 7) {
            cout << "Invalid move: Out of bounds." << endl;
            return false;
        }

        if (o1[sourceX][sourceY] == nullptr) {
            cout << "Invalid move: No piece at source position." << endl;
            return false;
        }

        if (o1[destinationX][destinationY] != nullptr && 
        o1[destinationX][destinationY]->get_color() == o1[sourceX][sourceY]->get_color()) {
            cout << "Invalid move: Destination is occupied by same color piece." << endl;
            return false;
        }

        if (o1[sourceX][sourceY]->get_name() == "Pawn" && (destinationX != sourceX + 1 && destinationX != sourceX + 2)) {
            cout << "Invalid move for pawn: First turn only." << endl;
            return false;
        }

        delete o1[destinationX][destinationY];
        o1[destinationX][destinationY] = o1[sourceX][sourceY];
        o1[sourceX][sourceY] = nullptr;

        return true;
    }
};

int main(){
    ChessBoard board;
    board.display();

    if (board.movepiece("e2", "e4")) {
        cout << "Move successful!" << endl;
    } else {
        cout << "Invalid move!" << endl;
    }
    board.display();
    return 0;
}


