# tpanum layout for QMK firmware
[This .hex-file](ergodox_ez_firmware_tpanum_colemak.hex) contains the layout for Ergodox EZ solution.

It can be modified [here](https://configure.ergodox-ez.com/ergodox-ez/layouts/PMlAG/latest/0).

## Flashing

``` shell
teensy-loader-cli -w -v -mmcu=atmega32u4 ergodox_ez_firmware_tpanum_colemak.hex
```
