import hypermedia.net.*;

int PORT = 57222;
String IP = "192.168.1.2";
UDP udp;

int SensorRead = 0;

PImage img;

void setup() {
  udp = new UDP(this, PORT, IP);
  udp.listen(true);
  
  fullScreen();
  img = loadImage("Flower.jpg");
  background(0);
  smooth();
}

void receive(byte[] data, String PORT, int IP) {
  String value = new String(data);
  SensorRead = int(value);
  println(int(value));
}

void draw() {
  // Pick a random point
  int x = int(random(img.width));
  int y = int(random(img.height));
  //int pointillize = SensorRead;
  int pointillize = 50;
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
