const fs = require("fs");
//"./input.txt , /dev/stdin"
const input = fs.readFileSync('./input.txt').toString().trim().split('\n')
// const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')
const [nodeCount, lineCount] = input.shift()

const arr = Array.from({ length: 201 }, (_, i) => Array.from({ length: 201 }, (_, j) => i === j ? 0 : Infinity))
let answer = Infinity
for (let i = 0; i < input.length; i++) {
  const [x, y, c] = input[i].split(' ').map(e => Number(e))
  arr[x][y] = Math.min(arr[x][y], c)
  arr[y][x] = Math.min(arr[y][x], c)
}

for (let i = 1; i <= nodeCount; i++) {
  for (let j = 1; j <= nodeCount; j++) {
    for (let k = 1; k <= nodeCount; k++) {
      arr[i][j] = Math.min(arr[i][j], arr[i][k] + arr[k][j])
      arr[j][i] = Math.min(arr[j][i], arr[j][k] + arr[k][i])
    }
  }
}

for (let start = 1; start <= nodeCount; start++) {
  let temp = 0
  for (let j = 0; j < input.length; j++) {
    const [x, y, c] = input[j].split(' ').map(e => Number(e))
    temp = Math.max(temp, (arr[start][x] + arr[y][start] + c) / 2)
  }
  answer = Math.min(answer, temp)
}

console.log(answer.toFixed(1));