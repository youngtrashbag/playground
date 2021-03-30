import './index.css';
import config from './config.json';
import tinycolor from 'tinycolor2';

const handleColorChange = (event) => {
    const s_color = event.target.value;
    console.log(s_color);
    if (s_color.length >= 3 && s_color.length <= 8) {
        const color = tinycolor(s_color);

        document.getElementsByTagName("body")[0].style.backgroundColor = color;
        [...document.getElementsByClassName("text")].forEach(element => {
            const colors = color.splitcomplement().map(function(t) { return t.toHexString(); })
            element.style.color = colors[1];
        });
    }
}

function App() {
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
        </div>
    </div>
    );
}

export default App;
