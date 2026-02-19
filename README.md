
# Input Behavior Research – League Client (PoC)

This project is a behavioral research proof-of-concept developed to study how input monitoring tools operate at a low level in Windows environments.

The goal is NOT offensive usage, but to understand how input capture mechanisms behave, how foreground window monitoring works, how clipboard interaction patterns occur, and potential detection surfaces used by anti-cheat and security systems.

All experiments were executed in controlled laboratory environments for educational and research purposes only.

## Autores

- Gabriel Passos — Anti-Cheat & Behavior Research

## Research Overview

The application monitors when a specific window is active and records input events into a temporary local log file. When the monitored window loses focus, the log can be transmitted to a local Flask server to simulate behavioral analysis pipelines.

This allows studying input monitoring patterns, data flow behavior, and detection vectors related to monitoring software.

## Features

- Foreground window monitoring
- Input event logging for research simulation
- Clipboard observation
- Local log processing via Flask server


## Deploy

To open the Flask server for receiving text files, open the terminal and type:

```bash
  python server.py
```
Running the Research Server

## Screenshots

### Login
![Login](https://github.com/user-attachments/assets/526b8e82-89cb-4ff7-9d1f-48b642306194)

### Server receiving the TXT file.
![Server](https://github.com/user-attachments/assets/dd1e0331-b50b-432d-894b-e6161dc90be0)

### Logs
![Logs](https://github.com/user-attachments/assets/65d907a3-9c32-4f7e-a04f-60c6cc54c10a)
## Support

- Send a DM to the Discord: .main.cpp
