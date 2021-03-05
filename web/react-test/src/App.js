import React, {useEffect, useState} from 'react';
import axios from 'axios';
import './App.css';

const App = () => {
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

  // change document attribtues
  useEffect(() => {
    document.title = "Dog images or something"
    // funny secret meme
    window.sessionStorage.setItem("secret", "kiffä hound");
  });

  var element = (<h1>Loading...</h1>);
  if (!isLoading) {
    element = <img src={data.url} alt="dog image" />
  }

  return (
    <div className="container">
      <div className="subContainer">
        {element}
      </div>
    </div>
  );
}

export default App;
