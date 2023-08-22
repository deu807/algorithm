const fs = require("fs");

const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, K] = input.shift().split(" ").map(Number);

let dp = Array(K + 1).fill(0);
dp[0] = 1;
const coins = input.map(Number);

for (let i = 0; i < coins.length; i++) {
  for (let j = coins[i]; j <= K; j++) {
    dp[j] += dp[j - coins[i]];
  }
}

console.log(dp[K]);
