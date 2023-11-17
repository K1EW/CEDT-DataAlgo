void shift(int k) {
	node* ptr = mHeader->next;
	while (k<0) k += mSize;
	int n = k%mSize;
	while (n--) ptr = ptr->next;

	mHeader->next->prev = mHeader->prev;
	mHeader->prev->next = mHeader->next;

	mHeader->next = ptr;
	mHeader->prev = ptr->prev;

	mHeader->prev->next = mHeader;
	mHeader->next->prev = mHeader;
}