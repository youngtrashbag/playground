const step1 = (values, errors, touched) => {
    return (<>
        <input type="text" name="field1" value={values.field1}/>
        {touched.field1 && errors.field1 ? (
        <div>{errors.field1}</div>
        ) : null}
        <input type="number" name="field2" value={values.field2}/>
        {touched.field2 && errors.field2 ? (
        <div>{errors.field2}</div>
        ) : null}
    </>);
}
const step2 = (values, errors, touched) => {
    return (<>
        <input type="text" name="field3" value={values.field3}/>
        {touched.field3 && errors.field3 ? (
        <div>{errors.field3}</div>
        ) : null}
    </>);
}

const renderStep = (step, values, errors, touched) => {
    switch (step) {
        case 1:
            return step1(values, errors, touched);
        case 2:
            return step2(values, errors, touched);
        default:
            return <h1>test - default</h1>;
    }
}

const stepButton = (step) => {
    var buttonValue = "none";

    switch (step) {
        case 1:
            buttonValue = "Next";
            break;
        case 2: 
            buttonValue = "Submit";
            break;
        default:
            buttonValue = "none";
            break;
    }

    return (
        <button type="submit" value={buttonValue}/>
    );
}

export {renderStep, stepButton};
