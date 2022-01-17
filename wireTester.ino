String cmd;
char num_of_cyckles;
int num_of_cyckles_int;
byte testBuffer[70];

void setup() {
  // put your setup code here, to run once:
  uint8_t i;
  for(i=1;i<=70;i++){
    pinMode(i,INPUT);
  }
  Serial.begin(2000000);
  Serial.setTimeout(100);
  while (!Serial) {
    ;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  waiting_4_command();
  if (cmd == "HELLO") {
    I_AM_READY();
  }
  if (cmd == "GIVE") {
    TESTING();
  }
}

void waiting_4_command() {
  cmd = "";
  if (Serial.available()) {
    cmd = Serial.readString();
    cmd.trim();
  }
  if(cmd.substring(0,4)=="GIVE"){
  num_of_cyckles = cmd[4];
  num_of_cyckles_int = num_of_cyckles- '0';
  cmd = "GIVE";
  }
}

void I_AM_READY() {
  Serial.print("WireTester is ready\n");
}

void TESTING() {
  uint8_t i,j,k,pinVal;
  Serial.println("Testing in progress");
  Serial.println(num_of_cyckles);
  for(i=0;i<num_of_cyckles;i++){
    for(j=1;j<=70;j++){
      pinMode(j,OUTPUT);
      digitalWrite(j,HIGH);
      for(k=1;k<=70;k++){
        if(k!=j){
          pinVal=digitalRead(k);
          if(pinVal==1){
            testBuffer[k]=1; 
          }
          else{
            testBuffer[k]=0;  
          }
          Serial.print(testBuffer[k]);
          Serial.print(',');
        }
      }
      pinMode(j,INPUT);
    }
  }
  Serial.print('\n');
}
