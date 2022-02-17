String cmd;
int numOFpins=60;
int num_of_cyckles_int;
int actualPins[]={3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,60,61,62,63,64,65,66,67,68,69};

void setup() {
  // put your setup code here, to run once:
  uint8_t i;
  for (i = 1; i <= numOFpins; i++) {
    pinMode(i, INPUT);
  }
  Serial.begin(2000000);
  Serial.setTimeout(100);
  while (!Serial) {
    ;
  }
}
//Serial.print(actualPins);
void loop() {
  // put your main code here, to run repeatedly:
  waiting_4_command();
  if (cmd == "HELLO") {
    I_AM_READY();
  }
  if (cmd == "GIVE") {
    TESTING();
  }
    if (cmd == "SETN") {
    SET_OF_numOFpins();
  }
}

void waiting_4_command() {
  char num_of_cyckles;
  String num_of_cyckles_str;
  cmd = "";
  if (Serial.available()) {
    cmd = Serial.readString();
    cmd.trim();
  }
  if (cmd.substring(0, 4) == "GIVE") {
    num_of_cyckles = cmd[4];
    num_of_cyckles_int = num_of_cyckles - '0';
    cmd = "GIVE";
  }
    if (cmd.substring(0, 4) == "GIVE") {
    num_of_cyckles = cmd[4];
    num_of_cyckles_int = num_of_cyckles - '0';
    cmd = "SET_OF_numOFpins";
  }
}

void I_AM_READY() {
  Serial.print("WireTester is ready\n");
}

void SET_OF_numOFpins() {
  numOFpins=60;
  Serial.print("Now the number of oins is ");
  Serial.print(numOFpins, DEC);
}

void TESTING() {
  byte pinVal;
//  byte testBuffer[numOFpins];
  num_of_cyckles_int = byte(num_of_cyckles_int);
int  numOFpins = sizeof(actualPins)/sizeof(actualPins[0]);
  Serial.println("Testing in progress");
  Serial.println(num_of_cyckles_int, DEC);
  Serial.print(numOFpins, DEC);
  Serial.println();
  for (int i = 1; i <= num_of_cyckles_int; i++) {
    Serial.print("BOD");
    for (int j = 1; j <= numOFpins-1; j++) {
//      pinMode(j, OUTPUT);
//      digitalWrite(j, HIGH);
      pinMode(actualPins[j], OUTPUT);
      digitalWrite(actualPins[j], HIGH);
      delay(1);
      for (int k = 1; k <= numOFpins-1; k++) {
        if (k != j) {
//          pinVal = digitalRead(k);
            pinVal = digitalRead(actualPins[k]);
          if (pinVal == 1) {
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
        digitalWrite(actualPins[j], LOW);
        pinMode(actualPins[j], INPUT);
    }
    Serial.println("EOD");
  }
  Serial.print('\n');
  delay(1);
}
