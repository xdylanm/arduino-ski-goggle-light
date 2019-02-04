# Clip on Light

This project is a take on using capacitive touch to scroll through different lighting modes with neo-pixels. The lights are driven by an ATTiny85 on an [Arduino-compatible board](https://digistump.com/wiki/digispark/tutorials/connecting). The case and clip are 3D printed, and should screw together with M3 nuts & bolts. 
# Notes

## Using reset pin as digital IO on Digispark

This pin does work as input or output for the capacitive sense, nor did it work as a data pin for the neo-pixels (SK6812). Connecting the neo-pixels to pin 4 (shared with USB) does work, but leaves the neo-pixels in an unxpected state at initialization (two of them turn on white).


# References

1. [Unlock Digispark bootloader](https://www.instructables.com/id/How-to-unlock-Digispark-ATtiny85-and-convert-it-to/)
  * Recover the reset pin functionality
  * Change bootloaders (e.g. modify to Trinket)
  * Remove bootloader startup delay

