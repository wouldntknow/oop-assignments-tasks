//23K-2079
#include<iostream>
#include<string>
using namespace std;
class ChessPiece{
    string name;
    string color;
    string symbol;
public:
    ChessPiece(){
        name = "Knight";
        color = "white";
        symbol = "K";
    }

    ChessPiece(string n, string c, string s): name(n),color(c), symbol(s){}
    

    void set_name(){
        name = "Queen";
    }

    void set_color(){
        color = "White";
    }

    void set_symbol(){
        symbol = "Q";
    }

    string get_name(){
        return name;
    }

    string get_color(){
        return color;
    }

    string get_symbol(){
        return symbol;
    }
};

class ChessBoard{
    ChessPiece* Cp[8][8];

public:
    ChessBoard(){
      
        Cp[0][0] = new ChessPiece("rook", "black", "r");
        Cp[0][1] = new ChessPiece("knight", "black", "n");
        Cp[0][2] = new ChessPiece("bishop", "black", "b");
        Cp[0][3] = new ChessPiece("queen", "black", "q");
        Cp[0][4] = new ChessPiece("king", "black", "k");
        Cp[0][5] = new ChessPiece("bishop", "black", "b");
        Cp[0][6] = new ChessPiece("knight", "black", "n");
        Cp[0][7] = new ChessPiece("rook", "black", "r");
        for (int j = 0; j < 8; j++) {
            Cp[1][j] = new ChessPiece("pawn", "black", "p");
        }
           
        Cp[7][0] = new ChessPiece("rook", "white", "R");
        Cp[7][1] = new ChessPiece("knight", "white", "N");
        Cp[7][2] = new ChessPiece("bishop", "white", "B");
        Cp[7][3] = new ChessPiece("queen", "white", "Q");
        Cp[7][4] = new ChessPiece("king", "white", "K");
        Cp[7][5] = new ChessPiece("bishop", "white", "B");
        Cp[7][6] = new ChessPiece("knight", "white", "N");
        Cp[7][7] = new ChessPiece("rook", "white", "R");
        for (int j = 0; j < 8; j++) {
            Cp[6][j] = new ChessPiece("pawn", "white", "P");
        }
     
        for (int i = 2; i < 6; i++) {
            for (int j = 0; j < 8; j++) {
                Cp[i][j] = nullptr;
            }
        }
 
    }

 ~ ChessBoard() 
	{
        for (int i = 0; i < 8; i++)
		 {
            for (int j = 0; j < 8; j++) 
			{
                delete Cp[i][j];
            }
        }
    }

    void display() {
        cout << "  a b c d e f g h" << endl;
        cout << " -----------------" << endl;
        for (int i = 0; i < 8; i++) {
            cout << 8 - i << "|";
            for (int j = 0; j < 8; j++) {
                if (Cp[i][j] != nullptr) {
                    cout << Cp[i][j]->get_symbol() << " ";
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
    
         int sx=source[0]-'a';
         int sY=7-(source[1]-1);
         int Destx=destination[0]-'a';
         int Dest=7-(destination[1]-1);
         
          if (Cp[sY][sx] == nullptr) {
            cout << "No piece at the source position." << endl;
            return false;
    }
   
   

 if (sx < 0 || sY > 7 || sx < 0 || sY > 7 ||
            Destx < 0 || Destx > 7 || Dest < 0 || Dest> 7) {
            cout << "Invalid move: Out of bounds." << endl;
            return false;
        }

        if (Cp[sx][sY] == nullptr) {
            cout << "Invalid move: No piece at source position!" << endl;
            return false;
        }

        if (Cp[Destx][Dest] != nullptr && 
        Cp[Destx][Dest]->get_color() == Cp[sx][sY]->get_color()) {
            cout << "Invalid move: Destination is occupied by same color piece." << endl;
            return false;
        }

        if (Cp[sx][sY]->get_name() == "Pawn" && (Destx != sx + 1 && Destx != sx + 2)) {
            cout << "Invalid move for pawn: First turn only." << endl;
            return false;
        }

        delete Cp[Destx][Dest];
        Cp[Destx][Dest] = Cp[sx][sY];
        Cp[sx][sY] = nullptr;

        return true;
    }
};

int main(){
    ChessBoard B;
    B.display();

    if (B.movepiece("e2", "e4")) {
        cout << "Move successful!" << endl;
    } else {
        cout << "Invalid move!" << endl;
    }
    B.display();
    return 0;
}


