/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

let multiply = function(num1, num2) {
    if (num1 === "0" || num2 === "0") {
        return "0";
    }
        
    let firstNumber = [...num1];
    let secondNumber = [...num2];
    
    // Reverse both the numbers.
    firstNumber.reverse();
    secondNumber.reverse();

    // To store the multiplication result of each digit of secondNumber with firstNumber.
    let N = firstNumber.length + secondNumber.length;
    let answer = new Array(N).fill(0);
        
    for (let place2 = 0; place2 < secondNumber.length; place2++) {
        let digit2 = Number(secondNumber[place2]);

        // For each digit in secondNumber multiply the digit by all digits in firstNumber.
        for (let place1 = 0; place1 < firstNumber.length; place1++) {
            let digit1 = Number(firstNumber[place1]);

            // The number of zeros from multiplying to digits depends on the 
            // place of digit2 in secondNumber and the place of the digit1 in firstNumber.
            let currentPos = place1 + place2;

            // The digit currently at position currentPos in the answer string
            // is carried over and summed with the current result.
            let carry = answer[currentPos];
            let multiplication = digit1 * digit2 + carry;

            // Set the ones place of the multiplication result.
            answer[currentPos] = multiplication % 10;

            // Carry the tens place of the multiplication result by 
            // adding it to the next position in the answer array.
            answer[currentPos + 1] += Math.floor(multiplication / 10);
        }
    }

    if (answer[answer.length - 1] == 0) {
        answer.pop();
    }

    // Ans is in the reversed order.
    // Reverse it to get the final ans.
    answer.reverse();
    return answer.join('');
};
