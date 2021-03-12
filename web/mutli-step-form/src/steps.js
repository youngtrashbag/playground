const step1 = (values, errors, touched, handleChange) => {
    return (<>
        <input type="text" name="field1" value={values.field1} onChange={handleChange}/>
        {touched.field1 && errors.field1 ? (
        <div>{errors.field1}</div>
        ) : null}
        <br/>
        <input type="number" name="field2" value={values.field2} onChange={handleChange}/>
        {touched.field2 && errors.field2 ? (
        <div>{errors.field2}</div>
        ) : null}
    </>);
}
const step2 = (values, errors, touched, handleChange) => {
    return (<>
        <input type="text" name="field3" value={values.field3} onChange={handleChange}/>
        {touched.field3 && errors.field3 ? (
        <div>{errors.field3}</div>
        ) : null}
    </>);
}

const renderStep = (step, values, errors, touched, handleChange) => {
    switch (step) {
        case 1:
            return step1(values, errors, touched, handleChange);
        case 2:
            return step2(values, errors, touched, handleChange);
        default:
            return <h1>test - default</h1>;
    }
}

const stepButton = (step) => {
    var buttonValue = "none";
    var text = "Start";
    var newStep = 1;

    switch (step) {
        case 1:
            text = "Next";
            newStep = 2;
            break;
        case 2: 
            text = "Submit!";
            newStep = 3;
            break;
        default:
            break;
    }

    //return <button type="submit" value={text} onClick={setStep(newStep)}/>
    return {text, newStep};
}

export {renderStep, stepButton};
