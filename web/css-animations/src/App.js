import './App.css';

const GenerateText = (text) => {
  const arr = text.split("");

  var jsx = [];
  arr.forEach((c) => {
    jsx.push((
      <div className="Char">
        {c}
      </div>
    ));
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
