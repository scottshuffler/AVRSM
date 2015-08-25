
main: main.c
	avr-gcc -std=gnu99 -g -Os -Wall -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega2560 -DF_CPU=16000000L -MMD -DUSB_VID=null -DARDUINO=106 -I../lib -c -o ./output/main.o main.c 
	avr-gcc -g -mmcu=atmega2560 -DF_CPU=16000000L -o ./output/main.elf ./output/main.o
	avr-objcopy -O ihex -R .eeprom ./output/main.elf ./output/main.hex 

uploadMac:
	avrdude -v -v -patmega2560 -cwiring -P/dev/cu.usbmodemfa131 -b115200 -D -Uflash:w:./output/main.hex:i 
uploadLinux:
	avrdude -v -v -patmega2560 -cwiring -P/dev/ttyACM0 -b115200 -D -Uflash:w:./output/main.hex:i 


