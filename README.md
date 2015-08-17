# SPeAK
Scott's Preemptive AVR Kernel

Arduino Mega 2560


Atmel Instructions 
Tools -> External Tools -> Add

Title: --Whatever you want--

Command:

```C:\Program Files (x86)\Arduino\hardware\tools\avr\bin\avrdude.exe```

Arguments (change 'COM7' to the COM port your arduino is connected to):

``` -C"C:\Program Files (x86)\Arduino\hardware/tools/avr/etc/avrdude.conf" -v -v -v -v -patmega2560 -cwiring -P\\.\COM7 -b115200 -D -Uflash:w:"$(ProjectDir)Debug\$(ItemFileName).hex":i```
