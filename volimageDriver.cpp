#include <iostream>   //a system header file - needed to do simple I/O
#include "volimage1.h"	         // our header file - contains decl of fib()

using namespace std;  

int main (int argc, char *argv[]) { //argc = num args. argv = arr of args



   string programName;
   string baseName;
   string option;
   string file1;
   string file2;
   string outputFile;
   
   programName = argv[0];
   baseName = argv[1];
   
   if (argc == 5){
      cout << "Extracting...\n";
      option = argv[2];
      file1 = argv[3];
      outputFile = argv[4];
      
   }
   
   if (argc == 6){
      cout << "Difference map...\n";
      option = argv[2];
      file1 = argv[3];
      file2 = argv[4];
      outputFile = argv[5];
      
   } else {
      cout << "No option selected\n";
   }
        
   VolImage v;

   
   v.readImages(baseName);

   
   
   return 0; 

}