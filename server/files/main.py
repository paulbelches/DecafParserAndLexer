from flask import Flask, request
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/', methods=['POST'])
def hello_world():
    data = request.json['code']
    
    return data

if __name__ == '__main__':
    app.run()