#ifndef __CUSTOM_SWAP_H__
#define __CUSTOM_SWAP_H__

#define Swap(a, b, type) do {\
    type __t = a;\
    a = b;\
    b = __t;\
} while(0)

#define SwapInt8(a, b) Swap(a, b, char)
#define SwapUint8(a, b) Swap(a, b, unsigned char)
#define SwapInt16(a, b) Swap(a, b, short)
#define SwapUint16(a, b) Swap(a, b, unsigned short)
#define SwapInt32(a, b) Swap(a, b, long)
#define SwapUint32(a, b) Swap(a, b, unsigned long)
#define SwapInt64(a, b) Swap(a, b, long long)
#define SwapUint64(a, b) Swap(a, b, unsigned long long)
#define SwapCString(a, b) Swap(a, b, const char*)
#define SwapFloat(a, b) Swap(a, b, float)
#define SwapDouble(a, b) Swap(a, b, double)

#endif