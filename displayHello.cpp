#include <iostream>
#include <stdio.h>
#include <cstdint>

#define i2c_addr 0x20 // lcd display memory address
#define LCD_CHR 1 // Mode - Sending data
#define LCD_CMD 0 // Mode - Sending command
#define LINE1 0x80 // memory address of first line
#define LINE2 0xC0 // memory address of second line
#define LCD_BACKLIGHT 0x08 // on
#define ENABLE 0b00000100 // enable bit


void i2cInit(void);
void lcdInit(void);
void lcdWriteByte(int bits, int mode);

void writeToLcd(std::string input);
void writeCharToLcd(const char *s);

int fd; // global fileDescriptor
int file_i2c;
int length;
uint8_t buffer[3] = {0};

int timingLoopFreq = 500;
int timingLoopMicroSeconds = 1000000 / timingLoopFreq;
//uint8_t base_addr = 0x20;

int main(int argc, char **argv)
{
  std::cout << "Initializing display..." << std::endl;
  i2cInit();
  lcdInit();
  writeToLcd("Hello world");
  return 0;
}

void writeCharToLcd(const char *s){
  while(*s) lcdWriteByte(*(s++),LCD_CHR);
}

void writeToLcd(std::string input){
  std::cout << "writeToLcd method" << std::endl;
  std::cout << input << std::endl;
  writeCharToLcd(input.c_str());
  std::cout << "writeToLcd complete!" << std::endl;
}

void i2cInit(){
  std::cout <<"initialize i2c device" << std::endl;
}

void lcdInit() {
  std::cout <<"initialize lcd display" << std::endl;

  lcdWriteByte(0x33, LCD_CMD);
  lcdWriteByte(0x32, LCD_CMD);
  lcdWriteByte(0x06, LCD_CMD);
  lcdWriteByte(0x0C, LCD_CMD);
  lcdWriteByte(0x28, LCD_CMD);
  lcdWriteByte(0x01, LCD_CMD);
}

void lcdWriteByte(int bits, int mode){
  std::cout << "writing byte to lcd not yet implemented." << std::endl;
  std::cout << "bits:" + std::to_string(bits) + ", mode: " + std::to_string(mode) << std::endl;
}
