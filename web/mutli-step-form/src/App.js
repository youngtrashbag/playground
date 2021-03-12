import {useState} from 'react';
import {Formik, Form} from 'formik';
import * as Yup from 'yup';

import {renderStep, stepButton} from './steps';
import './App.css';

function App() {
  const [step, setStep] = useState(1);

  const formData = {
    field1: "",
    field2: 2,
    field3: ""
  }

  const validationSchema = (Yup.object({
    field1: Yup.string()
      .max(5),
    field2: Yup.number(),
    field3: Yup.string()
      .required()
  }))

  const handleSubmit = (data) => {
    var prettified = JSON.stringify(data, null, 2)
    alert(prettified);
  }

  return (
    <div className="App">
      <h1>test</h1>
      <Formik
        enableReinitialize
        initialValues={formData}
        //initialValues={{...formData}}
        validationSchema={validationSchema}
        onSubmit={handleSubmit}
      >
        { ({values, errors, touched, handleChange}) => {
          var {text, newStep} = stepButton(step);

          return (<Form>
            {renderStep(step, values, errors, touched, handleChange)}
            <br />
            <button type="submit" >{text}</button>
          </Form>);
        }}
      </Formik>
    </div>
  );
}

export default App;
