import React, {useEffect, useState} from 'react';
import axios from 'axios';
import './App.css';

const HoundImage = () => {
  const [isLoading, setLoading] = useState(true);
  const [data, setData] = useState();

  useEffect(() => {
    axios({
      method: "get",
      baseURL: "https://random.dog",
      url: '/woof.json',
    }).then(
      response => {
        // ok
        setData(response.data);
        setLoading(false);
      }
    ).catch(err => {
      console.log("Axios err: ", err.message)
    });
  }, []);

  var element = (<h1>Loading...</h1>);
  if (!isLoading) {
    element = <img src={data.url} alt="dog image" />
  }

  return element;
}

const App = () => {
  // change document attribtues
  useEffect(() => {
    document.title = "low res hounds"
    // funny secret meme
    window.sessionStorage.setItem("secret", "kiffä hound");
  });

  return (
    <div className="container">
      <h1>low res hounds....</h1>
      <div className="subContainer">
        <HoundImage />
      </div>
    </div>
  );
}

export default App;
