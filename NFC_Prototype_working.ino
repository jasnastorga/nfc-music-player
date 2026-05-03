//Jason Astorga

// libraries
#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// preprocessor directives
#define RST_PIN 9
#define SS_RFID 10

//instantiating objects
SoftwareSerial softSerial(2, 3);
DFRobotDFPlayerMini dfPlayer;
MFRC522 mfrc522(SS_RFID, RST_PIN);

void setup() {

  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("MFRC522 initialized");

  softSerial.begin(9600);
  if (!dfPlayer.begin(softSerial)) {
    Serial.println("DFPlayer failed");
    while (true);
  }
  dfPlayer.volume(20);
  Serial.println("Scan Album or Track.");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  String uid = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) uid += "0";
    uid += String(mfrc522.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();
  Serial.print("Scanned UID: ");
  Serial.println(uid);

// Hardcoded songs

// Phantom's Revenge - Hellfire and Damnation
if (uid == "516572F2") {
    dfPlayer.playFolder(1, 1);

    // Phantom's Revenge - Jill
  } else if (uid == "C17771F2") {
    dfPlayer.playFolder(1, 2);

    // Beltran - Are You Satisfied
  } else if (uid == "D16F71F2") {
    dfPlayer.playFolder(1, 3);

    // Mochakk - Jealous 
  } else if (uid == "D16B7DF2") {
    dfPlayer.playFolder(1, 4);

    // Marcos Strous - Slay
  } else if (uid == "61E87DF2") {
    dfPlayer.playFolder(1, 5);

    // Surreal and Motiv - Comfort Me
  } else if (uid == "61E47DF2") {
    dfPlayer.playFolder(1, 6);

    // Breaking down - ERRx
  } else if (uid == "91A17EF2") {
    dfPlayer.playFolder(1, 7);

    // Stay Puffed - 4am krew
  } else if (uid == "D1737DF2") {
    dfPlayer.playFolder(1, 8);
    
    // Mobb Deep - Shook Ones (DJ Zinc Remix)
  } else if (uid == "919D7EF2") {
    dfPlayer.playFolder(1, 9);

    // Skeptikal - Cold Fold
  } else if (uid == "D16F7DF2") {
    dfPlayer.playFolder(1, 10);

    // Misty - Al Grey Jimmy Forrest Quintet
  } else if (uid == "61E07DF2") {
    dfPlayer.playFolder(1, 11);

    // Blues Everywhere - Al Grey Jimmy Forrest Quintet
  } else if (uid == "91957EF2") {
    dfPlayer.playFolder(1, 12);

    // Jam Blues (Norman Granz Jam Session)
  } else if (uid == "91997EF2") {
    dfPlayer.playFolder(1, 13);

    // Oscar Peterson - Blues For Big Scotia
  } else if (uid == "815972F2") {
    dfPlayer.playFolder(1, 14);

    // Perdido - The Infamous Illinois Jacquet
  } else if (uid == "715D72F2") {
    dfPlayer.playFolder(1, 15);

    // Carl Fontana - Bye Bye Blackbird
  } else if (uid == "616172F2") {
    dfPlayer.playFolder(1, 16);

    // MiLes Davis - When Lights Are Low
  } else if (uid == "D17371F2") {
    dfPlayer.playFolder(1, 17);

    // The Don Ellis Orchestra - Indian Lady
  } else if (uid == "E1F870F2") {
    dfPlayer.playFolder(1, 18);

    // Ahmad Jamal - Invitation
  } else if (uid == "E10071F2") {
    dfPlayer.playFolder(1, 19);

    // Benny Goodman and His Band - Breakfast Feud
  } else if (uid == "E1FC70F2") {
    dfPlayer.playFolder(1, 20);
  } else {
    // debug only
    Serial.println("UID not found");
  }

  mfrc522.PICC_HaltA();
}