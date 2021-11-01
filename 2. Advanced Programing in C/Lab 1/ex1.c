
/* Assignment: 1
Author: Hadar Rivlin
#include <stdio.h>

void encryption();
void reversi();
void print();
void computer_vs();
void two_players();
void randchoice();
char turn();




void main(){
	int num;
	while(1){		//the program runs until option 3 is selected
		printf("Please choose an option by typing a number between 1-3 \n");
		printf("1.encryption \n2.reversi \n3.exit \n");
		scanf("%d", &num); while(getchar()!='\n'); 		//getting num and cleans buffer from enter
		switch(num){ 		//checks cases and launches functions 
		case 1:
			encryption();
			break;
		case 2:
			reversi();
			break;
		case 3:
			return;
		default:
			printf("error, number not in range\n");

		}
	}
}

void encryption(){
	char pass[8];		//contains password
	int flag1=0;		//needs 2 big letters
	int flag2=0;		//needs 2 numbers
	int valid=0;		//0 while waiting for password
	int len;
	printf("Enter an encrypted password that is 8 characters long\n");
	while(valid==0){		//STAYS 0 WHEN PAASWORD IS INCORRECT OR WASN'T TYPED YET
		scanf("%s", pass); while(getchar()!='\n');
		for(int i=0; i<8; i++){		//iterates over pass and updates flags so wer'e sure pass has at least 2 big letters and numbers
			if(pass[i]>='A' && pass[i]<='Z')		
				flag1+=1;
			if(pass[i]>='0' && pass[i]<='9')
				flag2+=1;
		}
		for(len = 0; pass[len] != '\0'; ++len);
		if(len!=8)
			printf("password is too short!\n");
		else if(flag1>=2 && flag2>=2) valid=1;		//pass is correct and valid=1 to stop scanning for more data
		else printf("password has to contain at least 2 numbers and 2 BIG letter!\n");
	}

	for(int i=0; i<8; i++){
		if(pass[i]>='A' && pass[i]<='Z'){			//this encryption was defined in the course 
			flag1+=1;
			if(pass[i]>'C')
				pass[i] = pass[i]-3;
			else if(pass[i]=='A') pass[i] = 'X';
			else if(pass[i]=='B') pass[i] = 'Y';
			else if(pass[i]=='C') pass[i] = 'Z';
		}
		if(pass[i]>='0' && pass[i]<='9'){
			flag2+=1;
			while(pass[i]>'3'){
				pass[i] = pass[i]-3;
				continue;
			}
			switch(pass[i]){
			case '0': pass[i] = '7';
			break;
			case '1': pass[i] = '8';
			break;
			case '2': pass[i] = '9';
			break;
			}
		}

	}



	char askii[36]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
	char n_askii[36]={'S','5','P','W','A','R','8','Q','I','V','B','0','D','Z','3','C','2','H','4','1','K','7','G','Y','6','O','J','E','U','N','F','9','M','L','T','X'};
	for(int i=0; i<8; i++){
		for(int j=0; j<36; j++){
			if(*(pass+i) == *(n_askii+j)){
				*(pass+i) = *(askii+j);
				break;
			}
		}
	}

	char tmp;
	for(int i=0; i<8; i++)
		if(i%2==0){
			tmp=*(pass+i);
			*(pass+i)=*(pass+i+1);
			*(pass+i+1)=tmp;
		}
	char new_s[8];
	char *p = pass;
	for(int i=0; i<8; i++){
		new_s[i] = *(p+7-i);
		*(new_s+8) = '\0';
		//*(new_s+8) = *(p+8);
	}
	char n_string[8];
	char *q = new_s;
	for(int i=2; i<8; i++)
		n_string[i] = *(q+i-2);
	n_string[0] = *(q+6);
	n_string[1] = *(q+7);
	*(n_string+8) = '\0';
	//*(n_string+8) = *(q+8);

	printf("%s\n", n_string);
}


void reversi(){
	int num;
	int Xwins=0;
	int Owins=0;
	int game_num=0;
	int curr_player=0;
	printf("please choose option by typing a number:\n");
	printf("1. computer VS \n2. two players\n");
	scanf("%d", &num); //while(getchar()!='\n');
	switch(num){
	case 1:

		computer_vs(&Xwins, &Owins, &game_num, &curr_player);
		break;
	case 2:
		two_players(&Xwins, &Owins, &game_num, &curr_player);
		break;
	default:
		printf("error, number not in range\n");
	}
}



void computer_vs(int* Xwins, int* Owins, int* game_num, int* curr_player){
	int count = 0;
	int full = 0;
	char board[8][8];
	int a=0, b=0, x=0, y=0;

	if(*game_num!=0){
		if(*curr_player == 1)
			count = 1;
		else if(*curr_player == 2)
			count = 2;
	}
	else
		randchoice(&count);

	printf("player X is computer \nyou are player O\n");


	for(int i=0; i<8; i++){ //starts the board as empty
		for(int j=0; j<8; j++){
			board[i][j]= '-';
		}
	}
	board[3][3]='O'; board[4][4]='O'; board[4][3]='X'; board[3][4]='X'; //assigns starting position
	print(board);



	while(full<64){

		while(turn(&count)== 'X' && full<64){
			printf("it's player X turn\n");
			full=0;
			char maxy[8][8]={0}; //stores values of flips by coordinate
			int p=0;
			int rowy=0;
			int coly=0;
			int flag = 0;

			for(rowy=0; rowy<8&&rowy>=0; rowy++){
				for(coly=0;coly<8 && coly>=0 ; coly++){
					if(board[rowy][coly]=='-'){
						//iters thru every i,j in board to find how many flips it causes
						p=0;
						flag=0;
						if(rowy>0 && coly>0 && rowy<7 && coly<7 && board[rowy][coly]=='-'){
							for(int i=(rowy-1); i<(rowy+2); i++){ //checks if its near a taken spot
								for(int j=(coly-1); j<(coly+2); j++){
									if(board[i][j]=='O' || board[i][j]=='X'){
										flag+=1; //number of neighbors in 8 coordinates

									}
								}
							}
						}
						else{
							switch(rowy){
							case 0:
								for(int i=(rowy); i<(rowy+2); i++){ //checks if its near a taken spot
									switch(coly){
									case 0:
										for(int j=(coly); j<(coly+2); j++){
											if(board[i][j]=='O' || board[i][j]=='X'){
												flag+=1; //number of neighbors in 8 coordinates

											}
										}
										break;
									case 7:
										for(int j=(coly-1); j<(coly+1); j++){
											if(board[i][j]=='O' || board[i][j]=='X'){
												flag+=1; //number of neighbors in 8 coordinates

											}
										}
										break;
									default:
										for(int j=(coly-1); j<(coly+2); j++){
											if(board[i][j]=='O' || board[i][j]=='X'){
												flag+=1; //number of neighbors in 8 coordinates

											}
										}
										break;
									}

								}
								break;
							case 7:
								for(int i=(rowy-1); i<(rowy+1); i++){ //checks if its near a taken spot
									switch(coly){
									case 0:
										for(int j=(coly); j<(coly+2); j++){
											if(board[i][j]=='O' || board[i][j]=='X'){
												flag+=1; //number of neighbors in 8 coordinates

											}
										}
										break;
									case 7:
										for(int j=(coly-1); j<(coly+1); j++){
											if(board[i][j]=='O' || board[i][j]=='X'){
												flag+=1; //number of neighbors in 8 coordinates

											}
										}
										break;
									default:
										for(int j=(coly-1); j<(coly+2); j++){
											if(board[i][j]=='O' || board[i][j]=='X'){
												flag+=1; //number of neighbors in 8 coordinates

											}
										}
										break;
									}

								}
								break;
							default:
								for(int i=(rowy-1); i<(rowy+2); i++){ //checks if its near a taken spot
									switch(coly){
									case 0:
										for(int j=(coly); j<(coly+2); j++){
											if(board[i][j]=='O' || board[i][j]=='X'){
												flag+=1; //number of neighbors in 8 coordinates

											}
										}
										break;
									case 7:
										for(int j=(coly-1); j<(coly+1); j++){
											if(board[i][j]=='O' || board[i][j]=='X'){
												flag+=1; //number of neighbors in 8 coordinates

											}
										}
										break;
									default:
										for(int j=(coly-1); j<(coly+2); j++){
											if(board[i][j]=='O' || board[i][j]=='X'){
												flag+=1; //number of neighbors in 8 coordinates

											}
										}
										break;
									}

								}
								break;
							}

						}
						if(flag>0){
							for(int i = 1; board[rowy+i][coly]=='O'; i++){ //checks down
								if(board[rowy+1+i][coly] == turn(&count)){
									for(int j=1; board[rowy+j][coly]=='O'; j++){
										p+=1;  //number of flips it causes

									}
								}
							}

							for(int i = 1; board[rowy][coly+i]=='O'; i++){ //checks right
								if(board[rowy][coly+1+i] == turn(&count)){
									for(int j=1; board[rowy][coly+j]=='O'; j++){
										p+=1;

									}
								}
							}

							for(int i = 1; board[rowy-i][coly]=='O'; i--){ //checks up
								if(board[rowy-1-i][coly] == turn(&count)){
									for(int j=1; board[rowy-j][coly]=='O'; j--){
										p+=1;

									}
								}
							}

							for(int i = 1; board[rowy][coly-i]=='O'; i--){ //checks left
								if(board[rowy][coly-1-i] == turn(&count)){
									for(int j=1; board[rowy][coly-j]=='O'; j--){
										p+=1;

									}
								}
							}

							for(int i=1, j=1; board[rowy-i][coly-j]=='O'; i--, j--){ //checks up left
								if(board[rowy-1-i][coly-1-j]==turn(&count)){
									for(int m=1, n=1; board[rowy-m][coly-n]=='O'; m--, n--){
										if(board[rowy-m][coly-n]!='-')
											p+=1;
									}
								}
							}


							for(int i=1, j=1; board[rowy-i][coly+j]=='O'; i--, j++){ //checks right up
								if(board[rowy-1-i][coly+1+j]==turn(&count)){
									for(int m=1, n=1; board[rowy-m][coly+n]=='O'; m--, n++){
										if(board[rowy-m][coly+n]!='-')
											p+=1;
									}
								}
							}


							for(int i=1, j=1; board[rowy+i][coly-j]=='O'; i++, j--){ //checks left down
								if(board[rowy+i+1][coly-1-j]==turn(&count)){
									for(int m=1, n=1; board[rowy+m][coly-n]=='O'; m++, n--){
										if(board[rowy+m][coly-n]!='-')
											p+=1;
									}
								}
							}



							for(int i=1, j=1; board[rowy+i][coly+j]=='O'; i++, j++){ //checks down right
								if(board[rowy+1+i][coly+1+j]==turn(&count)){
									for(int m=1, k=1; board[rowy+m][coly+k]=='O'; m++, k++){
										if(board[rowy+m][coly+k]!='-')
											p+=1;
									}
								}
							}
						}
						if(board[rowy][coly]!='-') flag=0;
						if(flag>0){ //checks if its a valid spot
							maxy[rowy][coly] = p; //puts value of flips in maxy for coordinates i,j
							if(maxy[a][b]<= maxy[rowy][coly]){ //compares between last value in maxy to current
								a=rowy;
								b=coly;
							}
						}

					}
				}
			}
			int row =a; //coordinate of max flips
			int col =b;
			if(board[row][col]!='-'){
				for(rowy=0; rowy<8&&rowy>=0; rowy++){
					for(coly=0;coly<8 && coly>=0 ; coly++){
						//iters thru every i,j in board to find how many flips it causes
						if(board[rowy][coly]=='-'){
							flag=0;
							if(rowy>0 && coly>0 && rowy<7 && coly<7 && board[rowy][coly]=='-'){
								for(int i=(rowy-1); i<(rowy+2); i++){ //checks if its near a taken spot
									for(int j=(coly-1); j<(coly+2); j++){
										if(board[i][j]=='O' || board[i][j]=='X'){
											flag+=1; //number of neighbors in 8 coordinates

										}
									}
								}
							}
							else{
								switch(rowy){
								case 0:
									for(int i=(rowy); i<(rowy+2); i++){ //checks if its near a taken spot
										switch(coly){
										case 0:
											for(int j=(coly); j<(coly+2); j++){
												if(board[i][j]=='O' || board[i][j]=='X'){
													flag+=1; //number of neighbors in 8 coordinates

												}
											}
											break;
										case 7:
											for(int j=(coly-1); j<(coly+1); j++){
												if(board[i][j]=='O' || board[i][j]=='X'){
													flag+=1; //number of neighbors in 8 coordinates

												}
											}
											break;
										default:
											for(int j=(coly-1); j<(coly+2); j++){
												if(board[i][j]=='O' || board[i][j]=='X'){
													flag+=1; //number of neighbors in 8 coordinates

												}
											}
											break;
										}

									}
									break;
								case 7:
									for(int i=(rowy-1); i<(rowy+1); i++){ //checks if its near a taken spot
										switch(coly){
										case 0:
											for(int j=(coly); j<(coly+2); j++){
												if(board[i][j]=='O' || board[i][j]=='X'){
													flag+=1; //number of neighbors in 8 coordinates

												}
											}
											break;
										case 7:
											for(int j=(coly-1); j<(coly+1); j++){
												if(board[i][j]=='O' || board[i][j]=='X'){
													flag+=1; //number of neighbors in 8 coordinates

												}
											}
											break;
										default:
											for(int j=(coly-1); j<(coly+2); j++){
												if(board[i][j]=='O' || board[i][j]=='X'){
													flag+=1; //number of neighbors in 8 coordinates

												}
											}
											break;
										}

									}
									break;
								default:
									for(int i=(rowy-1); i<(rowy+2); i++){ //checks if its near a taken spot
										switch(coly){
										case 0:
											for(int j=(coly); j<(coly+2); j++){
												if(board[i][j]=='O' || board[i][j]=='X'){
													flag+=1; //number of neighbors in 8 coordinates

												}
											}
											break;
										case 7:
											for(int j=(coly-1); j<(coly+1); j++){
												if(board[i][j]=='O' || board[i][j]=='X'){
													flag+=1; //number of neighbors in 8 coordinates

												}
											}
											break;
										default:
											for(int j=(coly-1); j<(coly+2); j++){
												if(board[i][j]=='O' || board[i][j]=='X'){
													flag+=1; //number of neighbors in 8 coordinates

												}
											}
											break;
										}

									}
									break;
								}

							}
							if(board[rowy][coly]!='-') flag=0;
							if(flag>0){
								row = rowy, col = coly;
							}
						}
					}
				}
			}

			printf("player X chose coordinates (%d,%d)\n", row, col);
			//if rules apply coordinate can be placed
			board[row][col] = turn(&count); //places coordinate in board according to turn of player

			//after placing i,j it checks what to flip and flips it
			for(int i = row; board[i][col]!='-' && i<8; i++){ //checks down
				if(board[i][col] == turn(&count)){ //if spot is empty then for ends.
					for(int j=row; j<i; j++){  //while curr spot is same char, it changes the prev
						board[j][col]= turn(&count);

					}
				}
			}

			for(int i = col; board[row][i]!='-' && i<8; i++){ //checks right
				if(board[row][i] == turn(&count)){
					for(int j=col; j<i; j++){
						board[row][j]= turn(&count);

					}
				}
			}

			for(int i = row; board[i][col]!='-' && i>=0; i--){ //checks up
				if(board[i][col] == turn(&count)){
					for(int j=row; j>i; j--){
						board[j][col]= turn(&count);

					}
				}
			}

			for(int i = col; board[row][i]!='-' && i>=0; i--){ //checks left
				if(board[row][i] == turn(&count)){
					for(int j=col; j>i; j--){
						board[row][j]= turn(&count);

					}
				}
			}

			for(int i=row, j=col; i>=0 && j>=0; i--, j--){ //checks up left
				if(board[i][j]!='-' && board[i][j]==turn(&count)){
					for(int m=row, n=col; m>i && n>j; m--, n--){
						if(board[m][n]!='-')
							board[m][n]= turn(&count);
					}
				}
			}


			for(int i=row, j=col; i>=0 && j<8; i--, j++){ //checks right up
				if(board[i][j]!='-' && board[i][j]==turn(&count)){
					for(int m=row, n=col; m>i && n<j; m--, n++){
						if(board[m][n]!='-')
							board[m][n]= turn(&count);
					}
				}
			}


			for(int i=row, j=col; i<8 && j>=0; i++, j--){ //checks left down
				if(board[i][j]!='-' && board[i][j]==turn(&count)){
					for(int m=(row), n=col; m<i && n>j; m++, n--){
						if(board[m][n]!='-')
							board[m][n]= turn(&count);
					}
				}
			}



			for(int i=row, j=col; (i)<8 && (j)<8; i++, j++){ //checks down right
				if(board[i][j]!='-' && board[i][j]==turn(&count)){
					for(int m=row, k=col; m<i && k<j; m++, k++){
						if(board[m][k]!='-')
							board[m][k]= turn(&count);
					}
				}
			}

			print(board);
			printf("\n");
			count +=1; //will update func 'turn'

			for(int i=0; i<8; i++){ //checks if board is full
				for(int j=0; j<8; j++){
					if(board[i][j]!='-')
						full++; //if is 64 wont enter the next turn and will finish the game
				}
			}

		}



		while(turn(&count)== 'O' && full<64){ //while board isnt full and its player O turn
			full = 0;
			int row=0;
			int col=0;
			printf("it's player's O turn\n");
			printf("please choose your ROW coordinates\n");
			scanf("%d", &row);
			printf("please choose your COLUMN coordinates\n");
			scanf("%d", &col);
			if(row<0 || row>=8 || col<0 || col>=8)
				printf("error, given coordinates out of range\n");
			else if(board[row][col]== '-'){ //checks if spot is empty
				int flag = 0;
				for(int i=(row-1); i<(row+2); i++){ //checks if its near a taken spot
					for(int j=(col-1); j<(col+2); j++){
						if(board[i][j]=='O' || board[i][j]=='X'){
							flag+=1;
						}
					}
				}
				if(flag>0){ //if rules apply coordinate can be placed
					board[row][col] = turn(&count); //places coordinate in board according to turn of player


					for(int i = row; board[i][col]!='-' && i<8; i++){ //checks down
						if(board[i][col] == turn(&count)){
							for(int j=row; j<i; j++){
								board[j][col]= turn(&count);

							}
						}
					}

					for(int i = col; board[row][i]!='-' && i<8; i++){ //checks right
						if(board[row][i] == turn(&count)){
							for(int j=col; j<i; j++){
								board[row][j]= turn(&count);

							}
						}
					}

					for(int i = row; board[i][col]!='-' && i>=0; i--){ //checks up
						if(board[i][col] == turn(&count)){
							for(int j=row; j>i; j--){
								board[j][col]= turn(&count);

							}
						}
					}

					for(int i = col; board[row][i]!='-' && i>=0; i--){ //checks left
						if(board[row][i] == turn(&count)){
							for(int j=col; j>i; j--){
								board[row][j]= turn(&count);

							}
						}
					}

					for(int i=row, j=col; i>=0 && j>=0; i--, j--){ //checks up left
						if(board[i][j]!='-' && board[i][j]==turn(&count)){
							for(int m=row, n=col; m>i && n>j; m--, n--){
								if(board[m][n]!='-')
									board[m][n]= turn(&count);
							}
						}
					}


					for(int i=row, j=col; i>=0 && j<8; i--, j++){ //checks right up
						if(board[i][j]!='-' && board[i][j]==turn(&count)){
							for(int m=row, n=col; m>i && n<j; m--, n++){
								if(board[m][n]!='-')
									board[m][n]= turn(&count);
							}
						}
					}


					for(int i=row, j=col; i<8 && j>=0; i++, j--){ //checks left down
						if(board[i][j]!='-' && board[i][j]==turn(&count)){
							for(int m=(row), n=col; m<i && n>j; m++, n--){
								if(board[m][n]!='-')
									board[m][n]= turn(&count);
							}
						}
					}



					for(int i=row, j=col; (i)<8 && (j)<8; i++, j++){ //checks down right
						if(board[i][j]!='-' && board[i][j]==turn(&count)){
							for(int m=row, k=col; m<i && k<j; m++, k++){
								if(board[m][k]!='-')
									board[m][k]= turn(&count);
							}
						}
					}

					print(board);
					printf("\n");
					count +=1;

					for(int i=0; i<8; i++){ //checks if board is full
						for(int j=0; j<8; j++){
							if(board[i][j]!='-')
								full++;
						}
					}
				}
				else printf("error, has to be placed next to X or O\n");
			}
			else
				printf("this coordinate spot is taken!\n");
		}
	}
	int xnum=0, onum=0;
	char answer;
	for(int i=0; i<8; i++){ //checks number of X's and O's in board
		for(int j=0; j<8; j++){
			if(board[i][j]=='X')
				xnum++;
			else if(board[i][j]=='O')
				onum++;
		}
	}
	if(xnum>onum){ //checks who won based on higher value
		printf("player X won:%d:%d\n", xnum, onum);
		*Xwins += 1;
		*game_num+=1;
		*curr_player = 2;

	}
	else if(onum>xnum){
		printf("player O won:%d:%d\n",onum, xnum);
		*Owins += 1; //updates total score count
		*game_num+=1; //updates total games count
		*curr_player = 1; //to check who begins next game
	}

	else{
		printf("we got a tie:%d:%d\n", xnum, onum);
	}
	printf("Total score: the score is %d for Player O and %d for player X \n", *Owins, *Xwins);

	while(1){
		while(getchar()!='\n');
		printf("would you like to play again? Y\\N? \n");
		scanf("%c", &answer);
		switch(answer){
		case 'Y':
			computer_vs(Xwins, Owins, game_num, curr_player);
			break;
		case 'N':
			if(*Owins>*Xwins){
				printf("The winner is player O with the score of %d:%d\n\n", *Owins, *Xwins);
				return;
			}
			else if(*Xwins>*Owins){
				printf("The winner is player X with the score of %d:%d\n\n", *Xwins, *Owins);
				return;
			}
			else{
				printf("It's a tie with the score of %d:%d\n\n", *Owins, *Xwins);
				return;
			}
			break;

		default:
			printf("wrong input");
			break;
		}
	}

}

void two_players(int* Xwins, int* Owins, int* game_num, int* curr_player){
	int count=0;
	if(*game_num!=0){
		if(*curr_player==1)
			count = 1;
		else if(*curr_player==2)
			count = 2;
	}
	else if(*game_num==0)
		randchoice(&count);

	char board[8][8];
	for(int i=0; i<8; i++){ //starts the board as empty
		for(int j=0; j<8; j++){
			board[i][j]= '-';
		}
	}
	board[3][3]='O'; board[4][4]='O'; board[4][3]='X'; board[3][4]='X'; //assigns starting position
	print(board);
	int row;
	int col;
	int full = 0;

	while(full<64){ //checks if board is full
		full = 0;
		if(turn(&count)== 'X') printf("it's player's X turn\n");
		else printf("it's player's O turn\n");
		printf("please choose your ROW coordinates\n");
		scanf("%d", &row);
		printf("please choose your COLUMN coordinates\n");
		scanf("%d", &col);
		if(row<0 || row>=8 || col<0 || col>=8)
			printf("error, given coordinates out of range\n");
		else if(board[row][col]== '-'){ //checks if spot is empty
			int flag = 0;

			if(row>0 && col>0 && row<7 && col<7){
				for(int i=(row-1); i<(row+2); i++){ //checks if its near a taken spot
					for(int j=(col-1); j<(col+2); j++){
						if(board[i][j]=='O' || board[i][j]=='X'){
							flag+=1; //number of neighbors in 8 coordinates
						}
					}
				}
			}
			else{
				switch(row){
				case 0:
					for(int i=(row); i<(row+2); i++){ //checks if its near a taken spot
						switch(col){
						case 0:
							for(int j=(col); j<(col+2); j++){
								if(board[i][j]=='O' || board[i][j]=='X'){
									flag+=1; //number of neighbors in 8 coordinates
								}
							}
							break;
						case 7:
							for(int j=(col-1); j<(col+1); j++){
								if(board[i][j]=='O' || board[i][j]=='X'){
									flag+=1; //number of neighbors in 8 coordinates
								}
							}
							break;
						default:
							for(int j=(col-1); j<(col+2); j++){
								if(board[i][j]=='O' || board[i][j]=='X'){
									flag+=1; //number of neighbors in 8 coordinates
								}
							}
							break;
						}

					}
					break;
				case 7:
					for(int i=(row-1); i<(row+1); i++){ //checks if its near a taken spot
						switch(col){
						case 0:
							for(int j=(col); j<(col+2); j++){
								if(board[i][j]=='O' || board[i][j]=='X'){
									flag+=1; //number of neighbors in 8 coordinates
								}
							}
							break;
						case 7:
							for(int j=(col-1); j<(col+1); j++){
								if(board[i][j]=='O' || board[i][j]=='X'){
									flag+=1; //number of neighbors in 8 coordinates

								}
							}
							break;
						default:
							for(int j=(col-1); j<(col+2); j++){
								if(board[i][j]=='O' || board[i][j]=='X'){
									flag+=1; //number of neighbors in 8 coordinates
								}
							}
							break;
						}

					}
					break;
				default:
					for(int i=(row-1); i<(row+2); i++){ //checks if its near a taken spot
						switch(col){
						case 0:
							for(int j=(col); j<(col+2); j++){
								if(board[i][j]=='O' || board[i][j]=='X'){
									flag+=1; //number of neighbors in 8 coordinates
								}
							}
							break;
						case 7:
							for(int j=(col-1); j<(col+1); j++){
								if(board[i][j]=='O' || board[i][j]=='X'){
									flag+=1; //number of neighbors in 8 coordinates
								}
							}
							break;
						default:
							for(int j=(col-1); j<(col+2); j++){
								if(board[i][j]=='O' || board[i][j]=='X'){
									flag+=1; //number of neighbors in 8 coordinates
								}
							}
							break;
						}

					}
					break;
				}

			}
			if(flag>0){ //if rules apply coordinate can be placed
				board[row][col] = turn(&count); //places coordinate in board according to turn of player


				for(int i = row; board[i][col]!='-' && i<8; i++){ //checks down
					if(board[i][col] == turn(&count)){
						for(int j=row; j<i; j++){
							board[j][col]= turn(&count);

						}
					}
				}

				for(int i = col; board[row][i]!='-' && i<8; i++){ //checks right
					if(board[row][i] == turn(&count)){
						for(int j=col; j<i; j++){
							board[row][j]= turn(&count);

						}
					}
				}

				for(int i = row; board[i][col]!='-' && i>=0; i--){ //checks up
					if(board[i][col] == turn(&count)){
						for(int j=row; j>i; j--){
							board[j][col]= turn(&count);

						}
					}
				}

				for(int i = col; board[row][i]!='-' && i>=0; i--){ //checks left
					if(board[row][i] == turn(&count)){
						for(int j=col; j>i; j--){
							board[row][j]= turn(&count);

						}
					}
				}

				for(int i=row, j=col; i>=0 && j>=0; i--, j--){ //checks up left
					if(board[i][j]!='-' && board[i][j]==turn(&count)){
						for(int m=row, n=col; m>i && n>j; m--, n--){
							if(board[m][n]!='-')
								board[m][n]= turn(&count);
						}
					}
				}


				for(int i=row, j=col; i>=0 && j<8; i--, j++){ //checks right up
					if(board[i][j]!='-' && board[i][j]==turn(&count)){
						for(int m=row, n=col; m>i && n<j; m--, n++){
							if(board[m][n]!='-')
								board[m][n]= turn(&count);
						}
					}
				}


				for(int i=row, j=col; i<8 && j>=0; i++, j--){ //checks left down
					if(board[i][j]!='-' && board[i][j]==turn(&count)){
						for(int m=(row), n=col; m<i && n>j; m++, n--){
							if(board[m][n]!='-')
								board[m][n]= turn(&count);
						}
					}
				}



				for(int i=row, j=col; (i)<8 && (j)<8; i++, j++){ //checks down right
					if(board[i][j]!='-' && board[i][j]==turn(&count)){
						for(int m=row, k=col; m<i && k<j; m++, k++){
							if(board[m][k]!='-')
								board[m][k]= turn(&count);
						}
					}
				}

				print(board);
				printf("\n");
				count +=1;

				for(int i=0; i<8; i++){ //checks if board is full
					for(int j=0; j<8; j++){
						if(board[i][j]!='-')
							full++;
					}
				}
			}
			else printf("error, has to be placed next to X or O\n");
		}
		else
			printf("this coordinate spot is taken!\n");
	}
	int xnum=0, onum=0;
	char answer;
	for(int i=0; i<8; i++){ //checks if board is full
		for(int j=0; j<8; j++){
			if(board[i][j]=='X')
				xnum++;
			else if(board[i][j]=='O')
				onum++;
		}
	}
	if(xnum>onum){
		printf("player X won:%d:%d\n", xnum, onum);
		*Xwins += 1;
		*game_num+=1;
		*curr_player=2;
	}
	else if(onum>xnum){
		printf("player O won:%d:%d\n",onum, xnum);
		*Owins += 1;
		*game_num+=1;
		*curr_player=1;
	}

	else{
		printf("we got a tie:%d:%d\n", xnum, onum);
	}
	printf("Total score: the score is %d for Player O and %d for player X \n", *Owins, *Xwins);

	while(1){
		while(getchar()!='\n');
		printf("would you like to play again? Y\\N \n");
		scanf("%c", &answer);
		switch(answer){
		case 'Y':
			two_players(Xwins, Owins, game_num, curr_player);
			break;
		case 'N':
			if(*Owins>*Xwins)
				printf("The winner is player O with the score of %d:%d\n\n", *Owins, *Xwins);
			else if(*Xwins>*Owins)
				printf("The winner is player X with the score of %d:%d\n\n", *Xwins, *Owins);
			else
				printf("It's a tie with the score of %d:%d\n\n", *Owins, *Xwins);
			return;
			break;

		default:
			printf("wrong input\n");
			break;
		}
	}
}

void randchoice(int* count){ //randomizes choice of first player
	int player;
	srand(time(0));
	player = rand()%2;
	if(player){
		printf("player O begins\n"); //updates value of count for use in function 'turn'
		(*count) = 1;
	}
	else{
		printf("player X begins\n");
		(*count) = 2;
	}
	return;
}


char turn(int* count){ //while count updates it returns the symbol of the player by turn
	if((*count)%2==0) //while count is even it's player X turn
		return 'X';
	else
		return 'O';  //while count is odd it's player O turn
}

void print(char board[8][8]){ //function that prints the board, returns none
	printf("\n");
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			printf("%c\t", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}


