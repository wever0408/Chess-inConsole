#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Block; 
class Piece;
class Game;
class Player; 
class Player1; 
class Player2; 
class MoveAlgorithm; 
class KingMoveAlgorithm; 
class QueenMoveAlgorithm; 
class RookMoveAlgorithm; 
class BishopMoveAlgorithm; 
class KnightMoveAlgorithm; 
class PawnMoveAlgorithm;
class Score;

enum ScoreType
{
	WIN,DRAW,LOSE
};

enum class PieceType
{
	Bishop,King,Knight,Pawn,Queen,Rook
};

enum class PieceColor
{
	Black,White
};

class Block
{
private:
	int x,y;
public:
	Block(int x = 0,int y = 0):x(x),y(y){}
	int GetX(){return x;}
	int GetY(){return y;}
	void SetX(int x);
	void SetY(int y);
};

class Piece
{
private:
	PieceColor color;
	MoveAlgorithm *moveAlgorithm;
	Block pos;
	PieceType type;
public:
	Piece(PieceColor c,int x,int y,PieceType pt);
	PieceColor GetColor();
	Block GetBlock();
	PieceType GetType();
	void MoveTo(Game &game,Block des);
	void Remove(Game &game);
	void SetMoveAlgorithm(MoveAlgorithm* moveAlgorithm);
	void SetPieceType(PieceType t);
	bool ValidMove(Game &game,Block des);
	
};

class Player
{
protected:
	string name;
	vector<Piece> pieceCollection;
	bool iSbeingChecked;
	bool isCastlingK;
	bool isCastlingQ;
	Block isEnpass;
public:
	Player(string name = "");
	virtual bool CheckEnpass(Block src,Block des) = 0;
	virtual void Promotion(Piece pawn) = 0;
};

class Player1:public Player
{
public:
	Player1(string name = "");
	bool CheckCastlingQ(Game &game,Player2 player2);
	bool CheckCastlingK(Game &game,Player2 player2);
	bool CheckEnpass(Block src,Block des);
	bool IsCheckingPlayer(Game &game,Player2& player2);
	bool IsMatingPlayer(Game &game,Player2& player2);
	void Promotion(Piece pawn);
	friend class Game;
	friend class PawnMoveAlgorithm;
	friend class Player2;
};

class Player2:public Player
{
public:
	Player2(string name = "");
	bool CheckCastlingQ(Game &game,Player1 player1);
	bool CheckCastlingK(Game &game,Player1 player1);
	bool CheckEnpass(Block src,Block des);
	bool IsCheckingPlayer(Game &game,Player1& player1);
	bool IsMatingPlayer(Game &game,Player1& player1);
	void Promotion(Piece pawn);
	friend class Game;
	friend class PawnMoveAlgorithm;
	friend class Player1;
};


class MoveAlgorithm
{
public:
	virtual bool validMove(Game &game,Block src,Block des) = 0;
};

class KingMoveAlgorithm : public MoveAlgorithm
{
public:
	bool validMove(Game &game,Block src,Block des);
};

class QueenMoveAlgorithm : public MoveAlgorithm
{
public:
	bool validMove(Game &game,Block src,Block des);
};

class RookMoveAlgorithm : public MoveAlgorithm
{
public:
	bool validMove(Game &game,Block src,Block des);
};

class KnightMoveAlgorithm : public MoveAlgorithm
{
public:
	bool validMove(Game &game,Block src,Block des);
};

class BishopMoveAlgorithm : public MoveAlgorithm
{
public:
	bool validMove(Game &game,Block src,Block des);
};

class PawnMoveAlgorithm : public MoveAlgorithm
{
public:
	bool validMove(Game &game,Block src,Block des);
};

class Game
{
private:
	Piece* Board[9][9];
	Player1 player1;
	Player2 player2;
public:
	Game();
	bool GameOver();
	void PrintBoard();
	void Start();
	friend class Piece;
	friend class KingMoveAlgorithm;
	friend class QueenMoveAlgorithm;
	friend class RookMoveAlgorithm;
	friend class BishopMoveAlgorithm;
	friend class KnightMoveAlgorithm;
	friend class PawnMoveAlgorithm;
};

class Score
{
private:
	vector<string> name;
	vector<float> nscore;
public:
	void CreateScore(string p1,string p2,int x);
};