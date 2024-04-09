# Kinesis
All kinesis firmware use Vial now, and the Vial config is within `tpanum.vil`.
Installing the firmware can be done using the teensy-loader, with the following command:

## Flashing teensy board

``` shell
sudo teensy-loader-cli -w -v -mmcu=TEENSY2PP kinesis_default_vial.hex
```

Now, press the reset button on the keyboard.

## Flashing Blackpill
```shell
sudo dfu-util -d 0483:df11 -a 0 -s 0x08000000:leave -D kinesis_blackpill_default.bin
 ```
