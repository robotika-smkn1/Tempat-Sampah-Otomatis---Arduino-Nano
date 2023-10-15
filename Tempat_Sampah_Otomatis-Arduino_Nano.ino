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
