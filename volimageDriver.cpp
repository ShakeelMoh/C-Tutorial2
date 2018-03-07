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
      file1 = arg[3];
      outputFile = arg[4];
      
   }
   
   if (argc == 6){
      cout << "Difference map...\n";
      option = argv[2];
      file1 = arg[3];
      file2 = arg[4];
      outputFile = arg[5];
      
      
   }
   
   string iteration;
   for (int i = 2; i < argc; ++i){
     
   }
        

   
   
        

   VolImage v;
   
   cout << "Enter the basename\n";
   
   string baseName;
   cin >> baseName;

   v.readImages(baseName);

   
   
   return 0; 


}