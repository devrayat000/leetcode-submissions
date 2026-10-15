int fib(int n) {
    double gr = (1 + sqrt(5)) / 2;
    return round(pow(gr, n) / sqrt(5));
}