#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <DHT.h>
#include "secrets.h"

#define DHTPIN 4
#define DHTTYPE DHT22
#define RELAY_PIN 18
#define TEMP_THRESHOLD_C 40

DHT dht(DHTPIN, DHTTYPE);

enum EstadoTemperatura {
  NORMAL,
  ALTA
};

EstadoTemperatura estadoAtual = NORMAL;

void conectaWiFi() {
  Serial.print("Conectando ao Wi-Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ Conectado ao Wi-Fi!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void enviaAlertaTelegram(const String& mensagem) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi não conectado. Não foi possível enviar mensagem ao Telegram.");
    return;
  }

  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient http;
  String telegramURL = "https://api.telegram.org/bot" + String(TELEGRAM_BOT_TOKEN) +
                       "/sendMessage?chat_id=" + String(TELEGRAM_CHAT_ID) +
                       "&text=" + mensagem;

  Serial.println("Enviando mensagem para o Telegram...");

  if (http.begin(client, telegramURL)) {
    int httpResponseCode = http.GET();

    Serial.print("Código de resposta do Telegram: ");
    Serial.println(httpResponseCode);

    if (httpResponseCode > 0) {
      Serial.print("📤 Mensagem enviada ao Telegram! Código HTTP: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("❌ Falha ao enviar mensagem ao Telegram. Erro: ");
      Serial.println(http.errorToString(httpResponseCode).c_str());
    }

    http.end();
  } else {
    Serial.println("Falha ao iniciar conexão com o Telegram.");
  }
}

void enviaAlertaWebhook(const String& mensagem) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi não conectado. Não foi possível enviar mensagem ao Webhook.");
    return;
  }

  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient http;
  String payload = "{\"mensagem\": \"" + mensagem + "\"}";

  if (http.begin(client, WEBHOOK_URL)) {
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.POST(payload);

    if (httpResponseCode > 0) {
      Serial.print("📤 Mensagem enviada para o Webhook! Código HTTP: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("❌ Falha ao enviar mensagem para o Webhook. Erro: ");
      Serial.println(http.errorToString(httpResponseCode).c_str());
    }

    http.end();
  } else {
    Serial.println("Falha ao iniciar conexão com o Webhook.");
  }
}

void setup() {
  Serial.begin(115200);
  conectaWiFi();
  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Erro ao ler o DHT22!");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" °C | Umidade: ");
  Serial.print(h);
  Serial.println(" %");

  if (t > TEMP_THRESHOLD_C) {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println(">>> Temperatura ALTA! Relé ATIVADO.");

    if (estadoAtual != ALTA) {
      String mensagem = "Temperatura alta detectada: " + String(t) + " C | Umidade: " + String(h) + " %";
      enviaAlertaTelegram(mensagem);
      enviaAlertaWebhook(mensagem);
      estadoAtual = ALTA;
    }
  } else {
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Temperatura normal. Relé DESLIGADO.");

    if (estadoAtual != NORMAL) {
      String mensagem = "Temperatura voltou ao normal: " + String(t) + " C | Umidade: " + String(h) + " %";
      enviaAlertaTelegram(mensagem);
      enviaAlertaWebhook(mensagem);
      estadoAtual = NORMAL;
    }
  }
}
