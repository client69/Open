// iterative function to implement Binary Search
const binary_search = (arr, x) => {
  let start = 0,
    end = arr.length - 1;

  // iterate while start not meets end
  while (start <= end) {
    // find the mid index
    let mid = Math.floor((start + end) / 2);

    // if element is present at mid, return true
    if (arr[mid] === x) {
      return true;
    } else if (arr[mid] < x) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return false;
};

// driver code
const arr = [1, 3, 5, 7, 8, 9];
const x = 5;

if (binary_search(arr, x)) {
  console.log('Element found!');
} else {
  console.log('Element not found!');
}
