#include <stdio.h>

int checkRows(char arr[][3], int play); //declaration to check rows of the board

int checkColumns(char arr[][3], int play); //declaration to check columns of the board

int checkDiagonals(char arr[][3], int play); //declaratioin to check diagonals of the board

int checkFull(char arr[][3]); //checks if the board is filled up

int main(){

	int r = 0, c = 0, player = 2; //int for rows, columns and player number
	//player is initialized to 2 because it will be decremented later
	char gameBoard[3][3]; //board
	int win = 0; //there's no boolean, so i'm using ints for if someone wins
	int tie = 0; //int for if the game is tied

	for (int row = 0; row < 3; row++){ //initializes the board with *
		for (int column = 0; column < 3; column++){
			gameBoard[row][column] = '*';
		}
	}

	printf("Let's play Tic Tac Toe!\n");



	for (int row = 0; row < 3; row++){ //prints out the empty board
		for (int column = 0; column < 3; column++){
			printf("%c ", gameBoard[row][column]);
		}
		printf("\n");
	}

	do { //starts do-while loop
		if (player == 2){
			player--; //changes player 2 turn to player 1 turn
		} else {
			player++; //changes player 1 turn to player 2 turn
		}
		if (player == 1){ //prints out prompt depending on which player it is
			printf("Player 1: Select the row you want to select: ");
			fflush(stdout); //ECLIPSE BUG
			scanf("%d", &r); //stores row into r
			printf("Player 1: Select the column you want to select: ");
			fflush(stdout);
			scanf("%d", &c); //stores column into c
			gameBoard[r-1][c-1] = 'X'; //changes the element at that row and column to an X
		} else if (player == 2){
			printf("Player 2: Select the row you want to select: ");
			fflush(stdout);
			scanf("%d", &r);
			printf("Player 2: Select the column you want to select: ");
			fflush(stdout);
			scanf("%d", &c);
			gameBoard[r-1][c-1] = 'O'; //changes the element at that row and column to an O
		}

		for (int row = 0; row < 3; row++){ //prints out result after the player chose
			for (int column = 0; column < 3; column++){
				printf("%c ", gameBoard[row][column]);
			}
			printf("\n");
		}

		win += checkRows(gameBoard, player); //checks for 3 consecutive Xs or Os in a row
		win += checkColumns(gameBoard, player); //checks for 3 consecutive Xs or Os in a column
		win += checkDiagonals(gameBoard, player); //checks for 3 consecutive Xs or Os in the diagonals
		//if a win is found, it is incremented to the variable win

		if (win!=0){ //if someone won, break out of the loop
			break;
		} else {
			tie = checkFull(gameBoard); //checks if the board is full (meaning there's a tie)
		}

		if (tie==0) //if there are no more spaces to enter Xs or Os, break out of the loop
			break;

	} while (win==0);

	if (tie==0){
		printf("You tied!\n"); //prints out tied if there was a tie
	} else if (win!= 0){
		printf("Player %d wins!\n", player); //if there was a win, we access variable player to find out whose turn ended the game
	}

	return 0;
}

int checkRows(char arr[][3], int play){ //definition of checkRows

	int value = 0; //this is what the method will return. It's initialized to 0
	int rowValue; //var for the number of Xs or Os (not together)in the same row
	int player = play; //indicating what player it is

	if (player == 1){ //if it's player 1, we check for Xs
		for (int row = 0; row < 3; row++){
			rowValue = 0; //with every row, the rowValue is assigned 0
			for (int column = 0; column < 3; column++){
				if (arr[row][column]=='X'){ //checks the value within every column in the row
					rowValue++; //if an X is found, increment rowValue
				}
				if (rowValue == 3){ //only increments value if there are 3 Xs in the same row
					value++;
				}
				if (value!=0) //once value is incremented, return to main
					return value;
			}
		}
	} else { //player 2: we check for Os
		for (int row = 0; row < 3; row++){
			rowValue = 0;
			for (int column = 0; column < 3; column++){ //same for player 1 except char is now O
				if (arr[row][column]=='O'){
					rowValue++;
				}
				if (rowValue == 3){
					value++;
				}
				if (value!=0)
					return value;
			}
		}
	}

	return value; //if nothing is found, returns value (which should be zero)
}

int checkColumns(char arr[][3], int play){ //definition for checkColumns

	int value = 0;
	int columnValue; //var for number of Xs or Os (not together) in a certain column
	int player = play;

	if (player == 1){
		for (int column = 0; column < 3; column++){ //first iterates through columns instead of rows first
			columnValue = 0; //with each column, columnValues is reassigned o 0
			for (int row = 0; row < 3; row++){ //checks all of the rows in the column for Xs
				if (arr[row][column]=='X'){
					columnValue++; //if an X is found, increment columnValue
				}
				if (columnValue == 3){ //if columnValue is ever incremented to 3, increment value
					value++;
				}
				if (value!=0) //as soon as value is no longer zero, return to main
					return value;
			}
		}
	} else { //player 2: check for Os
		for (int column = 0; column < 3; column++){
			columnValue = 0;
			for (int row = 0; row < 3; row++){
				if (arr[row][column]=='O'){
					columnValue++;
				}
				if (columnValue == 3){
					value++;
				}
				if (value!=0)
					return value;
			}
		}
	}

	return value; //if nothing is found, return value (which should be 0)
}

int checkDiagonals(char arr[][3], int play){
	int value = 0;
	int diagonals = 0; //similar to rowValues and columnValues
	int player = play;

	if (player == 1){
		for (int i = 0; i < 3; i++){
			if (arr[i][i] == 'X'){ //checks the diagonal that goes from top left to bottom right
				diagonals++;
			}
		}
		if (diagonals == 3){
			value++;
			return value;
		} else { //if the diagonal doesn't have consecutive Xs then check the other diagonal
			diagonals = 0; //reassigns diagonals to zero
			int column = 0; //will to
			for (int row = 2; row >= 0; row--){ //checks the diagonal that goes from bottom left to top right
				column++; //for each row, only increments column once so its a diagonal
				if (arr[row][column] == 'X'){
					diagonals++;
				}
			}
			if (diagonals == 3){
				value++;
				return value;
			}
		}
	} else { //player 2: checks for Os
		for (int i = 0; i < 3; i++){
			if (arr[i][i] == 'O'){
				diagonals++;
			}
		}
		if (diagonals == 3){
			value++;
			return value;
		} else {
			diagonals = 0;
			int column = 0;
			for (int row = 2; row >= 0; row--){
				column++;
				if (arr[row][column] == 'O'){
					diagonals++;
				}
			}
			if (diagonals == 3){
				value++;
				return value;
			}
		}
	}

	return value; //if nothing is found, return value (whih should be 0)
}

int checkFull(char arr[][3]){
	int value = 0; //this will be returned

	for (int row = 0; row < 3; row++){ //iterates through every element to look for *
		for (int column = 0; column < 3; column++){
			if (arr[row][column] == '*'){
				value++; //if a * is found, increment value
				return value; //return to main
			}
		}
	}

	return value; //if nothing is found, return value (which should be 0)
}




