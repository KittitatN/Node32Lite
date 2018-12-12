#include <WiFi.h>

const char *ssid = "...............";
const char *password = "................";

void Blink(void);

void setup()
{
  pinMode(23, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(15, OUTPUT);
  // pinMode(8, INPUT);
  // pinMode(7, INPUT);
  // pinMode(6, INPUT);
  //  pinMode(36, OUTPUT);
  //  pinMode(39, OUTPUT);
  //  pinMode(34, OUTPUT);
  //  pinMode(35, OUTPUT);
  //  pinMode(32, OUTPUT);
  //  pinMode(33, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  // pinMode(9, INPUT);
  // pinMode(10, INPUT);
  // pinMode(11, INPUT);

  digitalWrite(23, HIGH);
  digitalWrite(22, HIGH);
  digitalWrite(21, HIGH);
  digitalWrite(19, HIGH);
  digitalWrite(18, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(17, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(0, HIGH);
  //  digitalWrite(2, HIGH);
  digitalWrite(15, HIGH);
  // digitalWrite(8, HIGH);
  // digitalWrite(7, OUTPUT);
  // digitalWrite(6, OUTPUT);
  //    digitalWrite(36, HIGH);
  //    digitalWrite(39, HIGH);
  //    digitalWrite(34, HIGH);
  //    digitalWrite(35, HIGH);
  //    digitalWrite(32, HIGH);
  //    digitalWrite(33, HIGH);
  // digitalWrite(25, HIGH);
  // digitalWrite(26, HIGH);
  // digitalWrite(27, HIGH);
  // digitalWrite(14, HIGH);
  // digitalWrite(12, HIGH);
  // digitalWrite(13, HIGH);
  // digitalWrite(9, HIGH);
  // digitalWrite(10, HIGH);
  // digitalWrite(11, HIGH);
  Serial.begin(115200);
  ledcSetup(0, 5000, 12);
  ledcSetup(1, 5000, 12);
  ledcSetup(2, 5000, 12);
  ledcSetup(3, 5000, 12);
  ledcSetup(4, 5000, 12);
  ledcSetup(5, 5000, 12);
  ledcAttachPin(25, 0);
  ledcAttachPin(26, 1);
  ledcAttachPin(27, 2);
  ledcAttachPin(14, 3);
  ledcAttachPin(12, 4);
  ledcAttachPin(13, 5);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  // while (WiFi.status() != WL_CONNECTED)
  // {
  //   delay(500);
  //   Serial.print(".");
  // }

  // Serial.println("");
  // Serial.println("WiFi connected");
  // Serial.println("IP address: ");
  // Serial.println(WiFi.localIP());
}
void loop()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    Blink();
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }

  uint8_t duty0 = map(analogRead(36), 0, 4096, 0, 255);
  ledcWrite(0, duty0);
  uint8_t duty1 = map(analogRead(39), 0, 4096, 0, 255);
  ledcWrite(1, duty1);
  uint8_t duty2 = map(analogRead(34), 0, 4096, 0, 255);
  ledcWrite(2, duty2);
  uint8_t duty3 = map(analogRead(35), 0, 4096, 0, 255);
  ledcWrite(3, duty3);
  uint8_t duty4 = map(analogRead(32), 0, 4096, 0, 255);
  ledcWrite(4, duty4);
  uint8_t duty5 = map(analogRead(33), 0, 4096, 0, 255);
  ledcWrite(5, duty5);
  // Serial.println(analogRead(36));
  // if(analogRead(36) > 2048){

  // }
  // analogWrite(25, analogRead(36));
  // analogWrite(26, analogRead(36));
  // analogWrite(27, analogRead(36));
  // analogWrite(14, analogRead(36));
  // analogWrite(12, analogRead(36));
  // analogWrite(13, analogRead(36));
}

void Blink()
{
  digitalWrite(2, HIGH);
  delay(250);
  digitalWrite(2, LOW);
  delay(250);
}
