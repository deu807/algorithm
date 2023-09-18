const fs = require("fs");

const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const [x1, y1, x2, y2] = input[0].split(' ').map(Number)
const [x3, y3, x4, y4] = input[1].split(' ').map(Number)

const a = [x1, y1]
const b = [x2, y2]
const c = [x3, y3]
const d = [x4, y4]

const ccw = (a, b, c) => {
  const [x1, y1] = a
  const [x2, y2] = b
  const [x3, y3] = c
  return x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3)
}




if (ccw(a, b, c) * ccw(a, b, d) <= 0 && ccw(c, d, a) * ccw(c, d, b) <= 0) {
  console.log(1);
} else {
  console.log(0);
}