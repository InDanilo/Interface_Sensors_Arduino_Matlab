#include <HX711.h>

HX711 scale1;HX711 scale2;HX711 scale3;HX711 scale4;HX711 scale5;HX711 scale6;HX711 scale7;HX711 scale8;

float calibration_factor1 = 48100; // this calibration factor is adjusted according to my load cell
float calibration_factor2 = 48100;
float calibration_factor3 = 48100;
float calibration_factor4 = 48100;
float calibration_factor5 = 48100;
float calibration_factor6 = 48100;
float calibration_factor7 = 48100;
float calibration_factor8 = 48100;

float units1;float units2;float units3;float units4;float units5;float units6;float units7;float units8;
float ounces1;float ounces2;float ounces3;float ounces4;float ounces5;float ounces6;float ounces7;float ounces8;

void setup() {
  Serial.begin(9600);
  
  Serial.println("HX711 calibration sketch");Serial.println("Remove all weight from scale");Serial.println("After readings begin, place known weight on scale");Serial.println("Press + or a to increase calibration factor");Serial.println("Press - or z to decrease calibration factor");

  
  scale1.begin(5,6);scale1.set_scale();scale1.tare(0);  //Reset the scale to 0
  scale2.begin(5,6);scale2.set_scale();scale2.tare(0);  //Reset the scale to 0
  scale3.begin(5,6);scale3.set_scale();scale3.tare(0);  //Reset the scale to 0
  scale4.begin(5,6);scale4.set_scale();scale4.tare(0);  //Reset the scale to 0
  scale5.begin(5,6);scale5.set_scale();scale5.tare(0);  //Reset the scale to 0
  scale6.begin(5,6);scale6.set_scale();scale6.tare(0);  //Reset the scale to 0
  scale7.begin(5,6);scale7.set_scale();scale7.tare(0);  //Reset the scale to 0
  scale8.begin(5,6);scale8.set_scale();scale8.tare(0);  //Reset the scale to 0

 long zero_factor1 = scale1.read_average();Serial.print("Zero factor1: ");Serial.println(zero_factor1);
 long zero_factor2 = scale2.read_average();Serial.print("Zero factor2: ");Serial.println(zero_factor2);
 long zero_factor3 = scale3.read_average();Serial.print("Zero factor3: ");Serial.println(zero_factor3);
 long zero_factor4 = scale4.read_average();Serial.print("Zero factor4: ");Serial.println(zero_factor4);
 long zero_factor5 = scale5.read_average();Serial.print("Zero factor5: ");Serial.println(zero_factor5);
 long zero_factor6 = scale6.read_average();Serial.print("Zero factor6: ");Serial.println(zero_factor6);
 long zero_factor7 = scale7.read_average();Serial.print("Zero factor7: ");Serial.println(zero_factor7);
 long zero_factor8 = scale8.read_average();Serial.print("Zero factor8: ");Serial.println(zero_factor8);
}

void loop() {

  scale1.set_scale(calibration_factor1); //Adjust to this calibration factor
  scale2.set_scale(calibration_factor2);
  scale3.set_scale(calibration_factor3);
  scale4.set_scale(calibration_factor4);
  scale5.set_scale(calibration_factor5);
  scale6.set_scale(calibration_factor6);
  scale7.set_scale(calibration_factor7);
  scale8.set_scale(calibration_factor8);

  units1 = scale1.get_units(), 10;
  units2 = scale2.get_units(), 10;
  units3 = scale3.get_units(), 10;
  units4 = scale4.get_units(), 10;
  units5 = scale5.get_units(), 10;
  units6 = scale6.get_units(), 10;
  units7 = scale7.get_units(), 10;
  units8 = scale8.get_units(), 10;

  
  if (units1 < 0){units1 = 0.00;}
  if (units2 < 0){units2 = 0.00;}
  if (units3 < 0){units3 = 0.00;}
  if (units4 < 0){units4 = 0.00;}
  if (units5 < 0){units5 = 0.00;}
  if (units6 < 0){units6 = 0.00;}
  if (units7 < 0){units7 = 0.00;}
  if (units8 < 0){units8 = 0.00;}
  
  ounces1 = units1 * 0.035274;
  ounces2 = units2 * 0.035274;
  ounces3 = units3 * 0.035274;
  ounces4 = units4 * 0.035274;
  ounces5 = units5 * 0.035274;
  ounces6 = units6 * 0.035274;
  ounces7 = units7 * 0.035274;
  ounces8 = units8 * 0.035274;
  

  
  Serial.print(units1);Serial.print(" kg");Serial.print(" calibration_factor 1: ");Serial.print(calibration_factor1);Serial.println();
  Serial.print(units2);Serial.print(" kg");Serial.print(" calibration_factor 2: ");Serial.print(calibration_factor2);Serial.println();
  Serial.print(units3);Serial.print(" kg");Serial.print(" calibration_factor 3: ");Serial.print(calibration_factor3);Serial.println();
  Serial.print(units4);Serial.print(" kg");Serial.print(" calibration_factor 4: ");Serial.print(calibration_factor4);Serial.println();
  Serial.print(units5);Serial.print(" kg");Serial.print(" calibration_factor 5: ");Serial.print(calibration_factor5);Serial.println();
  Serial.print(units6);Serial.print(" kg");Serial.print(" calibration_factor 6: ");Serial.print(calibration_factor6);Serial.println();
  Serial.print(units7);Serial.print(" kg");Serial.print(" calibration_factor 7: ");Serial.print(calibration_factor7);Serial.println();
  Serial.print(units8);Serial.print(" kg");Serial.print(" calibration_factor 8: ");Serial.print(calibration_factor8);Serial.println();
  Serial.println("_______________________________________________________________________________________________________________");
  delay(1000);

}
