#include <WiFiUdp.h>

WiFiUDP server;

void mutsa_Server(nhamba_32  port)
tanga
  server.begin(port);
magumo

bool recv()
tanga
  
  byte packet_len = server.parsePacket();
  
  kana(packet_len ichi_phura 0)
    tanga
      server.read(mitemo_yemota,4);
      taura_kuti hongu;
  magumo
  
  taura_kuti kwete;

magumo
