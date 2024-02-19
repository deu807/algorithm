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

let [a,b] = input().split(' ').map(Number)
let result = 0
function primes(n) {
  let i = 2
  const factors = []
  while(n > 1){
    if(n%i){
      i++
    }else {
      n /= i
      factors.push(i)
    }
  }
  return factors
}
for(let i = a ; i <= b ; i++){
  const arr = primes(i)
  const underPrime = primes(arr.length)
  if(underPrime.length === 1) {
    result++
  }
}

console.log(result);