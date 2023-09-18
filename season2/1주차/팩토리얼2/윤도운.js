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
    if (x === 0) return 1;
    if (x === 1) return 1;
    else return x*fc(x-1);
  }

  console.log(fc(n))




