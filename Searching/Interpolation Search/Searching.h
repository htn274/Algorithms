#pragma once

int binarySearch(int a[], int n, int x) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (a[mid] == x) return mid;
		if (a[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}

int interpolationSearch(int a[], int n, int x) {
	int l = 0, r = n - 1;
	while (l <= r) {
		if (x > a[r] || x < a[l]) return -1;
		int pos = (double)((x - a[l]) * (r - l)) / (a[r] - a[l]) + l;
		if (a[pos] == x) return pos;
		if (a[pos] < x) l = pos + 1; else r = pos - 1;
	}
	return -1;
}