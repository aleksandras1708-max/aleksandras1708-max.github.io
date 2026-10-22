//2
void rev(int* arr, int st, int end){
    while(st<end){
        int a =arr[st];
        arr[st]=arr[end];
        arr[end]=a;
        st++;
        end--;
    }
}
int main(int argc, char* argv[]) {
    int n = 0;
    for (int i = 0; argv[1][i] != '\0'; ++i) {
        n = n * 10 + (argv[1][i] - '0');
    }

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int other_k;
    std::cin >> other_k;
    int k=other_k%n;
    if (k<0){
        k+=n;
    }
    if (n>0 and k>0){
        rev(arr,0, n-1);
        rev(arr,0,k-1);
        rev(arr,k, n-1);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << "\n";
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i];
        if (i < n - 1) {
            std::cout << " ";
        }
    }
    
    std::cout << "\n";
    delete[] arr;

    return 0;
}
