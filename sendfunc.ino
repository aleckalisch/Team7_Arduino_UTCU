#include <stdlib.h>
// SEND DATA IMPLEMENTATION FOR UTCU; SP2023
// Some don't care states are marked with a '0' instead of an 'X' due to the short data type not allowing use of X's

int totalBits = 7;
short antennaType[totalBits]; // global antenna type
String stateType; // global state type declaration
//declaration of all required UTCU states below: 
String allStates[totalBits] = {"NoData", "TakeData", "To", "Wait", "Fro"}; // declaration of all antenna states
short stateReset[totalBits] = {1, 0, 1, 0, 0, 0, 0}; // declaration of Reset state; last 4 bits are don't care
short stateNoData[totalBits] = {0, 0, 0, 0, 1, 0, 0}; // declaration of NoData state; last 2 bits are don't care 
short stateTakeData[totalBits] = {0, 0, 0, 1, 1, 0, 0}; // declaration of TakeData state; last 2 bits are don't care
short stateTo[totalBits] = {1, 0, 0, 0, 1, 0, 0}; // declaration of To state; 4th and last 2 bits are don't caare
short stateWait[totalBit] = {1, 0, 0, 0, 0, 0, 0}; // declaration of Wait state; 4th and last 2 bits are don't care
short stateFro[totalBits] = {1, 0, 0, 0, 1, 0, 0}; // declaration of Fro state; 4th and last 2 bits are don't care
unsigned long startMicros;  //starting value of time in microseconds
unsigned long currentMicros; // current value of elasped time in microseconds
const unsigned long sequenceTime = 615;  //total time given from shift to one function to another
const unsigned long bitReadTime = 64; //total time to read each sent bit

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  startMicros = micros();
  for (int i = 0; i < totalBits; i++){
    antennaType[i] = stateReset[i]; // antennaType is set to reset at beginning to accept states later on
  }
}

void loop() {
  // will run continuously, even out of scope:
  currentMicros = micros();
  sendData();
  //return; // took out return, will likely run infinitely; uncomment to run finitely
}

void sendData(){ // function made to check for elasped time to determine if antennaType is set to reset + if antennaType is set to every listed state
  if (currentMicros - startMicros >= sequenceTime) { // cond. for 615ms check
    for (int i = 0; i < totalBits; i++){
      antennaType[i] = stateReset[i]; // antennaType will be converted to state reset once time exceeds 615 ms
      return;
    }
  }
  else {
    for (int i = 0; i < 5; i++){ // for loop that will run through each listed state while checking total time doesn't proceed 64ms
      stateType = allStates[i];
        for (int i = 0; i < totalBits; i++){
            if (stateType == allStates[0] && currentMicros - startMicros >= bitReadTime){
              antennaType[i] = stateNoData[i]; //antennaType set to sending no data
            }
            else if (stateType == allStates[1] && currentMicros - startMicros >= bitReadTime){
              antenneType[i] = stateTakeData[i]; // antennaType set to take in data
            }
            else if (stateType == allStates[2] && currentMicros - startMicros >= bitReadTime){
              antennaType[i] = stateTo[i]; // antennaType set to "To" scan
            }
            else if (stateType == allStates[3] && currentMicros - startMicros >= bitReadTime){
              antennaType[i] = stateWait[i]; // antennaType set to pause scanning
            }
            else if (stateType == allStates[4] && currentMicros - startMicros >= bitReadTime){
              antennaType[i] = stateFro[i]; // antennaType set to "Fro" scan
            }
        }
    }
  }
  sendData();
  

}
