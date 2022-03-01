int binario[6];
int powers[] = { 64, 32, 16, 8, 4, 2, 1 };
int power = 0;
int n = 0;
int count = 0;
int prim = 0;

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
  
  for(int d = 1; d <= 63; d++){
    
    n = d;
    
    for(int i = 1; i < 7; i++){  
       power = powers[i];
    
      if(n >= power){
          binario[i-1] = 1;
          n -=power;
      }
    }
    
    prim = primo(d); 
    digitalWrite(7, prim);

    Serial.print(d);
    Serial.print(" ----> ");
    Serial.print(prim);
    Serial.print("\n");

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

int primo(int n){
  int res = 1;
  
  if(n == 1){
  	res = 0;
  }
  
  for(int i = 2; i < n; i++){
    if(n % i == 0){
      res = 0;
      break;
    } 
  }
	return res;
}