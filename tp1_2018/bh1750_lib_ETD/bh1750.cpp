#include "bh1750.h"

BH1750::BH1750(){

}

void BH1750::begin(){
  start();
  reset();
  setMode(16);

  
}

uint16_t BH1750::getRawLight(void){
	uint16_t data ;
	Wire.requestFrom(0x23, 2); // request 2 bytes from slave 
	delay(1) ;                // wait for data is ready
	if (Wire.available()>=2) { 
		data = Wire.read(); // read msb
		data <<= 8 ; // shift msb
		data |= Wire.read(); // read lsb and add to msb 
	}
	data = data/1.2;
	return data;
} 


void BH1750::i2cWrite8( uint8_t data ) {
  Serial.println(data);
}

 void BH1750::start(){
  Wire.beginTransmission(0x23);
  Wire.write(1);
  Wire.endTransmission();
}

/**
 * Reset
 */
void BH1750::reset(void){
  Wire.beginTransmission(0x23);
  Wire.write(7);
  Wire.endTransmission();
}

void BH1750::setMode(uint8_t mode){
  
  Wire.beginTransmission(0x23);
  Wire.write(mode);
  Wire.endTransmission();
}

uint16_t BH1750::i2cRead16(  ) {
	uint16_t data ;
	if (Wire.available()>=2) { 
			data = Wire.read(); // read msb
			data <<= 8 ; // shift msb
			data |= Wire.read(); // read lsb and add to msb 
		}
	return data;
}

