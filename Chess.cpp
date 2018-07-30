#include "Chess.h"

void Block::SetX(int x) 
{
	this->x = x;
}

void Block::SetY(int y) 
{
	this->y =y;
}

Game::Game() /
{
	cout << "Nhap ten nguoi choi 1: ";
	cin >> player1.name;
	cout << "Nhap ten nguoi choi 2: ";
	cin >> player2.name;
	system("cls");
	for(int i = 0;i < 9;i++)
	{
		for(int j= 0;j < 9;j++)
		{
			Board[i][j] = NULL;
		}
	}
	Piece KingW1(PieceColor::White,1,5,PieceType::King);
	Piece QueenW1(PieceColor::White,1,4,PieceType::Queen);
	Piece RookW1(PieceColor::White,1,1,PieceType::Rook);
	Piece RookW2(PieceColor::White,1,8,PieceType::Rook);
	Piece KnightW1(PieceColor::White,1,2,PieceType::Knight);
	Piece KnightW2(PieceColor::White,1,7,PieceType::Knight);
	Piece BishopW1(PieceColor::White,1,3,PieceType::Bishop);
	Piece BishopW2(PieceColor::White,1,6,PieceType::Bishop);
	Piece PawnW1(PieceColor::White,2,1,PieceType::Pawn);
	Piece PawnW2(PieceColor::White,2,2,PieceType::Pawn);
	Piece PawnW3(PieceColor::White,2,3,PieceType::Pawn);
	Piece PawnW4(PieceColor::White,2,4,PieceType::Pawn);
	Piece PawnW5(PieceColor::White,2,5,PieceType::Pawn);
	Piece PawnW6(PieceColor::White,2,6,PieceType::Pawn);
	Piece PawnW7(PieceColor::White,2,7,PieceType::Pawn);
	Piece PawnW8(PieceColor::White,2,8,PieceType::Pawn);
	player1.pieceCollection.push_back(KingW1);
	player1.pieceCollection.push_back(QueenW1);
	player1.pieceCollection.push_back(RookW1);
	player1.pieceCollection.push_back(RookW2);
	player1.pieceCollection.push_back(KnightW1);
	player1.pieceCollection.push_back(KnightW2);
	player1.pieceCollection.push_back(BishopW1);
	player1.pieceCollection.push_back(BishopW2);
	player1.pieceCollection.push_back(PawnW1);
	player1.pieceCollection.push_back(PawnW2);
	player1.pieceCollection.push_back(PawnW3);
	player1.pieceCollection.push_back(PawnW4);
	player1.pieceCollection.push_back(PawnW5);
	player1.pieceCollection.push_back(PawnW6);
	player1.pieceCollection.push_back(PawnW7);
	player1.pieceCollection.push_back(PawnW8);
	for(int i = 0;i < player1.pieceCollection.size();i++)
	{
		Board[player1.pieceCollection[i].GetBlock().GetX()][player1.pieceCollection[i].GetBlock().GetY()] = &player1.pieceCollection[i];
	}
	Piece KingB1(PieceColor::Black,8,5,PieceType::King);
	Piece QueenB1(PieceColor::Black,8,4,PieceType::Queen);
	Piece RookB1(PieceColor::Black,8,1,PieceType::Rook);
	Piece RookB2(PieceColor::Black,8,8,PieceType::Rook);
	Piece KnightB1(PieceColor::Black,8,2,PieceType::Knight);
	Piece KnightB2(PieceColor::Black,8,7,PieceType::Knight);
	Piece BishopB1(PieceColor::Black,8,3,PieceType::Bishop);
	Piece BishopB2(PieceColor::Black,8,6,PieceType::Bishop);
	Piece PawnB1(PieceColor::Black,7,1,PieceType::Pawn);
	Piece PawnB2(PieceColor::Black,7,2,PieceType::Pawn);
	Piece PawnB3(PieceColor::Black,7,3,PieceType::Pawn);
	Piece PawnB4(PieceColor::Black,7,4,PieceType::Pawn);
	Piece PawnB5(PieceColor::Black,7,5,PieceType::Pawn);
	Piece PawnB6(PieceColor::Black,7,6,PieceType::Pawn);
	Piece PawnB7(PieceColor::Black,7,7,PieceType::Pawn);
	Piece PawnB8(PieceColor::Black,7,8,PieceType::Pawn);
	player2.pieceCollection.push_back(KingB1);
	player2.pieceCollection.push_back(QueenB1);
	player2.pieceCollection.push_back(RookB1);
	player2.pieceCollection.push_back(RookB2);
	player2.pieceCollection.push_back(KnightB1);
	player2.pieceCollection.push_back(KnightB2);
	player2.pieceCollection.push_back(BishopB1);
	player2.pieceCollection.push_back(BishopB2);
	player2.pieceCollection.push_back(PawnB1);
	player2.pieceCollection.push_back(PawnB2);
	player2.pieceCollection.push_back(PawnB3);
	player2.pieceCollection.push_back(PawnB4);
	player2.pieceCollection.push_back(PawnB5);
	player2.pieceCollection.push_back(PawnB6);
	player2.pieceCollection.push_back(PawnB7);
	player2.pieceCollection.push_back(PawnB8);
	for(int i = 0;i < player2.pieceCollection.size();i++)
	{
		Board[player2.pieceCollection[i].GetBlock().GetX()][player2.pieceCollection[i].GetBlock().GetY()] = &player2.pieceCollection[i];
	}
}

bool Game::GameOver() 
{
	Score s;
	//CHIEU HET
	if (player1.pieceCollection[0].GetBlock().GetX()!= 0 && player2.pieceCollection[0].GetBlock().GetX() != 0)
	{
		if (player1.IsMatingPlayer(*this,player2))
		{
			cout << "***" << player1.name << " WIN***" << endl << endl;
			s.CreateScore(player1.name,player2.name,ScoreType::WIN);
			return 1;

		}
		else if (player2.IsMatingPlayer(*this,player1))
		{
			cout << "***" << player2.name << " WIN***" << endl;
			s.CreateScore(player1.name,player2.name,ScoreType::LOSE);
			return 1;
		}
	}
	else
	{
		if (player1.pieceCollection[0].GetBlock().GetX() == 0)
		{
			cout << "***" << player2.name << " WIN***" << endl;
			s.CreateScore(player1.name,player2.name,ScoreType::LOSE);
		}
		else
		{
			cout << "***" << player1.name << " WIN***" << endl << endl;
			s.CreateScore(player1.name,player2.name,ScoreType::WIN);
		}
		return 1;
	}

	//CO HOA
	int count1 = 0;
	for(int i = 0;i < player2.pieceCollection.size();i++)
	{
		if(player2.pieceCollection[i].GetBlock().GetX() != 0 && player2.pieceCollection[i].GetBlock().GetY() != 0)
		{
			count1++;
		}
	}
	if (count1 == 1)
	{
		if (!player1.IsCheckingPlayer(*this,player2))
		{
			int x = player2.pieceCollection[0].GetBlock().GetX();
			int y = player2.pieceCollection[0].GetBlock().GetY();
			int ArrX[8] = { x + 1, x + 1, x + 1, x, x, x - 1, x - 1, x - 1 };
			int ArrY[8] = { y - 1, y, y + 1, y - 1, y + 1, y - 1, y, y + 1 };
			int count = 0;
			for(int i = 0;i < 8;i++)
			{
				Block des(ArrX[i],ArrY[i]);
				if (player2.pieceCollection[0].ValidMove(*this,des)){
					int flag = 0;
					for(int j = 0;j < player1.pieceCollection.size();j++)
					{
						if(player1.pieceCollection[j].GetBlock().GetX() != 0 && player1.pieceCollection[j].GetBlock().GetY() != 0)
						{
							if (player1.pieceCollection[j].ValidMove(*this,des))
							{
								flag = 1;
								break;
							}
						}
					}
					if (flag == 0)
					{
						return 0;
					}
				}
				else count++;
			}
			if (count != 8)
			{
				cout << "***DRAW***" << endl;
				s.CreateScore(player1.name,player2.name,ScoreType::DRAW);
				return 1;
			}
		}
	}

	int count2 = 0;
	for(int i = 0;i < player1.pieceCollection.size();i++)
	{
		if(player1.pieceCollection[i].GetBlock().GetX() != 0 && player1.pieceCollection[i].GetBlock().GetY() != 0)
		{
			count2++;
		}
	}
	if (count2 == 1)
	{
		if (!player2.IsCheckingPlayer(*this,player1))
		{
			int x = player1.pieceCollection[0].GetBlock().GetX();
			int y = player1.pieceCollection[0].GetBlock().GetY();
			int ArrX[8] = { x + 1, x + 1, x + 1, x, x, x - 1, x - 1, x - 1 };
			int ArrY[8] = { y - 1, y, y + 1, y - 1, y + 1, y - 1, y, y + 1 };
			int count = 0;
			for(int i = 0;i < 8;i++)
			{

				Block des(ArrX[i],ArrY[i]);
				if (player1.pieceCollection[0].ValidMove(*this,des)){
					int flag = 0;
					for(int j = 0;j < player2.pieceCollection.size();j++)
					{
						if(player2.pieceCollection[j].GetBlock().GetX() != 0 && player2.pieceCollection[j].GetBlock().GetY() != 0)
						{
							if (player2.pieceCollection[j].ValidMove(*this,des))
							{
								flag = 1;
								break;
							}
						}
					}
					if (flag == 0)
					{
						return 0;
					}
				}
				else count++;
			}
			if (count != 8)
			{
				cout << "***DRAW***" << endl;
				s.CreateScore(player1.name,player2.name,ScoreType::DRAW);
				return 1;
			}
		}
	}
	return 0;
}

void Game::PrintBoard() 
{
	cout << setw(12) << "Player2" << endl;
	for(int i = 8;i > 0;i--)
	{
		cout << i << "|";
		for(int j = 1;j < 9;j++)
		{
			if (Board[i][j] == NULL)
			{
				cout << "* ";
			}
			else
			{
				if (Board[i][j]->GetColor() == PieceColor::White)
				{
					switch(Board[i][j]->GetType())
					{
					case PieceType::King:
						cout << "K ";
						break;
					case PieceType::Queen:;
						cout << "Q ";
						break;
					case PieceType::Rook:;
						cout << "R ";
						break;
					case PieceType::Bishop:;
						cout << "B ";
						break;
					case PieceType::Knight:;
						cout << "N ";
						break;
					case PieceType::Pawn:;
						cout << "P ";
						break;
					} 
				}
				else
				{
					switch(Board[i][j]->GetType())
					{
					case PieceType::King:;
						cout << "k ";
						break;
					case PieceType::Queen:;
						cout << "q ";
						break;
					case PieceType::Rook:;
						cout << "r ";
						break;
					case PieceType::Bishop:;
						cout << "b ";
						break;
					case PieceType::Knight:;
						cout << "n ";
						break;
					case PieceType::Pawn:;
						cout << "p ";
						break;
					}

				}
			}
		}
		cout << endl;
	}
	cout << "  ----------------" << endl;
	cout << "  a b c d e f g h" << endl;
	cout << setw(12) << "Player1" << endl << endl;
}
void Game::Start() 
{
	while(!GameOver())
	{
		char temp[10];
		int yfrom;
		int xfrom ;
		int xto;
		int yto;
		Block des;
		// LUOT CUA NGUOI CHOI 1 (QUAN TRANG)
		PrintBoard();
		cout << "Player1: " << player1.name << " (White)" << endl;
		if (player1.iSbeingChecked == 1)
		{
			cout << "***VUA DANG BI CHIEU***" << endl;
		}

		// KIEM TRA NEU LA O HOP LE
LOOP1:do{

		cout << "Nhap vi tri quan co: ";
		cin >> temp;
		yfrom = tolower(temp[0]) - 'a'+ 1;
		xfrom = temp[1] - '1' + 1;
		if ((yfrom  > 0 && yfrom  <= 8) && (xfrom  > 0 && xfrom  <= 8))
		{
			if (Board[xfrom][yfrom] != NULL && Board[xfrom][yfrom]->GetColor() == PieceColor::White)
			{
				break;
			}
		}
	  }while(1);

	  do{
		  cout << "Nhap o muon di chuyen toi(00 de hoan tac): ";
		  cin >> temp;
		  yto = tolower(temp[0]) - 'a' + 1;
		  xto = temp[1] - '1' + 1;
		  if (xto == 0) goto LOOP1;
		  des.SetX(xto);
		  des.SetY(yto);
	  }while(!Board[xfrom][yfrom]->ValidMove(*this,des));
	  // KIEM TRA NEU O DI CHUYEN TOI KHONG RONG (AN QUAN DOI PHUONG)
	  if (Board[xto][yto] != NULL) 
	  {
		  Board[xto][yto]->Remove(*this);
	  }
	  Board[xfrom][yfrom]->MoveTo(*this,des);
	  // KIEM TRA NEU LA AN CHOT QUA DUONG
	  if (Board[xto][yto]->GetType() == PieceType::Pawn)
	  {
		  if (player1.isEnpass.GetX() == des.GetX() && player1.isEnpass.GetY() == des.GetY())// operator ==
		  {
			  Board[player1.isEnpass.GetX()-1][player1.isEnpass.GetY()]->Remove(*this);
		  }
		  if (xto == 8)
		  {
			  player1.Promotion(*Board[xto][yto]);
		  }
	  }
	  // KIEM TRA NEU CON KHA NANG NHAP THANH
	  if (player1.isCastlingK == 1 || player1.isCastlingQ == 1){
		  if (Board[xto][yto]->GetType() == PieceType::Rook)
		  {
			  if (xfrom == 1 && yfrom == 8) player1.isCastlingK = 0;
			  if (xfrom == 1 && yfrom == 1) player1.isCastlingQ = 0;
		  }
		  if (Board[xto][yto]->GetType() == PieceType::King)
		  {

			  if (player1.isCastlingQ == 1 && (des.GetX() == 1 && des.GetY() == 3))
			  {
				  cout << "---NHAP THANH XA THANH CONG---" << endl;
				  Block desRook(1,4);
				  Board[1][1]->MoveTo(*this,desRook);

			  }
			  else if (player1.isCastlingK == 1 && (des.GetX() == 1 && des.GetY() == 7))
			  {
				  cout << "---NHAP THANH GAN THANH CONG---" << endl;
				  Block desRook(1,6);
				  Board[1][8]->MoveTo(*this,desRook);
			  }
			  if (xfrom == 1 && yfrom == 5 && (player1.isCastlingK == 1 || player1.isCastlingQ == 1))
			  {
				  player1.isCastlingK = 0;
				  player1.isCastlingQ = 0;
			  }
		  }
	  }
	  // DAT GIA TRI LAI CHO BIEN KIEM TRA AN CHOT QUA DUONG
	  player1.isEnpass.SetX(0);
	  player1.isEnpass.SetY(0);

	  system("cls");

	  if (!GameOver())
	  {
		  // LUOI CUA NGUOI CHOI 2
		  PrintBoard();
		  cout << "Player2: " << player2.name << " (Black)" << endl;
		  if (player2.iSbeingChecked == 1)
		  {
			  cout << "***VUA DANG BI CHIEU***" << endl;
		  }


		  // KIEM TRA NEU LA O HOP LE
LOOP2:do{

		  cout << "Nhap vi tri quan co: ";
		  cin >> temp;
		  yfrom = tolower(temp[0]) - 'a'+ 1;
		  xfrom = temp[1] - '1' + 1;
		  if ((yfrom  > 0 && yfrom  <= 8) && (xfrom  > 0 && xfrom  <= 8))
		  {
			  if (Board[xfrom][yfrom] != NULL && Board[xfrom][yfrom]->GetColor() == PieceColor::Black)
			  {
				  break;
			  }
		  }
	  }while(1);


	  // NHAP O MUON DI CHUYEN TOI
	  // KIEM TRA O DI CHUYEN TOI CO HOP LE
	  do{
		  cout << "Nhap o muon di chuyen toi(00 de hoan tac): ";
		  cin >> temp;
		  yto = tolower(temp[0]) - 'a' + 1;
		  xto = temp[1] - '1' + 1;
		  if (xto == 0) goto LOOP2;
		  des.SetX(xto);
		  des.SetY(yto);
	  }while(!Board[xfrom][yfrom]->ValidMove(*this,des));


	  // KIEM TRA NEU O DI CHUYEN TOI KHONG RONG (AN QUAN DOI PHUONG)
	  if (Board[xto][yto] != NULL) 
	  {
		  Board[xto][yto]->Remove(*this);
	  }
	  Board[xfrom][yfrom]->MoveTo(*this,des);
	  // KIEM TRA NEU LA AN CHOT QUA DUONG
	  if (Board[xto][yto]->GetType() == PieceType::Pawn)
	  {
		  if (player2.isEnpass.GetX() == des.GetX() && player2.isEnpass.GetY() == des.GetY())// operator ==
		  {
			  Board[player2.isEnpass.GetX()+1][player2.isEnpass.GetY()]->Remove(*this);
		  }
		  if (xto == 1)
		  {
			  player2.Promotion(*Board[xto][yto]);
		  }
	  }
	  // KIEM TRA NEU CON KHA NANG NHAP THANH
	  if (player2.isCastlingK == 1 || player2.isCastlingQ == 1){
		  if (Board[xto][yto]->GetType() == PieceType::Rook)
		  {
			  if (xfrom == 8 && yfrom == 8) player2.isCastlingK = 0;
			  if (xfrom == 8 && yfrom == 1) player2.isCastlingQ = 0;
		  }
		  if (Board[xto][yto]->GetType() == PieceType::King)
		  {

			  if (player2.isCastlingQ == 1 && (des.GetX() == 8 && des.GetY() == 3))
			  {
				  cout << "---NHAP THANH XA THANH CONG---" << endl;
				  Block desRook(8,4);
				  Board[8][1]->MoveTo(*this,desRook);

			  }
			  else if (player2.isCastlingK == 1 && (des.GetX() == 8 && des.GetY() == 7))
			  {
				  cout << "---NHAP THANH GAN THANH CONG---" << endl;
				  Block desRook(8,6);
				  Board[8][8]->MoveTo(*this,desRook);
			  }
			  if (xfrom == 8 && yfrom == 5 &&	(player2.isCastlingK == 1 || player2.isCastlingQ == 1))
			  {
				  player2.isCastlingK = 0;
				  player2.isCastlingQ = 0;
			  }
		  }
	  }
	  // DAT GIA TRI LAI CHO BIEN KIEM TRA AN CHOT QUA DUONG
	  player2.isEnpass.SetX(0);
	  player2.isEnpass.SetY(0);
	  system("cls");
	  }
	  else return;
	}

}

bool KingMoveAlgorithm::validMove(Game &game, Block src, Block des) 
{
	if ((des.GetX() > 0 && des.GetX() <= 8) && (des.GetY() > 0 && des.GetY() <= 8
		&& (des.GetX() != src.GetX() || des.GetY() != src.GetY()))){
			int x = src.GetX();
			int y = src.GetY();
			int ArrX[8] = { x + 1, x + 1, x + 1, x, x, x - 1, x - 1, x - 1 };
			int ArrY[8] = { y - 1, y, y + 1, y - 1, y + 1, y - 1, y, y + 1 };
			if (game.Board[src.GetX()][src.GetY()]->GetColor() == PieceColor::White)
			{
				if (des.GetX() == 1 && (des.GetY() == 3))
				{
					if (game.Board[1][4] == NULL && game.Board[1][3] == NULL && game.Board[1][2] == NULL)
					{
						if (game.player2.CheckCastlingQ(game,game.player1) == true)
						{
							return 1;
						}
					}
				}
				else if (des.GetX() == 1 && (des.GetY() == 7))
				{
					if (game.Board[1][6] == NULL && game.Board[1][7] == NULL)
					{
						if (game.player2.CheckCastlingK(game,game.player1) == true)
						{
							return 1;
						}
					}
				}
			}
			if (game.Board[src.GetX()][src.GetY()]->GetColor() == PieceColor::Black)
			{
				if (des.GetX() == 8 && des.GetY() == 3)
				{
					if (game.Board[8][4] == NULL && game.Board[8][3] == NULL && game.Board[8][2] == NULL)
					{
						if (game.player1.CheckCastlingQ(game,game.player2) == true)
						{
							return 1;
						}
					}
				}
				else if (des.GetX() == 8 && des.GetY() == 7)
				{
					if (game.Board[8][6] == NULL && game.Board[8][7] == NULL)
					{
						if (game.player1.CheckCastlingK(game,game.player2) == true)
						{
							return 1;
						}
					}
				}
			}
			for (int i = 0; i < 8; i++)
			{
				if (ArrX[i] == des.GetX() && ArrY[i] == des.GetY())
				{
					if (game.Board[des.GetX()][des.GetY()] != NULL)
					{
						if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
						{
							return 1;
						}
						else return 0;
					}
					else return 1;
				}
			}
	}
	return 0;
}

bool QueenMoveAlgorithm::validMove(Game &game,Block src,Block des) 
{
	if ((des.GetX() > 0 && des.GetX() <= 8) && (des.GetY() > 0 && des.GetY() <= 8
		&& (des.GetX() != src.GetX() || des.GetY() != src.GetY()))){
			//Truong hop xfrom < xto
			if (src.GetX() < des.GetX()){
				//Truong hop yfrom < yto
				if (src.GetY() < des.GetY()){
					for (int i = 1; src.GetX() + i <= 8; i++)
					{
						if (src.GetX() + i == des.GetX()){
							if (src.GetY() + i == des.GetY())
							{
								if (game.Board[des.GetX()][des.GetY()] != NULL)
								{
									if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
									{
										return 1;
									}
									else return 0;
								}
								else return 1;
							}
						}
						else
						{

							if (game.Board[src.GetX() + i][src.GetY() + i] != NULL)
							{
								return 0;
							}	
						}
					}
				}
				//Truong hop yfrom > yto
				else if (src.GetY() > des.GetY()){
					for (int i = 1; src.GetX() + i <= 8; i++)
					{
						if (src.GetX() + i == des.GetX()){
							if (src.GetY() - i == des.GetY())
							{
								if (game.Board[des.GetX()][des.GetY()] != NULL)
								{
									if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
									{
										return 1;
									}
									else return 0;
								}
								else return 1;
							}
						}
						else
						{

							if (game.Board[src.GetX() + i][src.GetY() - i] != NULL)
							{
								return 0;
							}
						}
					}
				}
				//Truong hop yfrom = yto
				else{
					for (int i = 1; src.GetX() + i <= 8; i++)
					{
						if (src.GetX() + i == des.GetX()){
							if (src.GetY() == des.GetY())
							{
								if (game.Board[des.GetX()][des.GetY()] != NULL)
								{
									if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
									{
										return 1;
									}
									else return 0;
								}
								else return 1;
							}
						}
						else
						{
							if (game.Board[src.GetX() + i][src.GetY()] != NULL)
							{
								return 0;
							}

						}
					}
				}
			}
			//Truong hop xfrom > xto
			else if (src.GetX() > des.GetX()){
				//Truong hop yfrom < yto
				if (src.GetY() < des.GetY()){
					for (int i = 1; src.GetX() - i > 0 ; i++)
					{
						if (src.GetX() - i == des.GetX()){
							if (src.GetY() + i == des.GetY())
							{
								if (game.Board[des.GetX()][des.GetY()] != NULL)
								{
									if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
									{
										return 1;
									}
									else return 0;
								}
								else return 1;
							}
						}
						else
						{

							if (game.Board[src.GetX() - i][src.GetY() + i] != NULL)
							{
								return 0;
							}	
						}
					}
				}
				//Truong hop yfrom > yto
				else if (src.GetY() > des.GetY()){
					for (int i = 1; src.GetX() - i > 0; i++)
					{
						if (src.GetX() - i == des.GetX()){
							if (src.GetY() - i == des.GetY())
							{
								if (game.Board[des.GetX()][des.GetY()] != NULL)
								{
									if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
									{
										return 1;
									}
									else return 0;
								}
								else return 1;
							}
						}
						else
						{

							if (game.Board[src.GetX() - i][src.GetY() - i] != NULL)
							{
								return 0;
							}
						}
					}
				}
				//Truong hop yfrom = yto
				else{
					for (int i = 1; src.GetX() - i > 0; i++)
					{
						if (src.GetX() - i == des.GetX()){
							if (src.GetY() == des.GetY())
							{
								if (game.Board[des.GetX()][des.GetY()] != NULL)
								{
									if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
									{
										return 1;
									}
									else return 0;
								}
								else return 1;
							}
						}
						else
						{
							if (game.Board[src.GetX() - i][src.GetY()] != NULL)
							{
								return 0;
							}

						}
					}
				}
			}
			//Truong xfrom = xto
			else{
				//Truong hop yfrom > yto
				if (src.GetY() > des.GetY()){
					for (int i = 1; src.GetY() - i > 0; i++)
					{
						if (src.GetY() - i == des.GetY()){
							if (src.GetX() == des.GetX())
							{
								if (game.Board[des.GetX()][des.GetY()] != NULL)
								{
									if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
									{
										return 1;
									}
									else return 0;
								}
								else return 1;
							}
						}
						else
						{
							if (game.Board[src.GetX()][src.GetY()-i] != NULL)
							{
								return 0;
							}
						}
					}
				}
				//Truong hop yfrom < yto
				else{
					for (int i = 1; src.GetY() + i <= 8; i++)
					{
						if (src.GetY() + i == des.GetY()){
							if (src.GetX() == des.GetX())
							{
								if (game.Board[des.GetX()][des.GetY()] != NULL)
								{
									if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
									{
										return 1;
									}
									else return 0;
								}
								else return 1;
							}
						}
						else
						{
							if (game.Board[src.GetX()][src.GetY() + i] != NULL)
							{
								return 0;
							}
						}
					}	
				}
			}
	}
	return 0;
}

bool RookMoveAlgorithm::validMove(Game &game,Block src,Block des) 
{
	if ((des.GetX() > 0 && des.GetX() <= 8) && (des.GetY() > 0 && des.GetY() <= 8
		&& (des.GetX() != src.GetX() || des.GetY() != src.GetY()))){
			//Truong hop yfrom = yto
			if (src.GetY() == des.GetY()){
				//Truong hop xfrom < xto
				if (src.GetX() < des.GetX()){
					for (int i = 1; src.GetX() + i <= 8; i++)
					{
						if (game.Board[src.GetX()+i][src.GetY()] != NULL)
						{
							if (src.GetX() + i != des.GetX()){
								return 0;
							}
							else
							{
								if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
								{
									return 1;
								}
								else return 0;
							}
						}
						else
						{
							if (src.GetX() + i == des.GetX()){
								return 1;
							}
						}
					}
				}
				//Truong hop xfrom > xto
				else{
					for (int i = 1; src.GetX() - i > 0; i++)
					{
						if (game.Board[src.GetX()-i][src.GetY()] != NULL)
						{
							if (src.GetX() - i != des.GetX()){
								return 0;
							}
							else
							{
								if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
								{
									return 1;
								}
								else return 0;
							}
						}
						else
						{
							if (src.GetX() - i == des.GetX()){
								return 1;
							}
						}
					}
				}
			}
			//Truong hop xfrom = xto
			if (src.GetX() == des.GetX()){
				//Truong hop yfrom > yto
				if (src.GetY() > des.GetY()){
					for (int i = 1; src.GetY() - i > 0; i++)
					{
						if (src.GetY() - i == des.GetY()){
							if (game.Board[des.GetX()][des.GetY()] != NULL)
							{
								if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
								{
									return 1;
								}
								else return 0;
							}
							else return 1;
						}
						else
						{
							if (game.Board[src.GetX()][src.GetY()-i] != NULL)
							{
								return 0;
							}
						}
					}
				}
				//Truong hop yfrom < yto
				else{
					for (int i = 1; src.GetY() + i <= 8; i++)
					{
						if (src.GetY() + i == des.GetY()){
							if (game.Board[des.GetX()][des.GetY()] != NULL)
							{
								if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
								{
									return 1;
								}
								else return 0;
							}
							else return 1;
						}
						else
						{
							if (game.Board[src.GetX()][src.GetY()+i] != NULL)
							{
								return 0;
							}
						}
					}
				}
			}
	}
	return 0;
}
bool KnightMoveAlgorithm::validMove(Game &game,Block src,Block des) 
{
	if ((des.GetX() > 0 && des.GetX() <= 8) && (des.GetY() > 0 && des.GetY() <= 8
		&& (des.GetX() != src.GetX() || des.GetY() != src.GetY()))){
			int x = src.GetX();
			int y = src.GetY();
			int ArrX[8] = { x + 2, x + 2, x + 1, x - 1, x + 1, x - 1, x - 2, x - 2 };
			int ArrY[8] = { y - 1, y + 1, y + 2, y + 2, y - 2, y - 2, y - 1, y + 1 };
			for (int i = 0; i < 8; i++)
			{
				if (ArrX[i] == des.GetX() && ArrY[i] == des.GetY())
				{
					if (game.Board[des.GetX()][des.GetY()] != NULL)
					{
						if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
						{
							return 1;
						}
						else return 0;
					}
					else return 1;
				}
			}
	}
	return 0;
}

bool BishopMoveAlgorithm::validMove(Game &game,Block src,Block des) 
{
	if ((des.GetX() > 0 && des.GetX() <= 8) && (des.GetY() > 0 && des.GetY() <= 8
		&& (des.GetX() != src.GetX() || des.GetY() != src.GetY()))){
			//Truong hop xfrom < xto
			if (src.GetX() < des.GetX()){
				//Truong hop yfrom < yto
				if (src.GetY() < des.GetY()){
					for (int i = 1; src.GetX() + i <= 8; i++)
					{
						if (src.GetX() + i == des.GetX()){
							if (src.GetY() + i == des.GetY())
							{
								if (game.Board[des.GetX()][des.GetY()] != NULL)
								{
									if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
									{
										return 1;
									}
									else return 0;
								}
								else return 1;
							}
						}
						else
						{

							if (game.Board[src.GetX() + i][src.GetY() + i] != NULL)
							{
								return 0;
							}	
						}
					}
				}
				//Truong hop yfrom > yto
				else if (src.GetY() > des.GetY()){
					for (int i = 1; src.GetX() + i <= 8; i++)
					{
						if (src.GetX() + i == des.GetX()){
							if (src.GetY() - i == des.GetY())
							{
								if (game.Board[des.GetX()][des.GetY()] != NULL)
								{
									if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
									{
										return 1;
									}
									else return 0;
								}
								else return 1;
							}
						}
						else
						{

							if (game.Board[src.GetX() + i][src.GetY() - i] != NULL)
							{
								return 0;
							}
						}
					}
				}
			}
			//Truong hop xfrom > xto
			else if (src.GetX() > des.GetX()){
				//Truong hop yfrom < yto
				if (src.GetY() < des.GetY()){
					for (int i = 1; src.GetX() - i > 0 ; i++)
					{
						if (src.GetX() - i == des.GetX()){
							if (src.GetY() + i == des.GetY())
							{
								if (game.Board[des.GetX()][des.GetY()] != NULL)
								{
									if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
									{
										return 1;
									}
									else return 0;
								}
								else return 1;
							}
						}
						else
						{

							if (game.Board[src.GetX() - i][src.GetY() + i] != NULL)
							{
								return 0;
							}	
						}
					}
				}
				//Truong hop yfrom > yto
				else if (src.GetY() > des.GetY()){
					for (int i = 1; src.GetX() - i > 0; i++)
					{
						if (src.GetX() - i == des.GetX()){
							if (src.GetY() - i == des.GetY())
							{
								if (game.Board[des.GetX()][des.GetY()] != NULL)
								{
									if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
									{
										return 1;
									}
									else return 0;
								}
								else return 1;
							}
						}
						else
						{

							if (game.Board[src.GetX() - i][src.GetY() - i] != NULL)
							{
								return 0;
							}
						}
					}
				}
			}
	}
	return 0;
}

bool PawnMoveAlgorithm::validMove(Game &game,Block src,Block des) 
{
	if ((des.GetX() > 0 && des.GetX() <= 8) && (des.GetY() > 0 && des.GetY() <= 8
		&& (des.GetX() != src.GetX() || des.GetY() != src.GetY()))){
			if (game.Board[src.GetX()][src.GetY()]->GetColor() == PieceColor::White){

				if (des.GetY() == src.GetY())
				{
					if  (src.GetX() == 2 && des.GetX() == src.GetX() + 2)
					{
						if (game.Board[des.GetX()][des.GetY()] == NULL)
						{

							if (game.Board[des.GetX()-1][des.GetY()] != NULL)
							{
								return 0;
							}
							game.player2.CheckEnpass(src,des);
							return 1;
						}
						else return 0;
					}
					else if (des.GetX() == src.GetX()+1){
						if (game.Board[des.GetX()][des.GetY()] == NULL)
						{
							return 1;
						}
						else return 0;
					}
				}
				if (des.GetX() == src.GetX()+1)
				{
					if (des.GetY() == src.GetY() + 1 || des.GetY() == src.GetY() - 1)
					{
						if (game.Board[des.GetX()][des.GetY()] != NULL)
						{

							if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
							{
								return 1;
							}
							else return 0;
						}
						else
						{
							if (game.player1.isEnpass.GetX() == des.GetX() && game.player1.isEnpass.GetY() == des.GetY())
							{
								return 1;
							}
							return 0;
						}
					}
				}
			}
			else if (game.Board[src.GetX()][src.GetY()]->GetColor() == PieceColor::Black){

				if (des.GetY() == src.GetY())
				{
					if  (src.GetX() == 7 && des.GetX() == src.GetX() - 2)
					{
						if (game.Board[des.GetX()][des.GetY()] == NULL)
						{
							if (game.Board[des.GetX()+1][des.GetY()] != NULL)
							{
								return 0;
							}
							game.player1.CheckEnpass(src,des);
							return 1;
						}
						return 0;
					}
					else if (des.GetX() == src.GetX()-1){
						if (game.Board[des.GetX()][des.GetY()] == NULL)
						{
							return 1;
						}
						else return 0;
					}
				}
				if (des.GetX() == src.GetX()-1)
				{
					if (des.GetY() == src.GetY() + 1 || des.GetY() == src.GetY() - 1)
					{
						if (game.Board[des.GetX()][des.GetY()] != NULL)
						{
							if (game.Board[des.GetX()][des.GetY()]->GetColor() != game.Board[src.GetX()][src.GetY()]->GetColor())
							{
								return 1;
							}
							else return 0;
						}
						else
						{
							if (game.player2.isEnpass.GetX() == des.GetX() && game.player1.isEnpass.GetY() == des.GetY())
							{
								return 1;
							}
							return 0;
						}
					}
				}
			}	
	}
	return 0;
}

Player::Player(string name):name(name) 
{
	this->iSbeingChecked = 0;
	this->isCastlingK = 1;
	this->isCastlingQ = 1;
}

Player1::Player1(string name):Player(name) 
{}

bool Player2::CheckCastlingQ(Game &game,Player1 player1) 
{
	if (!player1.iSbeingChecked)
	{
		Block des1(1,3);
		Block des2(1,4);
		for(int i = 0;i < pieceCollection.size();i++)
		{
			if(pieceCollection[i].GetBlock().GetX() != 0 && pieceCollection[i].GetBlock().GetY() != 0)
			{
				if (pieceCollection[i].ValidMove(game,des1))
				{
					return 0;
				}
				else if (pieceCollection[i].ValidMove(game,des2))
				{
					return 0;
				}
			}
		}
		return 1;
	}
	return 0;
}

bool Player2::CheckCastlingK(Game &game,Player1 player1) 
{
	if (!player1.iSbeingChecked)
	{
		Block des1(1,6);
		Block des2(1,7);
		for(int i = 0;i < pieceCollection.size();i++)
		{
			if(pieceCollection[i].GetBlock().GetX() != 0 && pieceCollection[i].GetBlock().GetY() != 0)
			{
				if (pieceCollection[i].ValidMove(game,des1))
				{
					return 0;
				}
				else if (pieceCollection[i].ValidMove(game,des2))
				{
					return 0;
				}
			}
		}
		return 1;
	}
	return 0;
}

bool Player1::CheckEnpass(Block src,Block des)
{
	if  (src.GetX() == 7 && des.GetX() == src.GetX() - 2)
	{
		for(int i = 8;i < pieceCollection.size();i++)
		{
			if (pieceCollection[i].GetBlock().GetX() == des.GetX())
			{
				if (pieceCollection[i].GetBlock().GetY() == des.GetY() + 1 || pieceCollection[i].GetBlock().GetY() == des.GetY() - 1)
				{
					isEnpass.SetX(des.GetX()+1);
					isEnpass.SetY(des.GetY());
					return 1;
				}
			}
		}
	}
	return 0;		
}

bool Player1::IsCheckingPlayer(Game &game,Player2& player2) 
{
	int x = player2.pieceCollection[0].GetBlock().GetX();
	int y = player2.pieceCollection[0].GetBlock().GetY();
	Block des(x,y);
	for(int i = 0;i < pieceCollection.size();i++)
	{
		if(pieceCollection[i].GetBlock().GetX() != 0 && pieceCollection[i].GetBlock().GetY() != 0)
		{
			if (pieceCollection[i].ValidMove(game,des))
			{
				player2.iSbeingChecked = 1;
				return 1;
			}
		}
	}
	player2.iSbeingChecked = 0;
	return 0;
}

bool Player1::IsMatingPlayer(Game &game,Player2& player2)
{
	if (IsCheckingPlayer(game,player2))
	{
		int x = player2.pieceCollection[0].GetBlock().GetX();
		int y = player2.pieceCollection[0].GetBlock().GetY();
		int ArrX[8] = { x + 1, x + 1, x + 1, x, x, x - 1, x - 1, x - 1 };
		int ArrY[8] = { y - 1, y, y + 1, y - 1, y + 1, y - 1, y, y + 1 };
		for(int i = 0;i < 8;i++)
		{
			Block des(ArrX[i],ArrY[i]);
			int flag = 0;
			for(int j = 0;j < pieceCollection.size();j++)
			{
				if(pieceCollection[j].GetBlock().GetX() != 0 && pieceCollection[j].GetBlock().GetY() != 0)
				{
					Block des1(pieceCollection[j].GetBlock().GetX(),pieceCollection[j].GetBlock().GetY());
					if (pieceCollection[j].ValidMove(game,des))
					{
						int flag1 = 0;
						for(int k = 0;k < player2.pieceCollection.size();k++)
						{
							if(player2.pieceCollection[k].GetBlock().GetX() != 0 && player2.pieceCollection[k].GetBlock().GetY() != 0){
								if (player2.pieceCollection[k].ValidMove(game,des1))
								{
									flag1 = 1;
									break;
								}
							}
						}
						if (flag1 == 0)
						{
							flag = 1;
							break;
						}
					}
				}
			}
			if (flag == 0 && player2.pieceCollection[0].ValidMove(game,des))
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

void Player1::Promotion(Piece pawn) 
{
	for(int i = 0;i < pieceCollection.size();i++)
	{
		if (pieceCollection[i].GetBlock().GetX() == pawn.GetBlock().GetX() && pieceCollection[i].GetBlock().GetY() == pawn.GetBlock().GetY())
		{
			int n;
			do{
				cout << "1.Queen" << endl;
				cout << "2.Rook" << endl;
				cout << "3.Bishop" << endl;
				cout << "4.Knight" << endl;
				cout << "Nhap so voi quan tuong ung ban muon thang cap (VD : 1): " ;
				cin >> n;
			}while(n < 1 && n > 4);
			switch (n)
			{
			case 1:
				{
					pieceCollection[i].SetPieceType(PieceType::Queen);
					pieceCollection[i].SetMoveAlgorithm(new QueenMoveAlgorithm);
					break;
				}
			case 2:
				{
					pieceCollection[i].SetPieceType(PieceType::Rook);
					pieceCollection[i].SetMoveAlgorithm(new RookMoveAlgorithm);
					break;
				}
			case 3:
				{
					pieceCollection[i].SetPieceType(PieceType::Bishop);
					pieceCollection[i].SetMoveAlgorithm(new BishopMoveAlgorithm);
					break;
				}
			case 4:
				{
					pieceCollection[i].SetPieceType(PieceType::Knight);
					pieceCollection[i].SetMoveAlgorithm(new KnightMoveAlgorithm);
					break;
				}
			}
		}
	}
}

Player2::Player2(string name):Player(name) 
{
}

bool Player1::CheckCastlingQ(Game &game,Player2 player2) 
{
	if (!player2.iSbeingChecked)
	{
		Block des1(8,3);
		Block des2(8,4);
		for(int i = 0;i < pieceCollection.size();i++)
		{
			if(pieceCollection[i].GetBlock().GetX() != 0 && pieceCollection[i].GetBlock().GetY() != 0)
			{
				if (pieceCollection[i].ValidMove(game,des1))
				{
					return 0;
				}
				else if (pieceCollection[i].ValidMove(game,des2))
				{
					return 0;
				}
			}
		}
		return 1;
	}
	return 0;
}

bool Player1::CheckCastlingK(Game &game,Player2 player2) 
{
	if (!player2.iSbeingChecked)
	{
		Block des1(8,6);
		Block des2(8,7);
		for(int i = 0;i < pieceCollection.size();i++)
		{
			if(pieceCollection[i].GetBlock().GetX() != 0 && pieceCollection[i].GetBlock().GetY() != 0)
			{
				if (pieceCollection[i].ValidMove(game,des1))
				{
					return 0;
				}
				else if (pieceCollection[i].ValidMove(game,des2))
				{
					return 0;
				}
			}
		}
		return 1;
	}
	return 0;
}

bool Player2::CheckEnpass(Block src,Block des) 
{
	if  (src.GetX() == 2 && des.GetX() == src.GetX() + 2)
	{
		for(int i = 8;i < pieceCollection.size();i++)
		{
			if (pieceCollection[i].GetBlock().GetX() == des.GetX())
			{
				if (pieceCollection[i].GetBlock().GetY() == des.GetY() + 1 || pieceCollection[i].GetBlock().GetY() == des.GetY() - 1)
				{
					isEnpass.SetX(des.GetX()+1);
					isEnpass.SetY(des.GetY());
					return 1;
				}
			}
		}
	}
	return 0;		
}

bool Player2::IsCheckingPlayer(Game &game,Player1& player1) 
{
	int x = player1.pieceCollection[0].GetBlock().GetX();
	int y = player1.pieceCollection[0].GetBlock().GetY();
	Block des(x,y);
	for(int i = 0;i < pieceCollection.size();i++)
	{
		if(pieceCollection[i].GetBlock().GetX() != 0 && pieceCollection[i].GetBlock().GetY() != 0)
		{
			if (pieceCollection[i].ValidMove(game,des))
			{
				player1.iSbeingChecked = 1;
				return 1;
			}
		}
	}
	player1.iSbeingChecked = 0;
	return 0;
}

bool Player2::IsMatingPlayer(Game &game,Player1& player1)
{
	if (IsCheckingPlayer(game,player1))
	{
		int x = player1.pieceCollection[0].GetBlock().GetX();
		int y = player1.pieceCollection[0].GetBlock().GetY();
		int ArrX[8] = { x + 1, x + 1, x + 1, x, x, x - 1, x - 1, x - 1 };
		int ArrY[8] = { y - 1, y, y + 1, y - 1, y + 1, y - 1, y, y + 1 };
		for(int i = 0;i < 8;i++)
		{
			Block des(ArrX[i],ArrY[i]);
			int flag = 0;
			for(int j = 0;j < pieceCollection.size();j++)
			{
				if(pieceCollection[j].GetBlock().GetX() != 0 && pieceCollection[j].GetBlock().GetY() != 0)
				{
					Block des1(pieceCollection[j].GetBlock().GetX(),pieceCollection[j].GetBlock().GetY());
					if (pieceCollection[j].ValidMove(game,des))
					{
						int flag1 = 0;
						for(int k = 0;k < player1.pieceCollection.size();k++)
						{
							if(player1.pieceCollection[k].GetBlock().GetX() != 0 && player1.pieceCollection[k].GetBlock().GetY() != 0){
								if (player1.pieceCollection[k].ValidMove(game,des1))
								{
									flag1 = 1;
									break;
								}
							}
						}
						if (flag1 == 0)
						{
							flag = 1;
							break;
						}
					}
				}
			}
			if (flag == 0 && player1.pieceCollection[0].ValidMove(game,des))
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

void Player2::Promotion(Piece pawn) 
{
	for(int i = 0;i < pieceCollection.size();i++)
	{
		if (pieceCollection[i].GetBlock().GetX() == pawn.GetBlock().GetX() && pieceCollection[i].GetBlock().GetY() == pawn.GetBlock().GetY())
		{
			int n;
			do{
				cout << "1.Queen" << endl;
				cout << "2.Rook" << endl;
				cout << "3.Bishop" << endl;
				cout << "4.Knight" << endl;
				cout << "Nhap so tuong ung voi quan ban muon thang cap (VD : 1): " ;
				cin >> n;
			}while(n < 1 && n > 4);
			switch (n)
			{
			case 1:
				{
					pieceCollection[i].SetPieceType(PieceType::Queen);
					pieceCollection[i].SetMoveAlgorithm(new QueenMoveAlgorithm);
					break;
				}
			case 2:
				{
					pieceCollection[i].SetPieceType(PieceType::Rook);
					pieceCollection[i].SetMoveAlgorithm(new RookMoveAlgorithm);
					break;
				}
			case 3:
				{
					pieceCollection[i].SetPieceType(PieceType::Bishop);
					pieceCollection[i].SetMoveAlgorithm(new BishopMoveAlgorithm);
					break;
				}
			case 4:
				{
					pieceCollection[i].SetPieceType(PieceType::Knight);
					pieceCollection[i].SetMoveAlgorithm(new KnightMoveAlgorithm);
					break;
				}
			}
		}
	}
}

Piece::Piece(PieceColor c,int x,int y,PieceType pt) 
{
	this->color = c;
	Block temp(x,y);
	pos = temp;
	this->type = pt;
	if (this->type == PieceType::King)
	{
		moveAlgorithm = new KingMoveAlgorithm;
	}
	else if (this->type == PieceType::Queen)
	{
		moveAlgorithm = new QueenMoveAlgorithm;
	}
	else if (this->type == PieceType::Rook)
	{
		moveAlgorithm = new RookMoveAlgorithm;
	}
	else if (this->type == PieceType::Knight)
	{
		moveAlgorithm = new KnightMoveAlgorithm;
	}
	else if (this->type == PieceType::Bishop)
	{
		moveAlgorithm = new BishopMoveAlgorithm;
	}
	else if (this->type == PieceType::Pawn)
	{
		moveAlgorithm = new PawnMoveAlgorithm;
	}
}

PieceColor Piece::GetColor() 
{
	return color;
}

Block Piece::GetBlock() 
{
	return pos;
}

PieceType Piece::GetType() 
{
	return type;
}

void Piece::MoveTo(Game &game,Block des) 
{

	game.Board[des.GetX()][des.GetY()] = game.Board[pos.GetX()][pos.GetY()];
	game.Board[pos.GetX()][pos.GetY()] = NULL;
	pos.SetX(des.GetX());
	pos.SetY(des.GetY());
}

void Piece::Remove(Game &game) 
{
	game.Board[pos.GetX()][pos.GetY()] = NULL;
	pos.SetX(0);
	pos.SetY(0);
}

void Piece::SetMoveAlgorithm(MoveAlgorithm *moveAlgorithm)
{
	this->moveAlgorithm = moveAlgorithm;
}

void Piece::SetPieceType(PieceType pt) 
{
	this->type = pt;
}

bool Piece::ValidMove(Game &game,Block des) 
{
	return moveAlgorithm->validMove(game,this->GetBlock(),des);
}

void Score::CreateScore(string p1,string p2,int x)
{
	fstream fIn;
	fIn.open("Score.txt",ios::in);
	string sname;
	float iscore;
	string temp;
	getline(fIn,temp);
	while(fIn >> sname)
	{

		fIn >> iscore;
		name.push_back(sname);
		nscore.push_back(iscore);
	}
	if (x == ScoreType::LOSE)
	{
		int flag1 = 0;
		int flag2 = 0;
		for(int i = 0;i < name.size();i++)
		{
			if (name[i] == p1)
			{
				flag1 = 1;
			}
			else if (name[i] == p2)
			{
				nscore[i]++;
				flag2 = 1;
			}
		}
		if (flag1 == 0)
		{
			name.push_back(p1);
			nscore.push_back(0);
		}
		if (flag2 == 0)
		{
			name.push_back(p2);
			nscore.push_back(1);
		}
	}
	else if (x == ScoreType::DRAW)
	{
		int flag1 = 0;
		int flag2 = 0;
		for(int i = 0;i < name.size();i++)
		{
			if (name[i] == p1)
			{
				nscore[i]+=0.5;
				flag1 = 1;
			}
			else if (name[i] == p2)
			{
				nscore[i]+=0.5;
				flag2 = 1;
			}
		}
		if (flag1 == 0)
		{
			name.push_back(p1);
			nscore.push_back(0.5);
		}
		if (flag2 == 0)
		{
			name.push_back(p2);
			nscore.push_back(0.5);
		}
	}
	else if (x == ScoreType::WIN)
	{
		int flag1 = 0;
		int flag2 = 0;
		for(int i = 0;i < name.size();i++)
		{
			if (name[i] == p1)
			{
				nscore[i]++;
				flag1 = 1;
			}
			else if (name[i] == p2)
			{
				flag2 = 1;
			}
		}
		if (flag1 == 0)
		{
			name.push_back(p1);
			nscore.push_back(1);
		}
		if (flag2 == 0)
		{
			name.push_back(p2);
			nscore.push_back(0);
		}
	}
	for(int i = 0 ;i < name.size();i++)
	{
		int max = i;
		for(int j = i+1;j < name.size();j++)
		{
			if (nscore[j] > nscore[i])
			{
				max = j;
			}
		}
		if (max != i)
		{
			std::swap(nscore[max],nscore[i]);
			std::swap(name[max],name[i]);
		}
	}
	fstream fOut;
	fOut.open("Score.txt",ios::out |ios::trunc);
	fOut << "Name\tScore" << endl;
	cout << "Name\tScore" << endl;
	for(int i = 0;i < name.size();i++)
	{
		fOut << name[i] << "\t" << nscore[i] << endl;
		cout << name[i] << "\t" << nscore[i] << endl;
	}
	fIn.close();
	fOut.close();
}