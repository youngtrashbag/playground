import {useEffect, useState} from "react";

import './App.css';

import Spin from "./spin";

const Links = () => {
  return (
    <a href="spin"><p>spin</p></a>
  );
}

function App() {
  const [component, setComponent] = useState(Links);
  useEffect(() => {
    if (window.location.pathname == encodeURI("/spin")) {
      setComponent(Spin("Loading..."));
    }
  }, []);
  return (
    <div className="App">
      <div className="TopContainer">
        {component}
      </div>
    </div>
  );
}

export default App;
