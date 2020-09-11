//#define  KLCD_NUL           0x00                     // Null
#include<SoftwareSerial.h>
SoftwareSerial mySerial(0,1); // rx tx 핀번호 정하기

#define  KLCD_HOME          0x01                     // Cursor Home
#define  KLCD_CLSTART       0x02                     // Cursor Move to Line Start
#define  KLCD_CRIGHT        0x03                     // Cursor Move to Right
#define  KLCD_CLEFT         0x04                     // Cursor Move to Left
#define  KLCD_CUP           0x05                     // Cursor Move to Up
#define  KLCD_CDOWN         0x06                     // Cursor Move to Down
#define  KLCD_NORMAL        0x08                     // Normal Screen Forground : Black / Background : White
#define  KLCD_REVERSE       0x09                     // Invert Screen Forground : White / Backgriund : Black                                 
#define  KLCD_CLEAR         0x0B                     // Clear Screen with Cursor Home
#define  KLCD_ENTER         0x0D                     // Carriage Return                  
#define  KLCD_LOCATE        0x0E                                                     


byte led [13] [13] = {
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
};

int num, i; // 반복문 변수
int ledPin_1 = 2;
int ledPin_1p = 3;
int ledPin_2 = 4;
int ledPin_2p = 5;
int ledPin_3 = 6;
int ledPin_4 = 7;
int ledPin_4p = 8;
int ledPin_5 = 9;
int ledPin_5p = 10;
int ledPin_6 = 11;
int ledPin_6p = 12;
int ledPin_7 = 13;
int ledPin_8 = A5;
int buttonState;
int button1 = A0;   
int button2 = A2; 
int   count;

void klcd(unsigned int v) {
//  1 바이트의 영문자/숫자/제어코드 또는 2 바이트로 구성되는 한글코드(KS5601-1987)를 
//  LCD화면에 출력합니다.
 unsigned char d;
 if (v > 0xFF) { d = (v>>8) & 0xFF;   Serial.write(d); }
 d = v & 0xFF; Serial.write(d); 
}

void klcd_locate(unsigned char r, unsigned char c) {
//  커서 위치를 설정합니다. 행(r)과 열(c)을 지정합니다 행은 0-3 범위이고 열은 0-15 범위의 숫자입니다. 
  unsigned char t;
  Serial.write(KLCD_LOCATE);
  t = ((r<<5) | (c & 0x1F));
  Serial.write(t);
}

void setup() {

  pinMode(ledPin_1, OUTPUT);  
  pinMode(ledPin_1p, OUTPUT);  
  pinMode(ledPin_2, OUTPUT);  
  pinMode(ledPin_2p, OUTPUT);  
  pinMode(ledPin_3, OUTPUT);  
  pinMode(ledPin_4, OUTPUT);    
  pinMode(ledPin_4p, OUTPUT);  
  pinMode(ledPin_5, OUTPUT);  
  pinMode(ledPin_5p, OUTPUT);  
  pinMode(ledPin_6, OUTPUT);  
  pinMode(ledPin_6p, OUTPUT);  
  pinMode(ledPin_7, OUTPUT);  
  pinMode(A5, OUTPUT);  
  digitalWrite(A5, HIGH);
  pinMode(A0, OUTPUT);  
  digitalWrite(A0, HIGH);
  pinMode(A2, OUTPUT);  
  digitalWrite(A2, HIGH); 
        
  Serial.begin(9600);                // Initialize Serial Port 
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(klcd, OUTPUT);
  delay(300);
  klcd(KLCD_CLEAR);                  // Clear Screen
  delay(300);
  klcd(KLCD_CLEAR);                  // Clear Screen
  klcd(KLCD_NORMAL);                 // Normal Screen
} 

void ledon(int num) 
{
  for(i=0; i<12; i++)
  digitalWrite(i+2, led[num][i]);    
}

void ledon2()
{
      digitalWrite(19, HIGH);
      delay(300);
      digitalWrite(19, LOW);
      delay(300);   
}

void loop() {
      /*ledon(0);
      delay(300);
      ledon(1);
      delay(300);
      ledon(2);
      delay(300);
      ledon(3);
      delay(300);      
      ledon(4);
      delay(300);
      ledon(5);
      delay(300);
      ledon(6);
      delay(300);
      ledon(7);
      delay(300);
      ledon(8);
      delay(300);
      ledon(9);
      delay(300);
      ledon(10); 
      delay(300);
      ledon(11);
      delay(300);                                          
      ledon(12);
      delay(300);  
      ledon2();
      delay(300);*/



/*String st = Serial.print('klcd');

switch(st)
{
  case '1':
  ledon(0);
  break;
  case '2':
  ledon(1);
  break;
  case '3':
  ledon(2);
  break;
  case '4':
  ledon(3);
  break;
  case '5':
  ledon(4);
  break;  
  case '6':
  ledon(5);
  break;
  case '7':
  ledon(6);
  break;
  case '8':
  ledon(7);
  break;
  case '9':
  ledon(8);
  break;
  
}*/
//--------------- 초기화면 ------------------------  
  
 klcd(KLCD_CLEAR);                   // Clear Screen
 klcd(KLCD_NORMAL);                  // Normal Screen
 klcd(0xBEC7);    //  "악"
  klcd(0xBAB8);    //  "보"
  klcd(0xBCB1);    //  "선"
  klcd(0xC5C3);    //  "택"
  klcd(0xC0BB);    //  "을"
  delay(1000);  
  Serial.println();                // New Line
  klcd(0xC7D8);    //  "해"
  klcd(0xC1D6);    //  "주"
  klcd(0xBCBC);    //  "세"
  klcd(0xBFE4);    //  "요"
  delay(1000);
  Serial.println();                // New Line
  klcd('1');    //  "1"
  klcd(0xB9F8);    //  "번"  
  klcd(' ');    //  " "    
  klcd(0xC2F0);    //  "찐"
  klcd(0xC0CC);    //  "이"
  klcd(0xBEDF);    //  "야"
  delay(1000);
  Serial.println();                // New Line
  klcd('2');    //  "2"
  klcd(0xB9F8);    //  "번"  
  klcd(' ');    //  " "  
  klcd(0xB3B2);    //  "남"
  klcd(0xC7E0);    //  "행"
  klcd(0xBFAD);    //  "열"
  klcd(0xC2F7);    //  "차"
  delay(1000);



  
//--------------- 찐이야 ------------------------  
  int button1 = digitalRead(A0);
  if (button1 == 0)
  {
  digitalWrite(klcd, 0);
  klcd(KLCD_CLEAR);                   // Clear Screen
  klcd(KLCD_NORMAL);                  // Normal Screen

 

  klcd_locate(1,0);
  klcd(0xC2F0);    //  "찐"
  klcd_locate(2,0);
  klcd('5');  // 음계
  //ledon(9);
  klcd_locate(2,1);
  klcd('+');  // 음계
  klcd_locate(1,4);
  klcd(0xC2F0);    //  "찐"
  klcd_locate(2,4);
  klcd('5');  // 음계
  klcd_locate(2,5);
  klcd('+');  // 음계
  klcd_locate(1,8);
  klcd(0xC2F0);    //  "찐"
  klcd_locate(2,8);
  klcd('5');  // 음계
  klcd_locate(2,9);
  klcd('+');  // 음계
  klcd_locate(1,12);
  klcd(0xC2F0);    //  "찐"
  klcd_locate(2,12);
  klcd('5');  // 음계
  klcd_locate(2,13);
  klcd('+');  // 음계


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(3,0);
  klcd('-');  //박자 시작
  delay(500);
  klcd_locate(3,2);
  klcd('-'); // 박자 끝
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(3,4);
  klcd('-');  //박자 시작
  delay(500);
  klcd_locate(3,6);
  klcd('-'); // 박자 끝
  delay(500);

  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,8);
  Serial.print('*');
  klcd_locate(3,8);
  klcd('-');  //박자 시작
  delay(500);
  klcd_locate(3,10);
  klcd('-'); // 박자 끝
  delay(500);

  klcd_locate(0,8);
  klcd(' ');
  klcd_locate(0,12);
  Serial.print('*');
  klcd_locate(3,12);
  klcd('-');  //박자 시작
  delay(500);
  klcd_locate(3,14);
  klcd('-'); // 박자 끝
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen


  
  klcd_locate(1,0);
  klcd(0xC2F0);    //  "찐"
  klcd_locate(2,0);
  klcd('5');
  klcd_locate(2,1);
  klcd('+');
  klcd_locate(1,4);
  klcd(0xC0CC);    //  "이"
  klcd_locate(2,4);
  klcd('5');
  klcd_locate(1,6);
  klcd(0xBEDF);    //  "야"
  klcd_locate(2,6);
  klcd('5');
  klcd_locate(2,7);
  klcd('+');


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(3,0);
  klcd('-');
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(3,4);
  klcd('-');
  delay(500);

  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(3,6);
  klcd('5');
  delay(500);
  klcd_locate(3,6);
  klcd('4');
  delay(500);
  klcd_locate(3,6);
  klcd('3');
  delay(500);
  klcd_locate(3,6);
  klcd('2');
  delay(500);
  klcd_locate(3,6);
  klcd('1');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen



  

  klcd_locate(1,0);
  klcd(0xBFCF);    //  "완"
  klcd_locate(2,0);
  klcd('5');  // 음계
  klcd_locate(2,1);
  klcd('+');  // 음계
  klcd_locate(1,4);
  klcd(0xC0FC);    //  "전"
  klcd_locate(2,4);
  klcd('5');
  klcd_locate(2,5);
  klcd('+');
  klcd_locate(1,6);
  klcd(0xC2F0);    //  "찐"
  klcd_locate(2,6);
  klcd('5');
  klcd_locate(2,7);
  klcd('+');
  klcd_locate(1,10);
  klcd(0xC0CC);    //  "이"
  klcd_locate(2,10);
  klcd('5'); 
  klcd_locate(1,12);
  klcd(0xBEDF);    //  "야"
  klcd_locate(2,12);
  klcd('5');
  klcd_locate(2,13);
  klcd('+');

  klcd_locate(0,0);
  Serial.print('*');  
  klcd_locate(3,0); //"완"
  klcd('-');  //박자 시작
  delay(500);
  klcd_locate(3,2); //"완"
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(3,4); //"전"
  klcd('-');
  delay(500);


  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(3,6); //"찐"
  klcd('-');
  delay(500);
  klcd_locate(3,8); //"찐"
  klcd('-');
  delay(500);

  klcd_locate(0,7);
  klcd(' ');
  klcd_locate(0,10);
  Serial.print('*');
  klcd_locate(3,10); //"이"
  klcd('-');
  delay(500);

  klcd_locate(0,10);
  klcd(' ');
  klcd_locate(0,12);
  Serial.print('*');
  klcd_locate(3,12); //"야"
  klcd('-');
  delay(500);
  klcd_locate(3,12);
  klcd('8');
  delay(500);
  klcd_locate(3,12);
  klcd('7');
  delay(500);
  klcd_locate(3,12);
  klcd('6');
  delay(500);
  klcd_locate(3,12);
  klcd('5');
  delay(500);
  klcd_locate(3,12);
  klcd('4');
  delay(500);
  klcd_locate(3,12);
  klcd('3');
  delay(500);
  klcd_locate(3,12);
  klcd('2');
  delay(500);
  klcd_locate(3,12);
  klcd('1');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen

//여기까지ok


  klcd_locate(1,0);
  klcd(0xC1F8);    //  "진"
  klcd_locate(2,0);
  klcd('5');  // 음계
  klcd_locate(1,4);
  klcd(0xC2A5);    //  "짜"
  klcd_locate(2,4);
  klcd('5');  // 음계  
  klcd_locate(2,5);
  klcd('+');  // 음계  
  klcd_locate(1,8);
  klcd(0xB0A1);    //  "가"
  klcd_locate(2,8);
  klcd('4');


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(3,0); // "진"
  klcd('-');
  delay(500);
  klcd_locate(3,2); // "진"
  klcd('-');
  delay(500);
  
  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(3,4); // "짜"
  klcd('-');
  delay(500);
  klcd_locate(3,6); // "짜" 
  klcd('-');
  delay(500);
  
  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,8);
  Serial.print('*');
  klcd_locate(3,8); // "가"
  klcd('-');  
  delay(500);
  klcd_locate(3,10); // "가"
  klcd('-');  
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen



  klcd_locate(1,0);
  klcd(0xB3AA);    //  "나"
  klcd_locate(2,0);
  klcd('2');
  klcd_locate(2,1);
  klcd('+');
  klcd_locate(1,4); 
  klcd(0xC5B8);    //  "타"
  klcd_locate(2,4);
  klcd('2');
  klcd_locate(2,5);
  klcd('+');
  klcd_locate(1,8); 
  klcd(0xB3B5);    //  "났"  
  klcd_locate(2,8);
  klcd('4');  
  klcd_locate(1,12); 
  klcd(0xB4D9);    //  "다"
  klcd_locate(2,12);
  klcd('5');


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(3,0); // "나"
  klcd('-');   
  delay(500);
  
  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,2);
  Serial.print('*');
  klcd_locate(3,2); // "나"
  klcd('-');   
  delay(500);
  
  klcd_locate(0,2);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(3,4); // "타"
  klcd('-');   
  delay(500);
  klcd_locate(3,6); // "타"
  klcd('-');   
  delay(500);
  
  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,8);
  Serial.print('*');
  klcd_locate(3,8);  // "났"
  klcd('-');   
  delay(500);
  klcd_locate(3,10); // "났"
  klcd('-');   
  delay(500);
  
  klcd_locate(0,8);
  klcd(' ');
  klcd_locate(0,12);
  Serial.print('*');
  klcd_locate(3,12); // "다"
  klcd('-');   
  delay(500);
  klcd_locate(3,14); // "다"
  klcd('-');   
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 


  klcd_locate(1,0); 
  klcd(0xC1F6);    //  "지"
  klcd_locate(2,0);
  klcd('5');
  klcd_locate(1,3); 
  klcd(0xB1DD);    //  "금"
  klcd_locate(2,3);
  klcd('1');


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(3,0);  //"지"
  klcd('-');   
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(3,3); // "금"
  klcd('-');   
  delay(500);
  klcd_locate(3,3); // "금"
  klcd('6');   
  delay(500);
  klcd_locate(3,3); // "금"
  klcd('5');   
  delay(500);  
  klcd_locate(3,3);// "금"
  klcd('4');   
  delay(500);
  klcd_locate(3,3);// "금"
  klcd('3');   
  delay(500);
  klcd_locate(3,3);// "금"
  klcd('2');   
  delay(500);
  klcd_locate(3,3);// "금"
  klcd('1');   
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen
// 여기까지 ok


  klcd_locate(1,0); 
  klcd(0xC2F0);    //  "찐"
  klcd_locate(2,0);
  klcd('5');
  klcd_locate(2,1);
  klcd('+');
  klcd_locate(1,4); 
  klcd(0xC2F0);    //  "찐"
  klcd_locate(2,4);
  klcd('5');
  klcd_locate(2,5);
  klcd('+');
  klcd_locate(1,8); 
  klcd(0xC2F0);    //  "찐"
  klcd_locate(2,8);
  klcd('5');
  klcd_locate(2,9);
  klcd('+');
  klcd_locate(1,10); 
  klcd(0xC2F0);    //  "찐"
  klcd_locate(2,10);
  klcd('5');  
  klcd_locate(2,11);
  klcd('+');  



  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(3,0); // "찐"
  klcd('-');
  delay(500);    
  klcd_locate(3,2); // "찐"
  klcd('-');
  delay(500);  
 // klcd_locate(3,2); // "찐"  ???
  //klcd('-'); 
 // delay(500);
  
  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(3,4); // "찐"
  klcd('-');  
  delay(500);
  klcd_locate(3,6); // "찐"
  klcd('-');  
  delay(500);
  
  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,8);
  Serial.print('*');
  klcd_locate(3,8); // "찐"
  klcd('-');  
  delay(500);
  
  klcd_locate(0,8);
  klcd(' ');
  klcd_locate(0,10);
  Serial.print('*');
  klcd_locate(3,10); // "찐"
  klcd('-');  
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen



  klcd_locate(1,0); 
  klcd(0xC2F0);    //  "찐"
  klcd_locate(2,0);
  klcd('5');
  klcd_locate(2,1);
  klcd('+');
  klcd_locate(1,4); 
  klcd(0xC0CC);    //  "이"
  klcd_locate(2,4);
  klcd('5');
  klcd_locate(1,6); 
  klcd(0xBEDF);    //  "야"
  klcd_locate(2,6);
  klcd('5');
  klcd_locate(2,7);
  klcd('+');


  klcd_locate(0,0);
  Serial.print('*');      
  klcd_locate(3,0); // "찐"
  klcd('-');     
  delay(500);
  
  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,2);
  Serial.print('*');
  klcd_locate(3,2); // "찐"
  klcd('-');     
  delay(500);  
  
  klcd_locate(0,2);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*'); 
  klcd_locate(3,4); //  "이"
  klcd('-');     
  delay(500);   
  
  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');   
  klcd_locate(3,6); //  "야"
  klcd('-');     
  delay(500);  
  klcd_locate(3,6); //  "야"
  klcd('5');     
  delay(500);  
  klcd_locate(3,6); //  "야"
  klcd('4');     
  delay(500);  
  klcd_locate(3,6); //  "야"
  klcd('3');     
  delay(500);  
  klcd_locate(3,6); //  "야"
  klcd('2');     
  delay(500);  
  klcd_locate(3,6); //  "야"
  klcd('1');     
  delay(500);  
  klcd(KLCD_CLEAR);                   // Clear Screen

// 여기까지 



//  여기서부터 다시 보기
  klcd_locate(1,0); 
  klcd(0xBFCF);    //  "완"
  klcd_locate(2,0);
  klcd('6');
  klcd_locate(2,1);
  klcd('+');
  klcd_locate(1,4); 
  klcd(0xC0FC);    //  "전"
  klcd_locate(2,4);
  klcd('6');
  klcd_locate(2,5);
  klcd('+');

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(3,0); //"완"
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  //klcd_locate(3,2);  //???
 // klcd('-'); //????
  klcd_locate(3,4); //"전"
  klcd('-');
  delay(500);  
  klcd(KLCD_CLEAR);                   // Clear Screen


  
  klcd_locate(1,0); 
  klcd(0xC2F0);    //  "찐"
  klcd_locate(2,0);
  klcd('6');
  klcd_locate(2,1);
  klcd('+');
  klcd_locate(1,4); 
  klcd(0xC0CC);    //  "이"
  klcd_locate(2,4);
  klcd('5');
  klcd_locate(2,5);
  klcd('+');
  klcd_locate(1,6); 
  klcd(0xBEDF);    //  "야"
  klcd_locate(2,6);
  klcd('6');
  klcd_locate(2,7);
  klcd('+');

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(3,0);
  klcd('-');
  delay(500);  
  klcd_locate(3,2); // "찐"
  klcd('-');
  delay(500);  

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(3,4); // "이"
  klcd('-');
  delay(500);

  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(3,6); // "야"
  klcd('-');
  delay(500);
  klcd_locate(3,6);
  klcd('6');
  delay(500);
  klcd_locate(3,6);
  klcd('5');
  delay(500);
  klcd_locate(3,6);
  klcd('4');
  delay(500);
  klcd_locate(3,6);
  klcd('3');
  delay(500);
  klcd_locate(3,6);
  klcd('2');
  delay(500);
  klcd_locate(3,6);
  klcd('1');
  delay(500);
  klcd(KLCD_CLEAR);    // Clear Screen



  // 여기까지 


  klcd_locate(1,0);
  klcd(0xC2F0);    //  "찐"
  klcd_locate(2,0);
  klcd('6');
  klcd_locate(2,1);
  klcd('+');
  klcd_locate(1,3); 
  klcd(0xC7CF);    //  "하"
  klcd_locate(2,3);
  klcd('5');
  klcd_locate(1,5);    
  klcd(0xB0D4);    //  "게"
  klcd_locate(2,5);
  klcd('6'); 

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(3,0); // "찐"
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(3,3); //"하"??
  klcd('-');
  delay(500);

  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(3,5); //"게"  ????
  klcd('-');
  delay(500);
  klcd_locate(3,7);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);    // Clear Screen

// 여기까지


  klcd_locate(1,0);  
  klcd(0xBBE7);    //  "사"
  klcd_locate(2,0);  
  klcd('7');
  klcd_locate(1,3);    
  klcd(0xB6FB);    //  "랑"
  klcd_locate(2,3);  
  klcd('6');
  klcd_locate(1,5);   
  klcd(0xC7D2);    //  "할"
  klcd_locate(2,5);  
  klcd('5');
  
  klcd_locate(1,9);   
  klcd(0xB0C5);    //  "거"
  klcd_locate(2,9);  
  klcd('4');
  klcd_locate(2,10);  
  klcd('+');
  klcd_locate(1,12);   
  klcd(0xBEDF);    //  "야"    
  klcd_locate(2,12);  
  klcd('3');


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(3,0);   //"사"
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(3,3);  //"랑" 
  klcd('-');
  delay(500);
  klcd_locate(3,3);  
  klcd('4');
  delay(500);
  klcd_locate(3,3);  
  klcd('3');
  delay(500);
  klcd_locate(3,3);  
  klcd('2');
  delay(500);
  klcd_locate(3,3);  
  klcd('1');
  delay(500);
  klcd_locate(3,3);  
  klcd(' ');
  delay(500);
  
  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(3,5);  //"할"
  klcd('-');      
  delay(500);
  klcd_locate(3,7);  
  klcd('-');      
  delay(500);

  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,9);
  Serial.print('*');
  klcd_locate(3,9);  //"거"
  klcd('-');      
  delay(500);

  klcd_locate(0,9);
  klcd(' ');
  klcd_locate(0,12);
  Serial.print('*');
  klcd_locate(3,12);  //"야"
  klcd('-');   
  delay(500);   
  klcd_locate(3,12);  
  klcd('5');   
  delay(500);  
  klcd_locate(3,12);  
  klcd('4');   
  delay(500);  
  klcd_locate(3,12);  
  klcd('3');   
  delay(500);  
  klcd_locate(3,12);  
  klcd('2');   
  delay(500);  
  klcd_locate(3,12);  
  klcd('1');   
  delay(500);            
  klcd(KLCD_CLEAR);                   // Clear Screen
  delay(1500);


//---------- 종료화면 ---------------------------

klcd_locate(1,0);
klcd(' ');
klcd(' ');
klcd(' ');
klcd(' ');
klcd(' ');
klcd(0xBFAC);   //"연"
klcd(0xC1D6);   //"주"
klcd(0xB0A1);   //"가"
delay(800);
Serial.println();                // New Line
klcd_locate(2,0);
klcd(' ');
klcd(' ');
klcd(' ');
klcd(0xB3A1);   //"끝"
klcd(0xB3B5);   //"났"
klcd(0xBDC0);   //"습"
klcd(0xB4CF);   //"니"
klcd(0xB4D9);   //"다"
Serial.print('!');
delay(4500);
klcd(KLCD_CLEAR);                   // Clear Screen
  }




  
//--------------- 남행열차 ------------------------  
  int button2 = digitalRead(A2);
  if (button2 == 0)
  {
digitalWrite(klcd, 0);
  klcd(KLCD_CLEAR);                   // Clear Screen Reverse  

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xBAF1);    //  "비"
  klcd_locate(2,0);
  klcd('3');  // 음계
  klcd_locate(3,0);
  klcd('-'); //박자 시작
  delay(500);

  klcd_locate(0,0);
  Serial.print(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xB3BB);    //  "내"
  klcd_locate(2,3);
  klcd('3');  // 음계
  klcd_locate(3,3);
  klcd('-');
  delay(500);


  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,5);
  klcd(0xB8AE);    //  "리"
  klcd_locate(2,5);
  klcd('3');
  klcd_locate(3,5);
  klcd('-'); //박자 시작
  delay(500);


  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xB4C2);    //  "는"
  klcd_locate(2,7);
  klcd('2'); //계
  klcd_locate(3,7);
  klcd('-'); //박자 시작
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen  완ㄹ


  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xC8A3);    //  "호"
  klcd_locate(2,0);
  klcd('3'); //계
  klcd_locate(3,0);
  klcd('-'); //박자 시작
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xB3B2);    //  "남"
  klcd_locate(2,3);
  klcd('5'); //계
  klcd_locate(3,3);
  klcd('-'); //박자 시작
  delay(500);
  klcd_locate(3,5);
  klcd('-'); //박자 끝  
  delay(500);

  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xBCB1);    //  "선"
  klcd_locate(2,7);
  klcd('7'); //계
  klcd_locate(3,7);
  klcd('-'); //박자 시작
  delay(500);
  klcd_locate(3,7);
  klcd('5');
  delay(500);
  klcd_locate(3,7);
  klcd('4');
  delay(500); 
  klcd_locate(3,7);
  klcd('3');
  delay(500);
  klcd_locate(3,7);
  klcd('2');
  delay(500);
  klcd_locate(3,7);
  klcd('1');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen  완ㄹ


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xB3B2);    //  "남"
  klcd_locate(2,0);
  klcd('8'); //계
  klcd_locate(3,0);
  klcd('-'); //박자 시작
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500); //


  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xC7E0);    //  "행"
  klcd_locate(2,4);
  klcd('7'); //계
  klcd_locate(3,4);
  klcd('-'); //박자 시작
  delay(500);
  klcd_locate(3,6);
  klcd('-');
  delay(500); //
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xBFAD);    //  "열"
  klcd_locate(2,0);
  klcd('6'); //계
  klcd_locate(3,0);
  klcd('-'); //박자 시작
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xC2F7);    //  "차"
  klcd_locate(2,4);
  klcd('8'); //계
  klcd_locate(3,4);
  klcd('-'); //박자 시작
  delay(500);


  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xBFA1);    //  "에"  ////////
  klcd_locate(2,7);
  klcd('7'); //계
  klcd_locate(3,7);
  klcd('-'); //박자 시작
  delay(500);
  klcd_locate(3,7);
  klcd('5');
  delay(500);
  klcd_locate(3,7);
  klcd('4');
  delay(500);
  klcd_locate(3,7);
  klcd('3');
  delay(500);
  klcd_locate(3,7);
  klcd('2');
  delay(500);  
  klcd_locate(3,7);
  klcd('1');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xC8E7);    //  "흔"
  klcd_locate(2,0);
  klcd('6'); //계
  klcd_locate(3,0);
  klcd('-'); //박자 시작
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xB5E9);    //  "들"
  klcd_locate(2,4);
  klcd('6'); //계
  klcd_locate(3,4);
  klcd('-'); //박자 시작
  delay(500);
  klcd_locate(3,6);
  klcd('-');
  delay(500);

  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,8);
  Serial.print('*');
  klcd_locate(1,8);
  klcd(0xB8AE);    //  "리"
  klcd_locate(2,8);
  klcd('7'); //계
  klcd_locate(3,8);
  klcd('-'); //박자 시작
  delay(500);

  klcd_locate(0,8);
  klcd(' ');
  klcd_locate(0,10);
  Serial.print('*');
  klcd_locate(1,10);
  klcd(0xB4C2);    //  "는"
  klcd_locate(2,10);
  klcd('6'); //계
  klcd_locate(3,10);
  klcd('-'); //박자 시작
  delay(500);
  klcd_locate(3,12);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xC2F7);    //  "차"
  klcd_locate(2,0);
  klcd('5'); //계
  klcd_locate(3,0);
  klcd('-'); //박자 시작
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xC3A2);    //  "창"
  klcd_locate(2,4);
  klcd('4'); //계
  klcd_locate(2,5);
  klcd('+'); //계
  klcd_locate(3,4);
  klcd('-'); //박자 시작
  delay(500);
  klcd_locate(3,6);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xB3CA);    //  "너"
  klcd_locate(2,0);
  klcd('3'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500); //

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xB8D3);    //  "머"
  klcd_locate(2,4);
  klcd('2'); //계
  klcd_locate(3,4);
  klcd('-');
  delay(500); //


  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xB7CE);    //  "로"
  klcd_locate(2,7);
  klcd('3'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500); //
  klcd_locate(3,7);
  klcd('8');
  delay(500); //
  klcd_locate(3,7);
  klcd('7');
  delay(500); //
  klcd_locate(3,7);
  klcd('6');
  delay(500); //
  klcd_locate(3,7);
  klcd('5');
  delay(500); //
  klcd_locate(3,7);
  klcd('4');
  delay(500); //
  klcd_locate(3,7);
  klcd('3');
  delay(500); //
  klcd_locate(3,7);
  klcd('2');
  delay(500); //
  klcd_locate(3,7);
  klcd('1');
  delay(500); //
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ //여기까지


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xBAF8);    //  "빗"
  klcd_locate(2,0);
  klcd('3'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500); //

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xB9B0);    //  "물"
  klcd_locate(2,4);
  klcd('3'); //계
  klcd_locate(3,4);
  klcd('-');
  delay(500);


  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xC0CC);    //  "이"
  klcd_locate(2,7);
  klcd('2'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xC8E5);    //  "흐"
  klcd_locate(2,0);
  klcd('3'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xB8A3);    //  "르"
  klcd_locate(2,3);
  klcd('5'); //계
  klcd_locate(3,3);
  klcd('-');
  delay(500);
  klcd_locate(3,5);
  klcd('-');
  delay(500); //

  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xB0ED);    //  "고"
  klcd_locate(2,7);
  klcd('7'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500);
  klcd_locate(3,7);
  klcd('5');
  delay(500); //
  klcd_locate(3,7);
  klcd('4');
  delay(500); //
  klcd_locate(3,7);
  klcd('3');
  delay(500); //
  klcd_locate(3,7);
  klcd('2');
  delay(500); // 
  klcd_locate(3,7);
  klcd('1');
  delay(500); //
  klcd(KLCD_CLEAR);                   // Clear Screen 완료 ㅇㅇ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xB3BB);    //  "내"
  klcd_locate(2,0);
  klcd('8'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500); //

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xB4AB);    //  "눈"
  klcd_locate(2,4);
  klcd('8'); //계
  klcd_locate(3,4);
  klcd('-');
  delay(500);

  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xB9B0);    //  "물"
  klcd_locate(2,7);
  klcd('8'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500);

  klcd_locate(0,7);
  klcd(' ');
  klcd_locate(0,10);
  Serial.print('*');
  klcd_locate(1,10);
  klcd(0xB5B5);    //  "도"
  klcd_locate(2,10);
  klcd('7'); //계
  klcd_locate(3,10);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완료 ㅇㅇ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xC8E5);    //  "흐"
  klcd_locate(2,0);
  klcd('6'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);


  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xB8A3);    //  "르"
  klcd_locate(2,3);
  klcd('8'); //계
  klcd_locate(3,3);
  klcd('-');
  delay(500);
  klcd_locate(3,5);
  klcd('-');
  delay(500);

  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xB0ED);    //  "고"
  klcd_locate(2,7);
  klcd('7'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500);
  klcd_locate(3,7);
  klcd('6');
  delay(500);
  klcd_locate(3,7);
  klcd('5');
  delay(500);
  klcd_locate(3,7);
  klcd('4');
  delay(500);
  klcd_locate(3,7);
  klcd('3');
  delay(500); 
  klcd_locate(3,7);
  klcd('2');
  delay(500);
  klcd_locate(3,7);
  klcd('1');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xC0D2);    //  "잃"
  klcd_locate(2,0);
  klcd('6'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xBEEE);    //  "어"
  klcd_locate(2,4);
  klcd('6'); //계
  klcd_locate(3,4);
  klcd('-');
  delay(500);
  klcd_locate(3,6);
  klcd('-');
  delay(500);

  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,8);
  Serial.print('*');
  klcd_locate(1,8);
  klcd(0xB9F6);    //  "버"
  klcd_locate(2,8);
  klcd('7'); //계
  klcd_locate(3,8);
  klcd('-');
  delay(500);

  klcd_locate(0,8);
  klcd(' ');
  klcd_locate(0,10);
  Serial.print('*');
  klcd_locate(1,10);
  klcd(0xB8B0);    //  "린"
  klcd_locate(2,10);
  klcd('6'); //계
  klcd_locate(3,10);
  klcd('-');
  delay(500);
  klcd_locate(3,12);
  klcd('-');
  delay(500);
  klcd_locate(3,14);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완료 ㅇㅇ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xC3B9);    //  "첫"
  klcd_locate(2,0);
  klcd('6'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xBBE7);    //  "사"
  klcd_locate(2,4);
  klcd('6'); //계
  klcd_locate(3,4);
  klcd('-');
  delay(500);


  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xB6FB);    //  "랑"
  klcd_locate(2,7);
  klcd('5'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500);

  klcd_locate(0,7);
  klcd(' ');
  klcd_locate(0,10);
  Serial.print('*');
  klcd_locate(1,10);
  klcd(0xB5B5);    //  "도"
  klcd_locate(2,10);
  klcd('4'); //계
  klcd_locate(3,10);
  klcd('-');
  delay(500);
  klcd_locate(3,12);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0); 
  klcd(0xC8E5);    //  "흐"
  klcd_locate(2,0);
  klcd('2'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xB8A3);    //  "르"
  klcd_locate(2,3);
  klcd('4'); //계
  klcd_locate(3,3);
  klcd('-');
  delay(500);
  klcd_locate(3,5);
  klcd('-');
  delay(500);


  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xB3D7);    //  "네"
  klcd_locate(2,7);
  klcd('4'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500);
  klcd_locate(3,7);
  klcd('6');
  delay(500);
  klcd_locate(3,7);
  klcd('5');
  delay(500);
  klcd_locate(3,7);
  klcd('4');
  delay(500);
  klcd_locate(3,7);
  klcd('3');
  delay(500);
  klcd_locate(3,7);
  klcd('2');
  delay(500);
  klcd_locate(3,7);
  klcd('1');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xB1F4);    //  "깜"
  klcd_locate(2,0);
  klcd('3'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xBAFD);    //  "빡"
  klcd_locate(2,4);
  klcd('8'); //계
  klcd_locate(3,4);
  klcd('-');
  delay(500);


  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xB1F4);    //  "깜"
  klcd_locate(2,7);
  klcd('7'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500);
  klcd_locate(3,9);
  klcd('-');
  delay(500);

  klcd_locate(0,7);
  klcd(' ');
  klcd_locate(0,11);
  Serial.print('*');
  klcd_locate(1,11);
  klcd(0xBAFD);    //  "빡"
  klcd_locate(2,11);
  klcd('8'); //계
  klcd_locate(3,11);
  klcd('-');
  delay(500);
  klcd_locate(3,13);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xC0CC);    //  "이"
  klcd_locate(2,0);
  klcd('7'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xB4C2);    //  "는"
  klcd_locate(2,4);
  klcd('3'); //계
  klcd_locate(3,4);
  klcd('-');
  delay(500);
  klcd_locate(3,6);
  klcd('-');
  delay(500);
  klcd_locate(3,8);
  klcd('-');
  delay(500);
  klcd_locate(3,10);
  klcd('-');
  delay(500);
  klcd_locate(3,12);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완료 ㅇ


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xC8F1);    //  "희"
  klcd_locate(2,0);
  klcd('3'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xB9CC);    //  "미"
  klcd_locate(2,3);
  klcd('6'); //계
  klcd_locate(3,3);
  klcd('-');
  delay(500);
  klcd_locate(3,3);
  klcd('6');
  delay(500);
  klcd_locate(3,3);
  klcd('5');
  delay(500);
  klcd_locate(3,3);
  klcd('4');
  delay(500);
  klcd_locate(3,3);
  klcd('3');
  delay(500);
  klcd_locate(3,3);
  klcd('2');
  delay(500);
  klcd_locate(3,3);
  klcd('1');
  delay(500);
  klcd_locate(3,3);
  klcd(' ');
  delay(500);
    
  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,5);
  klcd(0xC7D1);    //  "한"
  klcd_locate(2,5);
  klcd('3'); //계
  klcd_locate(3,5);
  klcd('-');
  delay(500);
  klcd_locate(3,7);
  klcd('-');
  delay(500);
  klcd_locate(3,9);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xB1E2);    //  "기"
  klcd_locate(2,0);
  klcd('4'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xBEEF);    //  "억"
  klcd_locate(2,3);
  klcd('4'); //계
  klcd_locate(2,4);
  klcd('+'); //계
  klcd_locate(3,3);
  klcd('-');
  delay(500);
  klcd_locate(3,5);
  klcd('-');
  delay(500);

  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xBCD3);    //  "속"
  klcd_locate(2,7);
  klcd('5'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500);


  klcd_locate(0,7);
  klcd(' ');
  klcd_locate(0,10);
  Serial.print('*');
  klcd_locate(1,10);
  klcd(0xBFA1);    //  "에"
  klcd_locate(2,10);
  klcd('4'); //계
  klcd_locate(2,11);
  klcd('+'); //계
  klcd_locate(3,10);
  klcd('-');
  delay(500);
  klcd_locate(3,10);
  klcd('7');
  delay(500);
  klcd_locate(3,10);
  klcd('6');
  delay(500);
  klcd_locate(3,10);
  klcd('5');
  delay(500);
  klcd_locate(3,10);
  klcd('4');
  delay(500);
  klcd_locate(3,10);
  klcd('3');
  delay(500);
  klcd_locate(3,10);
  klcd('2');
  delay(500);  
  klcd_locate(3,10);
  klcd('1');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xB1D7);    //  "그"
  klcd_locate(2,0);
  klcd('5'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xB6A7);    //  "때"
  klcd_locate(2,3);
  klcd('5'); //계
  klcd_locate(3,3);
  klcd('-');
  delay(500);


  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,5);
  klcd(0xB8B8);    //  "만"
  klcd_locate(2,5);
  klcd('5'); //계
  klcd_locate(3,5);
  klcd('-');
  delay(500);


  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xB3AD);    //  "난"
  klcd_locate(2,7);
  klcd('4'); //계
  klcd_locate(2,8);
  klcd('+'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완료


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xB1D7);    //  "그"
  klcd_locate(2,0);
  klcd('3'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);


  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xBBE7);    //  "사"
  klcd_locate(2,3);
  klcd('4'); //계
  klcd_locate(2,4);
  klcd('+'); //계
  klcd_locate(3,3);
  klcd('-');
  delay(500);
  klcd_locate(3,5);
  klcd('-');
  delay(500);
  klcd_locate(3,7);
  klcd('-');
  delay(500);

  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,9);
  Serial.print('*');
  klcd_locate(1,9);
  klcd(0xB6F7);    //  "람"
  klcd_locate(2,9);
  klcd('3'); //계
  klcd_locate(3,9);
  klcd('-');
  delay(500);
  klcd_locate(3,9);
  klcd('4');
  delay(500);
  klcd_locate(3,9);
  klcd('3');
  delay(500);
  klcd_locate(3,9);
  klcd('2');
  delay(500);
  klcd_locate(3,9);
  klcd('1');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xB8BB);    //  "말"
  klcd_locate(2,0);
  klcd('8'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xC0CC);    //  "이"
  klcd_locate(2,4);
  klcd('8'); //계
  klcd_locate(3,4);
  klcd('-');
  delay(500);


  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xBEF8);    //  "없"
  klcd_locate(2,7);
  klcd('8'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500);

  klcd_locate(0,7);
  klcd(' ');
  klcd_locate(0,9);
  Serial.print('*');
  klcd_locate(1,9);
  klcd(0xB4F8);    //  "던"
  klcd_locate(2,9);
  klcd('7'); //계
  klcd_locate(3,9);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완료 ㅇㅇ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xB1D7);    //  "그"
  klcd_locate(2,0);
  klcd('6'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xBBE7);    //  "사"
  klcd_locate(2,3);
  klcd('7'); //계
  klcd_locate(3,3);
  klcd('-');
  delay(500);
  klcd_locate(3,5);
  klcd('-');
  delay(500);
  klcd_locate(3,7);
  klcd('-');
  delay(500);


  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,9);
  Serial.print('*');
  klcd_locate(1,9);
  klcd(0xB6F7);    //  "람"
  klcd_locate(2,9);
  klcd('6'); //계
  klcd_locate(3,9);
  klcd('-');
  delay(500);
  klcd_locate(3,9);
  klcd('4');
  delay(500);
  klcd_locate(3,9);
  klcd('3');
  delay(500);
  klcd_locate(3,9);
  klcd('2');
  delay(500);
  klcd_locate(3,9);
  klcd('1');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완료

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xC0DA);    //  "자"
  klcd_locate(2,0);
  klcd('6'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xB2D9);    //  "꾸"
  klcd_locate(2,3);
  klcd('7'); //계
  klcd_locate(3,3);
  klcd('-');
  delay(500);


  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,5);
  klcd(0xB8B8);    //  "만"
  klcd_locate(2,5);
  klcd('8'); //계
  klcd_locate(3,5);
  klcd('-');
  delay(500);
  klcd_locate(3,7);
  klcd('-');
  delay(500);
  klcd_locate(3,9);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xB8D6);    //  "멀"
  klcd_locate(2,0);
  klcd('8'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xBEEE);    //  "어"
  klcd_locate(2,4);
  klcd('8'); //계
  klcd_locate(3,4);
  klcd('-');
  delay(500);
  klcd_locate(3,6);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xC1F6);    //  "지"
  klcd_locate(2,0);
  klcd('7'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);


  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xB4C2);    //  "는"
  klcd_locate(2,3);
  klcd('6'); //계
  klcd_locate(3,3);
  klcd('-');
  delay(500);
  klcd_locate(3,5);
  klcd('-');
  delay(500);

  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xB5A5);    //  "데"
  klcd_locate(2,7);
  klcd('7'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500);
  klcd_locate(3,7);
  klcd('4');
  delay(500);
  klcd_locate(3,7);
  klcd('3');
  delay(500);
  klcd_locate(3,7);
  klcd('2');
  delay(500);
  klcd_locate(3,7);
  klcd('1');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완료

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xB8B8);    //  "만"
  klcd_locate(2,0);
  klcd('8'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xB3AF);    //  "날"
  klcd_locate(2,4);
  klcd('8'); //계
  klcd_locate(3,4);
  klcd('-');
  delay(500);

  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,6);
  klcd(0xBCF8);    //  "순"
  klcd_locate(2,6);
  klcd('7'); //계
  klcd_locate(3,6);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완료 ㅇㅇ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xBEF8);    //  "없"
  klcd_locate(2,0);
  klcd('6'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xBEEE);    //  "어"
  klcd_locate(2,3);
  klcd('7'); //계
  klcd_locate(3,3);
  klcd('-');
  delay(500);
  klcd_locate(3,5);
  klcd('-');
  delay(500);

  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xB5B5);    //  "도"
  klcd_locate(2,7);
  klcd('8'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500);
  klcd_locate(3,7);
  klcd('4');
  delay(500);
  klcd_locate(3,7);
  klcd('3');
  delay(500);
  klcd_locate(3,7);
  klcd('2');
  delay(500);
  klcd_locate(3,7);
  klcd('1');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완료 ㅇㅇ


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xC0D8);    //  "잊"
  klcd_locate(2,0);
  klcd('7'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xC1F6);    //  "지"
  klcd_locate(2,4);
  klcd('7'); //계
  klcd_locate(3,4);
  klcd('-');
  delay(500);

  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,6);
  klcd(0xB4C2);    //  "는"
  klcd_locate(2,6);
  klcd('6'); //계
  klcd_locate(3,6);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완ㄹ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xB8BB);    //  "말"
  klcd_locate(2,0);
  klcd('5'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xBEC6);    //  "아"
  klcd_locate(2,3);
  klcd('6'); //계
  klcd_locate(3,3);
  klcd('-');
  delay(500);
  klcd_locate(3,5);
  klcd('-');
  delay(500);

  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xBFE4);    //  "요"
  klcd_locate(2,7);
  klcd('7'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500);
  klcd_locate(3,7);
  klcd('4');
  delay(500);
  klcd_locate(3,7);
  klcd('3');
  delay(500);
  klcd_locate(3,7);
  klcd('2');
  delay(500);
  klcd_locate(3,7);
  klcd('1');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완료 ㅇㅇ


  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xB4E7);    //  "당"
  klcd_locate(2,0);
 klcd('4'); //계
  klcd_locate(2,1);
 klcd('+'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,3);
  Serial.print('*');
  klcd_locate(1,3);
  klcd(0xBDC5);    //  "신"
  klcd_locate(2,3);
  klcd('5'); //계
  klcd_locate(3,3);
  klcd('-');
  delay(500);

  klcd_locate(0,3);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,5);
  klcd(0xC0BB);    //  "을"
  klcd_locate(2,5);
  klcd('6'); //계
  klcd_locate(3,5);
  klcd('-');
  delay(500);
  klcd_locate(3,7);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완료 ㅇㅇ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0); 
  klcd(0xBBE7);    //  "사"
  klcd_locate(2,0);
  klcd('7'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xB6FB);    //  "랑"
  klcd_locate(2,4);
  klcd('6'); //계
  klcd_locate(3,4);
  klcd('-');
  delay(500);
  klcd_locate(3,6);
  klcd('-');
  delay(500);
  klcd(KLCD_CLEAR);                   // Clear Screen 완료 ㅇㅇ

  klcd_locate(0,0);
  Serial.print('*');
  klcd_locate(1,0);
  klcd(0xC7DF);    //  "했"
  klcd_locate(2,0);
  klcd('5'); //계
  klcd_locate(3,0);
  klcd('-');
  delay(500);
  klcd_locate(3,2);
  klcd('-');
  delay(500);

  klcd_locate(0,0);
  klcd(' ');
  klcd_locate(0,5);
  Serial.print('*');
  klcd_locate(1,4);
  klcd(0xBEEE);    //  "어"
  klcd_locate(2,4);
  klcd('4'); //계
  klcd_locate(2,5);
  klcd('+'); //계
  klcd_locate(3,4);
  klcd('-');
  delay(500);
 
  klcd_locate(0,5);
  klcd(' ');
  klcd_locate(0,7);
  Serial.print('*');
  klcd_locate(1,7);
  klcd(0xBFE4);    //  "요"
  klcd_locate(2,7);
  klcd('3'); //계
  klcd_locate(3,7);
  klcd('-');
  delay(500);
  klcd_locate(3,9);
  klcd('-');
  delay(500);
  klcd_locate(3,11);
  klcd('-');
  delay(500);
  klcd_locate(3,13);
  klcd('-');
  delay(500);

  klcd(KLCD_CLEAR);                   // Clear Screen
  count++;


//---------- 종료화면 ---------------------------

klcd_locate(1,0);
klcd(' ');
klcd(' ');
klcd(' ');
klcd(' ');
klcd(' ');
klcd(0xBFAC);   //"연"
klcd(0xC1D6);   //"주"
klcd(0xB0A1);   //"가"
delay(800);
Serial.println();                // New Line
klcd_locate(2,0);
klcd(' ');
klcd(' ');
klcd(' ');
klcd(0xB3A1);   //"끝"
klcd(0xB3B5);   //"났"
klcd(0xBDC0);   //"습"
klcd(0xB4CF);   //"니"
klcd(0xB4D9);   //"다"
Serial.print('!');
delay(4500);
klcd(KLCD_CLEAR);                   // Clear Screen
  
  } 
}



   
