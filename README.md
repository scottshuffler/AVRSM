# SPeaK
##Scott's Preemptive almost Kernel

##Arduino Mega 2560




###Linux Instructions

* To find your COM port:

```dmesg | grep tty ```

* Use the text editor of your choice to update the make file with the appropriate COM port

* For Linux install screen through your package manager and run:

```sudo screen /dev/tty(Your Arduinos COM port) 19200```



###Mac Instructions

* To find your COM port:

```ls /dev/tty.*```

* Use the text editor of your choice to update the make file with the appropriate COM port

* Download SerialTools and select the appropriate COM port in the drop down, select 19200 in the baud rate drop down and then press connect.


