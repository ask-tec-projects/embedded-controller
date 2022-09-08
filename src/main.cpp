#include <Ethernet.h>
#include <WString.h>
#include <digital_button.h>
#include <led.h>
#include <parse.h>

EthernetServer HTTP_SERVER(80);
byte MAC_ADDR[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDA, 0x02};
IPAddress IP_ADDR(192, 168, 1, 1);
float frequency;         // Number of cycles per 1 second.
float freq_delta = 0.01; // Rate of frequency change.
DigitalButton inc_btn(2);
DigitalButton dec_btn(4);
Led led(13);
long int last_now;

void update_frequency() {
  inc_btn.tick();
  dec_btn.tick();

  if (inc_btn.is_pressed()) {
    frequency += freq_delta;
    Serial.print("New frequency ");
    Serial.println(frequency);
  }
  if (dec_btn.is_pressed() && frequency > freq_delta) {
    frequency -= freq_delta;
    Serial.print("New frequency ");
    Serial.println(frequency);
  }
}

void update_led() {
  long int now = millis();
  double rate =
      1000 / (frequency * 2); // Divide frequency by 2, since we're calculating
                              // the rate from one state to the same state.
  double tdelta = now - last_now;
  bool state = led.is_on();

  while (tdelta > rate) {
    tdelta -= rate;
    state = !state;
    last_now = now;
  }

  led.set(state);
}

void loop() {
  update_frequency();
  update_led();

  EthernetClient client = HTTP_SERVER.available();
  if (!client) {
    delay(1);
    return;
  }

  String request = parse_http_request(client);
  String path = parse_http_request_path(request);
  Serial.print("HTTP ");
  Serial.println(path);

  if (path != "/frequency") {
    client.println("HTTP/1.1 404 Not Found");
    client.println("Content-Type: text/plain");
    client.println();
    client.println("Not Found");
  } else {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println();
    client.print("{\"frequenzy\":");
    client.print(frequency);
    client.println("}");
  }

  delay(1);
  client.stop();
}

void setup() {
  Serial.begin(9600);
  Ethernet.begin(MAC_ADDR, IP_ADDR);
  HTTP_SERVER.begin();
  Serial.print("Listening on ");
  Serial.print(Ethernet.localIP());
  Serial.println(":80");
  frequency = 1;
  last_now = millis();
}
