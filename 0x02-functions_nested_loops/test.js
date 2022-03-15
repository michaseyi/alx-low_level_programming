function time() {
  let a = 0,
    b = 0,
    c = 0,
    d = 0;

  for (let i = 0; i < 1440; i++) {
    console.log(`${a}${b}:${c}${d}`);
    if (d == 9) {
      d = 0;
      if (c == 5) {
        c = 0;
        if (b == 9) {
          b = 0;
          a++;
        } else {
          b++;
        }
      } else {
        c++;
      }
    } else {
      d++;
    }
  }
}

time();
