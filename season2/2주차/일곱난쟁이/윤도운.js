const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .replaceAll("\r", "")
  .trim()
  .split("\n");


let sum = 0;

for (let i = 0; i < 9; i++) {
  sum += Number(input[i]);
}
// 모든 원소의 합

let result = [];

for (let i = 0; i < 9; i++) {
  for (let j = i + 1; j < 9; j++) {
    let s = Number(input[i]) + Number(input[j]);
    if ((sum - s) === 100) {
      result = input.filter((number, index) => index !== i && index !== j);
    }
  }
}

result.sort((a, b) => a - b);

console.log(result.join("\n"));