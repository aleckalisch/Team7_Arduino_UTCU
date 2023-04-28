short int antennaType = 0b1010000; // global antenna type, initial state @ reset
unsigned long startMicros;  //starting value of time in microseconds
unsigned long currentMicros; // current value of elasped time in microseconds
const unsigned long sequenceTime = 615;  //total time given from shift to one function to another

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  startMicros = micros();
}

void loop() {
  currentMicros = micros();
  // put your main code here, to run repeatedly:
  if (currentMicros - startMicros >= sequenceTime) {
    antennaType = 0b0100000; // program antenna back to reset; not accepting data
  }
  else {
    antennaType = 0b000110; // program antenna to start sending data over to USSIM
    antennaType = 0b100010; // program antenna to start "to" scanning
    antennaType = 0b100000; // program antenna to stop "to" scanning
    antennaType = 0b100011; // program antenna to start "fro" scanning
  }

}
