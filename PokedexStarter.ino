// InfoClip Starter Code
// Zane Cochran
// 13 APR 2024
int PokemonId = 0; 

// Setup
const char* ssid = "EZConnect";
const char* password = "zKs795KEb7";
String apiUrl = "https://pokeapi.co/api/v2/pokemon-form/" + String(PokemonId); // ***UPDATE THIS***

// Information
String pokemonName = "";
String pokemonType1 = "";
String pokemonType2 = "";
String pokemonGame = "";
String pokemonid = "";

// State Machine
int mode = -1;
int lastMode = -1;

void setup() {
  Serial.begin(115200);
  delay(2000);

  wifiConnect();
  wifiRequest();
  initDisplay();
  initButtons();
}

void loop() {
  checkButtons();
  checkSleep();

  switch(mode){
    case -1: showIntro(); break;
    case 0: showSleep(); break;
    case 1: showSunrise(); break;
  }
}
