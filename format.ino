//this file will be the format function of the tcu
//assuming that it would be a void function
//Aux data is 64 bits total
//baisc data is 32 total
//first twelve is ignore
#include <stdlib.h>

void format_func(int8_t ad,int8_t bd);

int8_t basic_Data[4];//basic data. holds 32 bits total
int8_t Aux_data[8];//Aux data. Hold 72 bits total

int data_word =0;

//Aux_data[1] = 
//3. 100x10 to
//4. 100x00 wait
//5.100x11 fro

void format_func(int8_t ad,int8_t bd)
{
    if(data_word == 0)//if data_word equals 0 then the data gets placed into the aux data array
    {
        for(int i =0; i < 8; i++)
        {
            if(!Aux_data[i])
            {
                Aux_data[i]=ad;   
            }
           else 
           return;
        }
    }
    else if(data_word ==1)//if data_word equals 1 then the data gets placed into the basic data array
    {
        for(int i =0; i < 4; i++)
        {
            if(!basic_data[i])
            {
                basic_data[i]=bd;    
            }
           else 
           return;
        }
       basic_data[i]=bd; 
    }
    else 
    return ;
}



