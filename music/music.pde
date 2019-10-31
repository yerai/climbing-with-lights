import processing.serial.*;
import ddf.minim.*;

Minim minim;
AudioPlayer sound_1;
AudioPlayer sound_2;
AudioPlayer sound_3;
AudioPlayer sound_4;
AudioPlayer sound_5;

int lf = 10; // Linefeed in ASCII
String myString = null;
Serial myPort; // The serial port
int sensorValue = 0;

void setup() {
  // Open the port you are using at the rate you want:
  println(Serial.list());
  myPort = new Serial(this, "/dev/tty.usbmodem14201", 9600);
  myPort.clear();
  // Throw out the first reading, in case we started reading 
  // in the middle of a string from the sender.
  myString = myPort.readStringUntil(lf);
  myString = null;
 // we pass this to Minim so that it can load files from the data directory
 minim = new Minim(this);
 // loadFile will look in all the same places as loadImage does.
 // this means you can find files that are in the data folder and the 
 // sketch folder. you can also pass an absolute path, or a URL.
 // Change the name of the audio file here and add it by clicking on "Sketch —> Import File"
 sound_1 = minim.loadFile("sound_1.wav"); 
 sound_2 = minim.loadFile("sound_2.wav");
 sound_3 = minim.loadFile("sound_3.wav");
 sound_4 = minim.loadFile("sound_4.wav");
 sound_5 = minim.loadFile("sound_5.wav");
}

void draw() {
  // check if there is something new on the serial port
  while (myPort.available() > 0) {
  // store the data in myString 
  myString = myPort.readStringUntil(lf);
  // check if we really have something
  if (myString != null) {
    myString = myString.trim(); // let's remove whitespace characters
    // if we have at least one character...
    if(myString.length() > 0) {
       println(myString); // print out the data we just received
       // if we received a number (e.g. 123) store it in sensorValue, we sill use this to change the background color. 
       try {
           sensorValue = Integer.parseInt(myString);
           // As the range of an analog sensor is between 0 and 1023, we need to 
           // convert it in order to use it for the background color brightness
           int brightness = (int)map(sensorValue, 0, 1023, 0, 255);
           background(brightness);
       } catch(Exception e){}
       
       if(myString.charAt(0) == '1'){
          if(sound_1.isPlaying() == false){
              sound_1.loop();
          }
       }
       
       if(myString.charAt(0) == '0'){
          if(sound_1.isPlaying() == true){
              sound_1.pause();
          }
       }
      
       
       if(myString.charAt(1) == '1'){
          if(sound_2.isPlaying() == false){
              sound_2.loop();
          }
       }
       
       if(myString.charAt(1) == '0'){
          if(sound_2.isPlaying() == true){
              sound_2.pause();
          }
       }
       
       if(myString.charAt(2) == '1'){
          if(sound_3.isPlaying() == false){
              sound_3.loop();
          }
       }
       
       if(myString.charAt(2) == '0'){
          if(sound_3.isPlaying() == true){
              sound_3.pause();
          }
       }
       
       if(myString.charAt(3) == '1'){
          if(sound_4.isPlaying() == false){
              sound_4.loop();
          }
       }
       
       if(myString.charAt(3) == '0'){
          if(sound_4.isPlaying() == true){
              sound_4.pause();
          }
       }
       
       if(myString.charAt(4) == '1'){
          if(sound_5.isPlaying() == false){
              sound_5.loop();
          }
       }
       
       if(myString.charAt(4) == '0'){
          if(sound_5.isPlaying() == true){
              sound_5.pause();
          }
       }
       
    }
  }
 }
}
