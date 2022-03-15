function timesTable() {
  for (let i = 0; i < 10; i++) {
    let count = 0;
    for (let j = 0; j < 10; j++) {
      if (j === 0) {
        process.stdout.write(`${count}`);
      } else {
        process.stdout.write(`,`);
        if (count < 10) {
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
