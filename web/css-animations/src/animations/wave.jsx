import { useParams } from "react-router-dom";

import "./wave.css";

const Wave = () => {
  const { text } = useParams();

  if (text === null || text === undefined) {
    text = "...";
  }

  const arr = text.split("");

  var jsx = [];
  var delay = 0;
  arr.forEach((c) => {
    var delayms = delay + "ms";

    jsx.push((
      <div className="Char" style={{animationDelay: delayms}}>
        {c}
      </div>
    ));

    delay += 200;
  })

  return (
    <div className="Container">
      {jsx}
    </div>
    );
}

export default Wave;
