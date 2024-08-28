#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <stack>
#include <queue>

using namespace sf;
using namespace std;

sf::RectangleShape wall(sf::Vector2f(46, 46));
sf::RectangleShape emptySpace(sf::Vector2f(46, 46));
sf::RectangleShape playerBody(sf::Vector2f(6, 30));
sf::RectangleShape playerArms(sf::Vector2f(30, 6));
sf::CircleShape playerHead(12);
sf::RectangleShape player(sf::Vector2f(46, 46));
sf::RectangleShape enemy(sf::Vector2f(46, 46));
sf::RectangleShape exitHere(sf::Vector2f(46, 46));
sf::RectangleShape guideBlock(sf::Vector2f(46, 46));

const int ROWS = 20;
const int COLS = 20;
const int BLOCK_SIZE = 50; // Size of each block in pixels

char maze[ROWS][COLS] = {
    // Maze initialization remains the same
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'P', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#', 'X', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', 'X', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#'},
    {'#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', '#', '#'},
    {'#', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#', ' ', '#', '#'},
    {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', 'X', ' ', '#', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', 'E', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

bool visited[ROWS][COLS];
int path[ROWS][COLS];

int playerX = 1;
int playerY = 1;
bool isGameOver = false;

struct Block {
    int x;
    int y;
};

bool DFS(Block source, Block destination) {
    // Initialize visited array and path
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visited[i][j] = false;
            path[i][j] = -1;
        }
    }

    queue<Block> queue;
    queue.push(source);
    visited[source.x][source.y] = true;

    while (!queue.empty()) {
        Block current = queue.front();
        queue.pop();

        if (current.x == destination.x && current.y == destination.y) {
            return true; // Destination reached
        }

        int offsetX[4] = { -1, 1, 0, 0 };
        int offsetY[4] = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; i++) {
            Block nextBlock;
            nextBlock.x = current.x + offsetX[i];
            nextBlock.y = current.y + offsetY[i];
            if ((maze[nextBlock.x][nextBlock.y] == ' ' || maze[nextBlock.x][nextBlock.y] == 'E')
                && !visited[nextBlock.x][nextBlock.y]) {
                queue.push(nextBlock);
                visited[nextBlock.x][nextBlock.y] = true;
                path[nextBlock.x][nextBlock.y] = i;
            }
        }
    }
    return false; // Destination not reached
}

void printPath(Block destination) {
    if (maze[destination.x][destination.y] == ' ')
    {
        maze[destination.x][destination.y] = '*';
    }

    if (path[destination.x][destination.y] == -1) {
        cout << destination.x << " " << destination.y << endl; // Print the source node
    }
    else {
        int offsetX[4] = { -1, 1, 0, 0 };
        int offsetY[4] = { 0, 0, -1, 1 };
        Block lastBlock;
        lastBlock.x = destination.x - offsetX[path[destination.x][destination.y]];
        lastBlock.y = destination.y - offsetY[path[destination.x][destination.y]];

        printPath(lastBlock); // Recursive call to print the path
        cout << destination.x << " " << destination.y << endl;
    }
}


int currentX = 0;
int currentY = 0;
bool escapedMaze = false;
bool validInput = true;
// Updated movePlayer function with SFML logic here
bool movePlayer(char input) {
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
        if (maze[currentX - 1][currentY] == ' ') {
            validInput = true;
            maze[currentX][currentY] = ' ';				//Set Current space to empty

            maze[currentX - 1][currentY] = 'P';			//Give space moved to the P marker
            currentY--;									//Update Player's Current position
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
    else if (tolower(input) == 'w') {
        if (maze[currentX][currentY - 1] == ' ') {
            validInput = true;
            maze[currentX][currentY] = ' ';				//Set Current space to empty

            maze[currentX][currentY - 1] = 'P';			//Give space moved to the P marker
            currentX--;									//Update Player's Current position
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
    else if (tolower(input) == 'd') {
        if (maze[currentX + 1][currentY] == ' ') {
            validInput = true;
            maze[currentX][currentY] = ' ';				//Set Current space to empty

            maze[currentX + 1][currentY] = 'P';			//Give space moved to the P marker
            currentY++;									//Update Player's Current position
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
    else if (tolower(input) == 's') {
        if (maze[currentX][currentY + 1] == ' ') {
            validInput = true;
            maze[currentX][currentY] = ' ';				//Set Current space to empty

            maze[currentX][currentY + 1] = 'P';			//Give space moved to the P marker
            currentX++;									//Update Player's Current position
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

void drawMaze(sf::RenderWindow& window) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[j][i] == '#') {
                wall.setPosition(i * BLOCK_SIZE, j * BLOCK_SIZE);
                wall.setFillColor(sf::Color(0, 0, 0));
                window.draw(wall);
            }
            else if (maze[j][i] == ' ') {
                emptySpace.setPosition(i * BLOCK_SIZE, j * BLOCK_SIZE);
                emptySpace.setFillColor(sf::Color(255, 255, 255));
                window.draw(emptySpace);
            }
            else if (maze[j][i] == 'P') {
                emptySpace.setPosition(i * BLOCK_SIZE, j * BLOCK_SIZE);
                emptySpace.setFillColor(sf::Color(255, 255, 255));
                window.draw(emptySpace);

                playerBody.setPosition(i * BLOCK_SIZE + 20, j * BLOCK_SIZE + 17);
                playerArms.setPosition(i * BLOCK_SIZE + 7, j * BLOCK_SIZE + 25);
                playerHead.setPosition(i * BLOCK_SIZE + 11, j * BLOCK_SIZE + 4);

                playerBody.setFillColor(sf::Color(35, 50, 80));
                playerArms.setFillColor(sf::Color(35, 50, 80));
                playerHead.setFillColor(sf::Color(100, 100, 100));

                window.draw(playerBody);
                window.draw(playerArms);
                window.draw(playerHead);

            }
            else if (maze[j][i] == 'X') {
                enemy.setPosition(i * BLOCK_SIZE, j * BLOCK_SIZE);
                enemy.setFillColor(sf::Color(240, 10, 10));
                window.draw(enemy);
            }
            else if (maze[j][i] == '*') {
                guideBlock.setPosition(i * BLOCK_SIZE, j * BLOCK_SIZE);
                guideBlock.setFillColor(sf::Color(255, 255, 190));
                window.draw(guideBlock);
            }
            else if (maze[j][i] == 'E') {
                exitHere.setPosition(i * BLOCK_SIZE, j * BLOCK_SIZE);
                exitHere.setFillColor(sf::Color(230, 230, 10));
                window.draw(exitHere);
            }
        }
    }
}

int main() {
    char input;

    Block source, destination;
    source.x = playerX;
    source.y = playerY;
    destination.x = 18;
    destination.y = 1;

    if (DFS(source, destination)) {
        cout << "Path found: ";
        printPath(destination);
    }

    sf::RenderWindow window(sf::VideoMode(ROWS * BLOCK_SIZE, COLS * BLOCK_SIZE), "Maze Game");
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && !isGameOver) {
                // Handle player movement
                if (event.key.code == sf::Keyboard::W) movePlayer('w');
                else if (event.key.code == sf::Keyboard::S) movePlayer('s');
                else if (event.key.code == sf::Keyboard::A) movePlayer('a');
                else if (event.key.code == sf::Keyboard::D) movePlayer('d');
            }
        }

        window.clear();
        drawMaze(window);
        window.display();

        if (isGameOver) {
            window.close();
        }
    }

    system("pause");
    return 0;
}