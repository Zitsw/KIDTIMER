#include <RTClib.h>

#define play_time 720
uint32_t timeStampVal;


//============================================================
int piezoPin = 3;
RTC_DS1307 rtc;

// void clock_now ();
void setup() {
rtc.begin();
pinMode(piezoPin, OUTPUT);
Serial.begin(9600);
DateTime now = rtc.now();
timeStampVal = now.unixtime();
}

void loop() {
  DateTime now = rtc.now();
  if(timeStampVal <= now.unixtime()){
    for(int buzz = 0;buzz<=3;buzz++){
    digitalWrite(piezoPin, LOW); 
    delay(100);
    digitalWrite(piezoPin, HIGH);   
    delay(1000); 
                                  }
  timeStampVal = timeStampVal + play_time;
}
}