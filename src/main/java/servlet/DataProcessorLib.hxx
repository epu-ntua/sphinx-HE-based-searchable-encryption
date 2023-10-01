/**
	Tech Inspire LTD
	DataProcessorLib.hxx
	Purpose: Calculates the total of 6 checks
	@author Indranil Ghosh Ray
	@version 1.1 21/02/18
*/

#ifndef DPL
#define DPL
#endif

#include"openssl/sha.h"
#include "openssl/bn.h"
#include"openssl/hmac.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<list>
#include<dirent.h>
#include<vector>
#include <sys/types.h>

#ifndef SNL
#include "SearchingLib.hxx"
#endif

#ifndef ENL
#include "EncryptionLib.hxx"
#endif

//#ifndef TRL
//#include "TrapdoorLib.hxx"
//#endif
#define NOF 2

using namespace std;

class DataProcessorLib {

	//friend class TrapdoorLib;
public:
	/**
		Function Name: ReadFile
		Input param  : null;
		Output param : on successful execution, it returns true else false;
		Purpose: reads the file and prepares keywords for PEKS;
		@author Indranil Ghosh Ray.
		@version 1.1 21/02/18.
	*/
	bool EncryptFile(BilinearPairing bp, string fp, string ep);
	bool DecryptFile(BilinearPairing bp, string dp, string ep, int* efp, int epflen,char* query);
	bool Search(BilinearPairing bp, list<int>& fplist, char* query, string ep);
	bool SearchWithTrapdoor(BilinearPairing bp, list<int>& fplist, string path, string ep);
	bool ReadFilesInFolder();
	bool ReadAllBytes(const char* filename, int* read, unsigned char** pChars);
	bool ReadAllStrings(const char* filename, int* read, char** pChars);
};
//#endif


bool DataProcessorLib::ReadFilesInFolder()
{
	DIR* dir;
	struct dirent* ent;
	if ((dir = opendir("c:\\src\\")) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL) {
			//printf("%s\n", ent->d_name);
		}
		closedir(dir);
	}
	else {
		/* could not open directory */
		perror("");
		return EXIT_FAILURE;
	}
	return true;
}



bool DataProcessorLib::SearchWithTrapdoor(BilinearPairing bp, list<int>& fplist, string path, string ep)
{
	bool bRetVal = false;
	int lenq = -1;
	string  tr1[10];
	BIGNUM* tr2[10] = { NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL };
	bp.ReadTrapdoorFromFile(path.c_str(), tr1, tr2, lenq);

	//return true;
	//cout << lenq << "\nTrapdoors are : \n";
	for (int i = 0; i <= lenq; i++)
	{
		//cout << "tr1=" << tr1[i] << endl;
		//cout << "tr2=" << BN_bn2dec(tr2[i]) << "\n==================\n";
	}

	SearchingLib sl;
	//cout << "\nSearching ...";
	// searching in files
	for (int i = 1; i <= NOF; i++)
	{
		//cout<<".";
		const int j = i;
		std::ostringstream s;
		s << j;
		const std::string no(s.str());
		std::string encP = ep + "e" + no;//"/home/indranil/FORTIKA/encryptedData/e" + no;
		encP = encP + ".txt";

		//string encP = "/home/indranil/FORTIKA/encryptedData/e1.txt";
		//cout<<"\n searching " << i <<"th FILE \n==================================\n";
		bRetVal = sl.search(encP, bp._key, tr1, tr2, lenq);

		if (bRetVal)
		{
			fplist.push_front(i);
		}
	}
	return bRetVal;
}






bool DataProcessorLib::Search(BilinearPairing bp, list<int>& fplist, char* query, string pathT)
{

	string name1[20];
	string namex[20];
	char name2[100];
	char name3[]=".txt";
	char *ref;
	char name4[]="e_AES";
	char *ref2;


	struct dirent* de;  // Pointer for directory entry 

	// opendir() returns a pointer of DIR type.  
	DIR* dr2 = opendir("/usr/local/encrypteddata/");

	if (dr2 == NULL)  // opendir returns NULL if couldn't open directory 
	{
	//	printf("Could not open current directory");
		return 0;
	}
	int k = 0;
	while ((de = readdir(dr2)) != NULL)
	{

	printf("%s name yahan a raha hai\n", de->d_name);
		namex[k] = de->d_name;
		
		strcpy(name2,namex[k].c_str());
		ref=strstr(name2,name3);
		ref2=strstr(name2,name4);
		if(ref != NULL && ref2 == NULL){
			name1[k]=de->d_name;
			cout<<"\n searching in name loop "<<name1[k] << "\n";
			k = k + 1;
			
		}
	}
	cout<<"\n total files are "<<k;
	//cout << "total num of names " << k - 2;
	//cout << "\n name1 " << name1[ 2];
	//cout << "\n name1 " << name1[ 3];
	//cout << "\n name1 " << name1[ 4];



	closedir(dr2);

   char char_array[30];



	bool bRetVal = false;
	//cout << "This is the search querry" << query << "\n";
	//cout << "This is the path" << pathT << "\n";
	//BilinearPairing bp;
	//string query;//char query[100];
	//cout<<"enter the search query\n";
	//getline(cin,query);//scanf("%s",query);
	//string qw(query);
	//cout<<"kJHEJKSHDKJSHDJKdhCKJcvHD";
	string  tr1[10];
	BIGNUM* tr2[10] = { NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL };
	int lenq = 0;

	bp.GetTrapdoorQuery(query, bp._key, tr1, tr2, lenq);//, pairing_t _pairing, ECCKey key);
	//cout << lenq << "\nTrapdoors are : \n";
	for (int i = 0; i <= lenq; i++)
	{
		//cout << BN_bn2dec(tr2[i]) << "\n==================\n";
	}

	SearchingLib sl;
//	cout << "\nSearching ...";
	// searching in files
	//for (int i = 1; i <= k/2; i++)
		for (int i = 0; i <= k; i++)
	{
		//	int n = 5;
//	string s = "geeksforgeeks";

//	n = s.length();
//	//cout << "\n n is " << n;
	// declaring character array 
//	char char_array[30];

	// copying the contents of the 
	// string to char array 
	strcpy(char_array, name1[i].c_str());

//	for (int i = 0; i < n; i++)
//		cout << char_array[i];
		if(char_array[0]== 'e' && char_array[2] != 'A' && char_array[3] != 'E'){
		//cout<<".";
		const int j = i;
		std::ostringstream s;
		s << j;
		const std::string no(s.str());
		//std::string encP = pathT + "e" + no;//"/home/indranil/FORTIKA/encryptedData/e" + no;
		//encP = encP + ".txt";
		std::string encP = pathT + name1[i];//"/home/indranil/FORTIKA/encryptedData/e" + no;

cout<<"\n yeh search k ander a k name hai "<<name1[i];
		//string encP = "/home/indranil/FORTIKA/encryptedData/e1.txt";
		//cout<<"\n searching " << i <<"th FILE \n==================================\n";
		bRetVal = sl.search(encP, bp._key, tr1, tr2, lenq);

		if (bRetVal)
		{
			fplist.push_front(i);  // yeh pehlay i that khali
		}
	}
	}
	return bRetVal;

	/*
	bool bRetVal = false;
	string  tr11[10];
	BIGNUM* tr22[10]= {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int lenq = 0;
	cout<<"search function k ander a raha hai ";
	bp.GetTrapdoorQuery(query, bp._key, tr11, tr22, lenq);//, pairing_t _pairing, ECCKey key);


	bp.WriteTrapdoorToFile(pathT,tr11, tr22,lenq);

		return bRetVal;*/   // yeh waqar nay band kia hai takay search locally ho sakay
}



bool DataProcessorLib::ReadAllStrings(const char* filename, int* read, char** pChars)
{

	bool fl = false;
	std::ifstream t;
	int length;
	t.open(filename);      // open input file
	t.seekg(0, std::ios::end);    // go to the end
	length = t.tellg();           // report location (this is the length)
	t.seekg(0, std::ios::beg);    // go back to the beginning
	*pChars = new char[length];    // allocate memory for a buffer of appropriate dimension
	*read = length;
	t.read(*pChars, length);       // read the whole file into the buffer
	t.close();
	return fl;

}

bool DataProcessorLib::ReadAllBytes(const char* filename, int* read, unsigned char** pChars)
{
	bool fl = false;
	//ifstream ifs(filename, ios::binary|ios::ate);
	ifstream ifs;
	ifs.open(filename, std::ios::binary);
	//ifstream ifs(filename, ios::binary|ios::in| ios::app);
	//ifstream::pos_type pos = ifs.tellg();

	//get the length of the file

	ifs.seekg(0, std::ios::end);

	size_t fileSize = ifs.tellg();

	ifs.seekg(0, std::ios::beg);

	//cout << "filesize ====  " << fileSize << endl;
	//ofstream output;
	//output.open( AESdecryptedFilePath.c_str());//, ios::binary | ios::out | ios::app );
 //fileSize =16176; 
 //int length = static_cast<int>(fileSize);
 //std::vector< char> bytedata(fileSize,0);

	*pChars = new unsigned char[fileSize];

	//ifs.read(static_cast<char*> (&bytedata[0]), fileSize);
	ifs.read(reinterpret_cast<char*> (*pChars), fileSize);
	ifs.close();

	//cout<<"reading done. size = ";//<<bytedata.size()<<endl;// << temp.size();
	//std::vector<unsigned char> temp = std::vector<unsigned char>(bytedata.begin(), bytedata.end());

	//cout<<"tempsize = " << temp.size();
	//if(*pChars !=0)
	//{
	//    delete [] (*pChars);*pChars = 0;
	//}
	//*pChars = new unsigned char[fileSize];

	//for(int i=0;i<bytedata.size();i++)
	//{

			//*pChars[i] = static_cast<unsigned char>(bytedata[i]);

	//}

	* read = fileSize;
	fl = true;
	return fl;

}


bool DataProcessorLib::DecryptFile(BilinearPairing bp, string dp, string ep, int* efp, int epflen,char* query) {

    string name1[20];
    string filename;

    struct dirent* de;  // Pointer for directory entry

    // opendir() returns a pointer of DIR type.
    DIR* dr1 = opendir("/usr/local/encrypteddata/");

    if (dr1 == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory");
        return 0;
    }
    int k = 0;
    while ((de = readdir(dr1)) != NULL)
    {
        if(strcmp(de->d_name, query)==0){
        //printf("%s\n", de->d_name);
            filename = de->d_name;
            cout<<"\n filename yeh hai "<<filename;
        }
        k = k + 1;
    }




    closedir(dr1);




/*
    string name1[20];

 //   struct dirent* de;  // Pointer for directory entry
    int quack=0;
    string eelement;

    FILE *fp1;
       char str[MAXCHAR];
       char* filename = "/Users/waqarasif/Documents/Sphinx/codebase/He-tool-Sphinx/He-tool-test/encrypteddata/ipaddress.txt";

       fp1 = fopen(filename, "r");
       if (fp1 != NULL){
           printf("\n Could open file %s",filename);


    int jil=0;
           strcat(query, "\n");
       while (fgets(str, MAXCHAR, fp1) != NULL)
       {
           cout<<"\n str ki value yeh hai "<<str <<" cmp it with "<<query;
           if(strcmp(str,query)==0){
               quack=jil;
               cout<<"\n yeh index hai "<<quack;
           }
          // ip[jil]=atoi(str);
         //  cout<<"\n element ki value yeh hai"<<eelement;
           jil=jil+1;
       }
       fclose(fp1);
       }



    FILE *fp2;

       char* filename2 = "/Users/waqarasif/Documents/Sphinx/codebase/He-tool-Sphinx/He-tool-test/encrypteddata/e_AES_fileall";

       fp2 = fopen(filename2, "r");
       if (fp2 != NULL){
           printf("\n Could open file %s",filename2);


    int jil2=0;
       while (fgets(str, MAXCHAR, fp2) != NULL)
       {

           if(jil2==quack){
               eelement=str;
                cout<<"\n element ki value yeh hai"<<eelement;
           }
          // ip[jil]=atoi(str);

           jil2=jil2+1;
       }
       fclose(fp2);
       }
*/

    int ciphertext_len;
       unsigned char* ciphertext = 0;
       //std::list<int>::const_iterator iterator;
       cout << "\nyahan a raha hai \n";
       cout << "yeh location hai \n" + dp + "\n " + ep + "\n";


//    int ciphertext_len=strlen(eelement.c_str());
//    unsigned char* ciphertext= (unsigned char*)eelement.c_str();
    string file = ep + filename; // yeh main nay kia hai waqar
           //string file = ep + "e_AES" + std::to_string(kit) + ".txt";
           cout << "file tobe decrypted :" + file + "\n";
           ReadAllBytes((const char*)file.c_str(), &ciphertext_len, &ciphertext);
           cout << "Encrypted file reading  length = " << ciphertext_len << "\n";
           printf("encrypted cipher = \n %s ", (char*)ciphertext);


        unsigned char* plaintext = new unsigned char[ciphertext_len * 2];

        int plaintextLen = bp.AESdecrypt((unsigned char*)ciphertext, ciphertext_len,
            (unsigned char*)bp._key.AES_k.c_str(), (unsigned char*)bp._key.AES_iv.c_str(), plaintext);
        plaintext[plaintextLen] = '\0';
    cout<<"length is  "<<plaintextLen;
        printf("decrypted text = \n\n %s\n", plaintext);

    std::string AESdecryptedFilePath = dp + filename;
    //std::string AESdecryptedFilePath = dp + std::to_string(kit) + ".txt";
    cout << "file tobe decrypted :" + AESdecryptedFilePath;

    ofstream output;
    output.open(AESdecryptedFilePath.c_str());//, ios::binary | ios::out | ios::app );
     //output.write( ( char * )&plaintext, plaintextLen);

    output << plaintext;
    output.close();
    delete[] plaintext; plaintext = 0;
    delete[] ciphertext; ciphertext = 0;

    return 0;

}

bool DataProcessorLib::EncryptFile(BilinearPairing bp, string fp, string ep) {
	bool bRetVal = true;
	string line;
	string name1[20];
	string namex[20];
	char name2[100];
	char name3[]=".txt";
	char *ref;
	
	struct dirent* de;  // Pointer for directory entry 

	// opendir() returns a pointer of DIR type.  
	DIR* dr = opendir("/usr/local/textdata/");

	if (dr == NULL)  // opendir returns NULL if couldn't open directory 
	{
		printf("Could not open current directory");
		return 0;
	}
	int k = 0;
	while ((de = readdir(dr)) != NULL)
	{
		
		printf("%s\n", de->d_name);
		namex[k] = de->d_name;
		
		strcpy(name2,namex[k].c_str());
		ref=strstr(name2,name3);
		if(ref != NULL){
			name1[k]=de->d_name;
			k = k + 1;
		}
		
	}
	cout << "total num of names " << k;
	//cout << "\n name1 " << name1[2];
	//cout << "\n name1 " << name1[3];
	//cout << "\n name1 " << name1[4];



	closedir(dr);
	

	// cout << "yahan a raha hai ++++++";
	// cout << "yeh strins hain" + fp + " yeh doosri hai  " + ep;
	 //BilinearPairing bp;
	 //bp.KeyGen(512,"/home/indranil/FORTIKA/KeyStore/key.txt"); 
	 //bp.ReadKey("/home/indranil/FORTIKA/KeyStore/key.txt"); 
	 //bp.PrintKey();

	 /*
	 string query;//char query[100];
	 cout<<"enter the search query\n";
	 getline(cin,query);//scanf("%s",query);
	 //string qw(query);
	 element_t  trList[10];
	 int lenq = 0;
	 bp.GetTrapdoorQuery(query, bp._key, trList, lenq);//, pairing_t _pairing, ECCKey key);
	 cout<<"\nTrapdoors are : \n";
	 for(int i = 0; i< lenq;i++)
	 {
		 element_printf("\n\n _Tr[%d]  : \n\n%B\n",i,trList[i]);
	 }

	  SearchingLib sl;
	  string encP = "/home/indranil/FORTIKA/encryptedData/e1.txt";
	  sl.search(encP,bp. _key, trList,lenq);
	  */
	  // Encryption of files
	  //iteration through files
	  //for (int i = 1; i <= NOF; i++)  /// yeh sahe kerna hai multiple  files read kernay k liay
	for (int i = 0; i < k; i++)
	{
		//cout << "\n name is "<<fp+ name1[i+1];
		//const int j = i;
		//std::ostringstream s;
		//s << j;
		//const std::string no(s.str());



		//std::string filePath = "/home/indranil/Desktop/Docs/eng/" + no;
		//string filePath = fp + no;
		string filePath = fp + name1[i];
		//std::string encryptedFilePath = "/home/indranil/FORTIKA/encryptedData/e" + no;
		//std::string encryptedFilePath = ep + "e" + no;
		std::string encryptedFilePath = ep + "e" + name1[i];
		//filePath = filePath + ".txt";

		 cout << "yeh file hai " + filePath;


		//AES encryption 
		int plaintext_len;
		char* plaintext = 0;
		ReadAllStrings((const char*)filePath.c_str(), &plaintext_len, &plaintext);
		printf("Plain text is:\n");
		printf("%s\n", plaintext);
		//cout << "length of plain text = " << plaintext_len << endl;
		unsigned char* ciphertext = new unsigned char[plaintext_len + 100];
		int cipherLen = bp.AESencrypt((unsigned char*)plaintext, plaintext_len,
			(unsigned char*)bp._key.AES_k.c_str(), (unsigned char*)bp._key.AES_iv.c_str(), ciphertext);

		cout << "Encrypted array length = " << cipherLen << endl;

		unsigned char* exactcipher = new unsigned char[cipherLen];
		memcpy(exactcipher, ciphertext, cipherLen);
		//   printf("encrypted cipher = \n %s ", (char*)exactcipher);
		std::string AESencryptedFilePath = ep + "e_AES" + name1[i];
		ofstream output;
		output.open(AESencryptedFilePath.c_str(), ios_base::binary);
		//ofstream output << cipher( AESencryptedFilePath.c_str(), ios::binary | ios::out | ios::app );
		output.write(reinterpret_cast<char*>(exactcipher), cipherLen);
		delete[] ciphertext; ciphertext = 0;
		delete[] exactcipher; exactcipher = 0;
		delete[] plaintext; plaintext = 0;
		output.close();

		//encryptedFilePath = encryptedFilePath + ".txt";
		ofstream outEncFile;
		outEncFile.open(encryptedFilePath.c_str());
		ifstream myfile(filePath.c_str());
		int pPointer = 1;

		////// yeh dala hai ///
	   // cout<<"yahan a raha hai ++++ get " +filePath;

		///////////////////////
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				//cout << "****tet yeh hai *******=";

			  //  cout<<" line ------ =" << line<<endl;
				istringstream iss(line);
				string word;
				//     cout<<"\n wrds --*************---- =\n";// << word;
		             do{
					 //	cout << "****tet yeh hai *******=";
						 //string subs;
				iss >> word;//subs;
				if (word[word.length() - 1] == ' ' || word[word.length() - 1] == '\b' || word[word.length() - 1] == '.' ||
					word[word.length() - 1] == ',')
				{
					//cout<<"\nyessssssssssssssssssssss\n";
					word = word.substr(0, word.length() - 1);

				}

				if (word[0] == ' ' || word[0] == '\b')
				{
					//cout<<"\nyessssssssssssssssssssss\n";
					word = word.substr(1, word.length() - 1);

				}

				// cout<<"\n " << word;

				string A, B;
				//      cout<<"\n["<<word<<"," << pPointer<<"]\n";
				bp.PEKSEncrypt(word, pPointer, A, B);
				pPointer = pPointer + 1;
				outEncFile << A << endl;
				outEncFile << B << endl;
				//   cout<<"\n " << B;
				   //break;
	          }
	          while(iss);
			   // to get the word out of the line


			   // to encrypt the word
			   //cout<<"word = " << word<< "\nEncrypted form = [A: " <<A<<"\n B: "<<B<<" ]\n"; 

			   // to write the data in file

			   //outEncFile << A << endl;
			   //outEncFile << B << endl;



			   //mpz_t aBig;
			   //mpz_init(aBig);
			   //bp.HMAC(word,aBig);
			   //cout << word << " is : ";
			   //gmp_printf ("%Zd\n", aBig);

			}
			//  cout<<"encryption length of file  = "<<NOF<<" is "<< pPointer;
			myfile.close();
			outEncFile.close();
			//cout << "yahan a gaya endof filer per";
		}
		else
		{
			bRetVal = false;
			//cout << "Unable to open file";
		}
	}
	// cout << "yeh b a raha hai ";
	return bRetVal;
}

