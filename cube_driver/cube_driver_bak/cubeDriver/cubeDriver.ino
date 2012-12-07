int LB0 = 7;
int LB1 = 6;
int LB2 = 5;
int LB3 = 4;
int LB4 = 3;
int LB5 = 2;
int LB6 = 1;
int LB7 = 0;

int topRow = 8;
int bottomRow = 9;
int L0= 10;
int L1= 11;
int L2= 12;
int L3= 13;

char testAll[8] ={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
char x[8] ={0x90,0x09,0x06,0x60,0x06,0x60,0x90,0x09};

char box[8] = {0x00,0x00,0x06,0x60,0x06,0x60,0x00,0x00};    
char outline[8] = {0xf9, 0x9f, 0x90,0x09,0x90,0x09,0xf9,0x9f};   

void setup() {   
  pinMode(LB0, OUTPUT);
  pinMode(LB1, OUTPUT);
  pinMode(LB2, OUTPUT);
  pinMode(LB3, OUTPUT);
  pinMode(LB4, OUTPUT);
  pinMode(LB5, OUTPUT);
  pinMode(LB6, OUTPUT);
  pinMode(LB7, OUTPUT);
  pinMode(topRow, OUTPUT);
  pinMode(bottomRow, OUTPUT);
  pinMode(L0, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  
  digitalWrite(L0, 1);
  digitalWrite(L1, 1);
  digitalWrite(L2, 1);
  digitalWrite(L3, 1);
  
  
}



void loop() {
  
  writeCube(testAll);

 // writeLayer(0xff,0xff,L1);

}
//char x[8] ={0x90,0x09,0x06,0x60,0x06,0x60,0x90,0x09};
//char outline[8] = {0xf9, 0x9f, 0x90,0x09,0x90,0x09,0xf9,0x9f};   

void writeCube(char cube[]){
//  cube =x;
 
//  writeLayer(cube[0],cube[1],L0); 
  int frameDelay = 10;

  for(int i =0; i <frameDelay; i++){
    writeLayer(0x90,0x09,L0); 
    writeLayer(0x06,0x60,L1);
    writeLayer(0x06,0x60,L2); 
    writeLayer(0x90,0x09,L3); 
  }

  for(int i =0; i <frameDelay; i++){
    writeLayer(0x90,0x09,L0); 
    writeLayer(0x00,0x00,L1);
    writeLayer(0x06,0x60,L2); 
    writeLayer(0x96,0x69,L3); 
  }
  
  for(int i =0; i <frameDelay; i++){
    writeLayer(0x90,0x09,L0); 
    writeLayer(0x00,0x00,L1);
    writeLayer(0x00,0x00,L2); 
    writeLayer(0x96,0x69,L3); 
  }
  
  for(int i =0; i <frameDelay; i++){
    writeLayer(0x90,0x09,L0); 
    writeLayer(0x00,0x00,L1);
    writeLayer(0x00,0x00,L2); 
    writeLayer(0x90,0x09,L3); 
  }
  
  
  for(int i =0; i <frameDelay; i++){
    writeLayer(0x96,0x69,L0); 
    writeLayer(0x00,0x00,L1);
    writeLayer(0x00,0x00,L2); 
    writeLayer(0x90,0x09,L3); 
  }
  

  for(int i =0; i <frameDelay; i++){
    writeLayer(0x96,0x69,L0); 
    writeLayer(0x06,0x60,L1);
    writeLayer(0x00,0x00,L2); 
    writeLayer(0x90,0x09,L3); 
  }
  
  
  
// delay(100);
// writeLayer(cube[2],cube[3] ,L1);
 //delay(100);
 //writeLayer(cube[4],cube[5],L2); 
  //delay(100);
  //writeLayer(cube[6],cube[7] ,L3);
  //delay(100);
  
  
}


void writeLayer(char bottom, char top, int layerNum){

  
  digitalWrite(layerNum,1);  
  //delay(10);
  writeByte(bottom & 1,
           (bottom >> 1) & 1,
           (bottom >> 2) & 1,
           (bottom >> 3) & 1,
           (bottom >> 4) & 1,
           (bottom >> 5) & 1,
           (bottom >> 6) & 1,
           (bottom >> 7) & 1, bottomRow);
           
  
  
  writeByte(top & 1,
           (top >> 1) & 1,
           (top >> 2) & 1,
           (top >> 3) & 1,
           (top >> 4) & 1,
           (top >> 5) & 1,
           (top >> 6) & 1,
           (top >> 7) & 1, topRow);
  //turnOnLayer(layerNum);
  digitalWrite(layerNum,0);
  delay(5);           
  digitalWrite(layerNum,1);
}

void turnOnLayer(int layerNum){
//  digitalWrite(layerNum,0);
//  delay(10);
//  digitalWrite(layerNum,1);
//  delay(10);
  
  
}

void writeByte(int b0, int b1, int b2, int b3,
               int b4, int b5, int b6, int b7, int regNo){

  digitalWrite(regNo, 0);  
  
  digitalWrite(LB0,b0);
  digitalWrite(LB1,b1);
  digitalWrite(LB2,b2);
  digitalWrite(LB3,b3);
  digitalWrite(LB4,b4);
  digitalWrite(LB5,b5);
  digitalWrite(LB6,b6);
  digitalWrite(LB7,b7);

  digitalWrite(regNo, 1);    
      
} 
      

