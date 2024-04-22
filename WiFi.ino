#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Connect to WiFi
void wifiConnect() {
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to the WiFi network");
}

void wifiRequest() {
  HTTPClient http;
  http.begin(apiUrl);
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    String payload = http.getString();
    Serial.println("API Response:");
    Serial.println(payload);
    wifiExtract(payload);
  } else {
    Serial.print("Error in HTTP request: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}

void wifiExtract(String payload) {
  DynamicJsonDocument doc(2048*64);
  DeserializationError error = deserializeJson(doc, payload);
  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
  }

  // Extract specific data
  pokemonName = (const char*)doc["pokemon"]["name"];
  pokemonType1 = (const char*)doc["types"][0]["type"]["name"];
  pokemonType2 = (const char*)doc["types"][1]["type"]["name"];             // Check if a second type exists
  pokemonGame = (const char*)doc["version_group"]["name"];




  Serial.print("Pokemon Name: ");
  Serial.println(pokemonName);  // Echo the value of the first result
  
  Serial.print("Pokemon Type: ");
  Serial.println(pokemonType1);  // Display the first type
  if (pokemonType2) {
    Serial.println(pokemonType2);  // Display the second type if it exists
  }
  Serial.print("Pokemon Game: ");
  Serial.print(pokemonGame);
}
