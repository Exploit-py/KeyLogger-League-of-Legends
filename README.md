
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
![Login](https://cdn.discordapp.com/attachments/933791098827059204/1184967215225770054/image.png?ex=664871f7&is=66472077&hm=4e77c45e0ccc68ae2fe3990f75ad18a2c48728fb4c9961708f1424760b3ec780&)

### Server receiving the TXT file.
![Server](https://cdn.discordapp.com/attachments/933791098827059204/1184968667163799572/image.png?ex=66487351&is=664721d1&hm=29c68e9949aede45511b0b2a6cabe6b775a2922354652ac96b0fed51024b86d6&)

### Logs
![Logs](https://cdn.discordapp.com/attachments/933791098827059204/1184969493303263434/image.png?ex=66487416&is=66472296&hm=769d818fe6801eedb4a7fc22b6e5af70f695b195ad172023e395bf9b53d828c2&)
## Support

- Send a DM to the Discord: .main.cpp
