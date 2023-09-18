const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .replaceAll("\r", "")
  .trim()
  .split("\n");

  const n = Number(input[0])

  const fc = (x) => {

    return (x === 0 ) ? 1 : (x === 1 ) ? 1 : x * fc(x-1)
  }

  console.log(fc(n))




