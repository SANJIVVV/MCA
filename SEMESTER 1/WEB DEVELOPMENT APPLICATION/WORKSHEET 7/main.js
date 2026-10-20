const fs = require("fs");
const totalPalinWords = require("./totalPalinWords");

fs.writeFileSync("myText.txt", "Madam and mom saw a level radar.");

let text = fs.readFileSync("myText.txt", "utf8");

console.log("Total palindrome words:", totalPalinWords(text));