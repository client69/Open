import React, { useState } from "react";

export function RomanForm() {
    const [numInput, setInput] = useState("");

    // const handleSubmit = (e) => {
    //     e.preventDefault();
    // }

    // 1 = "I"
    // 5 = "V"
    // 10 = "X"
    // 50 = "L"
    // 100 = "C"
    // 500 = "D"
    // 1000 = "M"

    const romanize = (arg) => {

        if (arg >= 1000) {
            return "M" + romanize(arg - 1000)
        } if (arg >= 500) {
            return "D" + romanize(arg - 500)
        } if (arg >= 100) {
            return "C" + romanize(arg - 100)
        } if (arg >= 50) {
            return "L" + romanize(arg - 50)
        } if (arg >= 10) {
            return "X" + romanize(arg - 10)
        } if (arg >= 9) {
            return "IX" + romanize(arg - 9)
        } if (arg >= 5) {
            return "V" + romanize(arg - 5)
        } if (arg >= 4) {
            return "IV" + romanize(arg - 4)
        } if (arg >= 1) {
            return "I" + romanize(arg - 1)
        } if (arg === 0) { return '' } //Gets rid of undefined 

    }

    console.log(romanize(numInput))


    return (

        <form>
            <h1 className="roman">{romanize(numInput)}</h1>
            <label> Enter a number 👉 </label>
            <input
                type="text"
                value={numInput}
                onChange={e => setInput(e.target.value)}
            />
        </form>
    );
}

export default RomanForm;
