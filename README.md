
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
![Login](https://cdn.discordapp.com/attachments/933791098827059204/1184967215225770054/image.png?ex=669834b7&is=6696e337&hm=dd4810882d9cef3fb98bc1b984d1bdf4e2d5ecc06164ada6c3834146db0af04c&)

### Server receiving the TXT file.
![Server](https://cdn.discordapp.com/attachments/933791098827059204/1184968667163799572/image.png?ex=66983611&is=6696e491&hm=c8146f39e25ca252d8425f1a2a7067873053199b29f75ab631cbe7990d3ec300&)

### Logs
![Logs](https://cdn.discordapp.com/attachments/933791098827059204/1184969493303263434/image.png?ex=669836d6&is=6696e556&hm=900d8e624b5f6c8ca120164d1d665cd93985992334ad118c11b5f66d22f28f93&)
## Support

- Send a DM to the Discord: .main.cpp
