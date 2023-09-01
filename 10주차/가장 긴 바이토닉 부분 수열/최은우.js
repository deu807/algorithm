const fs = require("fs");

const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .replaceAll("\r", "")
  .trim()
  .split("\n");

const n = Number(input[0]);
const arr = input[1].split(" ").map(Number);

const higher = Array.from({ length: n }, () => 1);
const lower = Array.from({ length: n }, () => 1);

for (let i = n - 2; i >= 0; i--) {
  for (let j = i + 1; j < n; j++) {
    if (arr[i] > arr[j]) {
      lower[i] = Math.max(lower[i], lower[j] + 1);
    }
  }
}

for (let i = 1; i < n; i++) {
  for (let j = i - 1; j >= 0; j--) {
    if (arr[i] > arr[j]) {
      higher[i] = Math.max(higher[i], higher[j] + 1);
    }
  }
}
let result = 0;
for (let i = 0; i < n; i++) {
  result = Math.max(result, lower[i] + higher[i]);
}
console.log(result - 1);
