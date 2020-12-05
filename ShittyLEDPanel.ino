
/*
Panel header pins
1   R Data
2   G Data
3   B Data
4   Gnd
5   Clock
6   Latch
7   !Enable R
8   !Enable G
9   !Enable B
10  VCC/VLED?
11  VCC/VLED?
*/

#define rdata     5
#define gdata     17
#define bdata     16
#define latchPin  19
#define clockPin  18

unsigned long timestamp;

int z = 0;
int rando;
struct rgb{
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

uint8_t bits;
struct rgb bufferA[2048];
uint8_t brightness = 1;
uint16_t pxl = 0;

void setup(){
  pinMode( rdata, OUTPUT );
  pinMode( gdata, OUTPUT );
  pinMode( bdata, OUTPUT );
  pinMode( latchPin, OUTPUT );
  pinMode( clockPin, OUTPUT );
  randomSeed(0);
  Serial.begin( 115200 );
  for( int i=0; i<2048; i++ ){
    bufferA[i].r = 0; //i % 255;
    bufferA[i].g = (i % 5)*51;
    bufferA[i].b = 0;//i % 255;
  }
}

void loop(){
  writeBuffer();
  if( millis() - timestamp > 10 ){
    pxl++;
    pxl = pxl % 2048;
    timestamp = millis();
  }
}

void writeBuffer(){
  bits = 255 >> brightness;
  for( int i=0; i<2048; i++ ){
    //delayMicroseconds( 1 );
    digitalWrite( clockPin, 0 );
    //delayMicroseconds( 1 );
    digitalWrite( clockPin, 1 );
    //delayMicroseconds( 1 );
    digitalWrite( rdata, (i==(pxl-256)%2048)?1:0 );
    digitalWrite( gdata, (i==pxl)?1:0 );
    digitalWrite( bdata, (i==(pxl-512)%2048)?1:0 );
    //digitalWrite( rdata, bufferA[i].r & bits );
    //digitalWrite( gdata, bufferA[i].g & bits );
    //digitalWrite( bdata, bufferA[i].b & bits );
  }
  //delayMicroseconds( 1 );
  digitalWrite( latchPin, 1 );
  //delayMicroseconds( 1 );
  digitalWrite( latchPin, 0 );
  brightness++;
  brightness = brightness % 8;
}
