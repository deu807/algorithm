const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .replaceAll("\r", "")
  .trim()
  .split("\n");


let [a, b, c] = input[0].split(' ').map(Number)

let ans = 0;

const func = ((a, b) => {
  if (a === b)
    return true;
  else
    return false;
})

if (a === b && a === c && c === b) {
  ans = 10000 + a * 1000;
}

else if (a === b || a === c || b === c) {
  if (func(a, b)) ans = 1000 + a * 100;
  else if (func(b, c)) ans = 1000 + b * 100;
  else ans = 1000 + a * 100;
}

else {
  let max = Math.max(a, b, c);
  ans = max * 100;
}

console.log(ans);