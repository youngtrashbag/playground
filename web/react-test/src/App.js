import React, {useEffect, useState} from "react";

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
        id="newTitle"
        type="text"
        placeholder="change title of this page"
        onChange={ () => {document.title = document.getElementById("newTitle").value} }
      />
      <div className="subContainer">
        {component}
      </div>
    </div>
  );
}

export default App;
