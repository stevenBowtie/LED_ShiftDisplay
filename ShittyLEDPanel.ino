
int z = 0;
int rando;
struct rgb{
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

struct rgb bufferA[2048];
uint8_t brightness = 1;

void setup(){
  pinMode( 2, OUTPUT );
  pinMode( 3, OUTPUT );
  pinMode( 4, OUTPUT );
  pinMode( 5, OUTPUT );
  pinMode( 6, OUTPUT );
  pinMode( 7, OUTPUT );
  pinMode( 8, OUTPUT );
  pinMode( 9, OUTPUT );
  pinMode( 10, OUTPUT );
  pinMode( 11, OUTPUT );
  for( int x=2; x<11; x++ ){
    digitalWrite( x, 0 );
  }
  randomSeed(0);
  Serial.begin( 115200 );
  for( int i=0; i<2048; i++ ){
    bufferA[i].r = i % 255;
    bufferA[i].g = i % 255;
    bufferA[i].b = i % 255;
  }
}

void loop(){
  writeBuffer();
}

void writeBuffer(){
  for( int i=0; i<2048; i++ ){
    digitalWrite( 11, 0 );
    digitalWrite( 11, 1 );
    digitalWrite( 2, bufferA[i].r & brightness );
    digitalWrite( 3, bufferA[i].g & brightness );
    digitalWrite( 4, bufferA[i].b & brightness );
  }
  digitalWrite( 10, 1 );
  digitalWrite( 10, 0 );
  brightness = brightness++ % 255;
}
