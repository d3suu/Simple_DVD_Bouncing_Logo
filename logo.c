#include <stdio.h> // printf
#include <unistd.h> // usleep
#include <stdlib.h> // rand
#include <stdbool.h> // bool, true, false

// uncomment to debug
//#define DEBUG

#define Y_SIZE 20 // You can change these values as you want!
#define X_SIZE 50
#define SPEED 150


char screenBuffer[Y_SIZE][X_SIZE];
const char logoChar = 'A';
const char borderChar = '#';
long long loopCount = 0;
struct logo {
	unsigned int x;
	unsigned int y;
	unsigned int last_x;
	unsigned int last_y;
	bool move_right;
	bool move_down;
} logoPos;

int main(){
	// setup

	// clear buffer
	for(int i = 0; i<Y_SIZE; i++){
		for(int j = 0; j<X_SIZE; j++){
			screenBuffer[i][j] = ' ';
		}
	}

	// setup borders
	for(int i = 0; i<X_SIZE; i++){
		screenBuffer[0][i] = borderChar;
		screenBuffer[Y_SIZE-1][i] = borderChar;
	}
	for(int i = 0; i<Y_SIZE; i++){
		screenBuffer[i][0] = borderChar;
		screenBuffer[i][X_SIZE-1] = borderChar;
	}

	// setup "logo" position
	logoPos.x = X_SIZE+1;
	logoPos.y = Y_SIZE+1;
	while(logoPos.x < 0 || logoPos.x > X_SIZE-1){
		logoPos.x = rand() % X_SIZE-1;
	}
	while(logoPos.y < 0 || logoPos.y > Y_SIZE-1){
		logoPos.y = rand() % Y_SIZE-1;
	}
	logoPos.last_x = 1; // here 1 is safe becouse (0, 0) is border
	logoPos.last_y = 1;
	logoPos.move_right = true;
	logoPos.move_down = true;

	// HERE BEGINS FUN (aka main loop)

	while(1){ // "game" loop
		for(int i = 0; i<20; i++){ // clear screen
			printf("\n");
		}

		// clear screenBuffer by last known position of logo
		screenBuffer[logoPos.last_y][logoPos.last_x] = ' ';

		// put updated logo in screenBuffer
		screenBuffer[logoPos.y][logoPos.x] = logoChar;

		// some debugging
#ifdef DEBUG
		printf("X: %d, Y: %d, RAND: %d, RIGHT: %d, DOWN: %d, LOOP: %lld\n", logoPos.x, logoPos.y, rand(), logoPos.move_right, logoPos.move_down, loopCount);
#endif
		// print screenBuffer
		for(int i = 0; i<Y_SIZE; i++){
			for(int j = 0; j<X_SIZE; j++){
				printf("%c", screenBuffer[i][j]);
			}
			printf("\n");
		}

		// update logoPos state
		logoPos.last_x = logoPos.x;
		logoPos.last_y = logoPos.y;
		
		if(logoPos.x == 1){
			logoPos.move_right = true;
		}
		if(logoPos.x == X_SIZE-2){
			logoPos.move_right = false;
		}

		if(logoPos.y == 1){
			logoPos.move_down = true;
		}
		if(logoPos.y == Y_SIZE-2){
			logoPos.move_down = false;
		}

		if(logoPos.move_right == true){
			logoPos.x += 1;
		}else{
			logoPos.x -= 1;
		}
		if(logoPos.move_down == true){
			logoPos.y += 1;
		}else{
			logoPos.y -= 1;
		};

		// sleep (screen flickering fix)
		usleep(SPEED*1000);
		loopCount += 1;
	}
	return 1;
}
