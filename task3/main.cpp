//3
int main(int argc, char* argv[]) {
    int n = 0;
    for (int i = 0; argv[1][i] != '\0'; ++i) {
        n = n * 10 + (argv[1][i] - '0');
    }

    double* a = new double[n];
    double* b = new double[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    double ans = 0;
    for (int i = 0; i < n; ++i) {
        ans+= a[i] * b[i];
    }

    std::cout.precision(15);
    std::cout << ans << '\n';

    delete[] a;
    delete[] b;
    return 0;
}
