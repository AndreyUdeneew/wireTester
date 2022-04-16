String cmd, num_of_pins_str, CMDcur;
int numOFpins = 60;
int num_of_cyckles_int;
//uint8_t actualPins[]={3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,60,61,62,63,64,65,66,67,68,69};
uint8_t actualPins[]={18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,66,67,68,69};


void setup() {
  // put your setup code here, to run once:
  numOFpins = sizeof(actualPins);
  uint8_t i;
  for (int i = 0; i < numOFpins; i++) {
//    pinMode(actualPins[i], OUTPUT);
//    digitalWrite(actualPins[i], HIGH);
    pinMode(actualPins[i], INPUT_PULLUP);
  }
  Serial.begin(115200);
  Serial.setTimeout(100);
  while (!Serial) {
    ;
  }
}
//Serial.print(actualPins);
void loop() {
  // put your main code here, to run repeatedly:
  waiting_4_command();

  while (CMDcur == "PING"){
      PING_test();
  }

    if (cmd == "PINS"){
      PINS_IN_USE();
  }
  
  if (cmd == "HELLO") {
    I_AM_READY();
  }
//  if (cmd == "PING") {
//    PING_test();
//  }
  
  if (cmd == "GIVE") {
    TESTING();
  }
  
    if (cmd == "SETN") {
    SET_numOFpins();
  }
}

void waiting_4_command() {
  char num_of_cyckles, numOFpinsH, numOFpinsL;
  String num_of_cyckles_str;
  cmd = "";
  if (Serial.available()) {
    cmd = Serial.readString();
    cmd.trim();
  }

  if (cmd.substring(0, 4) == "PING") {
     CMDcur = "PING";
  }

    if (cmd.substring(0, 4) == "PINS") {
     CMDcur = "PINS";
  }
  
  if (cmd.substring(0, 4) == "GIVE") {
    num_of_cyckles = cmd[4];
    num_of_cyckles_int = num_of_cyckles - '0';
    cmd = "GIVE";
    CMDcur = "GIVE";
  }
    if (cmd.substring(0, 3) == "SET") {
        numOFpinsH = cmd[3] - '0';
        numOFpinsL = cmd[4] - '0';
        if(cmd[4] != '\0'){
        numOFpins = (numOFpinsH*10) + (numOFpinsL*1);
        }
        else{
         numOFpins = (numOFpinsH*1) + (numOFpinsL*0); 
        }
        Serial.println(cmd);
        Serial.println(sizeof(cmd), DEC);
        Serial.println(numOFpinsH, DEC);
        Serial.println(numOFpinsL, DEC);
        Serial.println(numOFpins, DEC);        
    cmd = "SETN";
    CMDcur = "SETN";
  }
}

void I_AM_READY() {
  Serial.print("WireTester is ready\n");
}

void SET_numOFpins() {
  Serial.print("Now the number of pins is ");
  Serial.println(numOFpins);
}
void PING_test() {
  byte pinVal;
  Serial.println("Ping function in progress");
    Serial.println();
    Serial.println("BOD");

      for (int k = 0; k < numOFpins-0; k++) {
            pinVal = digitalRead(actualPins[k]);
          if (pinVal == 0) {
//              Serial.print('1');
                Serial.print(actualPins[k]);
                Serial.print(',');
          }
//          else {
//              Serial.print('0');
//          }
        }
      Serial.print('\n');
 
    Serial.println("EOD");
  Serial.print('\n');
  delay(1);
  waiting_4_command();
}

void PINS_IN_USE(){
  Serial.println(numOFpins);
  Serial.println("BOD");
  for(int i = 0; i < sizeof(actualPins); i++){
  Serial.print(actualPins[i]);
  Serial.print(',');
  }
  Serial.println();
  Serial.println("EOD");
}

void TESTING() {
  byte pinVal;
//  byte testBuffer[numOFpins];
  num_of_cyckles_int = byte(num_of_cyckles_int);
//int  numOFpins = sizeof(actualPins)/sizeof(actualPins[0]);
  Serial.println("Testing in progress");
  Serial.println(num_of_cyckles_int, DEC);
  Serial.print(numOFpins, DEC);
  Serial.println();
  for (int i = 1; i <= num_of_cyckles_int; i++) {
    Serial.println("BOD");
    for (int j = 0; j < numOFpins-0; j++) {
      pinMode(actualPins[j], OUTPUT);
      digitalWrite(actualPins[j], LOW);
      delay(1);
      for (int k = 0; k < numOFpins-0; k++) {
        if (k != j) {
            pinVal = digitalRead(actualPins[k]);
          if (pinVal == 0) {
              Serial.print('1');
          }
          else {
              Serial.print('0');
          }
        }
        else {
            Serial.print('8');
        }
      }
      Serial.print('\n');
//      digitalWrite(j, LOW);
//      pinMode(j, INPUT);
//        digitalWrite(actualPins[j], HIGH);
        pinMode(actualPins[j], INPUT_PULLUP);
    }
    Serial.println("EOD");
  }
  Serial.print('\n');
  delay(1);
}
