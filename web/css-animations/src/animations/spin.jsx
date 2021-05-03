import { useParams } from "react-router-dom";

import "./spin.css";

const Spin = () => {
  const { text } = useParams();
  const arr = text.split("");

  var jsx = [];
  arr.forEach((c) => {
    jsx.push((
      <div className="Char">
        {c}
      </div>
    ));
  })

  return (
    <div className="SpinContainer">
      {jsx}
    </div>
  )
}

export default Spin;
