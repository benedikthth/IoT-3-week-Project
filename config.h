
/*DHT22*/
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

/*CCS811*/
#include "Adafruit_CCS811.h"



/******************************* WIFI **************************************/

// the AdafruitIO_WiFi client will work with the following boards:
//   - Feather HUZZAH ESP8266 -> https://www.adafruit.com/products/2821
/*
#define WIFI_SSID     "BenediktNidri"  ///"iot-research"
#define WIFI_PASS     "0123456789"  //"yNUtn6uwGa7PFrLdv3hgqDRpf89MsTHb"
*/
#define WIFI_SSID     "iot-research"
#define WIFI_PASS     "yNUtn6uwGa7PFrLdv3hgqDRpf89MsTHb"


/*Wifi Client from mqtt tutorial. any client should work*/
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define SERVERPORT  1883
#define SERVER "192.168.1.115"//"192.168.1.101"

/*PINS*/
#define DHT_PIN 2
#define FAN_PIN 16
//light
#define p_red 14
#define p_green 12
#define p_blue 13

/* struct for lights */
struct RGB {
  int red, green, blue;
};

/*pre computed colors*/
RGB red = { 255, 10, 10 };
RGB blue = { 0, 20, 255  };
RGB green = { 0, 255, 20  };
RGB white = { 220, 220, 255};
RGB off = { 0, 0, 0};
RGB orange = {255, 119, 0};
RGB cyan = {0, 229, 255};
RGB pink = {255, 0, 229};

//duty cycle constants
#define fan_on_time 2000        // intake air for 2 seconds
#define normalization_time 3000 // wait 3 seconds for the air to settle
#define sleep_time 15000        // 30 seconds in between measurements.
