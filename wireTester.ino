String cmd;
char num_of_cyckles;
int num_of_cyckles_int;

void setup() {
  // put your setup code here, to run once:
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
//  String cmdType;
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
  Serial.println(num_of_cyckles_int);
}
