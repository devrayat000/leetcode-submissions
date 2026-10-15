function* fibGenerator(): Generator<number, any, number> {
    let i = 0, j = 1;
    while (true) {
        yield i;
        [i, j] = [j, i + j];
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */