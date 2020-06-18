void divCount(long long n) {
  bool hash[n + 1];
  memset(hash, true, sizeof(hash));

  for (int i = 2; i * i < n; i++) {
    if (hash[i]) {
      for (int j = 2 * i; j < n; j += i)
        hash[j] = false;
    }
  }

  int totalDivisors = 1;
  for (int i = 2; i <= n; i++) {
    if (hash[i]) {
      int count = 0;
      if (n % i == 0) {
        while (n % i == 0) {
          count++;
          n = n / i;
        }
        totalDivisors = totalDivisors * (count + 1);
      }
    }
  }

  cout << totalDivisors << " ";

  return;
}
