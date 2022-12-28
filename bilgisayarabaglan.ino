#include "serialCommand.h"
SerialCommand sc;
void setup() {
  sc.setBautRate(115200);
  sc.setup();
  pinMode(8,OUTPUT);

}
void loop() {
  sc.read();
  if(sc.modul=="led"&&sc.action=="yak"&&sc.data1=="1") digitalWrite(8,HIGH);
  if(sc.modul=="led"&&sc.action=="sondur"&&sc.data1=="1") digitalWrite(8,LOW);
}
