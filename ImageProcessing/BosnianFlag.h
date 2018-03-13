#include <iostream>
#include <fstream>
using namespace std;

void makeBosnianFlag(int width, int height) {
	ofstream fout;

	int blue[3] = { 28, 15, 198 };
	int yellow[3] = { 255, 250, 0 };
	fout.open("ImageProcessing/bosnianFlag.ppm");
	if (fout.is_open()) {
		cout << "Image opened" << endl;
		fout << "P3" << endl;
		fout << width << " " << height << endl;
		fout << "255" << endl;
		int k1 = 50;
		int k2 = 30;
		int k4 = 20;
		int k5 = 15;
		int k3 = 10;
		for (int i = 0; i < height; i++) {
			int d1 = 99;
			int d2 = 101;
			for (int j = 0; j < width; j++) {

				if ((j - i) == 100 && (k1 % 50) == 0) {
					fout << "255" << " " << "255" << " " << "255" << " ";
				}

				/*else if ((k1 % 50 > 0 && k1 % 50 < 20) && (((j-i) <= 100 && (j-i) >= d1) || ((j - i) >= 100 && (j - i) < d2))) {
					fout << "255" << " " << "255" << " " << "255" << " ";
					
				}*/
				
				else if (k2 % 50 == 0 && ((j - i) == 55 || (j - i) == 75 || (j - i) == 85 || (j - i) == 105)) {
					fout << "255" << " " << "255" << " " << "255" << " ";
				}

				else if (k4 % 50 == 0 && ((j - i) == 60 || (j - i) == 80)) {
					fout << "255" << " " << "255" << " " << "255" << " ";
				}

				else if ((j - i) == 65 && (k5 % 50) == 0) {
					fout << "255" << " " << "255" << " " << "255" << " ";
				}

				else if (k3 % 50 == 0 && ((j - i) == 45 || (j - i) == 75)) {
					fout << "255" << " " << "255" << " " << "255" << " ";
				}

				else if ((j - i) >= 130 && j <= 530) {
					
					fout << yellow[0] << " " << yellow[1] << " " << yellow[2] << " ";
				
				} else {
					
					fout << blue[0] << " " << blue[1] << " " << blue[2] << " ";
				}
			}
			fout << endl;
			k1++; k2++; k3++; k4++; k5++;
			d1--; d2++;
		}
		fout << endl;
	}
	else {
		cout << "Not opened" << endl;
	}
	fout.close();
}