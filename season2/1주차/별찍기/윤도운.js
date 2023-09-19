const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .replaceAll("\r", "")
  .trim()
  .split("\n");

const n = Number(input[0])


// 문제 1 ========================================
// for (let i = 1; i <= n; i++) {
//   for (let j = 0; j < i; j++) {
//     process.stdout.write("*");
//   }
//   console.log("");T
// }

// 문제 2 ============================================

answer = ""
blank = ""

// for (let i = 1; i <= n; i++) {
//   answer += "*";
//   for (let j = 1; j <= n - i; j++) {
//     blank += " ";
//   }
//   console.log(blank + answer);
//   blank = "";
// }

// 문제 3 ================================================

// for (let i = 1; i <= n; i++) {
//   for (let j = 0; j <= n - i; j++) {
//     process.stdout.write("*");
//   }
//   console.log("");
// }


// 문제 4 ==================================================

// for (let i = 0; i < n; i++) {
//   for (let j = 1; j <= n - i; j++) {
//     answer += "*"
//   }
//   console.log(blank + answer);
//   blank += " ";
//   answer = ""
// }

// 문제 5 ======================================================
