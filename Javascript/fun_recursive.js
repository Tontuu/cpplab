function rangeOfNumbers(startNum, endNum) {
    return (startNum == endNum+1) ? [] : [startNum].concat(rangeOfNumbers(startNum+1, endNum));
};

console.log(rangeOfNumbers(2, 9));
