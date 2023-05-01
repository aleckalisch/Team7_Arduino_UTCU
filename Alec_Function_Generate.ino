//this file contains the generate function for the TCU
// I am making a few assumptions that we might need to iron out, so bear with me
// Assumption 1: Global variables are allowed in Arduinos
// Assumption 2: We will be using Global Variables for the storage of function type as well as the actual data
// Assumption 3: there is a global variable for the barker code that is preset and cannot be modified
//function IDs were found in Annex 10 page 46
#include <stdlib.h>
char function_Type_name[] = "AZ"; //can also be EL, and BAZ
int8_t barker_code = 0b11101;
int8_t function_ID = 0b0000000;
int data_word = 0;
int8_t raw_data[8];

void generateData()
{
    if(function_Type_name == "AZ")
    {
        int8_t AZ_function = 0b0011001; //all function ID's are 7 bits
        function_ID = AZ_function; //stored in the first slot
    }
    else if(function_Type_name == "BAZ")
    {
        int8_t BAZ_function = 0b1001001; //all function ID's are 7 bits
        function_ID = BAZ_function; //stored in the first slot
    }
    else if(function_Type_name == "EL")
    {
        int8_t EL_function = 0b1100001; //all function ID's are 7 bits
        function_ID = EL_function; //stored in the first slot
    }
    if(data_word)
    {
        for(int i =0;i<3;i++){
            raw_data[i] = rand()%256;
        }
    }
    else{
        for(int i =0;i<8;i++){
            raw_data[i] = rand()%256;
        }
    }

}