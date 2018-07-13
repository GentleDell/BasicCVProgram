# BasicCVProgram
computer vsion programs related to camera calibration, video capturing and some other basic functions

1.videocapture_basic.cpp:
    Opencv program to obtain image from camera.
    Now it captures stereo images and it relies on the ports mappping file under /etc/udev/rules.d which maps video0/1 to leftcam/rightcam. Therefore, names of the two cameras are no longer changeable. (a camera -> a port -> a unique name.) 

2.imagelist_creator.cpp:
    Opencv program to generate image list for calibration(only for mono).
    It supports yml yaml xml xml.gz etc., and it reads jpg png etc.
    /* USAGE:
     ./imagelist_creator nameofoutfile.xml *.jpg */

3.calibration.cpp: 
    Opencv program for camera calibration.
    Camera matrix and distortion parameters can be obtained by the program.
    /* USAGE:
     ./calibration -w=7 -h=7 -s=0.025 -o=camera.yml -op -oe image_list.xml*/
    Help messages are writen in the program.

4.stereo_calib.cpp:
    Opencv program for stereo camera calibration.
    Outputs include extrinsics and intrinsics.
    /* USAGE:
     ./stereo\_calib -w=7 -h=7 -s=0.025 stereo_imagelist.xml */

