const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .replaceAll("\r", "")
  .trim()
  .split("\n");

  const arr= input[0].split(' ');
  const a = arr[0]
  const b = arr[1]
  const c = arr[2]
  const d = arr[3]
  const e = arr[4]
  const f = arr[5]
  
  let x, y;

  x = (e*c - b*f) / (e*a-b*d)
  y = (d*c - a*f) / (d*b - a*e)

  console.log(x + " " + y)

