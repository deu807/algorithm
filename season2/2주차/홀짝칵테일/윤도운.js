const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .replaceAll("\r", "")
  .trim()
  .split("\n");


let [a, b, c] = input[0].split(' ').map(Number)



let result = [a, b, c];

result.sort((a, b) => a - b);

let A = result[0];
let B = result[1];
let C = result[2];

let ans = 0;

const func = (a) => {
  return (a % 2 === 0) ? true : false;
}

if (!func(A * B * C)) ans = A * B * C;  // 세 수의 곱이 홀수일 경우 정답
else {
  if (!func(B * C)) ans = B * C; // 두 수의 곱이 홀수 일 경우
  else if (!func(A * C)) ans = A * C;
  else if (!func(A * B)) ans = A * B;
  else {

    if (C % 2 !== 0) {
      ans = C;
    }

    else if (B % 2 !== 0) {
      ans = B;
    }

    else if (A % 2 !== 0) {
      ans = A;
    }

    else
      ans = A * B * C
  }
}


console.log(ans);