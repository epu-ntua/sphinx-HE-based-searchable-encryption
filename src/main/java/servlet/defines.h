/*
 * Tests for the implementation of AES Algorithm for an FPGA.
 * Author: Dimitris Apostolakis, Future Inteligence Ltd.
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#include <fstream>
#include <sstream>
#include <string>
#include <cerrno>
#include <stdio.h>
#include <chrono>
#include <bits/stdc++.h> 
#include <algorithm>
#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>

#define NUM_OF_MODULES 1
#define NUM_OF_FIFOS_PER_MODULE 6

// Directory of all FIFOS of all modules
#define FIFOS "/usr/local/dev/fifos"

#define MODULE0_PATH "/usr/local/dev/fifos/module_0"

const char *fifo_paths_0[NUM_OF_FIFOS_PER_MODULE] =
{
MODULE0_PATH"/message_Size",	// client writes the size of the message he is about to send to hardware in Bytes
MODULE0_PATH"/messageFifo",	// client writes his message
MODULE0_PATH"/param_Size",	// client writes the size of the parameters he is about to send to hardware in Bytes
MODULE0_PATH"/paramFifo",	// client writes the parameters in this FIFO
MODULE0_PATH"/result_Size",	// server writes the size of the message that client expects to receive from hardware in Bytes
MODULE0_PATH"/resultFifo"	// server writes the message that client expects to receive from hardware
};

// Paths to files used when Encrypt
#define plainText_path "data.txt"
#define encryptedText_path "data_encrypt.txt"

// Paths to files used when Decrypt
#define cipherText_path "data_encrypt.txt"
#define decryptedText_path "data_decrypt.txt"


#define inputKey_maxLength 32	// max length for AES 256

struct pipes_data {
	int inSize;
	uint32_t *inFifoMessage;
	int paramSize;
	uint32_t *paramFifoMessage;
	int outSize;
	uint32_t *outFifoMessage;
};

#endif
