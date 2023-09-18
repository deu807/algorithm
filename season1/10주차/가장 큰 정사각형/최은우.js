const fs = require("fs");

const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().replaceAll('\r', '').trim().split("\n")

const [n, m] = input[0].split(' ').map(Number)
const map = []

for (let i = 1; i <= n; i++) {
  map.push(input[i].split('').map(Number))
}

let max = 0
const square = Array.from({ length: n }, () => Array.from({ length: m }, () => 0))
for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (map[i][j]) {
      square[i][j] = 1
      max = 1
    }
  }
}


for (let length = 1; length < Math.min(n, m); length++) {
  for (let i = 0; i < n - length; i++) {
    for (let j = 0; j < m - length; j++) {
      if (square[i][j] && square[i + 1][j] && square[i][j + 1] && square[i + 1][j + 1]) {
        square[i][j] = 1
        max = Math.pow(length + 1, 2)
      }else {
        square[i][j] = 0
      }
    }
  }
}

console.log(max);