function analysis(text) {
    let numbers = text.match(/(?<![\w@])\d+(?!\w)/g) || [];
    let frequency = {};

    for (let num of numbers) {
        frequency[num] = (frequency[num] || 0) + 1;
    }

    return frequency;
}

module.exports = analysis;