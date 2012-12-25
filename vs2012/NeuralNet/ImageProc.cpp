#include "ImageProc.h"


#ifdef __DEBUG__

#include <stdio.h>

MyImage::MyImage(char* ImageSrc){
	FILE* fp= fopen(ImageSrc, "rt");

	for(int i=0; i< 64; i++){
		char ch= fgetc(fp);
		if(ch== '1'){
			Image.push_back(1);
		}
		else if(ch== '0'){
			Image.push_back(0);
		}
		else{
			i--;
			continue;
		}
	}
	while(char ch= fgetc(fp)){
		if(ch>='0' && ch<= '9'){
			Result.push_back(ch-'0');
		}
		if(ch== -1){
			break;
		}
	}
}

void MyImage::ImageProc(){

}

#endif