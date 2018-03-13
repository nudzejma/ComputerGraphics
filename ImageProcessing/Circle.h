#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void drawACircle(int width, int height, int x, int y, int r) {
	ofstream fout;

	int blue[3] = { 28, 15, 198 };
	int yellow[3] = { 255, 250, 0 };
	int center[2] = { x, y };
	fout.open("ImageProcessing/circle.ppm");
	if (fout.is_open()) {
		fout << "P3" << endl;
		fout << width << " " << height << endl;
		fout << "255" << endl;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (sqrt((pow(i - center[0], 2) + pow(j - center[1], 2))) < r-10) {
					fout << "110" << " " << "114" << " " << "122" << " ";
				}
				else {
					fout << "242" << " " << "56" << " " << "24" << " ";
				}
			}
		}
	}
	else {
		return;
	}
}