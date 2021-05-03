import {
  BrowserRouter as Router,
  Switch,
  Route,
  Link,
  useParams
} from "react-router-dom";

import './App.css';
import Spin from "./animations/spin";
import Wave from "./animations/wave";

function App() {
  return (
    <>
    <Router>
      <div className="header">
      <Link to="/wave">Wave</Link>
      <Link to="/spin">Spin</Link>
      </div>
      <div className="App">
        <div className="TopContainer">
          <Switch>
            <Route exact path="/wave/:text">
              <Wave />
            </Route>
            <Route exact path="/spin/:text">
              <Spin />
            </Route>
            <Route exact path="/">
              <Index />
            </Route>
          </Switch>
        </div>
      </div>
    </Router>
    </>
  );
}

const Index = () => {
  return (
  <div className="App">
    <div className="TopContainer">
      <Link to="/wave">Wave</Link>
      <Link to="/spin">Spin</Link>
    </div>
  </div>
  );
}

export default App;
