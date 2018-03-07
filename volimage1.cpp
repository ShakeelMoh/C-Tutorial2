// Implements volimage1.h

#include <iostream>
#include "volimage1.h"
#include <fstream> //For reading/writing textfile
#include <iterator>

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
   
   //Create 2d unsigned array
   unsigned char slice[height][width];
   
   
   for (int i = 0; i < numImages; i++){
      
      string fileName = "./brain_mri_raws/" + baseName + to_string(i) + ".raw";
      //cout << fileName << "\n";
      
      
      //inFile.open(fileName);
      
      //if (!inFile){ //while next line
         //cerr << "Unable to open file: " << fileName;
      //}

      FILE * pFile;
      pFile = fopen(fileName.c_str(), "r");
      fread(&slice[0][0], height, width, pFile);


   /*
      if (!inFile.eof() && !inFile.fail()){
      
         inFile.seekg(0, std::ios_base::end);
         std::streampos fileSize = inFile.tellg();
         slice.resize(fileSize);

         inFile.seekg(0, std::ios_base::beg);
         inFile.read(&slice[0], fileSize);
         
      }
  */
 
      cout << "Size of vector: " << sizeof(slice[0]) << " " << sizeof(slice)/sizeof(slice[0]) << "\n";
      
      ///VolImage::slices.push_back(slice); push back stuff now...
      
      inFile.close();
   }
   
}