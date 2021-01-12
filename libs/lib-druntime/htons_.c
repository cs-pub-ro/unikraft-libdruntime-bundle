unsigned short bswap_16(unsigned short __x)
{
	return __x<<8 | __x>>8;
}


unsigned short htons(unsigned short n)
{
    union { int i; char c; } u = { 1 };
	return u.c ? bswap_16(n) : n;
}
