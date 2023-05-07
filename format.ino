//this file will be the format function of the tcu
//assuming that it would be a void function
//Aux data is 64 bits total
//baisc data is 32 total
//first twelve is ignore
#include <stdlib.h>

void format_func(int8_t ad,int8_t bd);

bool basic_Data[64];//basic data. holds 32 bits total
bool Aux_data[72];//Aux data. Hold 72 bits total

int data_word =0;

//Aux_data[1] = 
//3. 100x10 to
//4. 100x00 wait
//5.100x11 fro

void format_func(int8_t ad,int8_t bd)
{
    if(data_word == 0)//if data_word equals 0 then the data gets placed into the aux data array
    {
        for(int i =0; i < 72; i++)
        {
           if(ad ==0)
           {
            Aux_data[i] = false;
           }
           else if(ad==1)
           {
            Aux_data[i] = true;
           }
        }
    }
    else if(data_word ==1)//if data_word equals 1 then the data gets placed into the basic data array
    {
        for(int i =0; i<64;i++)
        {
        if(bd == 0)
        {
            basic_Data[i] = false;
        }
        else if(bd == 1)
        {
            basic_Data[i] = true;
        }
        }
        
    }
    else 
    return ;
}



