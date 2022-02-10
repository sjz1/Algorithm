void swap(int* a, int f_element, int s_element)
{
	int temp = a[f_element];
	a[f_element] = a[s_element];
	a[s_element] = temp;
}

int partition(int* a, int first, int last)
{
	int lastSmall = first , i;
	for (i = first + 1; i <= last; i++)
	{
		if (a[i] <= a[first])
		{
			lastSmall++;
			swap(a, lastSmall, i);
		}
	}
	swap(a, first, lastSmall);
	return lastSmall;
}

void Quicksort(int* a, int first_index, int last_index)
{
	if (first_index >= last_index) { return; } //데이터가 없거나 1개인 경우
	int split_pt = partition(a, first_index, last_index);
	Quicksort(a, first_index, split_pt - 1);
	Quicksort(a, split_pt + 1, last_index);
}
