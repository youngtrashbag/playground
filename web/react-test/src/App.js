import React, {useEffect, useState} from "react";
import ReactDOM from 'react-dom';

import HoundImage from "./houndImage";
import About from "./about";
import "./App.css";

/*const selection = [
  {
    title: "low res hounds....",
    secret: "kiffä hound",
    component: (<HoundImage />)
  },
  {
    title: "!",
    secret: "chef hound",
    component: (<h1>kiffä</h1>)
  }
]*/

const Message1 = (msg) => {
  return (
    <p>{msg}</p>
  )
}

const handleChange = (event) => {
  const msg = Message1(event.target.value);
  ReactDOM.render(
    msg,
    document.getElementById("message")
  );

  var element = document.getElementById("message");
  element.style.visibility = "visible";
  //element.innerHTML = [(<Message2 msg={event.value} />)];
}

const App = () => {
  //const [metadata, setMetadata] = useState(selection[0]);
  const [component, setComponent] = useState((<HoundImage />));

  useEffect(() => {
    if (window.location.pathname === encodeURI("/about")) {
      setComponent(About);
    } else if (window.location.pathname === encodeURI("/kiffä")) {
      setComponent(<h1>kiffä</h1>)
    }

    //window.sessionStorage.setItem("secret", "value");
  }, [])

  return (
    <div className="container">
      <h1>yeees</h1>
      <input
        type="text"
        placeholder="write a message"
        onChange={ handleChange }
      />
      <div className="subContainer">
        <div id="message" className="message"></div>
        <br/>
        {component}
      </div>
    </div>
  );
}

export default App;
