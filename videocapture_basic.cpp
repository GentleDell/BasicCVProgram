/**
  @file videocapture_basic.cpp
  @brief A very basic sample for using VideoCapture and VideoWriter
  @author PkLab.net
  @date Aug 24, 2016
*/

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int, char**)
{
    char key;
    char filename_left[200], filename_right[200];  
    int count = 0;
    Mat frame_left, frame_right;
    //--- INITIALIZE VIDEOCAPTURE
    VideoCapture cap_left, cap_right;
    // open the default camera using default API
    // cap_left.open(0);
    // cap_right.open(1);
    // OR advance usage: select any API backend
    //int deviceID = 1;             // 0 = open default camera
    //int apiID = cv::CAP_V4L2;      // 0 = autodetect default API
    // open selected camera using selected API
    cap_left.open("/dev/leftcam");		// deviceID + apiID
    cap_right.open("/dev/rightcam");
    // check if we succeeded
    if (!cap_left.isOpened()) {
        cerr << "ERROR! Unable to open left camera\n";
        return -1;
    }
    if (!cap_right.isOpened()) {
        cerr << "ERROR! Unable to open right camera\n";
        return -1;
    }

    //--- GRAB AND WRITE LOOP
    cout << "Start grabbing" << endl
        << "Press any key to capture image" << endl;
    for (;;)
    {
        // wait for a new frame from camera and store it into 'frame'
        cap_left.read(frame_left);
        cap_right.read(frame_right);
        // check if we succeeded
        if (frame_left.empty() || frame_right.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // show live and wait for a key with timeout long enough to show images
        imshow("Live_left", frame_left);
        imshow("Live_right", frame_right);


	key = waitKey(5);
	// added by Zhant deng, 23/06/2018
	if(key == 27)  
            break;//按ESC键退出程序  
	if(key == 32)//按空格键进行拍照  
	{  
        sprintf(filename_left,"left%d.jpg",++count);  
        sprintf(filename_right,"right%d.jpg",count);
	    imwrite(filename_left,frame_left);
	    imwrite(filename_right,frame_right);
	    imshow("leftimage",frame_left);
	    imshow("rightimage", frame_right);
	}  

    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
