#include "pid.h"
#include <FlexCAN.h>

// 1MHz駆動のCANを定義する
FlexCAN CANBus(1000000);
static CAN_message_t msg0;
static CAN_message_t msg1;

void setup() {
  // LEDのピンを出力にする
  pinMode(13, OUTPUT);
  // BUTTONのピンを入力にする
  pinMode(2, INPUT);
  
  Serial.begin(115200);
  Serial1.begin(100000, SERIAL_8E1);

  // CANの初期設定
  CANBus.begin();
}

void loop() {
  if (digitalRead(2) == 1)
  {
    // ボタンが押されている間は出力する
    msg0.id = 0x1FF;
    msg0.len = 8;
    for (int i = 0; i < msg0.len; i++)
    {
      // 1BYTEずつ代入する
      msg0.buf[i] = i;
    }
    CANBus.write(msg0);
  }
}
