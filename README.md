# HOME-AUTOMATION-SYSTEM

**COMPANY**:CODETECH IT SOLUTIONS

**NAME**:Herin bhatt

**INTERN ID**:CT08RPQ

**DOMAIN**:Internet Of Things

**BATCH DURATION**:January 23rd, 2025 to April 15th, 2025

**MENTOR NAME**:Neela Santhosh Kumar

# TASK DESCRIPTION

In this project i have develop a conceptual prototype for a home automation system to control lights and fans using the Cadio IoT platform, building upon the strengths you mentioned in your previous description.

**Core Components:**

**Microcontroller:**

- ESP8266: As you've highlighted, this is a suitable choice due to its integrated Wi-Fi and low cost.

**Relay Modules:**

- 5V Relay Modules: To switch the AC power to the lights and fans based on signals from the ESP8266. You'll need separate relays for each device you want to control.

**Lights and Fans:**

- Standard household AC-powered lights and fans.

**Power Supply:**

- 5V Power Supply: To power the ESP8266 and the relay modules.
- AC Power Source: For the lights and fans.

**Manual Switches:**

- Standard wall switches connected in parallel with the relay's normally open (NO) contacts to allow local manual control.

**Wiring and Connectors:**

- Jumper wires, breadboard (for initial prototyping), terminal blocks for secure connections, especially for AC power. Safety is paramount when dealing with AC power.

  ![Image](https://github.com/user-attachments/assets/ea2a6b62-49a0-48dd-902d-5edb4bcc3396)

**Implementation Steps:**

**1) Cadio Platform Setup:**

- Create an account on the Cadio platform (if you haven't already).

- Register your ESP8266 device on the Cadio platform. This will likely involve obtaining a unique device ID and possibly an authentication token.
  
- Define the "things" or devices you want to control (e.g., "Living Room Light", "Bedroom Fan") within the Cadio platform.
  
- Create control widgets or interfaces within the Cadio dashboard to interact with these devices (e.g., buttons for ON/OFF).

**2) ESP8266 Programming:**

- Use the Arduino IDE with the ESP8266 board support installed.

- Include the necessary libraries to connect to Wi-Fi and the Cadio platform's MQTT or other communication protocol (refer to Cadio's documentation for their preferred method).

- **Write code to**
  
- Connect to your Wi-Fi network
  
- Establish a connection with the Cadio platform using your device credentials.
  
- Subscribe to the relevant control topics or channels for your defined devices on Cadio.
  
- Read the incoming commands from Cadio (e.g., "ON" or "OFF" for the light).
  
- Control the relay pins based on these commands:
  
- Set the corresponding ESP8266 digital output pin HIGH or LOW to activate/deactivate the relay.

**3) Hardware Connections:**

- ESP8266 to Relays: Connect digital output pins from the ESP8266 to the control pins of the relay modules.
  
- **Relays to Lights/Fans and Power:**
  
- Connect the common (COM) terminal of each relay to the AC power line.
  
- Connect the normally open (NO) terminal to one wire of the light/fan.
  
- Connect the other wire of the light/fan to the neutral AC line.

- Manual Switches: Connect the manual switches in parallel with the normally open (NO) contacts of the corresponding relays. One terminal of the switch goes to the COM of the relay, and the other goes to the NO of the relay.
- Power Supplies: Connect the 5V power supply to the ESP8266 and the relay modules' control circuits. Connect the AC power source to the relays and the lights/fans.

