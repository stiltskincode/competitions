#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }
    
    if (largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main() {
    freopen ("./input.txt","r",stdin);
    freopen ("./output.txt","w+",stdout);
    
    int T; cin >> T;
    while(T--){
        int n, m; cin >> n >> m;
        int arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        
        for(int i = n/2-1; i >= 0; i--){
            heapify(arr, n, i);
        }
        
        for(int i = n - 1; i >= n - m; --i){
            cout << arr[0] << " ";
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
        cout << "\n";
    }
    return 0;
}
