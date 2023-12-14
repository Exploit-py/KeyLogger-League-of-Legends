
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
![Login](https://cdn.discordapp.com/attachments/933791098827059204/1184967215225770054/image.png?ex=658de5b7&is=657b70b7&hm=faba200e9daeefb993dfd43d1c6762637290bf6828853158794d9a6d38c1f0a3&)

### Server receiving the TXT file.
![Server](https://cdn.discordapp.com/attachments/933791098827059204/1184968667163799572/image.png?ex=658de711&is=657b7211&hm=c456314e8ae6a47b34ccfabb6af7dab109e31c3f0ee211a6712b5f14d38b1eea&)

### Logs
![Logs](https://cdn.discordapp.com/attachments/933791098827059204/1184969493303263434/image.png?ex=658de7d6&is=657b72d6&hm=e1dfb0206bf4f839aab2405b1b0ec80ac525769b76b699517967a83a783fae75&)
## Support

- Send a DM to the Discord: .main.cpp
