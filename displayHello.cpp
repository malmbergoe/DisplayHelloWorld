#include <iostream>
#include <stdio.h>
#include <cstdint>

#include <linux/i2c-dev.h> // needed for I2C port
//#include <i2c/smbus.h>
#include <unistd.h>   // needed for I2C port
//#include <sys/types.h>
//#include <sys/stat.h>
#include <sys/ioctl.h>   // needed for I2C port
#include <fcntl.h>       // needed for I2C port
//#include <stdlib.h>
//#include <errno.h>
//#include "linux/i2c-dev.h"


#define i2c_addr 0x20 // lcd display memory address
#define LCD_CHR 1 // Mode - Sending data
#define LCD_CMD 0 // Mode - Sending command
#define LINE1 0x80 // memory address of first line
#define LINE2 0xC0 // memory address of second line
#define LCD_BACKLIGHT 0x08 // on
#define ENABLE 0b00000100 // enable bit


void i2cInit(const int i2c_dev_address, const char *i2c_dev_node_path);
void lcdInit(void);
void lcdWriteByte(int bits, int mode);

void writeToLcd(std::string input);
void writeCharToLcd(const char *s);

int fd; // global fileDescriptor
int file_i2c;
int length;
uint8_t buffer[60] = {0};

int timingLoopFreq = 500;
int timingLoopMicroSeconds = 1000000 / timingLoopFreq;
//uint8_t base_addr = 0x20;

int main(int argc, char **argv)
{
  std::cout << "Initializing display..." << std::endl;
  char i2c_dev_node_path[] = "/dev/i2c-1";
  i2cInit(2, i2c_dev_node_path);
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

void i2cInit(const int i2c_dev_address, const char *i2c_dev_node_path){
  std::cout <<"initialize i2c device" << std::endl;
  int i2c_dev_node = 0;
  int ret_val = 0;
  /* Open the device node for the I2C adapter of bus 4 */
  file_i2c = open(i2c_dev_node_path, O_RDWR);
  if (file_i2c < 0) {
    perror("Unable to open device node.");
    exit(1);
  }

  /* Set I2C_SLAVE for adapter 4 */
  ret_val = ioctl(file_i2c, I2C_SLAVE, i2c_dev_address);
  if (ret_val < 0) {
    perror("Could not set I2C_SLAVE.");
    exit(2);
  }
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
  buffer[0] = bits;
  length = 1;

  if(write(file_i2c, buffer, length) != length){
    /* ERROR HANDLING: i2c transaction failed */
    printf("Failed to write to the i2c bus.\n");
  }

}
