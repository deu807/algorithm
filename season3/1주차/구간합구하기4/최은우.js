const fs = require("fs");

const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = (() => {
  const stdin = fs
    .readFileSync(filePath)
    .toString()
    .replaceAll("\r", "")
    .split("\n");
    let ln = 0;
    return () => stdin[ln++];
})();

const [n, m] = input().split(' ').map(Number)
const arr = input().split(' ').map(Number)
const sum = [0]
for(let i = 1; i <= n ; i++){
  sum.push(sum[i-1] + arr[i-1])
}
const result = []
for(let i = 0 ; i < m ; i++){
  const [x, y] = input().split(' ').map(Number)
  result.push(sum[y]-sum[x-1]);
}

console.log(result.join('\n'))