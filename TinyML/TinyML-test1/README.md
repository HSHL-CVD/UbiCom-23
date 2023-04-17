# TinyML on Arduino Nano RP2040 Connect

## Using EdgeImpulse on Arduino RP2040

- Get an Account on EdgeImpulse https://edgeimpulse.com/
- Install EdgeImpulse CLI https://docs.edgeimpulse.com/docs/edge-impulse-cli/cli-installation

---

### Easy Way: Connect Board to EdgeImpulse via webUSB (Chrome only) 0o

https://www.edgeimpulse.com/blog/collect-sensor-data-straight-from-your-web-browser

the firmware is here: https://cdn.edgeimpulse.com/firmware/pi-rp2040.zip

To upload the Firmware you have to force the board in bootloading mode. To do that, just double tap on the reset button. Then you can drag and drop the firmware file to the board.

---

### Using Data Forwarder

Even though the Arduion RP2040 is officially supported now in EdgeImpulse via the official rp2040 package (not in the Arduino Package!), you cann still use the Data Forwarder if you want to work with multiple sensors etc.: https://docs.edgeimpulse.com/docs/edge-impulse-cli/cli-data-forwarder

Here is a pretty good tutorial from levelup that was very helpful: https://levelup.gitconnected.com/creating-a-machine-learning-workflow-for-arduino-nano-rp2040-connect-with-edge-impulse-284792021e79
