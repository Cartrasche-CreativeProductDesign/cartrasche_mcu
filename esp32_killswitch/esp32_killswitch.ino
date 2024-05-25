#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFiClient.h>
#include "config.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
char buffer[16];
int state = 0;

WiFiClient espClient; 
PubSubClient client(espClient);

void resetDisplay(){
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(1);
}

void defaultDisplay(){
  display.clearDisplay();
  display.setCursor(0, 24);
  display.setTextSize(1);
  display.println("E-STOP READY");
  display.print("IP addr: ");
  display.println(WiFi.localIP());
  display.println("Press to Stop!!");
  display.display();
}

void setupOLED(){
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(4, 25);
    display.println("**Begin CARTRASCHE**");
    display.display();
    delay(2000);
}

void setup_wifi() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
      client.subscribe(mqtt_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 3 seconds");
      delay(3000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setupOLED();
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  pinMode(buttonPin, INPUT_PULLUP);
  resetDisplay();
  memset(buffer, 0x00, sizeof(buffer));
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  defaultDisplay();
  int state = digitalRead(buttonPin);
  Serial.println(state);
  if(!state){
    resetDisplay();
    sprintf(buffer, "kill");
    display.setCursor(4, 24);
    display.setTextSize(2);
    display.println("E-Stop");
    display.println("Activated");
    Serial.println("E-Stop Activated");
    client.publish(mqtt_topic, buffer);
    display.display();
  }
  delay(100);
}
