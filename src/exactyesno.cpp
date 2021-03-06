#include "testlib.h"
#include <sstream>
#include <string>

#define YES "YES"
#define NO  "NO"

bool readYesNo(InStream& stream) {
    static std::string s;
    stream.readTokenTo(s);
    std::string upper = upperCase(s);
    if (upper == YES)
        return true;
    if (upper == NO)
        return false;
    stream.quitf(_pe, "'" YES "' or '" NO "' expected, but '%s' found", compress(s).c_str());
}

int main(int argc, char* argv[ ]) {
    setName("compare sequences of '" YES "' or '" NO "' (case-insensitive)");
    registerTestlibCmd(argc, argv);

    int n = 0;
    bool j, p = false;
    int mask = 0x0;

    while (!ans.seekEof()) {
        n++;
        j = readYesNo(ans);
        quitif(ouf.seekEof(),
            _wa, "Unexpected EOF in participant's output: '%s' expected", j ? YES : NO
        );
        p = readYesNo(ouf);

        if (j != p)
            expectedButFound(
                _wa, j ? YES : NO, p ? YES : NO, "%d%s words differ", n, englishEnding(n).c_str()
            );

        if (n <= 5)
            mask |= p << n;
    }
    if (!ouf.seekEof()) {
        p = readYesNo(ouf);
        quitf(_wa, "Extra words in participant's output: '%s'", p ? YES : NO);
    }

    if (n == 1)
        quit(_ok, p ? YES : NO);
    else if (n <= 5) {
        std::ostringstream ss;
        ss << (mask & 0x2 ? YES : NO);
        for (int i = 2; i <= n; i++)
            ss << ' ' << (mask & 1 << i ? YES : NO);
        quitf(_ok, "%d words: '%s'", n, ss.str().c_str());
    } else
        quitf(_ok, "%d words", n);
}
