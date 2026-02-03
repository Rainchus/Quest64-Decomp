#include "os.h"
#include "xstdio.h"
//#include "string.h"

// TODO: this comes from a header
#ident "$Revision: 1.23 $"

void* proutSprintf(void* s, const char* buf, size_t n);

void* proutSprintf(void* s, const char* buf, size_t n) {
    return (char*)memcpy(s, buf, n) + n;
}

int sprintf(char* s, const char* fmt, ...) {
    int ans;
    va_list ap;
    va_start(ap, fmt);
    ans = _Printf(proutSprintf, s, fmt, ap);
    if (ans >= 0) {
        s[ans] = 0;
    }
    return ans;
}
