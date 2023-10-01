
/**
    Tech Inspire LTD
    DataProcessorLib.hxx
    Purpose: Calculates the total of 6 checks
    @author Indranil Ghosh Ray
    @version 1.1 21/02/18
*/

#ifndef SNL
#define SNL
#endif

#include<stdio.h>
#include<iostream>
#include"openssl/sha.h"
#include"openssl/hmac.h"
#include<string.h>
#include <openssl/bn.h>
//#include <string>
#include <sstream>
#include<fstream>

#ifndef KEY_DEF
#include"ECCKey.h"
#endif


using namespace std;

class SearchingLib{

public:

 SearchingLib(){}
 bool search(string filePath, ECCKey _key, string tr1[], BIGNUM* tr2[], int len );
 void HMACE2S(char str[], string& out, string k,ECCKey _key);

};


 
 
 bool SearchingLib::search(string filePath, ECCKey _key, string tr1[], BIGNUM* tr2[], int len )
 {

    bool bRetVal = false;
    string line; 
    string aStr;
    bool bFound = false;
    bool bFinalBool = false;
    ifstream efile (filePath.c_str());
    int pPointer = 0;
    char* to=NULL; 
    BN_CTX *bn_ctx = BN_CTX_new();
    if (efile.is_open())
    {
        while( getline (efile,line) )
        {
            //cout<<"\nline =iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii\n";
            if(bFinalBool == true)
            {
                //cout<<"yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\n";
                break;
            }
            pPointer++;
            if(pPointer%2 == 1)
            {
                aStr = string(line.c_str());
                continue;
            }

            //////////////////////////////////////////////////////////
            // COMPUTE A _e1^pos, i.e.,  aComp = a._e1              //
            //////////////////////////////////////////////////////////
            
            //set position
            BIGNUM *bnP = BN_new();//NULL;
            //BN_dec2bn(&bnP, "2");
            string A;
            
            int ap = pPointer/2;
            BN_set_word(bnP, ap);

            //compute A
            HMACE2S((char*)tr1[0].c_str(),A,_key.k2, _key);
            //cout<<"search A = "<<A.c_str()<<endl; 
            BIGNUM *result1 = NULL;
            result1 = BN_new(); 
            BN_mod_exp(result1, tr2[0], bnP, _key.p, bn_ctx);
            //printf("pos = %d and B is %s\n", ap, BN_bn2dec(result1));
            char* to1 = BN_bn2dec(result1);
            //printf("B to bin is %s\n", to);
            string BSrch1;
            HMACE2S((char*)to1,BSrch1,_key.k2,_key);
            BN_free(result1);
            free(to1);
            BN_free(bnP);
            
            if(A.compare(aStr) == 0 && BSrch1.compare(line) == 0)
            {
                bFound = true;
            }
            
            if(bFound == true){
                //cout<<"\n\nhyrrey ...... pPointer = "<<ap<<endl;
                //cout<<"\n\nhyrrey ......  = len = "<<len<<endl;
                for(int np = 1;np<=len;np++)
                {
                    string line1;
                    getline(efile,line1);
                    pPointer++;
                    //
                    HMACE2S((char*)tr1[np].c_str(),A,_key.k2, _key);
                    //if(A.compare(line) == 0)
                    //{
                        //cout<<"\n\n jio kakaaaaaa " <<np<<endl;  
                    //}
                    //
                    getline(efile,line);
                    pPointer++;
                    ap = pPointer/2;
                    //BN_free(bnP);
                    BIGNUM* bnP1 = NULL;
                    bnP1 = BN_new();
                    BN_set_word(bnP1, ap);
                    //cout<<"\n   here ap = "<<ap<<endl; 
                    //////////////////////////////////////

                    // compute b
                    BIGNUM *result = NULL;
                    result = BN_new(); 
                    BN_mod_exp(result, tr2[np], bnP1, _key.p, bn_ctx);
                    //printf("B is %s\n", BN_bn2dec(result));
                    char* to = BN_bn2dec(result);
                    BN_free(result);
                    BN_free(bnP1);
                    
                    //printf("B to bin is %s\n", to);
                    string BSrch;
                    HMACE2S((char*)to,BSrch,_key.k2,_key);
                    free(to);
                    /////////////////////////////////////
                
                    //
                    if(!(A.compare(line1) == 0 && BSrch.compare(line) == 0))
                    {
                        bFound = false;
                        //cout<<"\n\n o hoo  noooo\n\n";
                        break;
                    }
                    //
                }
            
                if(bFound == true){
                    bFinalBool = true;
                    //cout<<"\n\nfinal match hyrrey ...... pPointer = "<<ap<<endl;
                    //fplist.push_front(  );
                    //break;
                }
                //
            }////
            //
        }
    }
    //
    bRetVal = bFinalBool;//Found;
    return bRetVal;

 }


  
  void SearchingLib::HMACE2S(char str[], string& out, string keystr, ECCKey _key)
  {

    //apply key
    char buf[2000];
    strcpy(buf,str);
    strcat(buf,keystr.c_str());
    
    //
    unsigned char digest[SHA512_DIGEST_LENGTH];
    SHA512_Init(&_key.ctx); // experimental
    SHA512_Update(&_key.ctx, buf, strlen(buf));
    SHA512_Final(digest, &_key.ctx);
    char mdString[SHA512_DIGEST_LENGTH*2+1];
    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++){
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    }

    string tmp(mdString);
    out = tmp;
  }

