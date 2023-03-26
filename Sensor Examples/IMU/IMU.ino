#include <Arduino_LSM6DSOX.h>

float Ax, Ay, Az;
float Gx, Gy, Gz;

void setup() {
  Serial.begin(9600);

  while(!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println("Hz");
  Serial.println();

  Serial.print("Gyroscope sample rate = ");  
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println("Hz");
  Serial.println();

}

void loop() {

  // if (IMU.accelerationAvailable()) {
  //   IMU.readAcceleration(Ax, Ay, Az);

  //   Serial.print("Accelerometer data: ");
  //   Serial.print(Ax);
  //   Serial.print('\t');
  //   Serial.print(Ay);
  //   Serial.print('\t');
  //   Serial.println(Az);
  //   Serial.println();
  // }
  Serial.print("Top:");
  Serial.print(1000); // To freeze the lower limit
  Serial.println();
  Serial.print("Bottom:");
  Serial.println(-1000); // To freeze the upper limit
 
  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(Gx, Gy, Gz);
    
    Serial.print("Gyroscope data: ");
    Serial.println();

    Serial.print("Gx:");
    Serial.print(Gx);
    Serial.print('\t');
    Serial.print("Gy:");
    Serial.print(Gy);
    Serial.print('\t');
    Serial.print("Gz:");
    Serial.println(Gz);
  }

delay(10);

}