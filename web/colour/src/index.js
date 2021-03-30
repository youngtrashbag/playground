import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './App';
import config from './config.json';

document.title = config.title;

ReactDOM.render(
  <React.StrictMode>
    <App />
  </React.StrictMode>,
  document.getElementById('root')
);
