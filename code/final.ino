#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
//#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include<string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//LiquidCrystal lcd3(12, 11, 10, 9, 8, 7);

int year;
int month;
int day;
SoftwareSerial Bluetooth(5,6);
const unsigned long eventTime_1 = 500; // interval in ms
const unsigned long eventTime_2 = 10000;

unsigned long previousTime_1 = 0;
unsigned long previousTime_2 = 0;

int rotate=1;

char BT_input;
int n = 0;
char text;
char date[26];
char times[26];
int i=0,j=0,k=0;
int stat=0;
char t[2];


char* token,token1;
char chour[][15]={"","",""};
char cdate[][15]={"","",""};
int hc=0,dc=0;
int si,wi=0;
int c=0;

RTC_DS1307 RTC;
char a[20];
LiquidCrystal_I2C lcd(0x27,20,4);
LiquidCrystal_I2C lcd3(0x26,20,4);


char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
byte r[] = {
  0x0,0x1f,0x6,0xa,0x1a,0xa,0x6,0x12,
};
byte bi[] = {
  0xf,0x10,0x1f,0x13,0x15,0x15,0x13,0x11,
};
byte ba[] = {
  0x0,0x1f,0x5,0xd,0x15,0xd,0x5,0x0,
};
byte shu[] = {
  0x0,0x17,0x9,0x15,0x1,0x6,0x11,0xf,
};
byte cro[] = {
  0x0,0x1f,0xc,0x6,0x15,0x1c,0x4,0x0,
};
byte ono[] = {
  0x0,0x0,0xc,0xc,0x0,0x2,0x3,0x1,
};
byte se[] = {
  0x0,0x1f,0x15,0x15,0x17,0x1d,0x11,0x9,
};
byte am[] = {
  0x0,0x1f,0x19,0x15,0x1f,0x1d,0x11,0x0,
};
byte bu[] = {
  0x0,0x1f,0x6,0xa,0xe,0x2,0x6,0x1,
};
byte bri[] = {
  0x0,0x1f,0x6,0xa,0x6,0x2,0xc,0x2,
};
byte sp[] = {
  0x14,0xc,0x15,0x1d,0xb,0x5,0x9,0x1,
};
byte m[] = {
  0x0,0x1f,0x9,0x5,0x5,0xf,0xd,0x1,
};
byte l[] = {
  0x0,0x1f,0x1,0x1,0x1b,0x15,0x1,0x1,
};
byte dh[] = {
  0x4,0x8,0x7,0xa,0xa,0x6,0x2,0x0,
};
byte g[] = {
  0x0,0xd,0x13,0x19,0x5,0x1d,0x1,0x1,
};
byte h[] = {
  0x0,0x1f,0xc,0xa,0x2,0xc,0x6,0x1,
};
byte ti[] = {
  0xf,0x10,0x1f,0x16,0x15,0x11,0x19,0x16,
};
byte sho[] = {
  0x1,0x17,0x9,0x15,0x1,0x1,0x1,0x0,
};
byte ni[] = {
  0x7,0x8,0xf,0x9,0xf,0xd,0x9,0x0,
};
byte zero[]={0x0,0xe,0x11,0x11,0x11,0x11,0xe,0x0,};
byte one[]={0x8,0x8,0x4,0x2,0x1,0x1,0xe,0x4,};
byte two[]={0x8,0x8,0x4,0x2,0x2,0xc,0x2,0x1,};
byte three[]={0x0,0x17,0x15,0x11,0x11,0x11,0xe,0x0,};
byte four[]={0xe,0x11,0xa,0x4,0xa,0x11,0xe,0x0,};
byte five[]={0x0,0x14,0x1c,0x14,0x15,0x17,0x11,0x1e,};
byte six[]={0x0,0x4,0x4,0x15,0x17,0x11,0x11,0xe,};
byte seven[]={0x4,0xa,0x11,0xf,0x1,0x1,0x1,0x1,};
byte eight[]={0x10,0x10,0x10,0x1f,0x14,0x12,0x14,0x18,};
byte nine[]={0x8,0x8,0x4,0x2,0x1,0xd,0x16,0x4,};

////////////////////////////////////////////////////////////////////////////
//Week days
void monday()
{
  
  lcd.createChar(0, se);
  lcd.createChar(1, am);
  lcd.createChar(2, ba);
  lcd.createChar(3, r);
  lcd.begin(16,2);
  lcd.setCursor(5,1);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));

}
void tuesday()
{
  
  lcd.createChar(0, m);
  lcd.createChar(1, ono);
  lcd.createChar(2, g);
  lcd.createChar(3, l);
  lcd.createChar(4, ba);
  lcd.createChar(5, r);

  lcd.begin(16,2);
  lcd.setCursor(5,1);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.write(byte(5));


}

void wednesday()
{
  
  lcd.createChar(0, bu);
  lcd.createChar(1, dh);
  lcd.createChar(2, ba);
  lcd.createChar(3, r);
  lcd.begin(16,2);
  lcd.setCursor(5,1);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));

}

void thursday()
{
  
  lcd.createChar(0, bri);
  lcd.createChar(1, h);
  lcd.createChar(2, sp);
  lcd.createChar(3, ti);
  lcd.createChar(4, ba);
  lcd.createChar(5, r);
  lcd.begin(16,2);
  lcd.setCursor(5,1);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.write(byte(5));

}

void friday()
{
  
  lcd.createChar(0, shu);
  lcd.createChar(1, cro);
  lcd.createChar(2, ba);
  lcd.createChar(3, r);
  lcd.begin(16,2);
  lcd.setCursor(5,1);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));

}
void saturday()
{
  
  lcd.createChar(0, sho);
  lcd.createChar(1, ni);
  lcd.createChar(2, ba);
  lcd.createChar(3, r);
  lcd.begin(16,2);
  lcd.setCursor(5,1);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));

}

void sunday()
{
  
  lcd.createChar(0, r);
  lcd.createChar(1, bi);
  lcd.createChar(2, ba);
  lcd.begin(16,2);
  lcd.setCursor(5,1);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(0));

}

void dOfTheWeek(char *a)
{
  lcd.clear();
  if(!strcmp("Monday",a))
      monday();
  if(!strcmp("Tuesday",a))
      tuesday();
  if(!strcmp("Wednesday",a))
      wednesday();
  if(!strcmp("Thursday",a))
      thursday();
  if(!strcmp("Friday",a))
      friday();
  if(!strcmp("Saturday",a))
      saturday();
  if(!strcmp("Sunday",a))
      sunday();
 
}
////////////////////////////////////////////////////////////////////////////////////////////
///Date
////////////////////////////////////////////////////////////////////////////////////
void Time(int hour, int mins , int second)
{
  if(hour>12)
    hour-=12;
  int second2=second%10;
 second=second/10;
 int second1=second%10;
 second=second/10;

 int mins2=mins%10;
 mins=mins/10;
 int mins1=mins%10;
 mins=mins/10;

 int hour2=hour%10;
 hour=hour/10;
 int hour1=hour%10;
 hour=hour/10;
  //lcd3.clear();
  lcd3.backlight();
 if(hour1==0)
 {
   lcd3.createChar(0, zero);
 }
 else if(hour1==1)
 {
   lcd3.createChar(0, one);
 }
 else if(hour1==2)
 {
   lcd3.createChar(0, two);
 }
 else if(hour1==3)
 {
   lcd3.createChar(0, three);
 }
 else if(hour1==4)
 {
   lcd3.createChar(0, four);
 }
 else if(hour1==5)
 {
   lcd3.createChar(0, five);
 }
 else if(hour1==6)
 {
   lcd3.createChar(0, six);
 }
 else if(hour1==7)
 {
   lcd3.createChar(0, seven);
 }
 else if(hour1==8)
 {
   lcd3.createChar(0, eight);
 }
 else if(hour1==9)
 {
   lcd3.createChar(0, nine);
 }

 if(hour2==0)
 {
   lcd3.createChar(1, zero);
 }
 else if(hour2==1)
 {
   lcd3.createChar(1, one);
 }
 else if(hour2==2)
 {
   lcd3.createChar(1, two);
 }
 else if(hour2==3)
 {
   lcd3.createChar(1, three);
 }
 else if(hour2==4)
 {
   lcd3.createChar(1, four);
 }
 else if(hour2==5)
 {
   lcd3.createChar(1, five);
 }
 else if(hour2==6)
 {
   lcd3.createChar(1, six);
 }
 else if(hour2==7)
 {
   lcd3.createChar(1, seven);
 }
 else if(hour2==8)
 {
   lcd3.createChar(1, eight);
 }
 else if(hour2==9)
 {
   lcd3.createChar(1, nine);
 }

if(mins1==0)
 {
   lcd3.createChar(2, zero);
 }
 else if(mins1==1)
 {
   lcd3.createChar(2, one);
 }
 else if(mins1==2)
 {
   lcd3.createChar(2, two);
 }
 else if(mins1==3)
 {
   lcd3.createChar(2, three);
 }
 else if(mins1==4)
 {
   lcd3.createChar(2, four);
 }
 else if(mins1==5)
 {
   lcd3.createChar(2, five);
 }
 else if(mins1==6)
 {
   lcd3.createChar(2, six);
 }
 else if(mins1==7)
 {
   lcd3.createChar(2, seven);
 }
 else if(mins1==8)
 {
   lcd3.createChar(2, eight);
 }
 else if(mins1==9)
 {
   lcd3.createChar(2, nine);
 }

if(mins2==0)
 {
   lcd3.createChar(3, zero);
 }
 else if(mins2==1)
 {
   lcd3.createChar(3, one);
 }
 else if(mins2==2)
 {
   lcd3.createChar(3, two);
 }
 else if(mins2==3)
 {
   lcd3.createChar(3, three);
 }
 else if(mins2==4)
 {
   lcd3.createChar(3, four);
 }
 else if(mins2==5)
 {
   lcd3.createChar(3, five);
 }
 else if(mins2==6)
 {
   lcd3.createChar(3, six);
 }
 else if(mins2==7)
 {
   lcd3.createChar(3, seven);
 }
 else if(mins2==8)
 {
   lcd3.createChar(3, eight);
 }
 else if(mins2==9)
 {
   lcd3.createChar(3, nine);
 }
 if(second1==0)
 {
   lcd3.createChar(4, zero);
 }
 else if(second1==1)
 {
   lcd3.createChar(4, one);
 }
 else if(second1==2)
 {
   lcd3.createChar(4, two);
 }
 else if(second1==3)
 {
   lcd3.createChar(4, three);
 }
 else if(second1==4)
 {
   lcd3.createChar(4, four);
 }
 else if(second1==5)
 {
   lcd3.createChar(4, five);
 }
 else if(second1==6)
 {
   lcd3.createChar(4, six);
 }
 else if(second1==7)
 {
   lcd3.createChar(4, seven);
 }
 else if(second1==8)
 {
   lcd3.createChar(4, eight);
 }
 else if(second1==9)
 {
   lcd3.createChar(4, nine);
 }
 if(second2==0)
 {
   lcd3.createChar(5, zero);
 }
 else if(second2==1)
 {
   lcd3.createChar(5, one);
 }
 else if(second2==2)
 {
   lcd3.createChar(5, two);
 }
 else if(second2==3)
 {
   lcd3.createChar(5, three);
 }
 else if(second2==4)
 {
   lcd3.createChar(5, four);
 }
 else if(second2==5)
 {
   lcd3.createChar(5, five);
 }
 else if(second2==6)
 {
   lcd3.createChar(5, six);
 }
 else if(second2==7)
 {
   lcd3.createChar(5, seven);
 }
 else if(second2==8)
 {
   lcd3.createChar(5, eight);
 }
 else if(second2==9)
 {
   lcd3.createChar(5, nine);
 }
 lcd3.begin(16,2);
  lcd3.setCursor(4,0);
  lcd3.write(byte(0));
  lcd3.write(byte(1));
  lcd3.write(':');
  lcd3.write(byte(2));
  lcd3.write(byte(3));
  lcd3.write(':');
  lcd3.write(byte(4));
  lcd3.write(byte(5));

}
void Date(int year, int month , int date)
{
 int year2=year%10;
 year=year/10;
 int year1=year%10;
 year=year/10;

 int month2=month%10;
 month=month/10;
 int month1=month%10;
 month=month/10;

 int date2=date%10;
 date=date/10;
 int date1=date%10;
 date=date/10;
//  lcd2.clear();
 if(date1==0)
 {
   lcd.createChar(0, zero);
 }
 else if(date1==1)
 {
   lcd.createChar(0, one);
 }
 else if(date1==2)
 {
   lcd.createChar(0, two);
 }
 else if(date1==3)
 {
   lcd.createChar(0, three);
 }
 else if(date1==4)
 {
   lcd.createChar(0, four);
 }
 else if(date1==5)
 {
   lcd.createChar(0, five);
 }
 else if(date1==6)
 {
   lcd.createChar(0, six);
 }
 else if(date1==7)
 {
   lcd.createChar(0, seven);
 }
 else if(date1==8)
 {
   lcd.createChar(0, eight);
 }
 else if(date1==9)
 {
   lcd.createChar(0, nine);
 }

 if(date2==0)
 {
   lcd.createChar(1, zero);
 }
 else if(date2==1)
 {
   lcd.createChar(1, one);
 }
 else if(date2==2)
 {
   lcd.createChar(1, two);
 }
 else if(date2==3)
 {
   lcd.createChar(1, three);
 }
 else if(date2==4)
 {
   lcd.createChar(1, four);
 }
 else if(date2==5)
 {
   lcd.createChar(1, five);
 }
 else if(date2==6)
 {
   lcd.createChar(1, six);
 }
 else if(date2==7)
 {
   lcd.createChar(1, seven);
 }
 else if(date2==8)
 {
   lcd.createChar(1, eight);
 }
 else if(date2==9)
 {
   lcd.createChar(1, nine);
 }

if(month1==0)
 {
   lcd.createChar(2, zero);
 }
 else if(month1==1)
 {
   lcd.createChar(2, one);
 }
 else if(month1==2)
 {
   lcd.createChar(2, two);
 }
 else if(month1==3)
 {
   lcd.createChar(2, three);
 }
 else if(month1==4)
 {
   lcd.createChar(2, four);
 }
 else if(month1==5)
 {
   lcd.createChar(2, five);
 }
 else if(month1==6)
 {
   lcd.createChar(2, six);
 }
 else if(month1==7)
 {
   lcd.createChar(2, seven);
 }
 else if(month1==8)
 {
   lcd.createChar(2, eight);
 }
 else if(month1==9)
 {
   lcd.createChar(2, nine);
 }

if(month2==0)
 {
   lcd.createChar(3, zero);
 }
 else if(month2==1)
 {
   lcd.createChar(3, one);
 }
 else if(month2==2)
 {
   lcd.createChar(3, two);
 }
 else if(month2==3)
 {
   lcd.createChar(3, three);
 }
 else if(month2==4)
 {
   lcd.createChar(3, four);
 }
 else if(month2==5)
 {
   lcd.createChar(3, five);
 }
 else if(month2==6)
 {
   lcd.createChar(3, six);
 }
 else if(month2==7)
 {
   lcd.createChar(3, seven);
 }
 else if(month2==8)
 {
   lcd.createChar(3, eight);
 }
 else if(month2==9)
 {
   lcd.createChar(3, nine);
 }
 if(year1==0)
 {
   lcd.createChar(4, zero);
 }
 else if(year1==1)
 {
   lcd.createChar(4, one);
 }
 else if(year1==2)
 {
   lcd.createChar(4, two);
 }
 else if(year1==3)
 {
   lcd.createChar(4, three);
 }
 else if(year1==4)
 {
   lcd.createChar(4, four);
 }
 else if(year1==5)
 {
   lcd.createChar(4, five);
 }
 else if(year1==6)
 {
   lcd.createChar(4, six);
 }
 else if(year1==7)
 {
   lcd.createChar(4, seven);
 }
 else if(year1==8)
 {
   lcd.createChar(4, eight);
 }
 else if(year1==9)
 {
   lcd.createChar(4, nine);
 }
 if(year2==0)
 {
   lcd.createChar(5, zero);
 }
 else if(year2==1)
 {
   lcd.createChar(5, one);
 }
 else if(year2==2)
 {
   lcd.createChar(5, two);
 }
 else if(year2==3)
 {
   lcd.createChar(5, three);
 }
 else if(year2==4)
 {
   lcd.createChar(5, four);
 }
 else if(year2==5)
 {
   lcd.createChar(5, five);
 }
 else if(year2==6)
 {
   lcd.createChar(5, six);
 }
 else if(year2==7)
 {
   lcd.createChar(5, seven);
 }
 else if(year2==8)
 {
   lcd.createChar(5, eight);
 }
 else if(year2==9)
 {
   lcd.createChar(5, nine);
 }
 lcd.begin(16,2);
  lcd.setCursor(4,0);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write('/');
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write('/');
  lcd.write(byte(4));
  lcd.write(byte(5));
}

/////////////////////////////////////////////////////////////////////////////////////////////////
void setup () {
  Serial.begin(9600);
  lcd.init();
  //lcd2.init();
  lcd.begin(20, 4);
  lcd.backlight();

  lcd3.begin(20, 4);
  //lcd3.backlight();

  Wire.begin();
  RTC.begin();
 Bluetooth.begin(9600);
  if ( RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop () {


















  
    DateTime now = RTC.now();
    
    lcd.setCursor(1,0);
    //dOfTheWeek(daysOfTheWeek[now.dayOfTheWeek()]);
    
  
    unsigned long currentTime = millis();

/* This is event 1 stuff*/ 
if( currentTime - previousTime_1 >= eventTime_1 ){
  
  if (Bluetooth.available())
  {
    BT_input=(Bluetooth.read());
    Serial.println(Bluetooth.available());
 
    if(BT_input=='-')
    {
      date[i++]='\0';
      stat=stat%3+1;
    }
    if(stat==0)
    {
      date[i++]=BT_input;
      }
      if(BT_input=='#')
    {
      times[j++]='\0';
      stat=stat%3+1;
    }
    if(stat==1&&BT_input!='-')
    {
      times[j++]=BT_input;
      }
   
      

      
  }
 
else if(!strcmp(cdate[0],"")||!strcmp(cdate[1],"")||!strcmp(cdate[2],"")||!strcmp(chour[0],"")||!strcmp(chour[1],"")||!strcmp(chour[2],"")){
 Serial.println(times);
 Serial.println(date);
cdate[0][0]=date[0];
cdate[0][1]=date[1];
cdate[0][2]='\0';
cdate[1][0]=date[3];
cdate[1][1]=date[4];
cdate[1][2]='\0';
cdate[2][0]=date[6];
cdate[2][1]=date[7];
cdate[2][2]='\0';
chour[0][0]=times[0];
chour[0][1]=times[1];
chour[0][2]='\0';
chour[1][0]=times[3];
chour[1][1]=times[4];
chour[1][2]='\0';
chour[2][0]=times[6];
chour[2][1]=times[7];
chour[2][2]='\0';
 Serial.println(cdate[0]);
 Serial.println(cdate[1]);
 Serial.println(cdate[2]);
   Serial.println(chour[0]);
 Serial.println(chour[1]);
 Serial.println(chour[2]);

RTC.adjust(DateTime(2000+atoi(cdate[2]),atoi(cdate[1]),atoi(cdate[0]), atoi(chour[0]), atoi(chour[1]), atoi(chour[2])));
strcpy(cdate[0],"");
strcpy(chour[0],"");
strcpy(cdate[1],"");
strcpy(chour[1],"");
strcpy(cdate[2],"");
strcpy(chour[2],"");
}
  // Update the timing for the next event 
  previousTime_1 = currentTime;
  Time(int(now.hour()),int(now.minute()),int(now.second()));
 // Serial.println(now.second());
 if(rotate==1){
    lcd.clear();
    Date(int(now.year()),int(now.month()),int(now.day()));

  
  
  }

  if(rotate==2){
  lcd.clear();
  dOfTheWeek(daysOfTheWeek[now.dayOfTheWeek()]);

  

  }
  rotate=rotate%2+1;
  
}



    



    

  
}
  
