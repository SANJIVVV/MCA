
function totalPalinWords(text) {
    let words = text.toLowerCase().match(/\b[a-z]+\b/g) || [];
    let count = 0;

    for (let word of words) {
        let reverse = word.split("").reverse().join("");

        if (word === reverse) {
            count++;
        }
    }

    return count;
}

module.exports = totalPalinWords;
