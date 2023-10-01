/**
    Tech Inspire LTD
    DataProcessorLib.hxx
    Purpose: Calculates the total of 6 checks
    @author Indranil Ghosh Ray
    @version 1.1 21/02/18
*/


#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<list>
#include<dirent.h>
#include<vector>
#include <sys/types.h>

#ifndef ENL
#include"EncryptionLib.hxx"
#endif

#ifndef TRL
//#include"TrapdoorLib.hxx"
#endif

#ifndef DPL 
#include"DataProcessorLib.hxx"
#endif
#include<string>
#include "main_java_servlet_TechLib.h"
using namespace std;

//string techHELib(int ch_java, string data_java)
JNIEXPORT jstring JNICALL Java_main_java_servlet_TechLib_techHELib
  (JNIEnv *env, jobject jobj, jint ji, jstring jstr)

{

const char* searchName = env->GetStringUTFChars(jstr, NULL);
string bRetStr = "";
std::stringstream buffer;

int ch =  (int) ji;
 BilinearPairing bp;
 DataProcessorLib dpl;
 std::list<int>::const_iterator iterator;
 bool bTrue = false;//dpl.Search(bp,fPointers); 
 list<int> fPointers;
 int fpary[100];
 int fparyLen = -1;
 string  query;//("Duster Lies And");
 char qq[100];
 char sp;

 string fPath;
 string kPath;
 string ePath;
 string dPath;
 string pathA = "/usr/local/keystore/SetGlobalPath.txt";
 string pathT = "/usr/local/trapdoor/trapdoor.txt";
 ifstream myfileA (pathA.c_str());
 string line;
 int p = 1;

 if (myfileA.is_open())
 {
     while( getline (myfileA,line) ){
        if(p == 1)
        {
            kPath = line.substr(0,line.length());
            ////cout<<kPath<<endl;
        }

        if(p == 2)
        {
            fPath = line.substr(0,line.length());
            ////cout<<ePath<<endl;
        }
        if(p == 3)
        {
            ePath = line.substr(0,line.length());
            ////cout<<ePath<<endl;
        }
        if(p == 4)
        {
            dPath = line.substr(0,line.length());
            ////cout<<dPath<<endl;
        }
        p++;
     
     }
 }
            cout<< "inp = "<< pathA<<endl;
            cout<<"kPath = "<< kPath<<endl;
            cout<<"fPath = "<< fPath<<endl;
            cout<<"epath = "<< ePath<<endl;
            cout<<"dpath = "<< dPath<<endl;
			
			
			string name1[20];
			char name2[100];
			char name3[100];
			
			string namex[20];
			char name21[100];
			char name31[]=".txt";
			char name41[]="e_AES";
			char *ref;
			char *ref2;

	struct dirent* de;  // Pointer for directory entry 

	// opendir() returns a pointer of DIR type.  
	DIR* dr1 = opendir("/usr/local/encrypteddata");

	int k = 0;
	while ((de = readdir(dr1)) != NULL)
	{

	namex[k] = de->d_name;
		
		strcpy(name21,namex[k].c_str());
		ref=strstr(name21,name31);
		ref2=strstr(name21,name41);
		if(ref != NULL && ref2 == NULL){
			name1[k]=de->d_name;
			k = k + 1;
		}
	}
//	cout << "total num of names " << k - 2;
//	cout << "\n name1 " << name1[k / 2 + 1];
//	cout << "\n name1 " << name1[(k / 2) + 2];
//	cout << "\n name1 " << name1[(k / 2) + 3];



	closedir(dr1);

			
			
			
			
int ind = 0;
//////cout<<" ch == "<< ch<<endl;
     switch(ch)
     {
         
         case 1:    // Encrypt
                    bp.ReadPrivateKey(kPath);
                    bp.ReadPublicKey(kPath); 
                    bTrue = dpl.EncryptFile(bp,fPath,ePath); 
                    break;
     
         
         
         
         
         case 2:  //search

                    bp.ReadPrivateKey(kPath);
                    bp.ReadPublicKey(kPath); 
                    //////cout<<"search name is " <<(char*)searchName;
                    bTrue = dpl.Search(bp,fPointers,(char*)searchName,ePath);//pathT); 
                    //bTrue = dpl.Search(bp,fPointers,(char*)" ",pathT);
                    
					cout<<"\nbTrue ki value = "<< bTrue ;
					
					//cout<<"\n fpointer begin ki value "<<fPointers.begin()<< "\n fpointer end ki value "<<fPointers.end();
                    if(bTrue){
                        //////cout<<"\n FILE EXIST \n\n File pointers are :[ ";
                    }
                    //std::list<int>::const_iterator iterator;
                    ind = 0;
					////////cout<<"yeh length hai " << fPointers.length;
					//int num=0;
                    for (iterator = fPointers.begin(); iterator != fPointers.end(); ++iterator) {
                        fpary[ind] = *iterator;
						//////cout<<"ind" <<ind ;
                        ind++;
                       // std::cout << name1[fpary[ind - 1]+1]<<", ";
					  //  std::cout << name1[*iterator]<<", ";
                      //  buffer << *iterator<< ", ";
					//buffer << name1[fpary[ind - 1]+1]<< ", ";
					cout<<" \n print name yeh hai "<<name1[*iterator].c_str();
					strcpy(name2,name1[*iterator].c_str());
					name3[0]='e';
					name3[1]='_';
					name3[2]='A';
					name3[3]='E';
					name3[4]='S';
					for(int rl=1;rl<name1[*iterator].length();rl++){
						name3[4+rl]=name2[rl];
					}
					//////
name3[4+name1[*iterator].length()]='\0';
					buffer << name3<< ", ";
					//buffer =buffer + name1[fpary[ind - 1]+1]<< ", ";
                    }
                    fparyLen = ind;
                    //////cout<<" ]";
                    fPointers.clear();
                    bRetStr = bRetStr + buffer.str();
                    
                    break;
 
          case 3:  //decrypt
                    
                    bp.ReadPrivateKey(kPath);
                    bp.ReadPublicKey(kPath); 
                   //char* fName = env->GetStringUTFChars(jstr, NULL); 
                 //  fpary[0] = std::stoi( searchName );
		 //  //////cout<<"fp = "<< fpary[0]<<endl;
                   fparyLen = 1;
		   string dwd = "/usr/local/downloadeddata/";
                   bTrue =  dpl.DecryptFile(bp, dPath, ePath, fpary, fparyLen,(char*)searchName);
                   if (bTrue){
                	   bRetStr="success";
                   }
                   break;
         //case :default  //////cout<<"\nPress right option\n\n";
           //    break;

         //case 4: 
                  //fPointers.clear();
         //         exit(0);
         //default: //////cout<<"\nYou pressed wrong option\n";
     }
     //fPointers.clear();
     ////////cout<<"\nPress any key to continue ..";
     //cin>> sp;
     //system("clear");
      
      const char* chAry = (const char*) bRetStr.c_str();
      jstring resultStr = (*env).NewStringUTF(chAry);
      return resultStr;
 }

 
 
 //////cout<<"\n\n c++ covering done\n\n";
 //return 0;



/*
int main()
{
    techHELib();
    return 0;
}*/

