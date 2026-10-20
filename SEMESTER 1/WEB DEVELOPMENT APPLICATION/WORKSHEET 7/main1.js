const fs = require("fs");
const analysis = require("./analysis");

let text = fs.readFileSync("myAnalysis.txt", "utf8");
let result = analysis(text);

let numbers = Object.keys(result).map(Number);
let count = numbers.length;

console.log("Total number of plain number words are:", count, numbers);