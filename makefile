main: ./kernel-land/kernel.c
	##COMPILE THE KERNEL SIDE FIRST
	avr-gcc -std=gnu99 -g -Os -Wall -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega2560 -DF_CPU=16000000L -MMD -DUSB_VID=null -DARDUINO=106 -I../lib -c -o ./kernel-land/output/kernel.o ./kernel-land/kernel.c 
	avr-gcc -std=gnu99 -g -Os -Wall -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega2560 -DF_CPU=16000000L -MMD -DUSB_VID=null -DARDUINO=106 -I../lib -c -o ./kernel-land/output/digital.o ./kernel-land/digital.c 
	avr-gcc -std=gnu99 -g -Os -Wall -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega2560 -DF_CPU=16000000L -MMD -DUSB_VID=null -DARDUINO=106 -I../lib -c -o ./kernel-land/output/serial.o ./kernel-land/serial.c 
	
	##COMPILE THE USER SIDE AFTER
	avr-gcc -std=gnu99 -g -Os -Wall -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega2560 -DF_CPU=16000000L -MMD -DUSB_VID=null -DARDUINO=106 -I../lib -c -o ./user-land/output/main.o ./user-land/main.c

	##LINK ALL FILES INTO ONE .HEX FILE
	avr-gcc -g -mmcu=atmega2560 -DF_CPU=16000000L -o ./kernel-land/output/kernel.elf ./kernel-land/output/kernel.o ./kernel-land/output/digital.o ./kernel-land/output/serial.o ./user-land/output/main.o
	avr-objcopy -O ihex -R .eeprom ./kernel-land/output/kernel.elf ./kernel-land/output/kernel.hex 

	#UPLOAD TO MCU
	sudo avrdude -v -v -patmega2560 -cwiring -P/dev/ttyACM1 -b115200 -D -Uflash:w:./kernel-land/output/kernel.hex:i 

uploadMac:
	avrdude -v -v -patmega2560 -cwiring -P/dev/cu.usbmodemfa131 -b115200 -D -Uflash:w:./output/kernel.hex:i 
uploadLinux:
	avrdude -v -v -patmega2560 -cwiring -P/dev/ttyACM1 -b115200 -D -Uflash:w:./output/kernel.hex:i 

# CC=avr-gcc
# OBJCOPY=avr-objcopy
# CCFLAGS=-std=gnu99 -g -Os -Wall -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega2560 -DF_CPU=16000000L -MMD -DUSB_VID=null -DARDUINO=106 -I../lib -c
# TARGET=main.hex
# ELF=main.elf
# CFILES=$(shell find . -type f -name '*.c')
# BINDIR=output
# OFILES=$(CFILES:%.c=$(BINDIR)/%.o)
# DEPDIR=$(BINDIR)
# DEPFILES=$(OFILES:$(BINDIR)/%.o=$(DEPDIR)/%.d)

# print-%: ; @echo $*=$($*)

# all: $(TARGET)
# 	sudo avrdude -v -v -patmega2560 -cwiring -P/dev/ttyACM1 -b115200 -D -Uflash:w:$(TARGET):i

# $(TARGET): $(OFILES)
# 	$(CC) -o $(ELF) $(OFILES)
# 	$(OBJCOPY) -O ihex -R .eeprom $(ELF) $(TARGET)

# -include $(DEPFILES)
# $(BINDIR)/%.o: %.c | $(BINDIR)
# 	$(CC) -o $@ $(CFLAGS) $<

# $(BINDIR):
# 	mkdir -vp $(BINDIR)

# .PHONY: clean
# clean:
# 	$(RM) -rf $(TARGET) $(BINDIR)