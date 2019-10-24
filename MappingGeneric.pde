import hypermedia.net.*;

int PORT = 57222;
String IP = "192.168.1.2";
UDP udp;

int SensorRead = 0;

PImage img;

void setup() {
  udp = new UDP(this, PORT);
  udp.listen(true);
  
  fullScreen();
  img = loadImage("Flower.jpg");
  background(0);
  smooth();
}



void draw() {
  println(int(SensorRead));
  // Pick a random point
  int x = int(random(img.width));
  int y = int(random(img.height));
  int pointillize = 10;
  if (SensorRead > 0) {
    pointillize = SensorRead/2;
  }
  //int pointillize = 50;
  int loc = x + y*img.width;
  
  // Look up the RGB color in the source image
  loadPixels();
  float r = red(img.pixels[loc]);
  float g = green(img.pixels[loc]);
  float b = blue(img.pixels[loc]);
  noStroke();
  
  // Draw an ellipse at that location with that color
  fill(r,g,b,100);
  ellipse(x, y,pointillize,pointillize);
  
}

void receive(byte[] data) {
  if (data != null) {
    println("yes");
    String value = new String(data);
    SensorRead = int(value);
  }
}
