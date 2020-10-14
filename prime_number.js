function isPrime(num) {
	let index = 2,
		isValid = true,
		sqrt = Math.ceil(Math.pow(num,1/2));

	sqrt += 1;

	while(index < sqrt) {		
		if(num % index == 0) {
			isValid = false;
			break;
		}
		index++;
	}	

	return isValid;
}