
int z = 0;

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
  
}

void loop(){
  for( int i=0; i<768; i++ ){
    digitalWrite( 11, 0 );
    digitalWrite( 11, 1 );
    if( (i+z) % 6 == 0 ){
      digitalWrite( 3, 1 );
    }
    else{
      digitalWrite( 3, 0 );
    }
  }
  digitalWrite( 10, 1 );
  digitalWrite( 10, 0 );
   
  z++;
  delay(50);
}
