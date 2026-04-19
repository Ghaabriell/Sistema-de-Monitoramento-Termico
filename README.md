# 🌡️ Sistema de Monitoramento Térmico com ESP32

## 📖 Descrição
Este projeto consiste em um sistema de monitoramento térmico utilizando um ESP32 e um sensor DHT22. O sistema é capaz de medir a temperatura e a umidade do ambiente em tempo real, acionando automaticamente um relé quando a temperatura ultrapassa um limite definido.

Além disso, o sistema envia alertas via Telegram e Webhook (Discord ou outro serviço), permitindo monitoramento local e remoto em tempo real.


## 🚀 Funcionalidades
- Leitura de temperatura e umidade com sensor DHT22
- Acionamento automático de relé em alta temperatura
- Envio de alertas via Telegram
- Envio de alertas via Webhook
- Monitoramento em tempo real via Serial
- Acionamentos locais (através de relés)


## 🛠️ Tecnologias Utilizadas
- ESP32
- Linguagem C++ (Arduino)
- Sensor DHT22
- Wi-Fi
- API do Telegram
- Webhooks (HTTP)

## ⚙️ Como Executar

### 1. Clone o repositório
```bash
git clone https://github.com/SEU-USUARIO/sistema-monitoramento-termico.git
