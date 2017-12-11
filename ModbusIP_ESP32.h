/*
    ModbusIP_ESP32.h - Header for Modbus IP ESP32 Library
	Adapted entirely from ModbusIP_ESP8266.h from André Sarmento Barbosa


*/
#include <Modbus.h>
#include <WiFi.h>

#ifndef MODBUSIP_ESP32_H
#define MODBUSIP_ESP32_H

#define MODBUSIP_PORT 	  502
#define MODBUSIP_MAXFRAME 200
#define MODBUSIP_TIMEOUT   10

class ModbusIP : public Modbus {
    private:
        byte _MBAP[7];
    public:
        ModbusIP();
        void config(const char* ssid, const char* password);
        void task();
};

#endif //MODBUSIP_ESP32_H
