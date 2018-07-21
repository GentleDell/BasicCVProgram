# BasicCVProgram & BasicGSLProgram
Computer vsion programs related to camera calibration, video capturing and some other basic functions;
GSL(GNU Scientific Library) programs to find polynomial roots.

*** COMPILE OF OPENCV PROGRAM ***

g++ `pkg-config opencv --cflags` videocapture\_basic.cpp -o videocapture_basic `pkg-config opencv --libs`
(In the commandline, the above '\' doesn't exist. '\_' means blank space. we add a back slant to tell the .md file that the '_' doesn't means italic.)

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

5.stereo_match.cpp:
    Opencv program for stereo matching.
    Outputs inlude disparity image and point cloud file if it is required.
    /* USAGE:
     ./stereo_match left01.jpg right01.jpg --algorithm=hh --blocksize=5 --max-disparity=256 --scale=1.0 --no-display -i=intrinsics.yml -e=extrinsics.yml -o=disparity.jpg  */

6.launching_viz.cpp:
    Sample program to test viz lib.
    Output is an empty viz window.
    /* USAGEL
     ./ launching_viz */
    ATTENTION: In order to use the viz lib, it's necessary to reinstall the OpenCV with VTK (Visulization ToolKit) support. A tutorial about the installation is "https://blog.csdn.net/dell5200/article/details/81142951"

*** COMPILE OF GSL PROGRAM ***

g++ -o GSLtest GSLtest.cpp -I/usr/local/include -L/usr/local/lib -lgsl -lgslcblas -lm 

1.GSLtest.cpp:
    GSL program to obtain polynomial roots.
    /* USAGE:
     ./GSLtest  */
    




