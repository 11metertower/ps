#include <stdio.h>
#include <limits.h>

int size, msize, xsize;
int mheap[500001], xheap[500001];

void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void mheapify(int element, int target, int mod)
{
	if (mod) {
		mheap[target] = element;
		while (1) {
			if (target > 1 && mheap[target / 2] > mheap[target]) {
				swap(&mheap[target / 2], &mheap[target]);
				target /= 2;
			}
			else
				break;
		}
	}
	else {
		mheap[target] = element;
		while (1) {
			if (mheap[target] > mheap[target * 2 + 1] && mheap[target * 2] >= mheap[target * 2 + 1] && target * 2 + 1 <= msize) {
				swap(&mheap[target], &mheap[target * 2 + 1]);
				target = target * 2 + 1;
			}
			else if (mheap[target] > mheap[target * 2] && target * 2 <= msize) {
				swap(&mheap[target], &mheap[target * 2]);
				target = target * 2;
			}
			else
				break;
		}
	}
}

void xheapify(int element, int target, int mod)
{
	if (mod) {
		xheap[target] = element;
		while (1) {
			if (target > 1 && xheap[target / 2] < mheap[target]) {
				swap(&xheap[target / 2], &xheap[target]);
				target /= 2;
			}
			else
				break;
		}
	}
	else {
		xheap[target] = element;
		while (1) {
			if (xheap[target] < xheap[target * 2 + 1] && xheap[target * 2] <= xheap[target * 2 + 1] && target * 2 + 1 <= xsize) {
				swap(&xheap[target], &xheap[target * 2 + 1]);
				target = target * 2 + 1;
			}
			else if (xheap[target] < xheap[target * 2] && target * 2 <= xsize) {
				swap(&xheap[target], &xheap[target * 2]);
				target = target * 2;
			}
			else
				break;
		}
	}
}

void insert(int element)
{
	size++;
	if (size == 1) {
		msize++;
		mheapify(element, msize ,1);
		return;
	}
	if (size % 2) {
		if (element < xheap[1]) {
			msize++;
			mheapify(xheap[1], xsize, 1);
			xheapify(element, 1, 0);
		}
		else {
			msize++;
			mheapify(element, msize, 1);
		}
	}
	else {
		if (mheap[1] < element) {
			xsize++;
			xheapify(mheap[1], msize, 1);
			mheapify(element, 1, 0);
		}
		else {
			xsize++;
			xheapify(element, xsize, 1);
		}
	}
}

int delete_min()
{
	int tmp = find_min();
	int ret = xheap[tmp];
	size--;
	xsize--;
	if (tmp != xsize + 1)
		xheapify(xheap[xsize + 1], tmp, 1);
	return ret;
}

int delete_max()
{
	int tmp = find_max();
	int ret = mheap[tmp];
	size--;
	msize--;
	if (tmp != msize + 1)
		mheapify(mheap[msize + 1], tmp, 1);
	return ret;
}

int delete_median()
{
	int ret;
	if (size % 2) {
		ret = mheap[1];
		size--;
		msize--;
		mheapify(mheap[msize + 1], 1, 0);
		return ret;
	}
	ret = xheap[1];
	size--;
	xsize--;
	xheapify(xheap[xsize + 1], 1, 0);
	return ret;
}

int find_min()
{
	int i, idx, maxx = INT_MIN;
	for (i = xsize / 2 + 1; i <= xsize; i++) {
		if (maxx <= xheap[i]) {
			maxx = xheap[i];
			idx = i;
		}
	}
	return idx;
}

int find_max()
{
	int i, idx, minn = INT_MAX;
	for (i = msize / 2 + 1; i <= msize; i++) {
		if (minn >= mheap[i]) {
			minn = mheap[i];
			idx = i;
		}
	}
	return idx;
}

int find_median()
{
	if(size%2)
		return mheap[1];
	return xheap[1];
}

int main()
{
	int t, n, i, inputc, inputb;
	char inputa;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		size = 0, msize = 0, xsize = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf(" %c", &inputa);
			if (inputa == 'I') {
				scanf("%d", &inputc);
				insert(inputc);
			}
			else if (inputa == 'D') {
				scanf("%d", &inputb);
				if (!size)
					continue;
				if (inputb == -1) {
					if (size == 1) {
						msize--;
						size--;
					}
					else
						delete_min();
				}
				else if (inputb == 1)
					delete_max();
			}
		}
		if (size == 0)
			printf("EMPTY\n");
		else
			printf("%d %d\n", mheap[find_max()], xheap[find_min()]);
	}
	return 0;
}