// Implements volimage1.h

#include <iostream>
#include "volimage1.h"
#include <fstream> //For reading/writing textfile

using namespace std;

VolImage::VolImage(){

   width = 0;
   height = 0;
}

void VolImage::readImages(string baseName){

   ifstream inFile; //get .dat file info
   inFile.open("brain_mri_raws/" + baseName + ".data");

   if (!inFile){ //while next line
      cerr << "Unable to open file";
      
   }

   int width;
   int height;
   int numImages;

   inFile >> width >> height >> numImages;

   inFile.close();
   
   cout << baseName << " has dimensions " << width << " " << height; 
}