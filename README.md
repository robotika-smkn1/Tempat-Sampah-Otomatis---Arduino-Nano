# :pushpin: Tempat-Sampah-Otomatis---Arduino-Nano



<p align="center">
  <img src="https://i.postimg.cc/tRZw0xQ4/logo-removebg-preview.png" alt="robotika smkn1 kotabekasi logo"/ style="height:350px;" "width: 350px;">
</p>


[![Version](https://img.shields.io/badge/VENOM-1.0.17-brightgreen.svg?maxAge=259200)]()
[![Stage](https://img.shields.io/badge/Release-Stable-brightgreen.svg)]()
![licence](https://img.shields.io/badge/license-GPLv3-brightgreen.svg)
[![Coverity Scan Build Status](https://scan.coverity.com/projects/aircrack-ng/badge.svg)](##Link##)



## :inbox_tray: Media Social Instagram

To keep this collection up-to-date need contributors who can add more Program Arduino scripts
||
|--------------|
|:mailbox_with_mail: [artha_sa_](https://www.instagram.com/artha_sa_/)
|:mailbox_with_mail: [dicky_asqaelani26](https://www.instagram.com/dicky_asqaelani26/)
|:mailbox_with_mail: [rahmatnurraya](https://www.instagram.com/rahmatnurraya990/)
|:mailbox_with_mail: [applepi_fthur](https://www.instagram.com/applepi_fthur/)
|:mailbox_with_mail: [robotika-smkn1](https://www.instagram.com/robotika.smkn1kotabekasi/)


# :moneybag: [Donate](https://saweria.co/arthasyarif)


# :briefcase: Barang & Bahan
- Arduino Nano
- Kabel Male & Female
- Servo Sg 90
- Sensor Ultra Sonic ( Hc-sr04 )


# :mag: Ilustrasi Arduino

<p align="center">
  <img src="###" style="height:205px;" "width:205px;"/>
</p>


# :clipboard: Source Code By Robotika SMKN 1

```bash
/*
 * 
 * All the resources for this project: smkn1kotabekasi.sch.id
 * Modified by Robotika smkn1 kotabekasi
 * 
 * Created by Robotika smkn1 kotabekasi
 * 
 */

#include <Servo.h>

Servo myservo;  // Membuat objek Servo
int trigPin = 2;  // Pin trigger ultrasonik
int echoPin = 3;  // Pin echo ultrasonik
long duration;
int distance;
int servoPin = 9;  // Pin servo
int openAngle = 90;  // Sudut buka untuk servo
int closeAngle = 0;  // Sudut tutup untuk servo
bool isOpen = false;

void setup() {
  myservo.attach(servoPin);  // Menghubungkan servo ke pin
  myservo.write(closeAngle);  // Menutup servo pada awalnya
  pinMode(trigPin, OUTPUT);  // Konfigurasi pin trigger sebagai OUTPUT
  pinMode(echoPin, INPUT);  // Konfigurasi pin echo sebagai INPUT
  Serial.begin(9600);  // Inisialisasi komunikasi serial
}

void loop() {
  // Membaca jarak dari sensor ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.println(distance);

  // Jika objek mendekati sensor dalam jarak tertentu, buka tong sampah
  if (distance < 30 && !isOpen) {
    myservo.write(openAngle);  // Membuka servo
    delay(2000); // Tambahkan penundaan satu detik
    isOpen = true;
  }

  // Jika objek menjauhi sensor, tutup tong sampah
  if (distance > 30 && isOpen) {
    myservo.write(closeAngle);  // Menutup servo
    delay(1000); // Tambahkan penundaan satu detik
    isOpen = false;
  }

  delay(100);  // Tunggu sebentar sebelum membaca ulang jarak
}

```
