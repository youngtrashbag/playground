import React, {useEffect, useState} from 'react';
import axios from 'axios';
import './App.css';

const selection = [
  {
    title: "low res hounds....",
    secret: "kiffä hound"
  },
  {
    title: "!",
    secret: "chef hound"
  }
]

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
  const [metadata, setMetadata] = useState(selection[0]);
  const [title, setTitle] = useState(metadata.title);

  useEffect(() => {
    document.title = title

    window.sessionStorage.setItem("secret", metadata.secret);
  }, [])

  return (
    <div className="container">
      <h1>{title}</h1>
      <input
        id="newTitle"
        type="text"
        placeholder="change title of this page"
        onChange={ () => {setTitle(document.getElementById("newTitle").value)} }
      />
      <div className="subContainer">
        <HoundImage />
      </div>
    </div>
  );
}

export default App;
