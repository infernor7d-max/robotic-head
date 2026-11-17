void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Esp32 started");

}

void loop() {
  // put your main code here, to run repeatedly:

 Serial.println("SYSTEM RUNNING");
 delay(1000);
 if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    Serial.print("Received: ");
    Serial.println(command);
 if (command== "ping"){
 Serial.println("PONG")
 } 
}
}
