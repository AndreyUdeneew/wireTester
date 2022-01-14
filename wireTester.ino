static String cmd;
void setup() {
  // put your setup code here, to run once:
      Serial.begin(115200);
      while(!Serial){
        ;
      }
}

void loop() {
    // put your main code here, to run repeatedly:
    waiting_4_command();
    if(cmd=="HELLO"){
      I_AM_READY();
    }
    if(cmd=="GIVE5"){
      TESTING();
    }
}

void waiting_4_command(){
  byte ch;
  cmd = "";
  if(Serial.available()){
    cmd=Serial.readString();   
    if(ch=='\n');{
      cmd.trim();
    }
  }
}

void I_AM_READY() {
     Serial.print("WireTester is ready\n"); 
}

void TESTING(){
  Serial.print("Testing in Progress\n");
}
