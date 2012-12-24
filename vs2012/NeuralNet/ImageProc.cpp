/*

#include "ImageProc.h"

MyImage::MyImage(char* ImageSrc){

	Image= imread(ImageSrc);

	if(!Image.data){
		perror("Image Src is not valid :: ImageProc.MyImage.MyImage()");
		exit(1);
	}
}

void MyImage::ImageProc(){
	namedWindow("BeforeProc", CV_WINDOW_AUTOSIZE);
	imshow("BeforeProc", Image);
	
}

*/