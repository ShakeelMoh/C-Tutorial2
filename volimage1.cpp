// Implements volimage1.h

#include <iostream>
#include "volimage1.h"
#include <fstream> //For reading/writing textfile
#include <iterator>
#include <vector>

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
   
   cout << baseName << "\n\n";
   cout << "Number of images: " << numImages << "\n";
   int bytesRequired = width * height * numImages;
   cout << "Number of bytes required: " << bytesRequired << "\n\n";
   
   //vector<char> slice;
   
   for (int i = 0; i < numImages; i++){
      
      //unsigned char **slice = new unsigned char[height][width];
      
      string fileName = "./brain_mri_raws/" + baseName + to_string(i) + ".raw";

      unsigned char** slice = new unsigned char*[height];
      for (int i = 0; i < height; i++){
         slice[i] = new unsigned char[width];
      }

      
      FILE * pFile;
      pFile = fopen(fileName.c_str(), "r");
      fread(&slice[0][0], height, width, pFile);
      
      
      //cout << "Size of vector: " << sizeof(slice[0]) << " " << sizeof(slice)/sizeof(slice[0]) << "\n";
      //cout << "Random vector pos " << slice[100][100] << "\n\n";
      
      VolImage::slices.push_back(slice); //push back stuff now...push_back(new slice??)
      
      
      //Deallocate the array
      for (int i = 0; i < height; i++){
         delete[] slice[i];
      }
      delete[] slice;
      
   }
   
   //cout << VolImage::slices.size();
   
}