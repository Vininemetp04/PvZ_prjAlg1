void insertion(int* arr, int sz){
  for (int i = 0; i < sz; i++){
    int j = i;
    while (j < 0 && arr[j-1] > arr[j]){
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;
        j--;
    }
  }
}

void bubble(int* arr, int sz){
}
