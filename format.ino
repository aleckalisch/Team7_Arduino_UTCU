//this file will be the format function of the tcu
//assuming that it would be a void function
//Aux data is 64 bits total
//baisc data is 32 total
//first twelve is ignore
// Includes files
#include <stdlib.h>
#include <cstdint>
#include <string>
#include <ostream>
#include <iostream>
using namespace std;

void format_func();

const int totalBits_ID = 6;
int data_word =0;
int data_bit =0;
const int maxData = 32;  // aux data. Hold 32 bits total
const int maxAux = 72;   // basic data. holds 72 bits total
const int maxRaw = 60;

bool basic_data[maxData] = { 0 };  // basic data. holds 32 bits total
bool aux_data[maxAux] = { 0 };     // aux data. Hold 72 bits total



short antennaType[totalBits_ID] = { 0 };  // global antenna type
int raw_data[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
const int bdw1[] = {1,0,1,1,1,1,0,0,1,1,1,0,0,1,0,1,1,1,1,1};
const int bdw2[] = {1,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,0,1,0,0};
const int bdw3[] = {1,1,1,0,0,1,0,1,1,0,1,0,1,1,0,1,1,0,0,0};
const int bdw4[] = {1,1,1,1,0,0,1,0,1,1,1,0,0,1,0,1,0,1,0,1};
const int bdw5[] = {0,1,1,1,0,0,1,1,0,1,1,0,1,0,0,1,1,0,1,0};
const int bdw6[] = {1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0};
const int ad1[] = {0,0,0,0,1,1,1,1,1,0,0,1,1,0,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1,0,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,0,0};
void format_func() {
    // Set the databit to the "data bit" which is atenna type's 2 bool element
    bool dataBit = antennaType[1];

    // if data_word equals 1 then the data gets placed into the basic data array
    if (dataBit) {

        for (int i = 0; i < 20; i++) {
            raw_data[i] = basic_data[i];
        }

        for (int i = 20; i < maxData; i++) {
            basic_data[i] = bdw1[i];
        }
    }

    // if data_word equals 0 then the data gets placed into the aux data array
    else {

        for (int i = 0; i < maxRaw; i++) {
            raw_data[i] = aux_data[i];
        }

        for (int i = maxRaw; i < maxAux; i++) {
            aux_data[i] = ad1[i];
        }
    }
}

int main()
{
    format_func();
    
    for(int i = 0; i < maxAux; i++)
    {
     cout << aux_data[i] << endl;   
    }
    return 0;
}
