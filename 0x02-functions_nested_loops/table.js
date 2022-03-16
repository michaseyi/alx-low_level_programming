function timesTable() {
  for (let i = 0; i < 16; i++) {
    let count = 0;
    for (let j = 0; j < 16; j++) {
      if (j === 0) {
        process.stdout.write(`${count}`);
      } else {
        process.stdout.write(`,`);
        if (count < 10) {
          process.stdout.write(" ");
        }
        if (count < 100) {
          process.stdout.write(" ");
        }
        process.stdout.write(" ");
        process.stdout.write(`${count}`);
      }
      count += i;
    }
    process.stdout.write("\n");
  }
}

timesTable();
