#use python3.7
from flask import Flask, request
from flask_cors import CORS
import subprocess

app = Flask(__name__)
CORS(app)

@app.route('/', methods=['POST'])
def hello_world():
    data = request.json['code']
    command = ["../../compiler/main", data]
    result = subprocess.run(command, capture_output=True, encoding='ascii')
    
    if (result.stderr == ''):
        return result.stdout
    else:
        return result.stderr
    #return data

if __name__ == '__main__':
    app.run()

