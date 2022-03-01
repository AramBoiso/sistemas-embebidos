int binario[6];
int count = 0;
int pointer = 5;

void setup(){
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  Serial.begin(9600); 
}

void loop(){ 
  int cos = 0;
  int div = 0;
  
  for(int d = 1; d <= 63; d++){
    cos = d;

    while(cos >= 0){
        div = cos%2;
        cos = cos/2;
        binario[pointer] = div;
        pointer--;
        if(cos == 0) break;
    }
   
    pointer = 5;
    count = 13;
    for(int i = 0; i < 6; i++){
      digitalWrite(count--, binario[i]);
    }
    
    delay(1000);
    
    count = 13;
    for(int i = 0; i < 6; i++){
      binario[i] = 0;
      digitalWrite(count--, LOW);
    }
    
  }

}

