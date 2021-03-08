import "./spin.css";

const Spin = (text) => {
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
    <div className="Container">
      {jsx}
    </div>
  )
}

export default Spin;
