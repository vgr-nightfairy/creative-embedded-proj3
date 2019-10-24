## README

Flower with Friends is a true reuse of Projects 1 and 2. The mission of this wireless-sensor creation is to duplicate the main LED flower and showcase a union between a physical and cyber garden.

Functionally, most of the sensor operations from Project 2 are retained in terms of the switch making all the LEDs flash in coordination and the button terminating the program. The difference is that since the joystick is no longer in use, instead of individually being able to iterate through the LEDs in their petal formation, the user can squeeze the force resistant sensor, presented as a nub in the middle of the flower, to birth a new flower on the laptop screen.

The main differentiating element between this project and previous ones is the fact that we are using wireless here. Specifically we are using the UDP packet protocol to send and receive sensor data across devices (ex. ESP32 and the laptop).

## Usage

To turn on the device, make sure that the ESP32 is plugged into a power source. For this project, I decided not to use the given battery because of the fact that it would need to provide power for not only the sensor but all the existing LEDs (around 16) and the WiFi. Knowing that people were already running into issues with the battery just trying to support the bare minimum on the ESP32, I knew that it definitely would not work for me.

Following a connection to a power source, navigate to the laptop and make sure the Processing display is running. Then hit the switch near the flower to make all LEDs flash in unison, hit the button to terminate the operations, and squeeze the FRS with variable energy to generate a image on the laptop. In particular the range of force exerted is mapped to the size of the pointillism strokes that are being used to illustrate the image of an additional flower. Pointillism was the technique I used in Project 1. The reason it works well for this project is because the dynamic spottiness of the colors mimics the way the LED petals look like when they are lit (spread out, variable light reach, etc.).

## Reproducability

Although the overall structure of this enclose will be hard to reproduce, as it is very layered and construted, given the structure of Project 2, Project 3 can easily be achieved if the user makes a force resistant sensor out of copper tape, wires, and (conductive) foam and makes a processing program to intergrate sensor data transferred wirelessly over from the ESP32. Here is a photo of the sensor:

![Sensor](/72786952_749025632188224_5846252209926307840_n.jpg)

## Installation

This device is intended to be installed in a natural environment, preferably in a flower bed, as it is interesting to see how different constructued representations of nature interact with one another and the external world. The one difficulty with this is the fact that any portable power source seems to be inefficient to actually enable a reliable WiFi connection. Therefore other alternatives to power need to be explored for this installation. Maybe an extension cord embedded in the dirt?
