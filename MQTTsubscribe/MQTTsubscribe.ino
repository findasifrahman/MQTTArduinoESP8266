/*
 Basic MQTT example with Authentication
  - connects to an MQTT server, providing username
    and password
  - publishes "hello world" to the topic "outTopic"
  - subscribes to the topic "inTopic"
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>
#include <EEPROM.h>

WiFiUDP Udp;
WiFiUDP Udp2;
WiFiServer server(9999);

char packetBuffer[255]; //buffer to hold incoming packet
char  ReplyBuffer[] = "acknowledged";       // a string to send back
static int NET_FOUND = 1;

int check_internet();
void tcp_mode_start();
void udp_mode_start();

const char *ssid =  "MATRIX TECH BD";   // cannot be longer than 32 characters!
const char *pass =  "matrixtech15";   //
const char *mqtt_user = "tanvir";//"intricate2";//"jtsevrwm";
String user = "tanvir";//"intricate2";
const char *mqtt_pass = "intricate12";//"X4sAOLqQNi_o";
const char *mqtt_client_name = "asif"; // Client connections cant have the same connection name

const char *ip_add =  "35.154.168.239"; 
const int port = 1883;
String topic =  user + "SendTopic";
String rcvtopic = user + "RCVTopic";
#define BUFFER_SIZE 100

WiFiClient wclient;
PubSubClient client(wclient, ip_add , port);

void callback(const MQTT::Publish& pub) {
  String buff = "";
  //Serial.print(pub.topic());
  //Serial.print(" => ");
  if (pub.has_stream()) {
    uint8_t buf[BUFFER_SIZE];
    int read;
    while (read = pub.payload_stream()->read(buf, BUFFER_SIZE)) {
      //Serial.write(buf, read);
      //buff += String(read);
    }
    pub.payload_stream()->stop();
    Serial.println(buff);
  } else
    Serial.println(pub.payload_string());

    buff = pub.payload_string();
    if(buff.equalsIgnoreCase("CH1")){
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(7);
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(100);
      
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(7);
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(400);
      
      client.publish(rcvtopic, "RCV-1");
    }
    else if(buff.equalsIgnoreCase("CH2")){
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(5);
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(100);
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(5);
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(400);
      
      client.publish(rcvtopic, "RCV-2");
    }
    else if(buff.equalsIgnoreCase("CH3")){
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(5);
      digitalWrite(2, HIGH);
      delay(4);
      digitalWrite(2, LOW);
      delay(100);
      
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(5);
      digitalWrite(2, HIGH);
      delay(4);
      digitalWrite(2, LOW);
      delay(400);
      
      client.publish(rcvtopic, "RCV-3");
    }
    else if(buff.equalsIgnoreCase("CH4")){
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(4);
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(100);
      
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(4);
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(400);
      
      client.publish(rcvtopic, "RCV-4");
    }
    else if(buff.equalsIgnoreCase("F1")){
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(3);
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(100);

      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(3);
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(400);
      client.publish(rcvtopic, "RCV-F1");
    }
    else if(buff.equalsIgnoreCase("F2")){
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(3);
      digitalWrite(2, HIGH);
      delay(4);
      digitalWrite(2, LOW);
      delay(100);
      
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(3);
      digitalWrite(2, HIGH);
      delay(4);
      digitalWrite(2, LOW);
      delay(400);
      client.publish(rcvtopic, "RCV-F2");
    }
    else if(buff.equalsIgnoreCase("F3")){

      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(3);
      digitalWrite(2, HIGH);
      delay(6);
      digitalWrite(2, LOW);
      delay(100);
      
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(3);
      digitalWrite(2, HIGH);
      delay(6);
      digitalWrite(2, LOW);
      delay(400);
      client.publish(rcvtopic, "RCV-F3");
    }
    else if(buff.equalsIgnoreCase("F4")){
  
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(2);
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(100);
      
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(2);
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(400);
      
      client.publish(rcvtopic, "RCV-F4");
    }
    else if(buff.equalsIgnoreCase("F5")){

      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(2);
      digitalWrite(2, HIGH);
      delay(4);
      digitalWrite(2, LOW);
      delay(100);
      
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(2);
      digitalWrite(2, HIGH);
      delay(4);
      digitalWrite(2, LOW);
      delay(400);
      
      client.publish(rcvtopic, "RCV-F5");
    }
    else if(buff.equalsIgnoreCase("F6")){
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(2);
      digitalWrite(2, HIGH);
      delay(6);
      digitalWrite(2, LOW);
      delay(100);

      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(2);
      digitalWrite(2, HIGH);
      delay(6);
      digitalWrite(2, LOW);
      delay(400);
      client.publish(rcvtopic, "RCV-F6");
    }
    else if(buff.equalsIgnoreCase("F7")){
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(1);
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(100);
      
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(1);
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(400);
      
      client.publish(rcvtopic, "RCV-F7");
    }
    else if(buff.equalsIgnoreCase("F8")){
      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(1);
      digitalWrite(2, HIGH);
      delay(4);
      digitalWrite(2, LOW);
      delay(100);

      digitalWrite(2, HIGH);
      delay(2);
      digitalWrite(2, LOW);
      delay(1);
      digitalWrite(2, HIGH);
      delay(4);
      digitalWrite(2, LOW);
      delay(400);
      client.publish(rcvtopic, "RCV-F8");
    }
    else if(buff.equalsIgnoreCase("IntToOff")){
              client.publish(rcvtopic, "RCV-InternetToOffline");
              ESP.eraseConfig();
              delay(1000);
              int ret1;
              EEPROM.write(199,10);
              delay(100);
              EEPROM.commit();
              WiFi.begin("testa123", "testa1234");
              /////////////////////////////////////////
              uint8_t timeout = 20; // 20 * 500 ms = 5 sec time out
              while ( ((ret1 = WiFi.status()) != WL_CONNECTED) && timeout ){
                Serial.print(".");
                Serial.flush();
                delay(500);
                --timeout;
              }
              /////////////////////////////////////
              Serial.println("Going to UDP MODE:");
              NET_FOUND == 0;
              delay(500);
              udp_mode_start();
              delay(500);
    }
    else if(buff.equalsIgnoreCase("IntToRou")){
              client.publish(rcvtopic, "RCV-InternetToRouter");
              EEPROM.write(199,10);
              delay(100);
              EEPROM.commit();
              
              /////////////////////////////////////
              Serial.println("Going to Local Router MODE:");
              tcp_mode_start();
              delay(500); 
    }
    else if(buff.equalsIgnoreCase("CHOFF")){
      digitalWrite(2, HIGH);
      client.publish(rcvtopic, "RCV-OOF");
    }
}

void setup() {
  //AT+UART_DEF=9600,8,1,0,0
  int ret;
  EEPROM.begin(512);
  
  ESP.eraseConfig();
  
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  // Setup console
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.flush();
  //////////////////////////////////////////  Serial.println("Reading EEPROM ssid");
  ret = check_internet();
  // connected ? 
  if ((ret = WiFi.status()) == WL_CONNECTED) {
    NET_FOUND=1;
    tcp_mode_start();

  } else {
    NET_FOUND = 0;
    udp_mode_start();
  }
}

void loop() {
  if(NET_FOUND == 0){
    direct_con();
      if (WiFi.status() != WL_CONNECTED) {
        /*Serial.print("Connecting to ");
        Serial.print(ssid);
        Serial.println("...");
        WiFi.begin(ssid, pass);*/
        
        /*if (WiFi.waitForConnectResult() != WL_CONNECTED)
          return;
        Serial.println("WiFi connected");*/
        
      }
  }
  else{
      if (WiFi.status() == WL_CONNECTED) {
        if (!client.connected()) {
          Serial.println("Connecting to MQTT server");
          if (client.connect(MQTT::Connect("mqtt_client_name")
                             .set_auth(mqtt_user, mqtt_pass))){
            Serial.println("Connected to MQTT server");
            client.set_callback(callback);
            //client.publish("/lightMQTT", "hello world");
            client.subscribe(topic);
          } else {
            Serial.println("Could not connect to MQTT server");   
          }
        }
    
        if (client.connected())
          client.loop();
      }
  }
}
////////////////////////
void direct_con(){
        int packetSize = Udp.parsePacket();
        if (packetSize) 
        {
                Serial.print("Received packet of size ");
                Serial.println(packetSize);
                Serial.print("From ");
                IPAddress remoteIp = Udp.remoteIP();
                Serial.print(remoteIp);
                Serial.print(", port ");
                Serial.println(Udp.remotePort());
            
                // read the packet into packetBufffer
                int len = Udp.read(packetBuffer, 255);
                if (len > 0) {
                  packetBuffer[len] = 0;
                }
                Serial.println("Contents:");
                String tmp = packetBuffer;
                Serial.println(tmp);
                if(tmp.startsWith("CH1"))
                {
                      //send a reply, to the IP address and port that sent us the packet we received
                      
                      ////////////
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(7);
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW); 
                      ////////////////////////
                      delay(100);
                      ////////////////////////
                      
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(7);
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(400);
                      
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("CH1");
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);
                }
                else if(tmp.startsWith("CH2"))
                {
                      
                      //////////////////////
                       digitalWrite(2, HIGH);
                        delay(2);
                        digitalWrite(2, LOW);
                        delay(5);
                        digitalWrite(2, HIGH);
                        delay(2);
                        digitalWrite(2, LOW);
                        delay(100);
                        
                       digitalWrite(2, HIGH);
                        delay(2);
                        digitalWrite(2, LOW);
                        delay(5);
                        digitalWrite(2, HIGH);
                        delay(2);
                        digitalWrite(2, LOW);
                        delay(400);
                        
                      //send a reply, to the IP address and port that sent us the packet we received
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("CH2");
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);
                }
                else if(tmp.startsWith("CH3"))
                {
                      //////////////////////
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(5);
                      digitalWrite(2, HIGH);
                      delay(4);
                      digitalWrite(2, LOW);
                      /////////////////////
                      delay(100);
                      
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(5);
                      digitalWrite(2, HIGH);
                      delay(4);
                      digitalWrite(2, LOW);
                      /////////////////////
                      delay(400);
                      
                      //send a reply, to the IP address and port that sent us the packet we received
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("CH3");
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);
                }
                else if(tmp.startsWith("CH4"))
                {
                      //////////////////////
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(4);
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(100);

                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(4);
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(400);

                      //send a reply, to the IP address and port that sent us the packet we received
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("CH4");
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);
                }
                else if(tmp.startsWith("F1"))
                {
                      //////////////////////
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(3);
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(100);

                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(3);
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(400);
                      //send a reply, to the IP address and port that sent us the packet we received
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("F1");
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);
                }
                
                else if(tmp.startsWith("F2"))
                {
                      //////////////////////
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(3);
                      digitalWrite(2, HIGH);
                      delay(4);
                      digitalWrite(2, LOW);
                      delay(100);
    
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(3);
                      digitalWrite(2, HIGH);
                      delay(4);
                      digitalWrite(2, LOW);
                      delay(400);
                      //send a reply, to the IP address and port that sent us the packet we received
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("F2");
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(1000);
                }
                
                else if(tmp.startsWith("F3"))
                {
                      //////////////////////
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(3);
                      digitalWrite(2, HIGH);
                      delay(6);
                      digitalWrite(2, LOW);
                      delay(100);
                      
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(3);
                      digitalWrite(2, HIGH);
                      delay(6);
                      digitalWrite(2, LOW);
                      delay(400);
                      
                      //send a reply, to the IP address and port that sent us the packet we received
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("F3");
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);
                }
                
                else if(tmp.startsWith("F4"))
                {
                      //////////////////////
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(2);
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(100);

                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(2);
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(400);                      
                      //send a reply, to the IP address and port that sent us the packet we received
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("F4");
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);
                }
                
                else if(tmp.startsWith("F5"))
                {
                      //////////////////////
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(2);
                      digitalWrite(2, HIGH);
                      delay(4);
                      digitalWrite(2, LOW);
                      delay(100);

                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(2);
                      digitalWrite(2, HIGH);
                      delay(4);
                      digitalWrite(2, LOW);
                      delay(400);
                      //send a reply, to the IP address and port that sent us the packet we received
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("F5");
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);
                }
                
                else if(tmp.startsWith("F6"))
                {
                      //////////////////////
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(2);
                      digitalWrite(2, HIGH);
                      delay(6);
                      digitalWrite(2, LOW);
                      delay(100);

                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(2);
                      digitalWrite(2, HIGH);
                      delay(6);
                      digitalWrite(2, LOW);
                      delay(400);
                      //send a reply, to the IP address and port that sent us the packet we received
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("F6");
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);
                }
                
                else if(tmp.startsWith("F7"))
                {
                      //////////////////////
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(1);
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(100);

                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(1);
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(400);
                      //send a reply, to the IP address and port that sent us the packet we received
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("F7");
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);
                }
                
                else if(tmp.startsWith("F8"))
                {
                      //////////////////////
                      digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(1);
                      digitalWrite(2, HIGH);
                      delay(4);
                      digitalWrite(2, LOW);
                      delay(100);

                       digitalWrite(2, HIGH);
                      delay(2);
                      digitalWrite(2, LOW);
                      delay(1);
                      digitalWrite(2, HIGH);
                      delay(4);
                      digitalWrite(2, LOW);
                      delay(400);
                      //send a reply, to the IP address and port that sent us the packet we received
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("F8");
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);
                }
                
                //////////////////
                else if(tmp.startsWith("CHOFF"))
                {
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("CHOFF");
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);
                      digitalWrite(2, LOW);
                      delay(1000);
                }
                else if(tmp.equals("OffToInt")){
                      int tmp_ret = check_internet();
                      if ((tmp_ret = WiFi.status()) == WL_CONNECTED) {
                          NET_FOUND=1;
                          tcp_mode_start();                      
                      } else {
                          Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                          Udp2.write("No Router");
                          Udp2.flush();
                          Udp2.endPacket();
                          Udp2.stop();
                          delay(500);
                      }
                      NET_FOUND == 1;
                      tcp_mode_start();
                      delay(1000);
                }
                else if(tmp.equals("RouToInt")){
                      EEPROM.write(199,18);
                      delay(100);
                      EEPROM.commit();
                      int tyu = EEPROM.read(199);
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("Internet. Reset!--");
                      Udp2.print(tyu);
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);
                }
                else if(tmp.equals("IntToRou")){
                      EEPROM.write(199,10);
                      delay(100);
                      EEPROM.commit();
                      int tyu = EEPROM.read(199);
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("Router,Reset--");
                      Udp2.print(tyu);
                      Udp2.flush();
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);

                       int ret = check_internet();
                      // connected ? 
                      if ((ret = WiFi.status()) == WL_CONNECTED) {
                        NET_FOUND=1;
                        tcp_mode_start();
                    
                      } else {
                        NET_FOUND = 0;
                        udp_mode_start();
                      }
                }
                else if(tmp.startsWith("setIPSta")) //senderdata= setipsta:192.168.0.110
                {
                      int temp_len = tmp.length()-9;
                      char temp_buf[temp_len + 1];
                      String tmp_senderData = tmp.substring(9);
                      tmp_senderData.toCharArray(temp_buf, tmp_senderData.length() + 1);
                      ////////////////////////////////////////
                      EEPROM.write(198,18);                    
                      EEPROM.write(170,temp_len);
                      for(int i=171;i<=170+temp_len;i++){
                          EEPROM.write(i,temp_buf[i-171]);
                          delay(20);
                          Serial.print(temp_buf[i-171]);                          
                      }
                      delay(100);
                      EEPROM.commit();
                      ///////////////////////////////
                      delay(500);
                      //send a reply, to the IP address and port that sent us the packet we received
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.write("OK-IPSTA.wait 5s");
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(1000);

                      //ESP.eraseConfig();
                      //int ret = check_internet();

                        tcp_mode_start();

                      delay(500);
                }
                else if(tmp.startsWith("joinAP"))//senderdata= joinAP:SSID?PASS
                {
                      String tmp_senderData = tmp.substring(7);
            
                      int ind1 = tmp_senderData.indexOf('?');
                      String tmp_ssid = tmp_senderData.substring(0,ind1);
                      String tmp_pass = tmp_senderData.substring(ind1+1);  
                      char temp_ssid_buf[tmp_ssid.length()+1];
                      char temp_pass_buf[tmp_pass.length()+1];
            
                      tmp_ssid.toCharArray(temp_ssid_buf, tmp_ssid.length() + 1);
                      tmp_pass.toCharArray(temp_pass_buf, tmp_pass.length() + 1);
                                  
                      EEPROM.write(0,tmp_ssid.length());
                      EEPROM.write(30,tmp_pass.length());
            
                      for(int i=1;i<=0+tmp_ssid.length();i++){
                          EEPROM.write(i,temp_ssid_buf[i-1]);
                          delay(20);
                          Serial.print(temp_ssid_buf[i-1]);
                      }
                      Serial.println();                      
                      for(int i=31;i<=30+tmp_pass.length();i++){
                          EEPROM.write(i,temp_pass_buf[i-31]);
                          delay(20);
                          Serial.print(temp_pass_buf[i-31]);
                      }
                      Serial.println();
                      EEPROM.commit();
                      //send a reply, to the IP address and port that sent us the packet we received

                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      
                      Udp2.print(temp_pass_buf);
                      Udp2.print(".wait 10s");
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(500);

                      int ret = check_internet();
                      // connected ? 
                      if ((ret = WiFi.status()) == WL_CONNECTED) {
                        NET_FOUND=1;
                        tcp_mode_start();
                    
                      } else {
                        NET_FOUND = 0;
                        udp_mode_start();
                      }
                      delay(500);
                      /////////
                      /*String tmptt = WiFi.localIP().toString();
                      if(tmptt.indexOf("0.0.0.0")>0){
                            Serial.print("failed to connect--");
                          Udp2.beginPacket("192.168.4.2", 8888);//Udp.remotePort());
                          Udp2.print("Wrong ssid-");
                          Udp2.endPacket();
                          Udp2.stop();
                      }
                      else{
                          Udp2.beginPacket("192.168.4.2", 8888);//Udp.remotePort());
                          Udp2.print("Connected with -");
                          Udp2.print(temp_ssid_buf);
                          Udp2.endPacket();
                          Udp2.stop();
                      }*/
                      ////////
                      
                }
                else if(tmp.startsWith("setESPAP"))
                {//senderdata= setESPAP:SSID?PASS
                    String tmp_senderData = tmp.substring(9);
                    
                    int ind1 = tmp_senderData.indexOf('?');
                    String tmp_ssid = tmp_senderData.substring(0,ind1);
                    String tmp_pass = tmp_senderData.substring(ind1+1);
                    char temp_ssid_buf[tmp_ssid.length()+1];
                    char temp_pass_buf[tmp_pass.length()+1];
            
                    tmp_ssid.toCharArray(temp_ssid_buf, tmp_ssid.length() + 1);
                    tmp_pass.toCharArray(temp_pass_buf, tmp_pass.length() + 1);

                    EEPROM.write(169,18);
                    
                    EEPROM.write(100,tmp_ssid.length());
                    EEPROM.write(130,tmp_pass.length());
                    
                     for(int i=101;i<=100+tmp_ssid.length();i++){
                          EEPROM.write(i,temp_ssid_buf[i-101]);
                          delay(20);
                          Serial.print(temp_ssid_buf[i-101]);
                          
                      }
                      Serial.println();                      
                      for(int i=131;i<=130+tmp_pass.length();i++){
                          EEPROM.write(i,temp_pass_buf[i-131]);
                          delay(20);
                          Serial.print(temp_pass_buf[i-131]);
                          
                      }
                      Serial.println();
                      EEPROM.commit();
                      //send a reply, to the IP address and port that sent us the packet we received
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.print("OK-" + tmp_pass);
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(2000);
                      //ESP.reset();
                      WiFi.softAP(temp_ssid_buf,temp_pass_buf);
                      Serial.print("WiFi.softAP() called");
                      Serial.flush();
                      WiFi.softAPIP();
              }
              else if(tmp.startsWith("getIPSta")){ 
                      String tmptt = WiFi.localIP().toString();
                      //String cc = " ok-" + tmpt;
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.print(tmptt);
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(1000);

              }
              else if(tmp.startsWith("getMacSta")){
                  int ss_len = EEPROM.read(0);
                  int pp_len = EEPROM.read(30);  
                  String esid;
                  for (int i = 1; i <= 0+ss_len; i++)//router ssid
                  {
                      esid += char(EEPROM.read(i));
                  }
                  Serial.print("SSID: ");
                  Serial.println(esid);
                  Serial.println("Reading EEPROM pass");
                  String epass = "";
                  for (int i = 31; i <= 30 + pp_len; i++)
                  {
                      epass += char(EEPROM.read(i));
                  }
                  Serial.print("PASS: ");
                  Serial.println(epass); 
                      /*String tmptt = (String)WiFi.macAddress();//wifi.showStaMac();    */                  
                      Udp2.beginPacket(Udp.remoteIP(), 8888);//Udp.remotePort());
                      Udp2.print(esid + ".");
                      Udp2.print(epass);
                      Udp2.endPacket();
                      Udp2.stop();
                      delay(1000);

              }

              //////////////////////////////////////////////////////                                        
   }
  

}
////////////////////////
int check_internet(){
  int ret1;
  int ss_len = EEPROM.read(0);
  int pp_len = EEPROM.read(30);  
  String esid;
  for (int i = 1; i <= 0+ss_len; i++)//router ssid
  {
      esid += char(EEPROM.read(i));
  }
  Serial.print("SSID: ");
  Serial.println(esid);
  Serial.println("Reading EEPROM pass");
  String epass = "";
  for (int i = 31; i <= 30 + pp_len; i++)
  {
      epass += char(EEPROM.read(i));
  }
  Serial.print("PASS: ");
  Serial.println(epass); 
  
  WiFi.begin(esid.c_str(), epass.c_str());
  /////////////////////////////////////////
  uint8_t timeout = 20; // 20 * 500 ms = 5 sec time out
  while ( ((ret1 = WiFi.status()) != WL_CONNECTED) && timeout ){
    Serial.print(".");
    Serial.flush();
    delay(500);
    --timeout;
  }
    Serial.print("local address  : "); 
    Serial.println(WiFi.localIP());

  return ret1;
}

void udp_mode_start(){
    Serial.print("wifi mode--");
    Serial.println(WiFi.mode(WIFI_AP));
    Serial.println("Configuring access point...");
    Serial.flush();
    ////////////////////////////////////esp8266 ssid pass
    int a = EEPROM.read(169);
    String esid1 = "";
    String epass1 = "";
    if(a==18){// a= 18 means eeprom is written
          int ss_len = EEPROM.read(100);
          int pp_len = EEPROM.read(130);  
          
          for (int i = 101; i <= 100 + ss_len; i++)//esp name
          {
              esid1 += char(EEPROM.read(i));
          }
          Serial.print("SSID: ");
          Serial.println(esid1);
          Serial.println("Reading EEPROM ESPpass");
          
          for (int i = 131; i <= 130 + pp_len; i++)
          {
              epass1 += char(EEPROM.read(i));
          }
          Serial.print("PASS: ");
    }
    else{
      esid1 = "intricate0016";
      epass1 = "";
    }
    Serial.println(epass1); 
    WiFi.softAP(esid1.c_str(), epass1.c_str());

    Udp.begin(8888);
    Udp2.begin(8888);
 
    Serial.println(WiFi.localIP());
    Serial.print("MAC address  : "); 
    Serial.println(WiFi.softAPmacAddress());
    NET_FOUND = 0; 
 
}
IPAddress ip(192, 168, 1, 230);  
IPAddress gateway(0, 0, 0, 0);  
IPAddress subnet(255, 255, 255, 0); 
void tcp_mode_start(){
    int a3 = EEPROM.read(199);
    if(a3==18){
      Serial.println("Entering internet mode");
           
        if (WiFi.status() == WL_CONNECTED) {
            NET_FOUND = 1;
            if (!client.connected()) {
              Serial.println("Connecting to MQTT server");
              if (client.connect(MQTT::Connect("mqtt_client_name")
                                 .set_auth(mqtt_user, mqtt_pass))){
                Serial.println("Connected to MQTT server");
                client.set_callback(callback);
                //client.publish("/lightMQTT", "hello world");
                client.subscribe(topic);
              } else {
                Serial.println("Could not connect to MQTT server");   
              }
            }
        
            if (client.connected())
              client.loop();
        }
    }
    
    else{
       ////////////////////////////////////////// internet or local router choice
          ///////////////////////////////////////////////fixed ip address
        Serial.print("198 eeprom val--");
        int a2 = EEPROM.read(198);
        Serial.println(a2);
        
        int ip_len = EEPROM.read(170);
        String tmp_ip = "";
        if(a2==18){     
            for (int i = 171; i <= 170 + ip_len; i++)
            {
                tmp_ip += char(EEPROM.read(i));
                delay(20);
            }
            
            ip.fromString(tmp_ip.c_str());
            Serial.print("fixed eeprom ip--" + tmp_ip +","+ gateway +"," + subnet + "; IP is-");
            Serial.println(ip);
            Serial.print("Result is-");
            Serial.println(WiFi.config(ip, gateway, subnet));
        }
        else{
          Serial.print("Result is-");
          Serial.println(WiFi.config(ip, gateway, subnet)); 
        }
      Serial.print("IP address   : "); 
      Serial.println(WiFi.localIP());
      Serial.print("MAC address  : "); 
      Serial.println(WiFi.macAddress());
        ////////////////////////////////////////// internet or local router choice
       NET_FOUND = 0;
       Serial.println("Entering local router mode");
       Udp.begin(8888);
       Udp2.begin(8888);
       //udp_mode_start();
    }
  
}

