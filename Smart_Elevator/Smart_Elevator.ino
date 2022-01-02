//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT
#include <math.h>
#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "Smart Elevator"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,4,0,2,0,99,0,13,8,1,
  1,0,3,68,12,12,1,31,50,0,
  1,0,3,83,12,12,1,31,51,0,
  1,0,3,53,12,12,1,31,49,0,
  2,0,32,62,22,11,1,8,16,31,
  79,78,0,79,70,70,0,129,0,30,
  55,24,4,16,65,117,116,111,32,71,
  114,111,117,110,100,0,67,4,11,13,
  38,35,36,8,2,129,0,6,6,45,
  7,16,67,117,114,114,101,110,116,32,
  70,108,111,111,114,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t button_1; // =1 if button pressed, else =0 
  uint8_t button_2; // =1 if button pressed, else =0 
  uint8_t button_3; // =1 if button pressed, else =0 
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 

    // output variables
  char text_1[2];  // string UTF8 end zero 
  
    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////
int a,kat,rem;
char flr;
#define spin_count_for_1_floor 1032
#define dir 23
#define power 22
void setup() 
{
  RemoteXY_Init (); 
 pinMode(dir, OUTPUT);  //motor yönü
 pinMode(power,OUTPUT); //güç
  // TODO you setup code
flr==1; //Mevcut kat
kat==1; //kaç kat inip çıkması lazım yukarı çıkıcaksa - aşağı inicekse + değer alıyo  
}

void loop() 
{ 
  RemoteXY_Handler ();

  if(RemoteXY.button_1==1){
  if(flr!=1){
  flr=flr-1;
  kat=flr;
  flr==1;
  }
  }
  if(RemoteXY.button_2==1){
  if(flr!=2){
  flr=flr-2;
  kat=flr;
  flr==2;
  }
  }
  if(RemoteXY.button_3==1){
  if(flr!=3){
  flr=flr-3;
  kat=flr;
  flr==3;
  }
  }
  RemoteXY.text_1==flr;
  if(kat<0){
  digitalWrite(dir, HIGH);
  }
  if(kat>0){
  digitalWrite(dir, LOW);
  }
  fabs(kat);
  while(RemoteXY.switch_1==0){
  for(int x = 0; x <(kat*(spin_count_for_1_floor)); x++){
    digitalWrite(power, HIGH);
    delayMicroseconds(2000);
    digitalWrite(power, LOW);
    delayMicroseconds(2000);
  }
  }
  while(RemoteXY.switch_1==1){
  for(int x = 0; x <(kat*(spin_count_for_1_floor)); x++){
    digitalWrite(power, HIGH);
    delayMicroseconds(2000);
    digitalWrite(power, LOW);
    delayMicroseconds(2000);
  }
  delay(15000);
  if(kat>0){
  digitalWrite(dir, HIGH);
  }
  if(kat<0){
  digitalWrite(dir, LOW);
  }
  rem==flr;
  while(rem!=1 && flr!=1){
  rem=rem-1;
  a++;
  }
  for(int x = 0; x <(a*(spin_count_for_1_floor)); x++){
    digitalWrite(power, HIGH);
    delayMicroseconds(2000);
    digitalWrite(power, LOW);
    delayMicroseconds(2000);
  }
  }
}
