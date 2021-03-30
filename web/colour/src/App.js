import './index.css';
import config from './config.json';
import tinycolor from 'tinycolor2';
import { useEffect } from 'react';


function App() {
    var color = tinycolor("black");

    const handleColorChange = (event) => {
        const s_color = event.target.value;
        console.log(s_color);
        if (s_color.length >= 3 && s_color.length <= 8) {
            color = tinycolor(s_color);

            document.getElementsByTagName("body")[0].style.backgroundColor = color;
            [...document.getElementsByClassName("text")].forEach(element => {
                const colors = color.splitcomplement().map(function(t) { return t.toHexString(); })
                element.style.color = colors[1];
            });
        }
    }

    const analogDisplay = () => {
        var analogs = [];
        color.analogous().forEach(c => {
            const hexValue = c.toHexString();
            analogs.push(
                <div className="colorDisplay" style={{backgroundColor: hexValue}}></div>
            );
            console.log(c);
        });

        return (
            <>
            <div id="analogs" className="colorContainer">
                {analogs}
            </div>
            </>
        );
    }

    useEffect(() => {

    },[]);

    return (
    <div className="App">
        <div className="Container">
            <h1 class="text">{config.title}</h1>
            <h2 class="text">{config.description}</h2>
            <p class="text">Please enter Hexadecimal Color.</p>
            <div className="sameLine">
                #
                <input
                    id="color"
                    type="text"
                    placeholder="B4FF69"
                    onChange={handleColorChange}
                    maxLength={8}
                ></input>
            </div>
            <br />
            <h3>Analogs</h3>
            {analogDisplay()}
            <h3>Complements</h3>
            <div id="complements"></div>
            <h3>Triad</h3>
            <div id="triad"></div>
        </div>
    </div>
    );
}

export default App;
