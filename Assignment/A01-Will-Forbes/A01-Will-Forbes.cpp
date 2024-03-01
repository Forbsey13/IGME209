#include <stdio.h>
#include <stdlib.h>
#include <string>

const int ROWS = 10;
const int COLS = 10;
char maze[ROWS][COLS] = {
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{'#', ' ', ' ', ' ', '#', ' ', '#', ' ', 'X', '#'}, // Enemy at (1,8)
	{'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#'},
	{'#', ' ', '#', 'P', ' ', ' ', ' ', ' ', ' ', '#'}, // Player start position
	{'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#'},
	{'#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#'},
	{'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#'},
	{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
	{'#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#'},
	{'#', 'E', '#', '#', '#', '#', '#', '#', '#', '#'} // Exit
};

int playerX = 3;
int playerY = 3;
bool isGameOver = false;

void printMaze() {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
}

int currentX = 0;
int currentY = 0;
bool escapedMaze = false;
bool validInput = true;

bool movePlayer(char input) {
	// This function is responsible for moving the player based on the input direction ('w', 'a', 's', 'd') and the current layout of the maze.
	// Steps to follow:
	// 1. Determine the new position of the player based on the input direction.
	//    - 'w' moves the player up, 's' down, 'a' left, and 'd' right.
	// 2. Check if the new position is within the bounds of the maze and not blocked by a wall ('#').
	//    - If the move is invalid (out of bounds or into a wall), do not update the player's position.
	// 3. Update the player's position on the maze map:
	//    - Clear the current position of the player by setting it to ' ' (space).
	//    - Mark the new position with 'P' to represent the player.
	// 4. Check the new position for an enemy ('X') or the exit ('E'):
	//    - If the player reaches the enemy ('X'), display a message indicating the game is over due to encountering an enemy and set `isGameOver` to true.
	//    - If the player reaches the exit ('E'), display a congratulatory message indicating the player has escaped the maze and set `isGameOver` to true.
	// Note: The game's main loop checks the `isGameOver` flag to determine if the game should end.

	// Begin your implementation below this comment

	//Determine Player's current location
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (maze[i][j] == 'P') {
				currentX = i;
				currentY = j;
			}
		}
	}

	//Check if the Player can move the way they want and see if that changes the game outcome
	if (tolower(input) == 'a') {
		if (maze[currentX][currentY - 1] == ' ') {
			validInput = true;
			maze[currentX][currentY] = ' ';				//Set Current space to empty

			maze[currentX][currentY - 1] = 'P';			//Give space moved to the P marker
			currentY--;									//Update Player's Current position
		}
		else if (maze[currentX][currentY - 1] == 'X') {		//Check if player is on Enemy square
			escapedMaze = false;
			isGameOver = true;
		}
		else if (maze[currentX][currentY - 1] == 'E') {	//Check if player made it to the exit
			escapedMaze = true;
			isGameOver = true;
		}
		else {
			validInput = false;
		}
	}
	else if (tolower(input) == 'w') {
		if (maze[currentX - 1][currentY] == ' ') {
			validInput = true;
			maze[currentX][currentY] = ' ';				//Set Current space to empty

			maze[currentX - 1][currentY] = 'P';			//Give space moved to the P marker
			currentX--;									//Update Player's Current position
		}
		else if (maze[currentX - 1][currentY] == 'X') {		//Check if player is on Enemy square
			escapedMaze = false;
			isGameOver = true;
		}
		else if (maze[currentX - 1][currentY] == 'E') {	//Check if player made it to the exit
			escapedMaze = true;
			isGameOver = true;
		}
		else {
			validInput = false;
		}
	}
	else if (tolower(input) == 'd') {
		if (maze[currentX][currentY + 1] == ' ') {
			validInput = true;
			maze[currentX][currentY] = ' ';				//Set Current space to empty

			maze[currentX][currentY + 1] = 'P';			//Give space moved to the P marker
			currentY++;									//Update Player's Current position
		}
		else if (maze[currentX][currentY + 1] == 'X') {		//Check if player is on Enemy square
			escapedMaze = false;
			isGameOver = true;
		}
		else if (maze[currentX][currentY + 1] == 'E') {	//Check if player made it to the exit
			escapedMaze = true;
			isGameOver = true;
		}
		else {
			validInput = false;
		}
	}
	else if (tolower(input) == 's') {
		if (maze[currentX + 1][currentY] == ' ') {
			validInput = true;
			maze[currentX][currentY] = ' ';				//Set Current space to empty

			maze[currentX + 1][currentY] = 'P';			//Give space moved to the P marker
			currentX++;									//Update Player's Current position
		}
		else if (maze[currentX + 1][currentY] == 'X') {		//Check if player is on Enemy square
			escapedMaze = false;
			isGameOver = true;
		}
		else if (maze[currentX + 1][currentY] == 'E') {	//Check if player made it to the exit
			escapedMaze = true;
			isGameOver = true;
		}
		else {
			validInput = false;
		}
	}
	else {
		printf("Input is Invalid!");
		printf("\n");
	}

	if (!validInput) {
		printf("Input is Invalid!");
		printf("\n");
	}
	if (isGameOver && !escapedMaze) {
		printf("Unfortunately you have run into an enemy and the game is over!");
		printf("\n");
	}
	if (isGameOver && escapedMaze) {
		printf("Congratualations! You have beaten the game!");
		printf("\n");
	}


	return true;
	// End your implementation above this comment  
}

int main() {
	char input;

	while (!isGameOver) {
		printMaze();
		printf("Move (WASD): ");
		scanf_s(" %c", &input); // Space before %c to ignore 'enter'

		if (input == 'w' || input == 'a' || input == 's' || input == 'd') {
			movePlayer(input);
		}
	}

	system("Pause");

	return 0;
}