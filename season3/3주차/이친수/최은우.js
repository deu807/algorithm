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

const n = Number(input())


const arr = [0 , 1n , 1n]
let index = 3
while(!arr[n]){
  arr.push(arr[index-1]+arr[index-2])
  index++
}

console.log(arr[n].toString());