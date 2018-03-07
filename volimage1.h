//.h file

#ifndef _VOLIMAGE
#define _VOLIMAGE

#include<vector>

using namespace std;

class VolImage{

   private:
      
       //width and height of image stack
      int width;      
      int height;
      
      vector<unsigned char **> slices;//data for each slice in order
      
      //std::vector<char> slice; //contains single image slice data
      
   public:
      
      VolImage(); //default constructor defined in .cpp
      //VolImage(); //destructor defined in .cpp
      
      //populate object with images from stack
      void readImages(string baseName);
      
      //compute difference map and write out
      void diffmap(int sliceI, int sliceJ, string output_prefix);
      
      //extract slice slideID and write to output
      void extract(int sliceId, string output_prefix);
      
      //numbre of bytes to store image data
      int volImageSize(void);
      

};


#endif