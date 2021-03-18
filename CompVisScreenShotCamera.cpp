#include <iostream>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include <fstream>

using namespace cv;
using namespace std;


int i = 0;

int main(int argc, char** argv) {

	namedWindow("Video", WINDOW_AUTOSIZE);
	VideoCapture cap;

	cap.open(0);
	if (!cap.isOpened())
	{
		cout << "Camera tidak ditemukan" << endl;
		return -1;
	}
	int frame_width = cap.get(CAP_PROP_FRAME_WIDTH);
	int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);
	int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
	VideoWriter video("media/hasilvideo.avi", codec, 10, Size(frame_width, frame_height), true);

	Mat frame;
	for (;;) {
		cap >> frame;
		if (frame.empty()) break;
		video.write(frame);
		imshow("Video", frame);

		//screenshot
			if (i % 10 == 0)
			{
				ostringstream name;
				name << "media/frame" << i << ".jpg";
				imwrite(name.str(), frame);
			}
			i = i + 1;
		if ((char)waitKey(33) >= 0) break;
	}

	return 0;
}