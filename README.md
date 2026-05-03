# NFC Music Player

A standalone, phone-free music playback system triggered by physical NFC cards. Tap a card, play a track. No app, no screen, no internet.

## Concept

The goal was to make music physical again — closer to the experience of flipping through records than scrolling through a playlist. Each NFC sticker card is mapped to a specific track, and tapping it to the reader triggers immediate playback through a 3.5mm audio output.

## Hardware

| Component | Role |
|---|---|
| Elegoo Uno R3 | Microcontroller |
| MFRC522 | NFC reader (SPI) |
| DFPlayer Mini | MP3 audio playback (UART) |
| MIFARE Classic 1K tags | NFC sticker cards (x20) |
| MicroSD card | Track storage |
| 3.5mm stereo jack | Audio output |

## How It Works

1. MFRC522 listens for an NFC card over SPI
2. On detection, the UID is read and matched against a hardcoded lookup table
3. The corresponding track number is sent to the DFPlayer Mini over UART
4. Audio plays through the 3.5mm output

## Technical Challenge — SPI Bus Conflict

The intended v1.0 architecture used a standalone SD card adapter to load a `library.csv` file mapping UIDs to tracks dynamically. During development, initializing both the MFRC522 and the SD card adapter on the same SPI bus caused a bus contention issue — neither peripheral initialized reliably.

Two solutions were evaluated:

- **Option 1 (implemented):** Hardcode UID-to-track mappings directly in the sketch, eliminating the SD card adapter from the SPI bus entirely. Chosen for v0.1 as a deliberate tradeoff — sacrifices flexibility for reliable operation.
- **Option 2 (planned):** Load the CSV into memory arrays during `setup()`, call `SD.end()` to release the bus, then reinitialize the MFRC522 on a clear bus. Preserves the dynamic lookup architecture without permanent bus contention.

v0.1 runs on Option 1. Option 2 is the target architecture for v1.0.

## Status

- v0.1 — (3-12-26) Working. Hardcoded UID lookup, 20 tracks, stable playback.
- v1.0 — (Currently In Progress). CSV-based dynamic lookup via resolved SPI architecture.

## Built With

- Arduino (C++)
- SPI, UART protocols
- MFRC522 library
- DFPlayer Mini library
