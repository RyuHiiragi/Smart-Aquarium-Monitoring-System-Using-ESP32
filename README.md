# Smart Aquarium Monitoring System Using ESP32  

This system monitors **pH**, **temperature**, and **turbidity** in an aquarium using ESP32 and sends real-time alerts via Blynk/Telegram <button class="citation-flag" data-index="1"><button class="citation-flag" data-index="3">. It also automates pumps or lights to maintain optimal conditions <button class="citation-flag" data-index="8">.  

---

## Features  
- Real-time monitoring of pH, temperature, and turbidity <button class="citation-flag" data-index="4"><button class="citation-flag" data-index="7">.  
- Automated pump/light control via relay when thresholds are exceeded <button class="citation-flag" data-index="2"><button class="citation-flag" data-index="8">.  
- Notifications sent to Telegram for abnormal readings <button class="citation-flag" data-index="3">.  

---

## Components  
- **ESP32 Development Board**  
- **pH Sensor (SEN0161)** <button class="citation-flag" data-index="4">  
- **Turbidity Sensor (SEN0189)** <button class="citation-flag" data-index="7">  
- **DS18B20 Temperature Sensor** <button class="citation-flag" data-index="6">  
- **Relay Module** <button class="citation-flag" data-index="8">  
- **Jumper Wires & Power Supply**  

---

## Assembly  
1. Connect sensors to the ESP32 as described in the guide.  
2. Link the relay to pumps/lights for automated control <button class="citation-flag" data-index="8">.  
3. Power the system and calibrate sensors (e.g., pH using buffer solutions) <button class="citation-flag" data-index="4"><button class="citation-flag" data-index="6">.  

---

## Calibration Tips  
- **pH Sensor**: Use pH 4.0 and 7.0 buffer solutions for accuracy <button class="citation-flag" data-index="4">.  
- **Turbidity Sensor**: Test with known NTU standards (e.g., distilled water for 0 NTU) <button class="citation-flag" data-index="7">.  

---

## License  
MIT License. See [LICENSE](LICENSE) for details.  

---

By following this guide, you can maintain optimal aquarium conditions and prevent equipment failure. Happy monitoring! 🐠🌊  
