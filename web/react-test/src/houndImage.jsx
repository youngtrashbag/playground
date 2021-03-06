import React, {useEffect, useState} from 'react';
import axios from 'axios';

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

export default HoundImage;
