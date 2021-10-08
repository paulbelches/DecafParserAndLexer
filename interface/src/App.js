import React, {useState} from "react"
import './App.css';
import Terminal from './components/Terminal';
import Alert from './components/Alert';

function App() {
  const [value, setValue] = useState("");
  const [result, setResult] = useState("");
  const [title, setTitle] = useState("");

  const sendCode = () => {
    const axios = require('axios');
    axios.post('http://127.0.0.1:5000/', {
      code: value,
    })
    .then(function (response) {
      const message = response.data;
      console.log(message)
      if (message === ""){
        setTitle("Build succeed ✓")
        setResult("")
      } else {
        setTitle("Errors found")
        setResult(message)
      }
    })
    .catch(function (error) {
      setTitle("No Response")
      setResult("")
    });
  }

  return (
    <div className="App">
      <Terminal
        value={value}
        setValue={(value)=>{setValue(value)}}
      />
      <br></br>
      <Alert
        sendCodeMethod={() => sendCode()}
        text={result}
        title={title}
      />
    </div>
  );
}

export default App;
