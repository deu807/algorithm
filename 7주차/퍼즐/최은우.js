// 시간초과 코드
// js로는 풀수없는 문제 같음

const fs = require("fs");

const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().replaceAll('\r', '').trim().split('\n');

const puzzle = input.map(e => e.split(' ').map(Number))
const dir = [
  [-1, 0],
  [1, 0],
  [0, 1],
  [0, -1],
];

const solution = (puzzle) => {
  const str = puzzle.map(e => e.join('')).join('')
  const goal = "123456780"
  const memory = {}
  memory[str] = 0
  const queue = [str]
  let result = -1
  let index = 0
  const swap = (data, current, move) => {
    const newData = data.split("");
    newData[current] = newData[move];
    newData[move] = "0";

    return newData.join("");
  }


  while (queue.length !== index) {
    const now = queue[index++]
    const cost = memory[now]
    if (now === goal) {
      result = cost
      break
    }
    const current = now.indexOf('0')
    for (let [i, j] of dir) {
      const newIdx = current + i * 3 + j;
      if (newIdx < 0 || newIdx >= 9) continue;

      const next = swap(now, current, newIdx);
      if (memory[next] != undefined) continue;

      queue.push(next);
      memory[next] = cost + 1;
    }
  }
  console.log(result);

}




solution(puzzle)