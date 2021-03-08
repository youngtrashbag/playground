import './App.css';

const GenerateText = (text) => {
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

    delay += 150;
  })

  return jsx;
}

function App() {
  return (
    <div className="App">
      <div className="Container">
        <div className="Text">
          {GenerateText("Loading...")}
        </div>
      </div>
    </div>
  );
}

export default App;
