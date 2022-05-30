/* Get tilt angles on X and Y, and rotation angle on Z
    Angles are given in degrees
 License: MIT
 https://theiotprojects.com/measure-pitch-roll-and-yaw-angles-using-mpu6050-and-arduino/
 */
 #include "Wire.h"
 #include <MPU6050_light.h>
 MPU6050 mpu(Wire);
 unsigned long timer = 0;
 void setup() {
   Serial.begin(115200);
   Wire.begin();
 byte status = mpu.begin();
//   Serial.print(F("MPU6050 status: "));
//   Serial.println(status);
   while (status != 0) { } // stop everything if could not connect to MPU6050
// Serial.println(F("Calculating offsets, do not move MPU6050"));
//   delay(1000);
//   mpu.calcOffsets(); // gyro and accelero
//   Serial.println("Done!\n");
 }
 void loop() {
   mpu.update();
 if ((millis() - timer) > 10) { // print data every 10ms
     Serial.print(mpu.getAngleX());
     Serial.print(",");
     Serial.print(mpu.getAngleY());
     Serial.print(",");
     Serial.println(mpu.getAngleZ());
     timer = millis();
   }
 }



// /*!
//   * imu_show.ino
//   *
//   * Download this demo to show attitude on [imu_show](https://github.com/DFRobot/DFRobot_IMU_Show)
//   * Attitude will show on imu_show
//   *
//   * Product: http://www.dfrobot.com.cn/goods-1860.html
//   * Copyright   [DFRobot](http://www.dfrobot.com), 2016
//   * Copyright   GNU Lesser General Public License
//   *
//   * version  V1.0
//   * date  07/03/2019
//   */

// #include "DFRobot_BNO055.h"
// #include "Wire.h"

// typedef DFRobot_BNO055_IIC    BNO;    // ******** use abbreviations instead of full names ********

// BNO   bno(&Wire, 0x28);    // input TwoWire interface and IIC address

// // show last sensor operate status
// void printLastOperateStatus(BNO::eStatus_t eStatus)
// {
//   switch(eStatus) {
//   case BNO::eStatusOK:    Serial.println("everything ok"); break;
//   case BNO::eStatusErr:   Serial.println("unknow error"); break;
//   case BNO::eStatusErrDeviceNotDetect:    Serial.println("device not detected"); break;
//   case BNO::eStatusErrDeviceReadyTimeOut: Serial.println("device ready time out"); break;
//   case BNO::eStatusErrDeviceStatus:       Serial.println("device internal status error"); break;
//   default: Serial.println("unknow status"); break;
//   }
// }

// void setup()
// {
//   Serial.begin(115200);
//   bno.reset();
//   while(bno.begin() != BNO::eStatusOK) {
//     // Serial.println("bno begin faild");
//     printLastOperateStatus(bno.lastOperateStatus);
//     delay(2000);
//   }
// //   Serial.println("bno begin success");
// }

// void loop()
// {
//   BNO::sEulAnalog_t   sEul;
//   sEul = bno.getEul();
//   Serial.print(sEul.pitch, 8);
//   Serial.print(",");
//   Serial.print(sEul.roll, 8);
//   Serial.print(",");
//   Serial.println(sEul.head, 8);
//   delay(20);
// }
