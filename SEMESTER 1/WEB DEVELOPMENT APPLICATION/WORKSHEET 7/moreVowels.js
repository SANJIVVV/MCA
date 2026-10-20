
function moreVowels(text) {
    let words = text.match(/\b[a-zA-Z]+\b/g) || [];

    return words.filter(word => {
        let vowels = word.match(/[aeiou]/gi) || [];
        return vowels.length >= 3;
    });
}

module.exports = moreVowels;
