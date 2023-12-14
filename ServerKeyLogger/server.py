from flask import Flask, request
import os

app = Flask(__name__)

@app.route('/upload/<ipAddress>', methods=['POST'])
def receiveLogs(ipAddress):
    data = request.get_data()
    
    try:
        os.mkdir(ipAddress)
    except FileExistsError:
        pass

    with open(f"./{ipAddress}/logs.txt", "a") as log:
        log.write(data.decode("windows-1252"))

    return {"status": 200}

if __name__ == '__main__':
    app.run(debug=True)
