'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the minimumSwaps function below.
function minimumSwaps(arr) {
 let count = 0;
 for( let i = 0; i < arr.length; i++){
     count += swapper(arr,i);
 }
 return count;
}

function swapper(arrayData, index) {
    let swapCount = 0;
    // e.g. 4 3 1 2
    // index start from 0
    let currentValue = arrayData[index]
    //e.g. 4
    let leastValue = arrayData[currentValue - 1]; 
    //e.g. 2 because data of the dimension of 3 (current value is 4 - 1 is 3) is 2.
    // as long as the current value isn't same with least value, then process it
    while (currentValue !== leastValue) {
        // replace data of current array dimension with value of array least dimension
        arrayData[index] = leastValue
        // replace data of dimension array mention with the current array dimension data
        arrayData[currentValue - 1] = currentValue;
        //  count the process
        swapCount++;
        
        // assign the value so next loop will be start again
        currentValue = leastValue;
        leastValue = arrayData[currentValue - 1];
    }
    return swapCount;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine(), 10);

    const arr = readLine().split(' ').map(arrTemp => parseInt(arrTemp, 10));

    const res = minimumSwaps(arr);

    ws.write(res + '\n');

    ws.end();
}
