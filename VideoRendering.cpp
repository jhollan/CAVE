#define _CRT_SECURE_NO_DEPRECATE

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;


/*------------------------------ FUNCTION TO SUBDIVED IMAGES ------------------------------------*/
void subdivide(Mat image) {
	double height = image.rows;
	double width = image.cols / 3;

	char winName[20];

	for (int y = 0; y <= (image.rows - height); y += width) {
		for (int x = 0; x <= (image.cols - width); x += width) {
			Rect region = Rect(Point(x, y), Point(x + width, y + height));
			//Mat region (image, Rect(y, x, image.cols, image.rows));
			sprintf(winName, "Window%d", x);
			Mat frameStore = image(region);

			imshow(winName, frameStore);
		}
	}
} 




int main(int argc, char** argv)
{
	/*------------------------------ READ FILE AND CHECKS ----------------------------------------*/

	//CHECK IF FILE WAS CORRECTLY ENTERED INTO COMMAND PROMPT
	if (argc != 2)
	{
		cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
		return -1;
	}
	
	VideoCapture video(argv[1]); 

	//CHECK IF FILE CAN BE OPENED
	if (!video.isOpened()) {
		cout << "Error opening file" << endl;
		system("pause");
		return -1;
	}

	/*------------------------------ FUNCTION TO SUBDIVED VIDEO ------------------------------------*/
	while (1) {
		Mat frame;
		video >> frame;

		if (frame.empty())
			break;

		subdivide(frame);

		// Press  ESC on keyboard to exit
		char c = (char)waitKey(25);
		if (c == 27)
		break;
	} 



	/*------------------------------------------------------------------------------------------------*/



	


	waitKey();



	return 0;
}
