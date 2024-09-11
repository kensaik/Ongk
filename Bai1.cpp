#include <iostream>
#define Max 100
using namespace std;
//Cau truc danh sach dac
struct list {
	int a[Max];
	int n;
};

//Tim kiem
int search(list& l, int x) {
	for (int i = 0; i < l.n; i++) {
		if (l.a[i] == x)
			return i;
	}
}

//Them cuoi
void insert_Last(list& l, int x) {
	l.a[l.n++] = x;
}

//Them theo vi tri
void insert_pos(list& l, int vt, int x) {
	for (int i = ++l.n; i > vt - 1; i--) {
		l.a[i] = l.a[i - 1];
	}
	l.a[vt - 1] = x;
}

//Xoa cuoi
void del_Last(list& l) {
	l.n--;
}

//Xoa theo vi tri
void del_pos(list& l, int vt) {
	for (int i = vt - 1; i < l.n; i++) {
		l.a[i] = l.a[i + 1];
	}
	l.n--;
}

//Tim phan tu lon nhat
int find_Max(list& l) {
	int max = 0;
	for (int i = 0; i < l.n; i++) {
		if (l.a[i] > max)
			max = l.a[i];
	}
	return max;
}

//Tim phan tu lon nhi
int find_Second_Max(list& l) {
	int sec = 0, max = find_Max(l);
	for (int i = 0; i < l.n; i++) {
		if (l.a[i] < max)
			sec = l.a[i];
	}
	return sec;
}

//Sap xep
void swap(int& a, int& b) {
	int c;
	c = a;
	a = b;
	b = c;
}

void selection_sort(list& l) {
	int minpos;
	for (int i = 0; i < l.n - 1; i++) {
		minpos = i;
		for (int j = i + 1; j < l.n; j++) {
			if (l.a[j] < l.a[minpos])
				minpos = j;
		}
		swap(l.a[minpos], l.a[i]);
	}
}

void insertion_sort(list& l) {
	int x, j;
	for (int i = 1; i < l.n - 1; i++) {
		x = l.a[i];
		j = i - 1;
		while (j >= 0 && x < l.a[j]) {
			l.a[j + 1] = l.a[j];
			j--;
		}
		l.a[j + 1] = x;
	}
}

void bubble_sort(list& l) {
	for (int i = 0; i < l.n; i++) {
		for (int j = l.n - 1; j > i; j--) {
			if (l.a[j - 1] > l.a[j])
				swap(l.a[j - 1], l.a[j]);
		}
	}
}

void interchange_sort(list& l) {
	for (int i = 0; i < l.n - 1; i++) {
		for (int j = i + 1; j < l.n; j++) {
			if (l.a[j] < l.a[i])
				swap(l.a[j], l.a[i]);
		}
	}
}

void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int L[Max];
	int R[Max];
	int n1 = m - l + 1;
	int n2 = r - m;
	/* Copy dữ liệu sang các mảng tạm */
	for (i = 0; i < n1; i++)	
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	/* Gộp hai mảng tạm vừa rồi vào mảng arr*/
	i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
	j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
	k = l; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	/* Copy các phần tử còn lại của mảng L vào arr nếu có */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	/* Copy các phần tử còn lại của mảng R vào arr nếu có */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(list& L, int l, int r) {
	if (l < r) {
		int m =l + (r - l) / 2;
		merge_sort(L, l, m);
		merge_sort(L, m + 1, r);
		merge(L.a, l, m, r);
	}

}

void quick_sort(list& l, int left, int right) {
	int x = l.a[(right - left) / 2];
	int i = left, j = right;
	while (i <= j) {
		while (l.a[i] < x) i++;
		while (l.a[j] > x) j--;
		if (i <= j) {
			swap(l.a[i], l.a[j]);
			i++; j--;
		}
	}
	if (left < j) quick_sort(l, left, j);
	if (i < right) quick_sort(l, i, right);
}

void heapify(int a[], int n, int i) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < n && a[l] > a[largest]) {
		largest = l;
	}
	if (r < n && a[r] > a[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(a[largest], a[i]);
		heapify(a, n, largest);
	}
}

void heap_sort(list& l) {
	for (int i = l.n / 2 - 1; i >= 0; i--) {
		heapify(l.a, l.n, i);
	}
	for (int i = l.n - 1; i >= 0; i--) {
		swap(l.a[0], l.a[i]);
		heapify(l.a, i, 0);
	}
}
//Them ptu
void input(list& l) {
	cout << "Nhap phan tu cho danh sach:\n";
	for (int i = 0; i < l.n; i++) {
		cout << "Phan tu thu [" << i + 1 << "]: "; cin >> l.a[i];
	}
}

//xuat danh sach
void output(list l) {
	cout << "Danh sach da nhap la: ";
	for (int i = 0; i < l.n; i++) {
		cout << l.a[i] << " ";
	}
	cout << endl;
}

using namespace std;
int main() {
	list l;
	int x;
	do
	{
		cout << "Nhap  kich thuoc danh sach: "; cin >> l.n;
		if (l.n > Max)
			cout << "Kich thuoc qua lon !vui long nhap lai!\n";
	} while (l.n > Max);
	input(l);

	/*cout << "Nhap phan tu muon tim: "; cin >> x;
	cout << "Phan tu " << x << " co vi tri thu " << search(l, x) + 1 << " trong danh sach" << endl;*/
	merge_sort(l, 0, l.n - 1);
	output(l);
	//cout << "Phan tu lon nhat la: " << find_Max(l) << endl;
	//cout << "Phan tu lon thu 2 la: " << find_Second_Max(l) << endl;
	return 0;	
}