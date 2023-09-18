const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .replaceAll("\r", "")
  .trim()
  .split("\n");

let n = Number(input[0]);
let graph = [];

for (let i = 1; i <= n; i++) {
  graph.push(input[i].split(" ").map(Number));
}

let dp = Array.from({ length: n }, () => Array(1 << n).fill(-1));

function dfs(x, visited) {
  if (visited === (1 << n) - 1) {
    return graph[x][0] ? graph[x][0] : Infinity;
  }

  if (dp[x][visited] !== -1) {
    return dp[x][visited];
  }
  dp[x][visited] = Infinity;
  for (let i = 1; i < n; i++) {
    if (!graph[x][i]) continue;
    if (visited & (1 << i)) continue;

    dp[x][visited] = Math.min(
      dp[x][visited],
      dfs(i, visited | (1 << i)) + graph[x][i]
    );
  }

  return dp[x][visited];
}

console.log(dfs(0, 1));
