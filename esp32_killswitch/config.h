#define buttonPin 25
#define LED_BUILTIN 5
#define RUNNING_CORE 1
#define BASE_CORE 0
#define SDA_PIN 21
#define SCL_PIN 22
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define uS_TO_S_FACTOR 1000000ULL
#define TIME_TO_SLEEP  3600   

const char* ssid = "cartrasche";
const char* password = "cart1234";

const char* mqtt_server = "192.168.0.4"; // MQTT broker IP 
const int mqtt_port = 1883; // MQTT port 1883
const char* mqtt_topic = "kill";