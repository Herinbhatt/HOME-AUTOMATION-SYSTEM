#include <ESP8266WiFi.h>


// Wi-Fi credentials
const char* ssid = "WIFI_SSID";
const char* password = "WIFI_PASSWORD";

// Cadio device credentials and topics (replace with your actual values)
const char* cadio_server = "CADIO_MQTT_BROKER"; // Example
const int cadio_port = 1883;                        // Example
const char* cadio_device_id = "ESP8266_ID";
const char* light_control_topic = "devices/YOUR_ESP8266_ID/lights/control";
const char* fan_control_topic = "devices/YOUR_ESP8266_ID/fans/control";
const char* light_state_topic = "devices/YOUR_ESP8266_ID/lights/state";
const char* fan_state_topic = "devices/YOUR_ESP8266_ID/fans/state";

// Relay control pins
const int lightRelayPin = D2;
const int fanRelayPin = D4;

// Manual switch pins
const int lightSwitchPin = D5;
const int fanSwitchPin = D6;

WiFiClient espClient;
// CadioClient cadioClient(espClient); // Assuming a Cadio client library

bool lightState = false;
bool fanState = false;

void setup_wifi() {
  // ... (Standard Wi-Fi connection code) ...
}

// Callback function to handle messages from Cadio
void cadioCallback(char* topic, byte* payload, unsigned int length) {
  // ... (Parse the topic and payload to control relays) ...
  if (strcmp(topic, light_control_topic) == 0) {
    if (String((char*)payload).startsWith("ON")) {
      digitalWrite(lightRelayPin, LOW); // Assuming LOW turns ON
      lightState = true;
    } else if (String((char*)payload).startsWith("OFF")) {
      digitalWrite(lightRelayPin, HIGH); // Assuming HIGH turns OFF
      lightState = false;
    }
    // cadioClient.publish(light_state_topic, lightState ? "ON" : "OFF");
  } else if (strcmp(topic, fan_control_topic) == 0) {
    // ... (Control fan relay based on payload) ...
  }
}

void reconnectCadio() {
  // ... (Code to connect/reconnect to Cadio) ...
  // cadioClient.setCallback(cadioCallback);
  // cadioClient.subscribe(light_control_topic);
  // cadioClient.subscribe(fan_control_topic);
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  pinMode(lightRelayPin, OUTPUT);
  pinMode(fanRelayPin, OUTPUT);
  pinMode(lightSwitchPin, INPUT_PULLUP); // Use internal pull-up
  pinMode(fanSwitchPin, INPUT_PULLUP);   // Use internal pull-up

  digitalWrite(lightRelayPin, HIGH); // Initialize OFF
  digitalWrite(fanRelayPin, HIGH);   // Initialize OFF

  // reconnectCadio();
}

void loop() {
  // if (!cadioClient.connected()) {
  //   reconnectCadio();
  // }
  // cadioClient.loop();

  // Manual switch control
  if (digitalRead(lightSwitchPin) == LOW) {
    lightState = !lightState;
    digitalWrite(lightRelayPin, lightState ? LOW : HIGH);
    // cadioClient.publish(light_state_topic, lightState ? "ON" : "OFF");
    delay(200); // Debounce
  }
  if (digitalRead(fanSwitchPin) == LOW) {
    fanState = !fanState;
    digitalWrite(fanRelayPin, fanState ? LOW : HIGH);
    // cadioClient.publish(fan_state_topic, fanState ? "ON" : "OFF");
    delay(200); // Debounce
  }
}