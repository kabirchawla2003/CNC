#include <Stepper.h>

const int SPR = 200;
const int drill_down = 13;
const int MSpeed = 60;
int i = 0;
char c;

Stepper SY(SPR, 8,9,10,11);
Stepper SX(SPR, 4,5,6,7);

void setup() {pinMode(drill_down,OUTPUT);}

void loop() {
  for(i = 0;i<strlen(c);i++){
    switch(c[i]){
      case "A":
      A()
      //So on and so forth
    }
  }
}

int A(){                                 //Made only one for example
  digitalWrite(drill_down,HIGH);
  GoToPos(0,0,1,2);
  GoToPos(1,2,2,0);
  digitalWrite(drill_down,LOW);
  GoToPos(2,0,0.5,1);
  digitalWrite(drill_down,HIGH);
  GoToPos(0.5,1,1.5,1);
  digitalWrite(drill_down,LOW);
  GoToPos(1.5,1,3,0);
  return 0;
}

int GoToPos(int x1,int y1,int x2,int y2){
  for(i = 0;i<100;i++){
    SY.setSpeed(MSpeed);
    SY.step((SPR / 600)*(y2-y1));
    SX.setSpeed(MSpeed);
    SX.step((SPR / 600)*(x2-x1));
    return 0;
  }
}

int horizontalHalfCurve(int dir){
  int m = 1;
  if (dir==1){
    m = 1;
  }
  else{
    m = -1;
  }
  for(i = 0;i<100;i++){
    SY.setSpeed(4*MSpeed*(1-(i/50)));
    SY.step((SPR / 600)*1.236*m);
    SX.setSpeed(MSpeed);
    SX.step((SPR / 600));
    return 0;
}
}
int verticalHalfCurve(int dir){
    int m = 1;
  if (dir==1){
    m = 1;
  }
  else{
    m = -1;
  }
  for(i;i<100;i++){
    SX.setSpeed(4*MSpeed*(1-(i/50)));
    SX.step((SPR / 600)*1.236*m);
    SY.setSpeed(MSpeed);
    SY.step((SPR / 600));
    return 0;
}
}
int leftFullCurve(){
  int i = 1;
  for(i;i<100;i++){
    SX.setSpeed(4*MSpeed*(1-(i/50)));
    SX.step((SPR / 300)*1.236);
    SY.setSpeed(MSpeed);
    SY.step((SPR / 300));
    return 0;
}
}
int RightFullCurve(){
  for(i = 0;i<100;i++){
    SX.setSpeed(4*MSpeed*(1-(i/50)));
    SX.step((-SPR / 300)*1.236);
    SY.setSpeed(MSpeed);
    SY.step((SPR / 300));
    return 0;
}
}
