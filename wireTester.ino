String cmd;
int numOFpins=74;
int num_of_cyckles_int;

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
}

void I_AM_READY() {
  Serial.print("WireTester is ready\n");
}

void TESTING() {
  byte pinVal;
//  byte testBuffer[numOFpins];
  num_of_cyckles_int = byte(num_of_cyckles_int);
  Serial.println("Testing in progress");
  Serial.print(num_of_cyckles_int, DEC);
  Serial.println();
  for (int i = 1; i <= num_of_cyckles_int; i++) {
    Serial.print("BOD");
    for (int j = 1; j <= numOFpins; j++) {
      pinMode(j, OUTPUT);
      digitalWrite(j, HIGH);
      delay(1);
      for (int k = 1; k <= numOFpins; k++) {
        if (k != j) {
          pinVal = digitalRead(k);
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
      digitalWrite(j, LOW);
      pinMode(j, INPUT);
    }
    Serial.println("EOD");
  }
  Serial.print('\n');
}
