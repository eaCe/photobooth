# Photobooth

This is a simple photobooth project that uses a Arduino to control a camera.
If a button is pressed the camera takes a picture and saves it to a SD card.

In the future the images will be processed by a Raspberry Pi and maybe uploaded to a server.

## Hardware

The current hardware setup is:

* Arduino Mega
* Any camera that supports a remote shutter
* 1 large button
* 1 relay to trigger the camera
* Some wires
* 1 breadboard
* 1 Cable to connect the camera to the relay

## Software

See photobooth.ino for the Arduino code.