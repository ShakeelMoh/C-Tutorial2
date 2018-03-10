// Implements volimage1.h

#include <iostream>
#include "volimage1.h"
#include <fstream> //For reading/writing textfile
#include <iterator>
#include <vector>
#include <cmath>

//#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

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

   VolImage::height = height;
   VolImage::width = width;
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
      
      /*
      //Deallocate the array
      for (int i = 0; i < height; i++){
         delete[] slice[i];
      }
      delete[] slice;
      */
   }
   
   //cout << "Random slice piece " << VolImage::slices[0][150][100];
   
}

void VolImage::extract(int sliceID, string prefix){
   
   //cout << VolImage::height << " " << VolImage::width;

   //cout << sliceID << " " << prefix << "\n";
   //cout << "Random slice piece " << VolImage::slices[1][150][100];
   ofstream dataFile (prefix + ".txt");
   dataFile << "1 1 1" << endl;
   dataFile.close();
   
   ofstream  rawFile(prefix + ".raw");
   rawFile.close();
   
   FILE * pFile;
   string fileName = prefix + ".raw";
   pFile = fopen (fileName.c_str(), "w");
   
   for (int i = 0; i < VolImage::height; i++){
      for (int j = 0; j < VolImage::width; j ++){
         fwrite (VolImage::slices[sliceID][i], sizeof(char), sizeof(VolImage::slices[sliceID][i]), pFile);
      }
      

   }
   fclose(pFile);
     //int width = VolImage::slices[sliceID]);
   //cout << width << " width";

}

void VolImage::diffmap(int sliceI, int sliceJ, string prefix){

   unsigned char** Diffslice = new unsigned char*[VolImage::height];
      for (int i = 0; i < height; i++){
         Diffslice[i] = new unsigned char[VolImage::width];
      }
      
   
   for (int j = 0; j < height; j++){
      for (int k = 0; k < width; k++){
         Diffslice[j][k] = (unsigned char)(abs((float)VolImage::slices[sliceI][j][k] - (float)VolImage::slices[sliceJ][j][k])/2);
      }
   
   }
   
   ofstream  rawFile(prefix + ".raw");
   rawFile.close();
   
   FILE * pFile;
   string fileName = prefix + ".raw";
   pFile = fopen (fileName.c_str(), "w");
   
   for (int i = 0; i < VolImage::height; i++){
      for (int j = 0; j < VolImage::width; j ++){
         fwrite (Diffslice[i], sizeof(char), sizeof(Diffslice[i]), pFile);
      }
      

   }
   fclose(pFile);
   

}