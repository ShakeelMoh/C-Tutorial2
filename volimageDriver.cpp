#include <iostream>   //a system header file - needed to do simple I/O
#include "volimage1.h"	         // our header file - contains decl of fib()

#include <sstream>

using namespace std;  

int main (int argc, char *argv[]) { //argc = num args. argv = arr of args


   string programName;
   string baseName;
   string option;
   int file1;
   int file2;
   string outputFile;
   
   programName = argv[0];
   baseName = argv[1];
   
   
   VolImage v;
   v.readImages(baseName);
   
   
   
   if (argc == 5){
      cout << "Extracting...\n";
      option = argv[2];

      stringstream str(argv[3]); //converts to int
      str >> file1;
      //istringstream file1(argv[3]); //converts to int
      outputFile = argv[4];

      v.extract(file1, outputFile);
      
   } else if (argc == 6){
      cout << "Difference map...\n";
      option = argv[2];
      
      stringstream str(argv[3]); //converts to int
      str >> file1;
      
      stringstream str1(argv[4]); //converts to int
      str1 >> file2;
      
      //istringstream file1(argv[3]);
      //istringstream file2(argv[4]);
      outputFile = argv[5];
      
      v.diffmap(file1, file2, outputFile);
      
   }
        


   
   
   return 0; 

}