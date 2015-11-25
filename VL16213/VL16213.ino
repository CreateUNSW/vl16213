#define MAX_ROW 12
#define MAX_COL 45

#include <Adafruit_NeoPixel.h>

//POSSIBLE DATA STRUCTURES FOR THE SIDES//

// Structure #1
struct colourRGB {
	uint8_t red;
	uint8_t green;
	uint8_t blue
};
colourRGB side[MAX_COL][MAX_ROW];

// Structure #2
enum colours {
	WHITE,
	RED,
	YELLOW,
	BLUE
};

int side[MAX_COL][MAX_ROW] = {0};


void setup() {
	// put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void changeColour (uint8_t start_col, uint8_t start_row, uint8_t end_col, uint8_t end_row, uint8_t colour) {
	for (int i = start_col; i <= end_col; i++) {
		for (int j = start_row; j <= end_row; j++) {
			// change colour of each pixel
		}
	}
}



