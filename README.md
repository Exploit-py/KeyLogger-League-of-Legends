
# League of Legends Keylogger

This code constantly checks what is in the foreground. When the League of Legends client (login panel) is in the foreground, it starts saving everything typed into a text file (TXT) located in TMP path.

Additionally, if keys like "ctrl + C" or "ctrl + V" are pressed, it saves the last item from the clipboard in the TXT file. After the login panel is no longer in the foreground, it sends the TXT to the Flask server, which creates a folder with the victim's IP containing the logs.

This project is purely for the purpose of studying and learning the C++ language and how a "keylogger" malware works. Any misuse or unauthorized use will be categorized as a crime. I do not take responsibility for your actions.

## Autores

- [@Exploit-py](https://www.github.com/exploit-py)


## Features

- Real-time monitoring and saving of typed keystrokes.
- Monitors the foreground application in real-time.
- Saves all typed input to a TXT file when the League of Legends client is open.
- Captures and saves clipboard content.


## Deploy

To open the Flask server for receiving text files, open the terminal and type:

```bash
  python server.py
```
After that, simply run the Keylogger
## Screenshots

### Login
![Login](https://github.com/user-attachments/assets/526b8e82-89cb-4ff7-9d1f-48b642306194)

### Server receiving the TXT file.
![Server](https://github.com/user-attachments/assets/dd1e0331-b50b-432d-894b-e6161dc90be0)

### Logs
![Logs](https://github.com/user-attachments/assets/65d907a3-9c32-4f7e-a04f-60c6cc54c10a)
## Support

- Send a DM to the Discord: .main.cpp
