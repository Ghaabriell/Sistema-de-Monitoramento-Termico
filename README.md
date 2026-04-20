# 🌡️ Sistema de Monitoramento Térmico IoT com ESP32
> [!IMPORTANT] 
> Este repositório contém um projeto estritamente para fins acadêmicos e de portfólio profissional.
> 
![Status](https://img.shields.io/badge/Status-Concluído-success?style=flat-square)

[![Wokwi Simulation](https://img.shields.io/badge/Simulation-Wokwi-blue)](https://wokwi.com)

![Área](https://img.shields.io/badge/Área-Automação_Industrial-orange?style=flat-square)
![Hardware](https://img.shields.io/badge/Hardware-ESP32-blue?style=flat-square&logo=espressif)

## 📖 Descrição do Projeto
Sistema IoT desenvolvido para monitoramento térmico em tempo real, integrando hardware e software para garantir a segurança operacional de ativos críticos (como painéis elétricos ou salas de servidores). O projeto utiliza o microcontrolador **ESP32** e o sensor **DHT22** para automatizar o arrefecimento via relé e enviar alertas instantâneos via **Telegram** e **Webhooks**.

Este projeto foi desenvolvido com foco em **Engenharia de Produção**, unindo conceitos de automação, elétrica, segurança do trabalho e práticas da Indústria 4.0.

---

## 🎯 Funcionalidades e Aplicações

A lógica do sistema é versátil e pode ser aplicada em qualquer ambiente que exija controle de temperatura:

*   **Automação de Arrefecimento:** Acionamento imediato de sistemas de exaustão/ventilação via módulo relé ao atingir limites críticos.
*   **Monitoramento Remoto:** Integração via **Webhooks** e **Telegram Bot API** para alertas instantâneos no smartphone.
*   **Gestão de Riscos:** Prevenção de incêndios e falhas catastróficas em equipamentos sensíveis.
*   **Logs de Eventos via Telegram:** O sistema realiza o **registro sequencial de todas as anomalias e normalizações** diretamente no chat do administrador via Telegram, funcionando como um histórico contínuo de notificações em tempo real. Além disso, esses registros podem ser utilizados como uma **base de dados para análise de performance do sistema**, contribuindo para a identificação de padrões de falhas, avaliação de eficiência operacional e suporte à conformidade com normas técnicas aplicáveis.
- - -
## 🚀 Competências Técnicas Aplicadas
| Categoria | Tecnologias e Conceitos |
| :--- | :--- |
| **Desenvolvimento** | C++, Embedded C |
| **Protocolos & IoT** | HTTP, Webhooks, REST APIs (Telegram Bot) |
| **Hardware** | ESP32, Sensor DHT22, Atuadores (Módulo Relé) |
| **Engenharia** | Automação Industrial, Manutenção Preditiva, Gestão de Ativos |
| **Normatização** | NR-10, NR-12, NBR 5410, NBR IEC 61439 |
---

## 🗺️ Fluxograma de Funcionamento
O sistema segue uma lógica de controle de malha fechada, monitorando variáveis e executando ações baseadas em limites de segurança predefinidos.

<img width="576" height="590" alt="image" src="https://github.com/user-attachments/assets/d90848c8-4a2f-4ef1-bb76-0a59b879186b" />


---

## 📺 Demonstração do Protótipo
> [!IMPORTANT]
> **Assista à demonstração**

https://github.com/user-attachments/assets/77cdbc14-ff2f-4427-b29e-7a67adb5791c



No vídeo acima, observa-se o funcionamento completo:
1. **Monitoramento:** O sensor DHT22 realiza a leitura constante da temperatura. Enquanto estiver abaixo de 40°C, o sistema permanece em estado `NORMAL`.
2. **Atuação:** Ao atingir o limite crítico (>40°C), o ESP32 aciona instantaneamente o **Relé**, simulando a ativação de alarmes e sistemas de exaustão.
3. **Notificação Remota:** Simultaneamente, o sistema dispara alertas via API para o **Telegram** e **Webhook**, permitindo a identificação rápida da falha pela equipe de manutenção.
4. **Recuperação:** Ao retornar aos níveis seguros, o sistema desativa o relé e envia uma notificação de normalização.

---

## 🛠️ Desenvolvimento e Metodologia

A construção do sistema foi organizada em etapas progressivas para garantir a viabilidade técnica e funcional:

### 1. Pesquisa e Requisitos
Com base em demandas reais de painéis elétricos industriais, foram avaliados os riscos associados à falha de ventilação. A seleção dos componentes considerou a precisão, estabilidade térmica e capacidade de comunicação sem fio.

### 2. Arquitetura do Sistema
*   **ESP32:** Processamento central e conectividade Wi-Fi.
*   **DHT22:** Sensor de temperatura e umidade com alta estabilidade.
*   **Módulo Relé 5V:** Interface de acionamento para dispositivos de potência (Sinaleira/Buzzer).
*   **Integração IoT:** APIs do Telegram e Webhooks para monitoramento remoto.

### 3. Simulação e Validação (Wokwi)
O uso do ambiente virtual **Wokwi** permitiu validar a lógica de programação e o tempo de resposta do sistema antes da montagem física. Isso reduziu custos de prototipagem e permitiu ajustar a confiabilidade do código contra falhas de leitura.

---

## ⚖️ Conformidade Normativa
Para alinhar o projeto aos padrões industriais, o desenvolvimento considerou as diretrizes das seguintes normas técnicas:
*   **NR-10:** Segurança em instalações e serviços em eletricidade.
*   **NR-12:** Diretrizes para sistemas de acionamento, sinalização e parada de emergência.
*   **NBR 5410:** Requisitos para instalações elétricas de baixa tensão.
*   **NBR IEC 61439:** Segurança na construção de painéis elétricos.
*   **NBR ISO 13849-1:** Princípios de segurança funcional para sistemas de comando.

---

## 🚀 Como Utilizar este Repositório

1. **Código Fonte:** O código principal está disponível no arquivo `.ino`.
2. **Simulação Online:** Você pode acessar o circuito montado diretamente no Wokwi.
3. **Configuração de Alertas:**
   - No código, substitua as variáveis `telegramBotToken`, `chatID` e `webhookURL` pelas suas credenciais.
   - O limite de temperatura é ajustável na constante `TEMP_THRESHOLD_C`.
---

## 🔗 Acesso ao Projeto (Simulação Interativa)
Você pode testar a lógica e as notificações deste sistema diretamente no seu navegador através do simulador Wokwi:

👉[![Wokwi Simulation](https://img.shields.io/badge/Simular_no-Wokwi-blue?style=for-the-badge&logo=wokwi)](https://wokwi.com/projects/461777091023625217)


---
---

**Desenvolvido por João Ghabriel - Estudante de Engenharia de Produção e Técnico em Eletrotécnica.**
---

## 🛡️ Propriedade Intelectual e Uso
Este projeto foi desenvolvido como parte de um percurso acadêmico. 

*   **Finalidade:**
Este projeto representa a integração entre minha formação técnica em Eletrotécnica e meus estudos em Engenharia de Produção e Tecnologia da Informação.
Sua finalidade é demonstrar a capacidade de transformar conhecimentos de infraestrutura elétrica em uma solução digital aplicada à automação e monitoramento. Trata-se de uma Prova de Conceito (PoC) que utiliza lógica de programação embarcada para resolver problemas reais de segurança e controle, marcando o início do desenvolvimento de sistemas inteligentes voltados à digitalização de processos industriais.
*   **Restrições:** Direitos reservados. Proibida a reprodução ou uso comercial sem autorização prévia.
*   **Contato:** [joaoghabrielba@gmail.com](mailto:joaoghabrielba@gmail.com)
