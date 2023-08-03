const fs = require("fs");

const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const n = Number(input[0])
// console.log(n);
const isPrime = (x) => {
  if (x < 2) return false
  for (let i = 2; i < x ** 0.5 + 1; i++) {
    if (x % i === 0) return false
  }
  return true
}

const dfs = (num) => {
  if(num.length === n){
    console.log(num);
  }else {
    for(let i = 0 ; i < 10 ; i++){
      let temp = `${num}${i}`
      if(isPrime(Number(temp)))
        dfs(temp)
    }
  }
}

dfs('2')
dfs('3')
dfs('5')
dfs('7')